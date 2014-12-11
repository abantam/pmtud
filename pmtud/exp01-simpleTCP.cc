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
}


