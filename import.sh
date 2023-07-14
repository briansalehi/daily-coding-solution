#!/usr/bin/bash

# this script should only run when problems directory exist
# alternatively clone problems manually:
# https://github.com/oleg-cherednik/DailyCodingProblem.git
if ! [ -d problems/ ]
then
    git clone --depth 1 https://github.com/oleg-cherednik/dailycodingproblem.git problems
fi

# iterate through directories and move pdf files into corresponding solution directories
while read -r dir
do
    index="$(printf '%04d' "$(sed 's/\#0*\([0-9]\+\)\s*.*/\1/' <<< "$(basename "$dir")")")"

    if ! [ -d "solutions/$index" ]
    then
        mkdir "solutions/$index"
    fi

    if ! [ -f "solutions/$index/solution.pdf" ]
    then
        cp "$dir"/*.pdf "solutions/$index/solution.pdf"
    fi
done <<< "$(find problems/ -mindepth 2 -maxdepth 2 -type d -name '#*')"
