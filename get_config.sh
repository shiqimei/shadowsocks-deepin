#!/usr/bin/env bash
if [ $# -lt 1 ]; then
    echo "error.. need args"
    exit 1
fi
for line in $(cat $1)
do
if [[ ${line:0:1}="#" ]]; then
continue
fi
echo $line
done