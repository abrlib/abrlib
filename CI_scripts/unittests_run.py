import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def unittests_run():
    # setup
    ret = run_cmd("cd tests/unit && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        raise ContinuousIntegrationException("Setuping unit tests failed")

    # build
    run_cmd("cd tests/unit && rm -rf build ; mkdir build")
    ret = run_cmd("cd tests/unit/build && cmake .. && make")
    if ret != 0:
        raise ContinuousIntegrationException("Building unit tests failed")

    # run
    ret = run_cmd("cd tests/unit/build && ./unittests")
    if ret != 0:
        raise ContinuousIntegrationException("Running unit tests failed")

if __name__ == "__main__":
    print("Check if all unittests pass")
    check_present("Unittests check", unittests_run)
    print("")
    print("===========================")
    print("")
