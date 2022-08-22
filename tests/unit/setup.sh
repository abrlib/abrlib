#!/bin/bash

# create symlink if it's needed
if [ ! -L 3rd_party/abrlib ]; then
    ln -s ../../.. 3rd_party/abrlib
fi
