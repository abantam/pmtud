/*
グリッド型トポロジーの自動生成例
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
	
	uint32_t nRows = 8;//グリッドの行数
	uint32_t nCols = 8;//グリッドの列数
	
	PointToPointHelper p2p;
	PointToPointGridHelper grid_net(nRows, nCols, p2p);
	
	InternetStackHelper stack;
	grid_net.InstallStack(stack);
	
	grid_net.AssignIpv4Addresses(Ipv4AddressHelper("10.1.1.0", "255.255.255.0"), Ipv4AddressHelper("10.2.1.0", "255.255.255.0"));
	
	Simulator::Run();
	Simulator::Destroy();
	
	return 0;
}
