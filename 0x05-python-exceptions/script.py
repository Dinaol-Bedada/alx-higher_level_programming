#!/usr/bin/python3

import ctypes

# Load the shared library
lib = ctypes.CDLL('./libPython.so')

# Define function prototypes
print_python_list = lib.print_python_list
print_python_list.argtypes = [ctypes.py_object]
print_python_bytes = lib.print_python_bytes
print_python_bytes.argtypes = [ctypes.py_object]
print_python_float = lib.print_python_float
print_python_float.argtypes = [ctypes.py_object]

# Test the functions
lst = [1, 2, 3]
print_python_list(lst)

b = b'hello world'
print_python_bytes(b)

f = 3.14
print_python_float(f)
