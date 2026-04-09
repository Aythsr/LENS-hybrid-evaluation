
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/network-module.h"
#include "ns3/tap-bridgev2-module.h"

#include <fstream>
#include <iostream>

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("TestTapBridgeV2");

int
main(int argc, char* argv[])
{
    std::string img = "docker.1ms.run/ubuntu";
    LogComponentEnable("TapBridgeV2", LOG_LEVEL_ALL);
    LogComponentEnable("TapTransmitter", LOG_LEVEL_DEBUG);
    LogComponentEnable("TimeController", LOG_LEVEL_FUNCTION);
    LogComponentEnable("TestTapBridgeV2", LOG_LEVEL_INFO);
    
    CommandLine cmd(__FILE__);
    cmd.AddValue("img", "Image name for the container", img);

    cmd.Parse(argc, argv);

    GlobalValue::Bind("SimulatorImplementationType", StringValue("ns3::BalancingSimulatorImpl"));

    NodeContainer nodes;
    nodes.Create(2);

    CsmaHelper csma;
    csma.SetChannelAttribute("DataRate", DataRateValue(5000000 * 2));
    csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));

    NetDeviceContainer devices = csma.Install(nodes);

    InternetStackHelper stack;
    stack.Install(nodes);

    Ipv4AddressHelper addresses;
    addresses.SetBase("10.0.0.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces = addresses.Assign(devices);

    TapBridgeV2::setPythonPath("./.venv/bin/python3");
    TapBridgeV2::setContainerControlScript("./contrib/tap-bridgev2/model/container-controller.py");

    NS_LOG_INFO("创建并安装 TapBridgeV2 设备");

    Ptr<TapBridgeV2> tapBridge1 = CreateObject<TapBridgeV2>();
    Ptr<TapBridgeV2> tapBridge2 = CreateObject<TapBridgeV2>();

    tapBridge1->SetImage(img);
    tapBridge2->SetImage(img);
    
    tapBridge1->install(devices.Get(0));
    tapBridge2->install(devices.Get(1));

    // Ipv4GlobalRoutingHelper::PopulateRoutingTables();

    Simulator::Stop(Seconds(600));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
