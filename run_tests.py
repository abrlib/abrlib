#!/usr/bin/env python3
import subprocess
import sys

verbose = True

def run_cmd(cmd):
    if verbose == True:
        return subprocess.run(cmd ,shell=True).returncode
    else:
        return subprocess.run(cmd, stdout=subprocess.DEVNULL, shell=True).returncode

def main():

    ret = 0

    # build abrlib
    run_cmd("rm -rf build ; mkdir build")
    ret = run_cmd("cd build && cmake .. && make")
    if ret != 0:
        print("Building abrlib failed")
        return ret

    # setup example
    ret = run_cmd("cd example && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping abrlib example failed")
        return ret

    # build example
    run_cmd("cd example && rm -rf build ; mkdir build")
    ret = run_cmd("cd example/build && cmake .. && make")
    if ret != 0:
        print("Building abrlib example failed")
        return ret

    # run example
    ret = run_cmd("cd example/build && ./example")
    if ret != 0:
        print("Running example failed")
        return ret

    # run python3 wrapper
    ret = run_cmd("cd wrappers/python3 && ./example.py")
    if ret != 0:
        print("Running example failed")
        return ret

    # setup unit tests
    ret = run_cmd("cd tests/unit && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping unit tests failed")
        return ret

    # build unit tests
    run_cmd("cd tests/unit && rm -rf build ; mkdir build")
    ret = run_cmd("cd tests/unit/build && cmake .. && make")
    if ret != 0:
        print("Building unit tests failed")
        return ret

    # run unit tests
    ret = run_cmd("cd tests/unit/build && ./unittests")
    if ret != 0:
        print("Running unit tests failed")
        return ret

    return ret

if __name__ == '__main__':
    retcode = main()
    if retcode == 0:
        print("Success")
    else:
        print("Error: Something went wrong")
    sys.exit(retcode)