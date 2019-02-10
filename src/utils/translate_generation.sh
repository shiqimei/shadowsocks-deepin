#!/bin/bash
# this file is used to auto-generate .qm file from .ts file.
# author: shibowen at linuxdeepin.com

ts_list=(`ls ../i18n/*.xml`)

for ts in "${ts_list[@]}"
do
    ts_without_extension=`echo "${ts%.*}"`
    mv ${ts} ${ts_without_extension}
    printf "\nprocess ${ts}\n"
    lrelease "${ts_without_extension}"
    mv ${ts_without_extension} ${ts}
done