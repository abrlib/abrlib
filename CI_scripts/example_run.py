import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def example_run():
    # setup
    ret = run_cmd("cd example && chmod +x ./setup.sh && ./setup.sh")
    if ret != 0:
        raise ContinuousIntegrationException("Setuping abruslib example failed")

    # build
    run_cmd("cd example && rm -rf build ; mkdir build")
    ret = run_cmd("cd example/build && cmake .. && make")
    if ret != 0:
        raise ContinuousIntegrationException("Building abruslib example failed")

    # run
    ret = run_cmd("cd example/build && ./example")
    if ret != 0:
        raise ContinuousIntegrationException("Running example failed")

if __name__ == "__main__":
    print("Check if example run example")
    check_present("Example check", example_run)
    print("")
    print("============================")
    print("")
