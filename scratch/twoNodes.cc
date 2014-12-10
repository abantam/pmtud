#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"

using namespace ns3;

#define BANDWIDTH = 5Mbps;//帯域幅
#define DELAY = 20ms;//遅延時間

int main() {
	
	//コンテナ１にノードを２つ生成
	NodeContainer network1_nodes;
	network1_nodes.Create(2);
	
	//コンテナ２にノードを１つ生成
	NodeContainer network2_nodes;
	network2_nodes.Add(network1_nodes.Get(1));//コンテナ１にあるノード１つをコンテナ２に取り入れる
	network2_nodes.Create(1);
	
	//ノード間の配線の属性を設定
	PointToPointHelper p2p;
	p2p.SetDeviceAttribute("DataRate", StringValue("5Mbps"));//帯域幅を指定
	p2p.SetChannelAttribute("Delay", StringValue("2ms"));//伝搬遅延を指定
	
	//各コンテナの管理を行うための設定
	NetDeviceContainer dev0 = p2p.Install(network1_nodes);
	NetDeviceContainer dev1 = p2p.Install(network2_nodes);

	Simulator::Run();
	Simulator::Destroy();

	return 0;
}
