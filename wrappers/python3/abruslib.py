#!/usr/bin/env python3
from ctypes import *

# _abn_unit must be the same type like abn_unit in abn/include/abn.h file one
_abrunit_t = c_uint32

class _abr_t(Structure):
    _fields_ = [
        ("chain", POINTER(_abrunit_t)),
        ("bitsize", _abrunit_t),
        ("is_selfmanaged_chain", c_bool)
    ]

# pointers for main types that are present in the API
_abr_t_p = POINTER(_abr_t)
_abrunit_t_p = POINTER(_abrunit_t)

class Abrlib():
    """This class wraps abrlib library"""

    def __init__(self, shared_object_path):

        # load library
        self.lib = CDLL(shared_object_path)

        # define types used in the API
        self.abr_t = _abr_t
        self.abr_t_p = _abr_t_p
        self.abrunit_t = _abrunit_t
        self.abrunit_t_p = _abrunit_t_p

        # define API's functions

        self.lib.abr_alloc.argtypes = [_abrunit_t]
        self.lib.abr_alloc.restype = _abr_t

        self.lib.abr_free.argtypes = [_abr_t_p]
        self.lib.abr_free.restype = None

        self.lib.abr_create.argtypes = [_abrunit_t, _abrunit_t]
        self.lib.abr_create.restype = _abr_t

        self.lib.abr_create_empty.argtypes = None
        self.lib.abr_create_empty.restype = _abr_t

    def alloc(self, *params):
        return self.lib.abr_alloc(*params)

    def free(self, *params):
        return self.lib.abr_free(*params)
    
    def create(self, *params):
        return self.lib.abr_create(*params)

    def create_empty(self, *params):
        return self.lib.abr_create_empty(*params)
