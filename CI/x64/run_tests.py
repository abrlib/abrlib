#!/usr/bin/env python3
import subprocess
import sys
import os

verbose = True

def run_cmd(cmd):
    print(f"run cmd: [{cmd}]")
    if verbose == True:
        return subprocess.run(cmd ,shell=True).returncode
    else:
        return subprocess.run(cmd, stdout=subprocess.DEVNULL, shell=True).returncode

def main():

    ret = 0

    # Check if environment is setup
    print("=====================================================================\n\n")
    if os.getenv('ABR_ROOT') == None:
        print("Environment is not setup. Run source ./env.sh in abrlib directory")
        return 1

    # build abrlib
    print("=====================================================================\n\n")
    run_cmd("rm -rf build ; mkdir build")
    ret = run_cmd("cd build && cmake .. && make")
    if ret != 0:
        print("Building abrlib failed")
        return ret

    # setup example
    print("=====================================================================\n\n")
    ret = run_cmd("cd example && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping abrlib example failed")
        return ret

    # build example
    print("=====================================================================\n\n")
    run_cmd("cd example && rm -rf build ; mkdir build")
    ret = run_cmd("cd example/build && cmake .. && make")
    if ret != 0:
        print("Building abrlib example failed")
        return ret

    # run example
    print("=====================================================================\n\n")
    ret = run_cmd("cd example/build && ./example")
    if ret != 0:
        print("Running example failed")
        return ret

    # run python3 wrapper
    print("=====================================================================\n\n")
    ret = run_cmd("cd wrappers/python3 && ./example.py")
    if ret != 0:
        print("Running example failed")
        return ret

    # setup unit tests
    print("=====================================================================\n\n")
    ret = run_cmd("cd tests/unit && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping unit tests failed")
        return ret

    # build unit tests
    print("=====================================================================\n\n")
    run_cmd("cd tests/unit && rm -rf build ; mkdir build")
    ret = run_cmd("cd tests/unit/build && cmake .. && make")
    if ret != 0:
        print("Building unit tests failed")
        return ret

    # run unit tests
    print("=====================================================================\n\n")
    ret = run_cmd("cd tests/unit/build && ./unittests")
    if ret != 0:
        print("Running unit tests failed")
        return ret

    # run uncrustify
    print("=====================================================================\n\n")
    ret = run_cmd("cd tools/uncrustify && ./uncrustify-it check")
    if ret != 0:
        print("Uncrustify check failed")
        return ret

    return ret

if __name__ == '__main__':
    retcode = main()
    print("=====================================================================\n")
    print("")
    if retcode == 0:
        print(" CI result:")
        print("")
        print("        /---------\\")
        print("        | Success |")
        print("        \\---------/")
        print("")

    else:
        print(" CI result:")
        print("")
        print("        /--------\\")
        print("        |  FAIL  |")
        print("        \\--------/")
        print("")
    
    print("")
    print("=====================================================================\n")
    sys.exit(retcode)
    