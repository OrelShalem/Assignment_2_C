CC = gcc
AR = ar
FLAGS = -Wall -g
OBJECTS_MAIN = my_graph.o
OBJECTS_LIB = my_mat.o

all: my_matlibs my_matlibd my_graph my_Knapsack maind

my_graph: $(OBJECTS_MAIN) my_matlib.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) my_matlib.a

my_Knapsack: my_Knapsack.o my_matlib.a
	$(CC) $(FLAGS) -o my_Knapsack my_Knapsack.o my_matlib.a

maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./my_matlib.so

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC my_graph.c -o my_graph.o

my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC my_Knapsack.c -o my_Knapsack.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC my_mat.c -o my_mat.o

my_matlib.a: $(OBJECTS_LIB)
	$(AR) -rcs my_matlib.a $(OBJECTS_LIB)

my_matlib.so: $(OBJECTS_LIB)
	$(CC) -shared -o my_matlib.so $(OBJECTS_LIB)

my_matlibs: my_matlib.a

my_matlibd: my_matlib.so

clean:
	rm -f *.o *.a *.so my_graph my_Knapsack maind
