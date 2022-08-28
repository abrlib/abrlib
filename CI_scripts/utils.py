import subprocess
import sys
import os
import io

def run_cmd(cmd):
    print(f"run cmd: [{cmd}]")
    return subprocess.run(cmd, stdout=sys.stdout, stderr=sys.stdout, shell=True).returncode

def call_check(check, verbose = True):
    exception = None
    if verbose == False:
        stdout_save = sys.stdout
        sys.stdout = open(os.devnull, 'w')
    try:
        check()
    except Exception as ex:
        exception = ex
    finally:
        if verbose == False:
            sys.stdout = stdout_save
        if exception != None:
            raise exception

def check_present(name, check, verbose=True):
    try:
        if verbose:
            print("--------------------")
            call_check(check)
            print("--------------------")
        else:
            call_check(check, verbose)
        print(f"{name}: PASS")
        return True
    except Exception:
        if verbose:
            print("--------------------")
        print(f"{name}: FAIL")
        return False

class ContinuousIntegrationException(Exception):
    pass
