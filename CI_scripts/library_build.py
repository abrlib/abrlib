import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def library_build():
    run_cmd("rm -rf build ; mkdir build")
    ret = run_cmd("cd build && cmake .. && make")
    if ret != 0:
        raise ContinuousIntegrationException("Environment is not setup. Run source ./env.sh in abruslib directory")
    

if __name__ == "__main__":
    print("Check if library is buildable")
    check_present("Library check", library_build) 
    print("")
    print("=============================")
    print("")
