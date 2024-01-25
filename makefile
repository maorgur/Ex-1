CC=gcc
AR=ar
FLAGS= -Wall -g

OBJECT_MAIN=main.o
OBJECT_LOOP=advancedClassificationLoop.o basicClassifcation.o
OBJECT_RECURSIVE=advancedClassificationRecursion.o basicClassifcation.o
OBJECT_ALL= advancedClassificationRecursion.o basicClassifcation.o main.o

CODE_MAIN=main.c
CODE_LOOP=advancedClassificationLoop.c basicClassifcation.c
CODE_RECURSIVE=advancedClassificationRecursion.c basicClassifcation.c
HEADER=NumClass.h
CODE_ALL= advancedClassificationRecursion.c basicClassifcation.c main.c NumClass.h


all: loops recursives loopd recursived mains maindloop maindrec



#this is so the specified names will work
loops: libclassloops.a
recursives: libclassrec.a
loopd: libclassloops.so
recursived: libclassrec.so
#create libs
libclassloops.a: $(OBJECT_LOOP) #make loops
	$(AR) -rcs $@ $(OBJECT_LOOP)

libclassrec.a: $(OBJECT_RECURSIVE) #make recursives
	$(AR) -rcs $@ $(OBJECT_RECURSIVE)

libclassloops.so: $(OBJECT_LOOP) #make loopd
	$(CC) $(FLAGS) -shared -o $@ $(OBJECT_LOOP)

libclassrec.so: $(OBJECT_RECURSIVE) #make recursived
	$(CC) $(FLAGS) -shared -o $@ $(OBJECT_RECURSIVE)

# compile the code
advancedClassificationLoop.o: $(CODE_LOOP)
	$(CC) $(FLAGS) -fPIC -c $^

advancedClassificationRecursion.o: $(CODE_RECURSIVE)
	$(CC) $(FLAGS) -fPIC -c $^

basicClassifcation.o: basicClassifcation.c
	$(CC) $(FLAGS) -fPIC -c $^

$(OBJECT_MAIN): $(CODE_MAIN)
	$(CC) $(FLAGS) -c $(CODE_MAIN)

###

mains: $(OBJECT_MAIN) libclassrec.a #make mains
	$(CC) $(FLAGS) -o $@ $(OBJECT_MAIN) -l classrec -L.


maindloop: $(OBJECT_MAIN) libclassloops.so #make maindloop
	$(CC) $(FLAGS) $(OBJECT_MAIN) -o $@ -I. -L. -lclassloops

maindrec: $(OBJECT_MAIN) libclassrec.so #make maindrec
	$(CC) $(FLAGS) $(OBJECT_MAIN) -o $@ -I. -L. -lclassrec

make clean:
	rm *.o *.a *.so mains maindloop maindrec mains