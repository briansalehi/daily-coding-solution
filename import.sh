#!/usr/bin/bash

# this script should only run when problems directory exist
# alternatively clone problems manually:
# https://github.com/oleg-cherednik/DailyCodingProblem.git
if ! [ -d problems/ ]
then
    echo "problems/ directory does not exist" >&2
    exit 1
fi

# iterate through directories and move pdf files into corresponding solution directories
for dir in "problems/#"*/*
do
    index="${dir##*#}"
    index="${index%% *}"
    doc="$dir/#$index.pdf"

    if ! [ -d "solutions/$index" ]
    then
        mkdir "solutions/$index"
    fi

    cp "$dir/#$index.pdf" "solutions/$index/$index.pdf"
done
