#This code add the Fits header to the raw image, deletethe raw file and send the fits file to the QHYCCD directory to be sent to the NAS.
#This is always the most older file that is sent if there is files.
#The code check if there is raw file each 5 seconds

import os
import time
from astropy.io import fits
import numpy as np
import shutil

directory = "/home/indicatic-e1/Desktop/code/RawQHYImg"#Path where the rax files captured by QHYCCD are putted 
QHYCCD_directory = "/home/indicatic-e1/Desktop/ASTRODEVICES/QHYCCDFILE"#Path of QHYCCD image to be sent to the NAS

width, height = 5120, 3696
dtype = np.uint16  #16 bits pixels

while True: 
    oldest_file = None
    oldest_time = float('inf')

    for filename in os.listdir(directory):
        if filename.endswith(".raw"): 
            filepath = os.path.join(directory, filename)
            file_time = os.path.getmtime(filepath)

            if file_time < oldest_time:
                oldest_time = file_time
                oldest_file = filepath

    if oldest_file:
        try:
            raw_file = oldest_file
            fits_file = os.path.join(directory, os.path.splitext(os.path.basename(raw_file.replace("image", "").replace(" ", "_")))[0] + ".fits")

            data = np.fromfile(raw_file, dtype=dtype).reshape((height, width))

            #FITS HEADER
            hdu = fits.PrimaryHDU(data)
            hdu.header['BITPIX'] = 16
            hdu.header['NAXIS'] = 2
            hdu.header['NAXIS1'] = width
            hdu.header['NAXIS2'] = height
            hdu.writeto(fits_file, overwrite=True)

            new_fits_path = os.path.join(QHYCCD_directory, os.path.basename(fits_file))
            shutil.move(fits_file, new_fits_path)
            print(f"Déplacé : {fits_file} vers {new_fits_path}")

            os.remove(raw_file)
            print(f"Supprimé : {raw_file}")
        except Exception as e:
            print(f"Error for the file treatment {raw_file}: {e}")
    else:
        print("")

    time.sleep(5)
