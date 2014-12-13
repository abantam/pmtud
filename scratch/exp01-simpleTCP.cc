#include <iostream>
#include <fstream>
#include <string>

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/tcp-header.h"
#include "ns3/udp-header.h"

#define NET_ADD1 "192.168.1.0"
#define NET_ADD2 "192.168.2.0"
#define NET_ADD3 "192.168.3.0"
#define NET_MASK "255.255.255.0"
#define FIRST_NO "0.0.0.1"

#define SIM_START 00.10
#define SIM_STOP 10.10
#define DATA_MBYTES 500
#define PORT 50000

#define PROG_DIR "local/exp01/data/"

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("exp01-SimpleTCP");

int main(int argc, char *argv[]) {
    CommandLine cmd;
    std::string trace_socket = "False";
    
    cmd.AddValue("traceSocket", "True: trace source/sink sockets.", trace_socket);
    cmd.Parse(argc,argv);
    
    if(trace_socket.compare("True") == 0)
        LogComponentEnable("TcpSocketBase", LOG_LEVEL_FUNCTION);
    else
        LogComponentEnable("TcpNewReno", LOG_LEVEL_INFO);
        
    Config::SetDefault("ns3::DropTailQueue::MaxPackets", UintegerValue(5));
    
    NS_LOG_DEBUG("Creating Topology");
    NodeContainer net1_nodes;
    net1_nodes.Create(2);
    
    NodeContainer net2_nodes;
    net2_nodes.Add(net1_nodes.Get(1));
    net2_nodes.Create(1);
    
    NodeContainer net3_nodes;
    net3_nodes.Add(net1_nodes.Get(1));
    net3_nodes.Create(1);
    
    PointToPointHelper p2p1;
    p2p1.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
    p2p1.SetDeviceAttribute("Delay", StringValue("2ms"));
    p2p1.setQueue("ns3::DropTailQueue");
    
    NetDeviceContainer devices1;
    devices1 = p2p1.Install(net1_nodes);
    
    NetDeviceContainer devices2;
    devices2 = p2p1.Install(net2_nodes);
    
    PointToPointHelper p2p2;
    p2p2.setDeviceAttribute("DataRate", StringValue("800Kbps"));
    p2p2.setDeviceAttribute("Delay", StringValue("5ms"));
    p2p2.setQueue("ns3::DropTailQueue");
    
    NetDeviceContainer devices3;
    devices3 = p2p2.Install(net3_nodes);
    
    InternetStackHelper stack;
    stack.InstallAll();
    
    Ipv4AddressHelper address;
    
    address.SetBase(NET_ADD1, NET_MASK, FIRST_NO);
    Ipv4InterfaceContainer ifs1 = address.Assign(devices1);
    NS_LOG_INFO("Network 1: " << ifs1.GetAddress(0, 0) << " - " << ifs1.GetAddress(1, 0));
    
    address.SetBase(NET_ADD2, NET_MASK, FIRST_NO);
    Ipv4InterfaceContainer ifs2 = address.Assign(devices2);
    NS_LOG_INFO("Network 2: " << ifs2.GetAddress(0, 0) << " - " << ifs2.GetAddress(1, 0));
    
    address.SetBase(NET_ADD3, NET_MASK, FIRST_NO);
    Ipv4InterfaceContainer ifs3 = address.Assign(devices3);
    NS_LOG_INFO("Network 3: " << ifs3.GetAddress(0, 0) << " - " << ifs3.GetAddress(1, 0));
    
    NS_LOG_INFO("Initialize Global Routing.");
    Ipv4GlobalRoutingHelper::PopularRoutingTablets();
    
    //BulkSendHelperでシミュレートされるＦＴＰソケットを生成
    AddresValue remoteAddress(InetSocketAddress(ifa3.GetAddress(1, 0), PORT));
    BulkSendHelper ftp("ns3::TcpSocketFactory", Address());
    ftp.SetAttribute("Remote", remoteAddress);//接続先のピアアドレスを指定
    ftp.SetAttribute("MaxBytes", UIntegerValue(int(DATA_MBYTES) * 1024 * 1024));//転送される最大データ量を指定
    
    //ソースノードにＦＴＰアプリケーションを装着し、アプリケーションの開始・終了時刻を指定
    ApplicationContainer sourceApp1 = ftp.Install(net1_nodes.Get(0));
    sourceApp1.Start(Seconds(SIM_START + 0.1));
    sourceApp1.Stop(Seconds(SIM_STOP - 0.1));
    
    //シンクノード側の設定
    Address sinkAddress(InetSocketAddress(Ipv4Address::GetAny(), PORT));
    PacketSinkHelper sinkHelper("ns3::TcpSocketFactory", sinkAddress);
    
    ApplicationContainer sink_apps = sinkHelper.Install(net3_nodes.Get(1));
    sink_apps.Start(Seconds(SIM_START+0.1));
    sink_apps.Stop(Seconds(SIM_STOP-0.1));
    
    //トレース用設定
    AsciiTraceHelper ascii;
    std::string afname = std::string(PROG_DIR) + "simple-tcp.tr";
    p2p2.EnableAsciiAll(ascii.CreateFileStream(afname));
    
    //PCAPトレース用設定
    std::string pfname = std::string(PROG_DIR) + "simple-tcp";
    p2p2.EnablePcapAll(pfname);
    
    Simulator::Stop(Seconds(SIM_STOP));
    Simulator::Run();
    Simulator::Destroy();
    
    return 0;
} 


