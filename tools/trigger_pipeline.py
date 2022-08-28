#!/usr/bin/env python3

import http.client
import os
import sys
import json

class TriggerPipelineException(Exception):
    pass


def usage():
    return "Usage: trigger_pipeline.py (hash|branch|tag)\n"

def trigger_pipeline(revision="master"):

    token = os.getenv("CIRCLECI_TOKEN")
    if token == None:
        raise TriggerPipelineException("There is no token (CIRCLECI_TOKEN) among environemt variables")

    conn = http.client.HTTPSConnection("circleci.com")
    payload = "{\"branch\" : \"" + revision + "\"}"
    headers = {
        "content-type": "application/json",
        "Circle-Token" : token
    }
    conn.request("POST", "/api/v2/project/gh/abruslib/abruslib/pipeline", payload, headers)
    return conn.getresponse().read().decode("utf-8")

def main(argv):

    if len(argv) != 2:
        print(usage())
        raise TriggerPipelineException("Invalid number of parameters")
    
    if argv[1] == "help":
        print(usage())
        return 0

    print("Trigger pipeline")
    raw_res = trigger_pipeline(argv[1])
    try:
        res = json.loads(raw_res)
        number = res.get('number')
        if number == None:
            raise TriggerPipelineException("There is no required field 'number'")
    except:
        print(raw_res)
        raise TriggerPipelineException("Invalid communication")
    
    print("number \t: #{}".format(number))
    print("id \t: {}".format(res.get('id')))
    print("url \t: https://app.circleci.com/pipelines/github/abruslib/abruslib/{}".format(number))

    return 0

if __name__ == "__main__":
    try:
        ret = main(sys.argv)
        sys.exit(ret)
    except TriggerPipelineException as ex:
        print(ex)
        sys.exit(1)
