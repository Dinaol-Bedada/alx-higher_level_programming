#!/usr/bin/python3
class LockedClass:
    __slots__ = ['first_name']
    
    def __setattr__(self, key, value):
        if key != 'first_name' or not hasattr(self, 'first_name'):
            raise AttributeError(f"'{self.__class__.__name__}' object has no attribute '{key}'")
        super().__setattr__(key, value)
