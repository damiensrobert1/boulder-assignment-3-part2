#!/bin/sh

#Initialisation
if [ -z $1 ]; then exit 1; else writefile=$1; writedir=$(dirname $writefile) ; fi
if [ -z $2 ]; then exit 1; else writestr=$2; fi
if [ ! -d $writedir ]; then  mkdir -p $writedir; fi

#Running
echo -n $writestr > $writefile

#clean
#Nothing to do

#exit
exit $?
