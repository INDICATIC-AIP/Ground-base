# Project Description

Scientific and engineering group directed by Dr. José Robles focused on the first long-term light-pollution research program in a tropical environment across the Panama Canal Basin. The group develops remote-sensing methods, ground-based photometric and spectrometric instrumentation, and electronic/software control systems. Research activities integrate light pollution with environmental processes, biological interactions, and socioeconomic indicators such as GDP/PIB.

# Interoperability Code for the INDICATIC–UTP Light Pollution Substation (Panama Canal Basin)

The interoperability framework deployed here enables continuous operation of the INDICATIC–UTP substation and the automatic transmission of calibrated data to the institutional Network-Attached Storage (NAS). The system manages communication with multiple scientific instruments operating concurrently:

QHY 16200A (UV, B, V, R, IR photometry)

Nikon D5600 (RGB photometry and all-sky imaging)

ALPY 600 spectrometer

TESS-W/TESS-4C


1. [AutoRun](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun)
2. [INDIcode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode)
3. [NAScode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/NAScode)
4. [code](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code)

--------------------------------------------------------------------

## The following folders : "AutoRun" "INDIcode" "NAScode" and "code", containing different components necessary for the interoperability code to function.

### [AutoRun](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun)

_AutoRun folder contains all scripts related to the automation of the stations, allowing remote control, error detection, and other operational tasks_

### [INDIcode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode)

_INDIcode folder contains parts of the library sourced from GitHub (https://github.com/indigo-astronomy/indigo/blob/master/indigo_drivers/ccd_qhy/bin_externals/qhyccd/include/qhyccd.h). These components enable the .cpp scripts to function properly and control the cameras QHY 16200A and Alpy 600._

### [NAScode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/NAScode)

_The NAScode folder contains the different codes to achieve interoperability on the NAS side. Additionally, the decryption of files is performed here to ensure integrity. Furthermore, other scripts in this folder manage the organization of various files._

### [code](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code)

_code folder contains the different codes for interoperability within the Interop_code folder. On the other hand, the CryptageC folder holds all the scripts responsible for encryption, ensuring data integrity on the NAS side and securing the information._

_Several folders and .txt files can also be seen. These are used by various scripts from Interop_code and CryptageC to share information, determine which repository on the NAS the data should be sent to, and handle related processes._

--------------------------------------------------------------------

In each README file within the four folders, the functions of all scripts are explained globally and each README file must be read and the command (under **Installation Instructions**) executed if you want to install the whole interoperability code on a station to be operational. Some details may be further elaborated within individual scripts. Additionally, the README files specify the different libraries used and required on the stations to ensure proper functionality. Here is an exemple of order you can follow to install all the interoperability code: [code](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/code), [INDIcode](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/INDIcode), [AutoRun](https://github.com/INDICATIC-AIP/FID074-Estaciones/tree/main/AutoRun) , but before you must assure to have linux installed on the Jetson, to do so, you can refer to the [Initial Setup Guide for Jetson Orin Nano Developer Kit.](https://www.jetson-ai-lab.com/initial_setup_jon.html), Once this GitHub repository has been cloned into the station, you must extract the folders `code`, `INDIcode`, and `AuToRun` and place them on the `Desktop`, once this is done, you can delete the folder `NAScode`, as it is intended for the NAS side, after that, you can remove the cloned folder, which should be named `FID074-Estaciones`, you are now ready to begin the installation properly.

Once the installation is completed, to change the path of each file so the code can work on the station, open the script. `station_rename.py` that should be located on the `Desktop`, the three lines are commented `# new_content = re.sub("indicatic-e1", "indicatice2", content)` `# with open(filename, 'w', encoding='utf-8') as f:` `#     f.write(new_content)`, uncomment them and change `indicatice2` by the same of the station, and then execute the code with the command :

```bash
python3 station_rename.py
```
If you want to know what is the name of the station use the command :

```bash
whoami
```

If you have any questions after reading the README files or need clarification on how the code functions, feel free to reach out alexandre.olivie@bordeaux-inp.fr or jose.jaenj08@hotmail.com
