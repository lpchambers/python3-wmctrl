import os
from distutils.core import setup, Extension

def read(fname):
    return open(os.path.join(os.path.dirname(__file__), fname)).read()

wmctrl_module = Extension('wmctrl',
                           sources = ['wmctrl/wmctrlmodule.c'])

setup(
    name = 'cwmctrl',
    version = '0.0.1',
    author = "Lewis Chambers",
    url = "https://github.com/lpchambers/python3-wmctrl",
    description = "Bindings for wmctrl",
    license = "GPLv2",
    keywords = "wmctrl window manager X control",
    long_description = read("README"),
    ext_modules = [wmctrl_module],
    classifiers = [
        "Development Status :: 1 - Planning",
        "Environment :: Console",
        "Environment :: X11 Applications",
        "License :: OSI Approved :: GNU General Public License v2 (GPLv2)",
        "Operating System :: POSIX :: Linux",
        "Topic :: Desktop Environment :: Window Managers",
    ],
)
