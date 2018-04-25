.PHONY = clean

wmctrl.so: wmctrlmodule.c
	gcc -Wall -I/usr/include/python3.4m/ -lpython3.4m wmctrlmodule.c -o wmctrl.so

clean:
	rm -f wmctrl.so
