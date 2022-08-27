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

    print("=====================================================================\n\n")
    print("Check if environment is setup")
    print("-----------------------------")
    if os.getenv('ABR_ROOT') == None:
        print("Environment is not setup. Run source ./env.sh in abrlib directory")
        return 1

    print("=====================================================================\n\n")
    print("Build abrlib")
    print("------------")
    run_cmd("rm -rf build ; mkdir build")
    ret = run_cmd("cd build && cmake .. && make")
    if ret != 0:
        print("Building abrlib failed")
        return ret

    print("=====================================================================\n\n")
    print("Setup example")
    print("-------------")
    ret = run_cmd("cd example && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping abrlib example failed")
        return ret

    print("=====================================================================\n\n")
    print("Build example")
    print("-------------")
    run_cmd("cd example && rm -rf build ; mkdir build")
    ret = run_cmd("cd example/build && cmake .. && make")
    if ret != 0:
        print("Building abrlib example failed")
        return ret

    print("=====================================================================\n\n")
    print("Run example")
    print("-----------")
    ret = run_cmd("cd example/build && ./example")
    if ret != 0:
        print("Running example failed")
        return ret

    print("=====================================================================\n\n")
    print("Run python2 wrapper")
    print("-------------------")
    ret = run_cmd("cd wrappers/python2 && ./example.py")
    if ret != 0:
        print("Running example failed")
        return ret

    print("=====================================================================\n\n")
    print("Run python3 wrapper")
    print("-------------------")
    ret = run_cmd("cd wrappers/python3 && ./example.py")
    if ret != 0:
        print("Running example failed")
        return ret

    print("=====================================================================\n\n")
    print("Setup unit tests")
    print("----------------")
    ret = run_cmd("cd tests/unit && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        print("Setuping unit tests failed")
        return ret

    print("=====================================================================\n\n")
    print("Build unit tests")
    print("----------------")
    run_cmd("cd tests/unit && rm -rf build ; mkdir build")
    ret = run_cmd("cd tests/unit/build && cmake .. && make")
    if ret != 0:
        print("Building unit tests failed")
        return ret

    print("=====================================================================\n\n")
    print("Run unit tests")
    print("--------------")
    ret = run_cmd("cd tests/unit/build && ./unittests")
    if ret != 0:
        print("Running unit tests failed")
        return ret

    print("=====================================================================\n\n")
    print("Run uncrustify")
    print("--------------")
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
    