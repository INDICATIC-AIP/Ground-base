from secretsharing import SecretSharer
import json

#This code refund the hashes of info and payload, send them in a file so they can be traited in the bash code fileTreatment

checksumPayload = ""
checksumInfo = ""

#Sharmirs parts file
path = "/var/services/homes/INDICATIC/InteroperabilityCode/ShamirsParts.txt"
#file that's contains the two obtained hash
HashFile = "/var/services/homes/INDICATIC/InteroperabilityCode/Hash.txt"
content = open(path, "r").read()

#Assimilate each line to a variable
with open(path, "r") as fichier:
    checksumPayload = fichier.readline().strip()
    checksumInfo = fichier.readline().strip()

print("Checksum Payload:\n", checksumPayload)
print("\nChecksum Info:\n", checksumInfo)

#Make them a list to be understandable for SecretSharer
PayloadList = json.loads(checksumPayload)
PayloadInfo = json.loads(checksumInfo)

print("\npayload info :\n", PayloadInfo)

#Get the hash
recovered_secret_payload = SecretSharer.recover_secret(PayloadList[:2])

#Add 0 at the beginning of the text if missing
while len(recovered_secret_payload) < 64:
    recovered_secret_payload = "0" + recovered_secret_payload

print("Payload Hash python :", recovered_secret_payload)
print("len of payload hash python :", len(recovered_secret_payload))

recovered_secret_info = SecretSharer.recover_secret(PayloadInfo[:2])

#Add 0 at the beginning of the text if missing
while len(recovered_secret_info) < 64:
    recovered_secret_info = "0" + recovered_secret_info

print(type(recovered_secret_info))
print("Info Hash python :", recovered_secret_info)
print("len of info hash python :", len(recovered_secret_info))

#Put the Hash obtained into a file to compare them in sh code with the one received in the files Checksum
with open(HashFile, "w") as hash:
    hash.write(recovered_secret_payload + "\n")
    hash.write(recovered_secret_info + "\n")
