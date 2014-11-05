obj = libpower.o resistancecalc.o
curr_dir = $(shell pwd)

.PHONY: all
all: lib 
	cc -I"$(curr_dir)"/include -L"$(curr_dir)"/lib $(obj) -std=c99 -o electrotest electrotest.c -lm #compile with local libraries

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
	sudo cp lib/libpower.so /usr/lib
	sudo cp lib/libresistance.so /usr/lib	
	sudo chmod 755 /usr/lib/libpower.so
	sudo chmod 755 /usr/lib/libresistance.so	
	sudo ldconfig
	cc  -std=c99 -o electrotest electrotest.c -lpower -lresistance -lm #recompile
	sudo cp electrotest /usr/bin

.PHONY: uninstall
uninstall:
	sudo rm /usr/bin/electrotest
	sudo rm /usr/lib/libpower.so
	sudo rm /usr/lib/libresistance.so
	sudo ldconfig # not sure if this line is required

.PHONY: clean
clean: 
	sudo rm -r electrotest $(obj) lib 
