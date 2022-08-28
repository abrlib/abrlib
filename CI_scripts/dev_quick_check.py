import os
import sys
from utils import ContinuousIntegrationException, run_cmd, check_present

# Check set
from environment_check import environment_check
from library_build import library_build
from example_run import example_run
from unittests_run import unittests_run
from wrappers_check import wrappers_check
from uncrustify_check import uncrustify_check


if __name__ == "__main__":
    check_dict = {
        "Environment check\t" : environment_check,
        "Library check    \t" : library_build,
        "Example check    \t" : example_run,
        "Unittests check  \t" : unittests_run,
        "Wrappers check   \t" : wrappers_check,
        "Uncrustify check \t" : uncrustify_check
    }

    print("==============================")
    print("          Check all           ")
    print("==============================")
    status = "PASS"
    for name, check in check_dict.items():
        if not check_present(name, check, verbose=False):
            status = "FAIL"
    print("==============================")
    print(f"SUMMARY:        \t: {status}")
    print("==============================")
    print("")

    if status == "PASS":
        sys.exit(0)
    else:
        sys.exit(1)
