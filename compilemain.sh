#compile the class
g++ -c src/Inc.cpp -I. `root-config --glibs --cflags` -lGenVector -o obj/Inc.o
#compile the macro
g++ macros/Skelet.cpp -I. obj/Inc.o `root-config --glibs --cflags` -o bin/Skelet
