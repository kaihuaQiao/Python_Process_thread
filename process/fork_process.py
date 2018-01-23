import os

if __name__ == "__main__":
    print ("current process (%s) start ..." %(os.getpid()))
    pid = os.fork()
