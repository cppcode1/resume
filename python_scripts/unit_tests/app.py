# copyright 2021 Oleksandr Chastukhin

def is_string(data):
    return isinstance(data, str)

def raise_exception():
    raise Exception("expected error")
    pass # Failed: DID NOT RAISE <class 'Exception'>