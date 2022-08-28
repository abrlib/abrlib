#!/bin/bash

# create symlink if it's needed
if [ ! -L 3rd_party/abruslib ]; then
    ln -s ../.. 3rd_party/abruslib
fi
