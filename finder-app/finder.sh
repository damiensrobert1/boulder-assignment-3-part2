#!/bin/sh

# Initialisation
if [ -z $1 ]; then exit 1; else filedir=$1; fi
if [ -z $2 ]; then exit 1; else searchstr=$2; fi
if [ ! -d $filedir ]; then exit 1; fi

# Run
filesnum=$(find $filedir -type f | wc -l)
matchinglines=$(grep -r $searchstr $filedir | wc -l)
echo "The number of files are $filesnum and the number of matching lines are $matchinglines" 

#clean
# Nothing to do

exit $?
