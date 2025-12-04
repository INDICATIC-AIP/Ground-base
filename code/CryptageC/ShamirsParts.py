from secretsharing import SecretSharer
import hashlib

#Generate the shamirs parts for the encryption

#Declaration of the variables
checksumPayload = ""
checksumInfo = ""

path = "/home/indicatic-e1/Desktop/code/infoIMG/StringCrypt.txt"

try:
    #Open file to read it
    with open(path, "r") as file:
        print("File opened")

        buffer = file.read().strip()
        print(buffer)

        #Find the space to separate the two parts
        space_index = buffer.find(" ")
        if space_index != -1:
            checksumPayload = buffer[:space_index]  #First part before space
            checksumInfo = buffer[space_index + 1:]  #Second par, after the space

        #Check length
        if len(checksumPayload) != 64 or len(checksumInfo) != 64:
            raise ValueError("Hashes must have exactly 64 on length")

        print(f"Checksum Payload: {checksumPayload}")
        print(f"Checksum Info: {checksumInfo}")

except FileNotFoundError:
    print("Cannot open the file")
    exit()
except ValueError as e:
    print(e)
    exit()

#Generate conform parts
def generate_valid_parts(secret, threshold, total):
    while True:
        parts = SecretSharer.split_secret(secret, threshold, total)
        #Check of the parts length
        lengths = [len(part.split("-")[1]) for part in parts]
        if all(length == 64 for length in lengths):
            return parts
        else:
            print("Generation of a new part because not equal to 64...")

sharesPayload = generate_valid_parts(checksumPayload, 2, 8)
print("Generated parts (Payload) :", sharesPayload)

#Save payload parts in /shamirPartsPayload.txt
with open("/home/indicatic-e1/Desktop/code/CryptageC/shamirPartsPayload.txt", "w") as Payloadfile:
    for part in sharesPayload:
        hex_part = part.split("-")[1]
        Payloadfile.write(hex_part + "\n")

sharesInfo = generate_valid_parts(checksumInfo, 2, 8)
print("Generated parts (Info) :", sharesInfo)

#Save info parts in /shamirPartsInfo.txt
with open("/home/indicatic-e1/Desktop/code/CryptageC/shamirPartsInfo.txt", "w") as Infofile:
    for part in sharesInfo:
        hex_part = part.split("-")[1]
        Infofile.write(hex_part + "\n")
