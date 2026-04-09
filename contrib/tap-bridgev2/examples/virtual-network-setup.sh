#!/bin/bash

# docker run -it --name node1 --network=none -d ubuntu bash
# docker run -it --name node2 --network=none -d ubuntu bash

# docker inspect node1 | grep 'Pid'
# docker inspect node1 | grep 'Pid'
ip netns add node1
ip netns add node2
ip link add node1v1 type veth peer node1v2
ip link add node2v1 type veth peer node2v2

ip link set node1v1 netns  node1
ip link set node2v1 netns  node2

ip netns exec node1 sh -c 'ip link set lo up && ip link set node1v1 up && ip addr add 10.0.0.1/24 dev node1v1 && ip -6 addr flush dev node1v1 && sysctl -w net.ipv6.conf.all.disable_ipv6=1'
ip netns exec node2 sh -c 'ip link set lo up && ip link set node2v1 up && ip addr add 10.0.0.2/24 dev node2v1 && ip -6 addr flush dev node2v1 && sysctl -w net.ipv6.conf.all.disable_ipv6=1'

ip link add br-left type bridge
ip link add br-right type bridge
ip tuntap add mode tap tap-left
ip tuntap add mode tap tap-right
ip link set tap-left promisc on up
ip link set tap-right promisc on up

ip link set dev tap-left master br-left
ip link set dev br-left up
ip link set dev node1v2 master br-left
ip link set dev node1v2 up

ip link set dev tap-right master br-right
ip link set dev br-right up
ip link set dev node2v2 master br-right
ip link set dev node2v2 up
