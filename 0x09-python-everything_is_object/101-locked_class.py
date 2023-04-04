#!/usr/bin/python3

class LockedClass:
    __slots__ = ['first_name']

    def __init__(self):
        self.first_name = None
    
    def __setattr__(self, key, value):
        if key != 'first_name':
            raise AttributeError("'LockedClass' object has no attribute '{}'".format(key))
        self.__dict__[key] = value
