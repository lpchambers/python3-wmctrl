from distutils.core import setup, Extension

module1 = Extension('wmctrl',
                    sources = ['wmctrlmodule.c'])

setup (name = 'wmctrl',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
