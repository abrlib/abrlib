# ABR

ABR - Adjustable Bit Registers. This library allows simple mathematical operations like addition, multiplication, bit operations on big natural numbers. It's not a standard implementation of big number - numbers are not expansible, which mins that you have to define size first (eg. 256, 4096 or 4294967296 bit). This size cannot be changed in runtime.

[![CircleCI](https://dl.circleci.com/status-badge/img/gh/abrlib/abrlib/tree/master.svg?style=svg)](https://dl.circleci.com/status-badge/redirect/gh/abrlib/abrlib/tree/master)  
[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.cprogramming.com/)
[![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/) 
[![Docker](https://img.shields.io/badge/Docker-2CA5E0?style=for-the-badge&logo=docker&logoColor=white)](https://hub.docker.com/r/mksth/abrlib-image)


## How to use?

### Get abr library:
> git clone https://github.com/mgorzkowski/abr.git  
> cd ./abr   

### Prepare environment variables:
> source ./env.sh

### Use ready to use container with prepared software (optional):
> dockerize-it launch  
> dockerize-it shell  
> source ./env.sh

### Building library:
> mkdir -p build & cd build  
> cmake .. -GNinja  
> ninja

Now, in 'build' directory you can find both libraries:
- libabr-static.a
- libabr-shared.so

You can use different dictionary but please use 'build' directory because this name is required by test runner.

## Example project:
In the 'example' directory there is a 'sample' example of ABR usage. This is a series of some operations.  
To build and run example project type:
> cd examples/sample  
> setup.sh  
> mkdir -p build && cd build  
> cmake .. -GNinja  
> ninja  

## How to adjust abr library to your project:
The ABR library works on abr units, which are the basic type the calculations are porformed on.
The abrunit_t has ABR_UNIT_BITSIZE size (8, 16, 32, 64, 128 or 256). By default it is set to 32.
To change it modify the ABR_UNIT_BITSIZE definition.

The bigger size gives the shortest execution time.


## If you have noticed something what can be improved, please let me know.  
:mailbox: dhmaciek@gmail.com
