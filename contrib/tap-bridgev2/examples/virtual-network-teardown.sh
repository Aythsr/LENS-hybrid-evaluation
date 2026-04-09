#!/bin/bash

# docker stop node1 && docker rm node1
# docker stop node2 && docker rm node2
ip netns del node1
ip netns del node2
ip link del node1v1
ip link del node2v1
ip link set dev br-left down
ip link set dev br-right down
ip link set dev tap-left nomaster
ip link set dev tap-right nomaster
ip link del br-left
ip link del br-right
ip link set dev tap-left down
ip link set dev tap-right down
ip tuntap del mode tap tap-left
ip tuntap del mode tap tap-right
