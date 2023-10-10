import os
import socket
#from Crypto.Cipher import AES
import sys
print(sys)

def main():
    key = b'\x00' * 16  # 16-byte AES key
    file_name = './send_flag'

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('127.0.0.1', 1234)  # Change the port as needed
    sock.connect(server_address)

    while True:
        buff = sock.recv(128).decode()
        if buff[0] == 'S':
            break
        elif buff[0] == 'P':
            key = buff[1:17].encode()  # Assuming the key is sent as a string
            print(f"KEY: {key}")
            # aes_cipher = AES.new(key, AES.MODE_ECB)
        elif buff[0] == 'F':
            file_name = buff[1:129].strip('\x00')
            print(f"FILE: {file_name}")

    with open(file_name, "rb") as file_stream:
        block = file_stream.read(16)
        while block:
            if not key:
                sock.send(block)
            else:
                block = xor_blocks(block)
                # cypher = aes_cipher.encrypt(block)
                # sock.send(cypher)
            block = file_stream.read(16)

    sock.close()

def xor_blocks(block):
    previous = 0
    result = bytearray()
    for byte in block:
        result.append(byte ^ previous)
        previous = byte
    return bytes(result)

if __name__ == "__main__":
    print(sys.path)
