import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def wrappers_check():

    # python2
    ret = run_cmd("cd wrappers/python2 && ./example.py")
    if ret != 0:
        raise ContinuousIntegrationException("Running example failed")

    # python3
    ret = run_cmd("cd wrappers/python3 && ./example.py")
    if ret != 0:
        raise ContinuousIntegrationException("Running example failed")


if __name__ == "__main__":
    print("Check wrappers works")
    check_present("Wrappers check", wrappers_check)
    print("")
    print("====================")
    print("")
