# Python3 abrlib wrapper
You can use this wrapper to call functions from abrlib shared library.
If you don't know how use it, please read this notes or take a look at the example.

## How to use abrlib.py
1) Build shared library (libabrlib-shared.so) and know it's location
2) Copy abrlib.py to your codebase (or install abr)
3) Import abrlib in your source file:
> git from abrlib import Abrlib  
  
4) Create Abrlib object passing the path to the abrlib shared object file:
> abrlib = Abrlib('abrlib/build/libabrlib-shared.so')  

5) Use abr object to perform whatever you want
> key = abrlib.create(4096)  
> ...

## In case of any problem please let me know:
:mailbox: dhmaciek@gmail.com




