/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- 
 * Author: F.Qian, Nov., 2012. <fei@kanto-gakuin.ac.jp>
 */
#define	DUMBBELL 1

#include <iostream>

#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/point-to-point-layout-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc,argv);

#ifdef DUMBBELL
  uint32_t    nLeftLeaf  = 5;
  uint32_t    nRightLeaf = 5;

  // Create the point-to-point link helpers
  PointToPointHelper p2pRouter, p2pLeaf;
  PointToPointDumbbellHelper dumbbell_net (nLeftLeaf, p2pLeaf, nRightLeaf, p2pLeaf, p2pRouter);

  // Install Stack
  InternetStackHelper stack;
  dumbbell_net.InstallStack (stack);

  // Assign IP Addresses
  dumbbell_net.AssignIpv4Addresses (
		Ipv4AddressHelper ("10.1.1.0", "255.255.255.0"),
		Ipv4AddressHelper ("10.2.1.0", "255.255.255.0"),
		Ipv4AddressHelper ("10.3.1.0", "255.255.255.0"));

  dumbbell_net.BoundingBox (1, 1, 100, 100);

#endif

#ifdef GRID
  uint32_t nRows = 8; 
  uint32_t nCols = 8;

  PointToPointHelper p2p;
  PointToPointGridHelper grid_net (nRows, nCols, p2p);

  InternetStackHelper stack;
  grid_net.InstallStack (stack);

  grid_net.AssignIpv4Addresses (Ipv4AddressHelper ("10.1.1.0", "255.255.255.0"),
                         Ipv4AddressHelper ("10.2.1.0", "255.255.255.0"));
#endif

#ifdef STAR
  uint32_t numSpokes = 12;

  PointToPointHelper p2p;
  PointToPointStarHelper star_net (numSpokes, p2p);

  InternetStackHelper stack;
  star_net.InstallStack (stack);

  star_net.AssignIpv4Addresses (Ipv4AddressHelper ("192.168.1.0", "255.255.255.0"));
#endif

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
