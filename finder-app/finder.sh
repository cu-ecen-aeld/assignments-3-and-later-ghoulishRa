#!/bin/bash 

if [ $# -ne 2 ]; then
    echo "pasa dos argumentoooooos"
    exit 1
fi


filesdir=$1
searchstr=$2


if [ ! -d "$filesdir" ]; then
    echo "Y pasa que: '$filesdir' no es un directorio valido"
    exit 1
fi

num_files=$(find "$filesdir" -type f | wc -l)

num_matches=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $num_files and the number of matching lines are $num_matches"