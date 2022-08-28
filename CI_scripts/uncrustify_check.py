import os
from utils import ContinuousIntegrationException
from utils import run_cmd
from utils import check_present

def uncrustify_check():
    ret = run_cmd("cd tools/uncrustify && ./uncrustify-it check")
    if ret != 0:
        raise ContinuousIntegrationException("Uncrustify check failed")

if __name__ == "__main__":
    print("Check if uncrustify reports no issues")
    check_present("Uncrustify check", uncrustify_check)
    print("")
    print("=====================================")
    print("")

















