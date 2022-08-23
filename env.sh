#!/bin/bash

export ABR_ROOT=$(pwd)
export PATH=$PATH:$ABR_ROOT

git submodule init
git submodule update