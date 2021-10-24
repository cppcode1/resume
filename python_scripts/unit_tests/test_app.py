# copyright 2021 Oleksandr Chastukhin
import app
import pytest

# here we test the expected behaviour
def test_is_string():
    assert app.is_string("test string") == True

# here we ignore the expected exception
def test_raise_exception():
    with pytest.raises(Exception) as error:
        app.raise_exception()
    # breakpoint()
    assert str(error.value) == 'expected error'

# test something you need to setup and tear down
@pytest.fixture
def configure():
    # create some configuration to test
    return "configuration"

def test_configuration(configure):
    # here you can use the common configuration
    assert configure == 'configuration'