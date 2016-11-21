#!/bin/bash

declare -a artists
artists[0]="Pink Floyd"
artists[1]="Grateful dead"
artists[2]="Nick Drake"
artists[3]="Merle Haggard"
artists[4]="Lynyrd Skynyrd"
artists[5]="Will Oldham"
artists[6]="Tom Petty"
artists[7]="George Jones"
artists[8]=""

declare -a songs
songs[0]="Love is in the air"
songs[1]="Lovie lovie lovie"
songs[2]="Air is in the love"
songs[3]="Arty farty"
songs[4]="Door"
songs[5]="Mighty boosh"
songs[6]="Rich Fulcher love me"
songs[7]="Naboo"
songs[8]="Bollo"
songs[9]="Old Greg's ballads"
songs[10]="Vince and Neil"
songs[11]=" "

declare -a albums
albums[0]="Albumie"
albums[1]="Greatest hits"
albums[2]="My number ones"
albums[3]="December is the coldest month"
albums[4]="November november"
albums[5]="Unknown album"
albums[5]=" "

NR_ARTISTS=${#artists[@]}
NR_ALBUMS=${#albums[@]}
NR_SONGS=${#songs[@]}

CNT=0
LIMIT=$1

if [ "$(echo $LIMIT | grep -e '^[0-9][0-9]*$' |wc -l)" = "0" ]
then
    echo "You must supply a number .... $1 will not do"
    exit 1
fi
   

while [ $CNT -lt $LIMIT ]
do
    IDX=$(( $RANDOM % $NR_ARTISTS ))
    echo "${artists[$IDX]}"
    IDX=$(( $RANDOM % $NR_ALBUMS ))
    echo "${albums[$IDX]}"
    IDX=$(( $RANDOM % $NR_SONGS ))
    echo "${songs[$IDX]}"
    CNT=$(( $CNT + 1 ))
done
