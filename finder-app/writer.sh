#!/bin/bash

if [ $# -ne 2 ]; then
    echo "pasa dos argumentoooooos"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

echo "$writestr" > "$writefile"

if [ $? -ne 0 ]; then
    echo "Error: No se creo tu fichero"
    exit 1
fi