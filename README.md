# Project Description

Scientific and engineering group directed by Dr. José Robles focused on the first long-term light-pollution research program in a tropical environment across the Panama Canal Basin. The group develops remote-sensing methods, ground-based photometric and spectrometric instrumentation, and electronic/software control systems. Research activities integrate light pollution with environmental processes, biological interactions, and socioeconomic indicators such as GDP/PIB. 

# Interoperability Code 

The interoperability framework deployed here enables continuous operation of the INDICATIC–UTP substation and the automatic transmission of calibrated data to the institutional Network-Attached Storage (NAS). The system manages communication with multiple scientific instruments operating concurrently:

QHY 16200A (UV, B, V, R, and IR all-sky images)

Nikon D5600 (RGB all-sky imaging)

ALPY 600 spectrometer

TESS-W/TESS-4C


1. [AutoRun](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun)
2. [INDIcode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode)
3. [NAScode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/NAScode)
4. [code](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code)

--------------------------------------------------------------------

## Components ("AutoRun", "INDIcode", "NAScode", and "code").

### [AutoRun](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun)

This folder contains all scripts related to the automation of the stations, allowing remote control, error detection, and other operational tasks.

### [INDIcode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode)

This folder contains parts of the library sourced from the INDIGO Astronomy project: (https://github.com/indigo-astronomy/indigo/blob/master/indigo_drivers/ccd_qhy/bin_externals/qhyccd/include/qhyccd.h). These components enable the C++ scripts to function properly and control the QHY 16200A and ALPY 600 devices.

### [NAScode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/NAScode)

This folder contains the scripts used to achieve interoperability on the NAS side. File decryption and organization tasks are managed here to ensure data integrity.

### [code](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code)

This folder contains the interoperability scripts within the "Interop_code" directory. The "CryptageC" folder includes all encryption scripts used to secure data transmitted to the NAS.
Additional folders and .txt files serve as shared resources for determining NAS destinations, exchanging status information, and supporting interoperability processes.

--------------------------------------------------------------------

# Installation Instructions
Each folder contains a README explaining the functions of the scripts and specifying the required libraries. To fully install the interoperability code on a station, you must read and execute the instructions in all four folders.
A recommended installation order is:

1. code — https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code
2. INDIcode — https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode
3. AutoRun — https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun

Before installation, ensure Linux is properly installed on the Jetson system. Guidance:
1. Initial Setup Guide for Jetson Orin Nano:
2. https://www.jetson-ai-lab.com/initial_setup_jon.html
   
After cloning this repository on the station:
1. Move the folders "code", "INDIcode", and "AutoRun" to the Desktop.
2. Delete the folder "NAScode" (NAS-side only).
3. Delete the cloned folder "FID074-Estaciones" once extraction is complete.

You can now begin installation following each module’s README.

# Configuring the Station Name
To ensure the code uses the correct internal paths:
1. On the Desktop, open the script named station_rename.py.
2. Uncomment the following three lines:

 new_content = re.sub("indicatic-e1", "indicatice2", content)
 with open(filename, 'w', encoding='utf-8') as f:
 f.write(new_content)

Replace "indicatice2" with the actual station hostname.
Run the script:

python3 station_rename.py
whoami

# Contact Information

For scientific and technical inquiries about this project:
Jose Robles
jrobles@indicatic.org.pa

For questions about the code after reading the READMEs:
Jose Jaen
jose.jaenj08@hotmail.com
Alexandre Olivie
alexandre.olivie@bordeaux-inp.fr

For environmental communication or outreach regarding light pollution:
Alma Rivera
arivera@indicatic.org.pa
