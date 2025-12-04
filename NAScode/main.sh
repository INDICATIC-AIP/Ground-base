#!/bin/bash

/var/services/homes/INDICATIC/InteroperabilityCode/OrderImages.sh > /dev/null 2>&1 &

#This code look intot all directory of each stations, if CryptFile files are detected, then the code fileTreatment is executed
NASPath=("Caribe" "Punto_medio/STRE" "Pacifico/INDICATIC/UTP")

while :; do
  for dir in "${NASPath[@]}"; do

    cd "/var/services/homes/INDICATIC/"$dir"/ALPY"
    echo "In ALPY directory of "$dir""
    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/ALPY"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/NIKON"
      echo "In NIKON directory of "$dir""

      resultat=$(find . \( -type f \) -name "*CryptFile*")
      if [[ -n "$resultat" ]]; then
        directory="/var/services/homes/INDICATIC/"$dir"/NIKON"
        /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
      fi

      sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/QHYCCD/B-Bessell"
    echo "In QHYCCD B directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/QHYCCD/B-Bessell"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/QHYCCD/I-Bessell"
    echo "In QHYCCD I directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/QHYCCD/I-Bessell"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi
    
    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/QHYCCD/R-Bessell"
    echo "In QHYCCD R directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/QHYCCD/R-Bessell"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/QHYCCD/U-Bessell"
    echo "In QHYCCD U directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/QHYCCD/U-Bessell"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/QHYCCD/V-Bessell"
    echo "In QHYCCD V directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/QHYCCD/V-Bessell"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/TESS-W"
    echo "In TESS-W directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/TESS-W"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi

    sleep 3

    cd "/var/services/homes/INDICATIC/"$dir"/TESS-W4"
    echo "In TESS-W4 directory of "$dir""

    resultat=$(find . \( -type f \) -name "*CryptFile*")
    if [[ -n "$resultat" ]]; then
      directory="/var/services/homes/INDICATIC/"$dir"/TESS-W4"
      /var/services/homes/INDICATIC/InteroperabilityCode/fileTreatment.sh "$directory"
    fi
  done
done
