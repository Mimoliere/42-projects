#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usage: $0 <project_name>"
	exit 1
fi

mkdir -p $1
mkdir -p $1/subject
mkdir -p $1/srcs
mkdir -p $1/includes
touch $1/Makefile
touch $1/README.md

exit 0
