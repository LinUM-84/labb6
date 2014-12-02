obj = libpower.o resistancecalc.o libcomponent.o
curr_dir = $(shell pwd)

#-std=c99

.PHONY: all
all: lib
	cc electrotest.c -o electrotest  -Llib -I. -lpower -lresistance  -lcomponent -lm    #compile with local libraries

#objects
libpower.o: libpower.h
	cc -c libpower.c -o libpower.o -fPIC -lm 
	cc -shared -o libpower.so libpower.o

resistancecalc.o: resistancecalc.h
	cc -c -fPIC resistancecalc.c -lm
	cc -shared -o libresistance.so resistancecalc.o

libcomponent.o: libcomponent.h
	cc -c -fPIC component.c -o libcomponent.o -lm
	cc -shared -o libcomponent.so libcomponent.o

.PHONY: lib
lib: $(obj)
	mkdir lib
	sudo mv -f  *.so lib

.PHONY: install
install: 
	sudo cp lib/libpower.so /usr/lib
	sudo cp lib/libresistance.so /usr/lib	
	sudo chmod 755 /usr/lib/libpower.so
	sudo chmod 755 /usr/lib/libresistance.so	
	sudo ldconfig
	cc electrotest.c -o electrotest  -L/usr/lib -I. -lpower -lresistance  -lcomponent -lm 
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
