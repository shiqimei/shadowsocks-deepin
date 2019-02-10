#!/bin/bash
# this file is used to auto-generate translation source files.
# author: lolimay <lolimay@lolimay.cn>

mv ../i18n/shadowsocks-deepin_zh.xml ../i18n/shadowsocks-deepin_zh.ts
lupdate -recursive ../ -ts ../i18n/shadowsocks-deepin_zh.ts

ts_list=(`ls ../i18n/*.ts`)
for ts in "${ts_list[@]}"
do
    ts_without_extension=`echo "${ts%.*}"`
    mv "${ts_without_extension}.ts" "${ts_without_extension}.xml"
done