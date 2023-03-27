#!/usr/bin/python3

def raise_exception():
    """Raises a type exception"""
    try:
        raise TypeError("Type Error")
    except TypeError as e:
        print(e)
