CFLAGS = -Wall $(shell python3-config --cflags)
LDFLAGS = $(shell python3-config --ldflags)
PYTHON = $(shell which python3)

SRCDIR = wmctrl
SOURCES = $(SRCDIR)/wmctrlmodule.c

.PHONY: clean rpm build test

lala: $(SOURCES) setup.py
	python3 setup.py build

wmctrl.so: wmctrlmodule.c
	gcc -Wall $(CFLAGS) $(LDFLAGS) wmctrlmodule.c -o wmctrl.so

rpm: setup.py wmctrlmodule.c
	python3 setup.py bdist_rpm

clean:
	python3 setup.py clean
	rm -rf build/ dist/

test:
	(cd test; $(PYTHON) -m pytest .)
