#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Incorrect number of arguments"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: Directory not created"
    exit 1
fi