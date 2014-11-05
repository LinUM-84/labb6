obj = libpower.o resistancecalc.o
curr_dir = $(shell pwd)
libs = power resistance

.PHONY: all
all: lib 
	cc -I"$(curr_dir)"/include -L"$(curr_dir)"/lib $(obj) -std=c99 -o electrotest electrotest.c -lm

#objects
libpower.o: libpower.h
	cc -c libpower.c -o libpower.o -fPIC -lm 
	cc -shared -o libpower.so libpower.o

resistancecalc.o: resistancecalc.h
	cc -c -fpic resistancecalc.c
	cc -shared -o libresistance.so resistancecalc.o

.PHONY: lib
lib: $(obj)
	mkdir lib
	mv -f  *.so lib

.PHONY: install
install: 
	sudo cp electrotest /usr/bin
	sudo cp lib/libpower.so /usr/lib
	sudo cp lib/libresistance.so /usr/lib	

.PHONY: uninstall
uninstall:
	sudo rm /usr/bin/electrotest
	sudo rm /usr/lib/libpower.so
	sudo rm /usr/lib/libresistance.so

.PHONY: clean
clean: 
	sudo rm -r electrotest $(obj) lib 
