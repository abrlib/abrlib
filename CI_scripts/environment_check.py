import os
from utils import ContinuousIntegrationException
from utils import check_present

def environment_check():
    if os.getenv('ABRUSLIB_ROOT') == None:
        raise ContinuousIntegrationException("Environment is not setup. Run source ./env.sh in abruslib directory")

if __name__ == "__main__":

    print("Check if environment is setup")
    check_present("Environment check", environment_check)
    print("")
    print("=============================")
    print("")
