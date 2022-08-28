#!/bin/bash

# update submodules
git submodule init
git submodule update

# create symlink if it's needed
if [ ! -L 3rd_party/abruslib ]; then
    ln -s ../../.. 3rd_party/abruslib
fi
