# Abruslib

Abrus - Adjustable Bit Registers Upon the System.  
This library allows essential operations on big natural numbers.  
It's a custom implementation of big number idea:
Once created register cannot be automatically extended, so please create as wide register as you need at first.
This will reward you with faster operations.

[![CircleCI](https://dl.circleci.com/status-badge/img/gh/abruslib/abruslib/tree/master.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/abruslib/abruslib/tree/master)  
[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.cprogramming.com/)
[![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/) 
[![Docker](https://img.shields.io/badge/Docker-2CA5E0?style=for-the-badge&logo=docker&logoColor=white)](https://hub.docker.com/r/abruslib/abruslib-image)


## How to use?

### Get abr library:
> git clone https://github.com/abruslib/abruslib.git  
> cd ./abruslib  

### Prepare environment variables:
> source ./env.sh  

### Use ready to use container with prepared software (optional):
> dockerize-it complex

### Building library:
> mkdir -p build & cd build  
> cmake .. -GNinja  
> ninja

Now, in 'build' directory you can find both libraries:
- libabruslib.a
- libabruslib-shared.so

You can use different dictionary but please use 'build' directory because this name is required by test runner.

## Example project:
In the 'example' directory there is a 'sample' example of abruslib usage.
To build and run example project type:
> cd example  
> setup.sh  
> mkdir -p build && cd build  
> cmake .. -GNinja  
> ninja  

## How to adjust abr library to your project:
The abruslib library works on abr units, which are the basic type the calculations are performed on.
The abrusunit_t has ABRUS_UNIT_BITSIZE size (8, 16, 32, 64, 128 or 256). By default it is set to 32.
To change it modify the ABRUS_UNIT_BITSIZE definition.

The bigger size gives the shortest execution time.


## If you have noticed something what can be improved, please let me know.  
:mailbox: abruslib@gmail.com
