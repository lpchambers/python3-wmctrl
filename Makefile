CFLAGS = -Wall $(shell python3-config --cflags)
LDFLAGS = $(shell python3-config --ldflags)
PYTHON = $(shell which python3)

SRCDIR = wmctrl
SOURCES = $(SRCDIR)/wmctrlmodule.c

.PHONY: clean rpm build test install

wmctrl.so: $(SOURCES) setup.py
	python3 setup.py build
	cp build/lib.linux-x86_64*/wmctrl.cpython*.so ./wmctrl.so

rpm: setup.py wmctrlmodule.c
	python3 setup.py bdist_rpm

clean:
	python3 setup.py clean
	rm -rf build/ dist/
	rm -f wmctrl.so
	rm MANIFEST

test: wmctrl.so
	$(PYTHON) -m pytest .

install: setup.py $(SOURCES)
	python3 setup.py install
