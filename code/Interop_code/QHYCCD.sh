#!/bin/bash

#From here the oldest file of QHY is selected and then treated

source /home/indicatic-e1/Desktop/code/Interop_code/TrameArchitecture.sh
source /home/indicatic-e1/Desktop/code/Interop_code/connect.sh
source /home/indicatic-e1/Desktop/code/Interop_code/info_Nass_connect.sh
source /home/indicatic-e1/Desktop/code/Interop_code/file_treatment.sh

Station=""
directory="/home/indicatic-e1/Desktop/ASTRODEVICES/QHYCCDFILE"
imageInfo="/home/indicatic-e1/Desktop/code/infoIMG"
File=$(ls -t --reverse "$directory" | head -n 1)

read -r Station < "/home/indicatic-e1/Desktop/code/NBstation.txt"
echo "Path of the station is : $Station"

#Select the number after the W letter wich indicate the filter used
index=$(echo "$File" | sed -n 's/.*W\([0-9]\+\).*/\1/p')

execution
