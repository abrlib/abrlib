import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def cppcheck_check():
    ret = run_cmd("cd tools/cppcheck && ./cppcheck-it")
    if ret != 0:
        raise ContinuousIntegrationException("Cppcheck check failed")
    

if __name__ == "__main__":
    print("Static code anlysis (cppcheck)")
    check_present("Library check", cppcheck_check)
    print("")
    print("=============================")
    print("")
