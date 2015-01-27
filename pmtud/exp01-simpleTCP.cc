/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/* exp01-simpleTCP: simulate TCP behaviours with a simple 4-nodes topology.
 * F.Qian, Nov. 2012
 *
 * n0(tcp source) 
 *  \.1
 *   \ net1(25Mbps,2ms)192.168.1.0/24
 *  .2\
 *     n1 -----net3(10Mbps,5ms)----- n3(tcp sink)
 *  .1/  .1	192.168.3.0/24      .2
 *   / net2(25Mbps,2ms)192.168.2.0/24
 *  /.2
 * n2(tcp source)
 */

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

#define	NET_MASK  	"255.255.255.0"
#define	NET_ADD1  	"192.168.1.0"
#define	NET_ADD2  	"192.168.2.0"
#define	NET_ADD3  	"192.168.3.0"
#define	FIRST_NO  	"0.0.0.1"

#define	SIM_START 	00.10
#define	SIM_STOP  	20.10
#define DATA_MBYTES  	500
#define PORT		50000

using namespace ns3;

#define PROG_DIR	"local/exp01/data/"

NS_LOG_COMPONENT_DEFINE ("exp01-SimpleTCP");

int main (int argc, char *argv[], char *envp[])
{
	CommandLine cmd;
	std::string	trace_socket = "false";

	cmd.AddValue("traceSocket", "True:trace TCP flow between source and sink.", trace_socket);
	cmd.Parse(argc, argv);

	if(trace_socket.compare("True") == 0)
  		LogComponentEnable("TcpSocketBase", LOG_LEVEL_FUNCTION);
  	else
		LogComponentEnable("TcpNewReno", LOG_LEVEL_INFO);

	Config::SetDefault ("ns3::DropTailQueue::MaxPackets", UintegerValue (5));

  	NS_LOG_DEBUG("Creating Topology");
  	NodeContainer net1_nodes;
  	net1_nodes.Create (2);

  	NodeContainer net2_nodes;
	net2_nodes.Add (net1_nodes.Get(1));
  	net2_nodes.Create (1);

  	NodeContainer net3_nodes;
	net3_nodes.Add (net1_nodes.Get(1));
  	net3_nodes.Create (1);

  	PointToPointHelper p2p1;
  	p2p1.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  	p2p1.SetChannelAttribute ("Delay", StringValue ("2ms"));
	p2p1.SetQueue ("ns3::DropTailQueue");

  	NetDeviceContainer devices1;
  	devices1 = p2p1.Install (net1_nodes);

  	NetDeviceContainer devices2;
  	devices2 = p2p1.Install (net2_nodes);

  	PointToPointHelper p2p2;
  	p2p2.SetDeviceAttribute ("DataRate", StringValue ("800Kbps"));
  	p2p2.SetChannelAttribute ("Delay", StringValue ("5ms"));
	p2p2.SetQueue ("ns3::DropTailQueue");

  	NetDeviceContainer devices3;
  	devices3 = p2p2.Install (net3_nodes);

  	InternetStackHelper stack;
  	stack.InstallAll ();

  	Ipv4AddressHelper address;

  	address.SetBase (NET_ADD1, NET_MASK, FIRST_NO);
  	Ipv4InterfaceContainer ifs1 = address.Assign (devices1);
  	NS_LOG_INFO ("Network 1: " << ifs1.GetAddress(0, 0) << " - " << ifs1.GetAddress(1, 0));

  	address.SetBase (NET_ADD2, NET_MASK, FIRST_NO);
  	Ipv4InterfaceContainer ifs2 = address.Assign (devices2);
  	NS_LOG_INFO ("Network 2: " << ifs2.GetAddress(0, 0) << " - " << ifs2.GetAddress(1, 0));

  	address.SetBase (NET_ADD3, NET_MASK, FIRST_NO);
  	Ipv4InterfaceContainer ifs3 = address.Assign (devices3);
  	NS_LOG_INFO ("Network 3: " << ifs3.GetAddress(0, 0) << " - " << ifs3.GetAddress(1, 0));

	NS_LOG_INFO ("Initialize Global Routing.");
  	Ipv4GlobalRoutingHelper::PopulateRoutingTables ();

	AddressValue remoteAddress (InetSocketAddress (ifs3.GetAddress(1, 0), PORT));

	BulkSendHelper ftp ("ns3::TcpSocketFactory", Address());
	ftp.SetAttribute ("Remote", remoteAddress);
	ftp.SetAttribute ("MaxBytes", UintegerValue (int(DATA_MBYTES * 1024 * 1024)));

	ApplicationContainer sourceApp1 = ftp.Install (net1_nodes.Get(0));
        sourceApp1.Start (Seconds (SIM_START+0.1));
        sourceApp1.Stop  (Seconds (SIM_STOP -0.1));

	// create a sink to recieve packets @ network3's node 1(192.168.3.2).
  	Address sinkAddress (InetSocketAddress (Ipv4Address::GetAny (), PORT));
  	PacketSinkHelper sinkHelper ("ns3::TcpSocketFactory", sinkAddress);

	//sinkHelper.SetAttribute ("Protocol", TypeIdValue (TcpSocketFactory::GetTypeId ()));
        ApplicationContainer sink_apps = sinkHelper.Install (net3_nodes.Get(1));

	sink_apps.Start (Seconds (SIM_START+0.1));
  	sink_apps.Stop  (Seconds (SIM_STOP -0.1));

	// Tracing stuff
	AsciiTraceHelper ascii;
	std::string afname = std::string(PROG_DIR) + "simple-tcp.tr";
        p2p2.EnableAsciiAll (ascii.CreateFileStream (afname));

  	// for PCAP Tracing
	//std::string pfname = std::string(PROG_DIR) + "simple-tcp";
	//p2p2.EnablePcapAll (pfname);

	Simulator::Stop (Seconds(SIM_STOP));
  	Simulator::Run ();
  	Simulator::Destroy ();
  	return 0;
}
