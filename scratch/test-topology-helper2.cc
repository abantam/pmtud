/*
スター型トポロジーの自動生成
*/

#include "ns3/point-to-point-layout-module.h"

int main(int argc, char *argv[]) {
  CommandLine cmd;
  cmd.Parse(argc, argv);

  uint32_t numSpokes = 12;//中央ノードを含む全ノード数

  PointTpPointHelper p2p;//ノード接続用ヘルパーのインスタンス
  PointToPointStarHelper star_net(numSpokes, p2p);

  InternetStackHelper stack;
  star_net.InstallStack(stack);

  star_net.AssignIpv4Addresses(Ipv4AddressHelper("192.168.1.0", "255.255.255.0"));
  
  Simulator::Run();
  Simulator::Destroy();
  return 0;
}
