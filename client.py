import socket
import struct


HOST = '127.0.0.1'
PORT = 12345
RECV_BUFFER_SIZE = 1024
TIME_TO_WAIT = 3.0


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        s = "not connected"
        client_socket.connect((HOST, PORT))
        command_to_send = input("press command to send:")
        length_to_send = len(command_to_send)
        client_socket.sendall(struct.pack('<I', length_to_send))
        client_socket.sendall(command_to_send.encode())
        try:
            length = client_socket.recv(RECV_BUFFER_SIZE).decode()
            client_socket.settimeout(TIME_TO_WAIT)
            s = client_socket.recv(RECV_BUFFER_SIZE).decode()
        except socket.timeout:
            pass
        except TypeError:
            pass
        if not s:
            print("not connected")
        else:
            print(s)
        return 0

if __name__ == '__main__':
    main()