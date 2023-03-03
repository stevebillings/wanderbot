#!/bin/bash

grep Copyright $1 > /dev/null
result="$?"
if [ "$result" = "1" ]; then
	echo "$1"
fi
