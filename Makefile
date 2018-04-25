CFLAGS = -Wall $(shell python3-config --cflags)
LDFLAGS = $(shell python3-config --ldflags)

.PHONY = clean rpm build

lala: wmctrlmodule.c setup.py
	python3 setup.py build

wmctrl.so: wmctrlmodule.c
	gcc -Wall $(CFLAGS) $(LDFLAGS) wmctrlmodule.c -o wmctrl.so

rpm: setup.py wmctrlmodule.c
	python3 setup.py bdist_rpm

clean:
	python3 setup.py clean
