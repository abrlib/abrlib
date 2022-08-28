#!/usr/bin/env python
from ctypes import *

# _abn_unit must be the same type like abn_unit in abn/include/abn.h file one
_abrusunit_t = c_uint32

class _abrus_t(Structure):
    _fields_ = [
        ("chain", POINTER(_abrusunit_t)),
        ("bitsize", _abrusunit_t),
        ("is_selfmanaged_chain", c_bool)
    ]

# pointers for main types that are present in the API
_abrus_t_p = POINTER(_abrus_t)
_abrusunit_t_p = POINTER(_abrusunit_t)

class Abruslib():
    """This class wraps abruslib library"""

    def __init__(self, shared_object_path):

        # load library
        self.lib = CDLL(shared_object_path)

        # define types used in the API
        self.abrus_t = _abrus_t
        self.abrus_t_p = _abrus_t_p
        self.abrusunit_t = _abrusunit_t
        self.abrusunit_t_p = _abrusunit_t_p

        # define API's functions

        self.lib.abrus_alloc.argtypes = [_abrusunit_t]
        self.lib.abrus_alloc.restype = _abrus_t

        self.lib.abrus_free.argtypes = [_abrus_t_p]
        self.lib.abrus_free.restype = None

        self.lib.abrus_create.argtypes = [_abrusunit_t, _abrusunit_t]
        self.lib.abrus_create.restype = _abrus_t

        self.lib.abrus_create_empty.argtypes = None
        self.lib.abrus_create_empty.restype = _abrus_t

    def alloc(self, *params):
        return self.lib.abrus_alloc(*params)

    def free(self, *params):
        return self.lib.abrus_free(*params)
    
    def create(self, *params):
        return self.lib.abrus_create(*params)

    def create_empty(self, *params):
        return self.lib.abrus_create_empty(*params)
