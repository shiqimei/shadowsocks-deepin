#!/bin/bash

flatpak-builder --repo=tutorial-repo shadowsocks-client cn.net.pikachu.shadowsocks-client.json --force-clean
flatpak --user uninstall  cn.net.pikachu.shadowsocks-client
flatpak --user install tutorial-repo cn.net.pikachu.shadowsocks-client
flatpak build-bundle tutorial-repo shadowsocks-client.flatpak cn.net.pikachu.shadowsocks-client

