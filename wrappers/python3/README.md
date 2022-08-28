# Python3 abruslib wrapper
You can use this wrapper to call functions from abruslib shared library.
If you don't know how use it, please read this notes or take a look at the example.

## How to use abruslib.py
1) Build shared library (libabruslib-shared.so) and know it's location
2) Copy abruslib.py to your codebase (or install abr)
3) Import abruslib in your source file:
> git from abruslib import abruslib  
  
4) Create abruslib object passing the path to the abruslib shared object file:
> abruslib = Abruslib('abruslib/build/libabruslib-shared.so')  

5) Use abr object to perform whatever you want
> key = abruslib.create(4096)  
> ...

## In case of any problem please let me know:
:mailbox: dhmaciek@gmail.com




