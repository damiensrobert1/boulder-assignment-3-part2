#!/bin/sh

#Initialisation
if [ -e $1 ]; then exit 1; else writefile=$1; writedir=$(dirname $writefile) ; fi
if [ -e $2 ]; then exit 1; else writestr=$2; fi
if [ ! -d $writedir ]; then  mkdir -p $writedir; fi

#Running
echo -n $writestr > $writefile

#clean
#Nothing to do

#exit
exit $?
