/*
ダンベル型トポロジーの自動生成例
*/

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

#include "ns3/point-to-point-layout-module.h"

using namespace ns3;

int main(int argc, char *argv[]) {
	CommandLine cmd;
	cmd.Parse(argc, argv);
	
	uint32_t nLeftLeaf = 5;//左辺のノード数
	uint32_t nRightLeaf = 5;//右辺のノード数
	
	PointToPointHelper p2pRouter, p2pLeaf;
	PointToPointDumbbellHelper net(nLeftLeaf, p2pLeaf, nRightLeaf, p2pLeaf, p2pRouter);
	
	InternetStackHelper stack;
	net.InstallStack(stack);
	
	//各ネットワークにＩＰアドレスを割り当てる
	net.AssignIpv4Addresses(Ipv4AddressHelper("192.168.1.0", "255.255.255.0"), 
	                        Ipv4AddressHelper("192.168.2.0", "255.255.255.0"), 
	                        Ipv4AddressHelper("192.168.3.0", "255.255.255.0"));
	
	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
