copyright 2021 Oleksandr Chastukhin
unit tests in python

# first you would need to install 'pytest' command
pip3 install pytest

# create a directory for unit tests
mkdir unit_tests

# then, create add code that you want to test
touch app.py

# next, create a unit test file for this code as follows
touch test_app.py
or
touch app_test.py

# open the unit tests file and import the code you want to test
import app

# to add a new test, create a function that starts with 'test_'
def test_name():
    pass

# and in the next step, run unit tests
pytest -v

# pytest arguments
-v  - to show more info
-k <name>  - to run test from the group 'test_<name>'
--help  - for help

# unit tests features
breakpoint() # to go to the debugger pdb after an exception occured
assert 2 == 2
@pytest.fixture