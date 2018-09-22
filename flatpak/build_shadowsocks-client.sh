#!/bin/bash

flatpak-builder --repo=tutorial-repo shadowsocks-deepin cn.net.pikachu.shadowsocks-deepin.json --force-clean
flatpak --user uninstall  cn.net.pikachu.shadowsocks-deepin
flatpak --user install tutorial-repo cn.net.pikachu.shadowsocks-deepin
flatpak build-bundle tutorial-repo shadowsocks-deepin.flatpak cn.net.pikachu.shadowsocks-deepin

