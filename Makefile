CC = gcc
Cflags = -Wall -g

loops = libclassloops.a
recursives = libclassrec.a
recursived = libclassrec.so
loopd = libclassloops.so

mains = main.o libclassrec.a
maindloop = main.o libclassloops.so
maindrec = main.o libclassrec.so


.Phony: all

all: mains maindloop maindrec loops
	

loops: $(loops)

$(loops): basicClassification.o advancedClassificationLoop.o
	ar rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: $(recursives)

$(recursives): basicClassification.o advancedClassificationRecursion.o
	ar rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: $(recursived)

$(recursived): basicClassification.c advancedClassificationRecursion.c
	$(CC) -c -Wall -Werror -fPIC basicClassification.c advancedClassificationRecursion.c 
	$(CC) -shared -Wall basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

loopd: $(loopd)

$(loopd): basicClassification.c advancedClassificationLoop.c
	$(CC) -c -Wall -Werror -fPIC basicClassification.c advancedClassificationLoop.c
	$(CC) -shared -Wall basicClassification.o advancedClassificationLoop.o -o libclassloops.so

basicClassification.o: basicClassification.c
	$(CC) $(Cflags) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(Cflags) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(Cflags) -c advancedClassificationRecursion.c

mains: $(recursives) main.o
	$(CC) $(Cflags) -static main.o -L. -lclassrec -o mains

maindloop: libclassloops.so main.o
	$(CC) -Wall main.o -L. -lclassloops -o maindloop

maindrec: libclassrec.so main.o
	$(CC) -Wall main.o -L. -lclassrec -o maindrec

main.o: main.c
	$(CC) $(Cflags) main.c -c


clean:
	rm -f *.o *.a *.so mains maindloop maindrec




