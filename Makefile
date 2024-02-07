
CC = gcc
AR = ar
OBJECTS_MAIN=my_graph.o
OBJECTS= my_mat.o
OBJECTS_KNAP= my_Knapsack.o
FLAGS= -Wall -g

all: libmy_mat.so my_graph my_Knapsack
libmy_mat.so: $(OBJECTS)
	$(CC) -shared -o libmy_mat.so $(OBJECTS)
my_graph: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) ./libmy_mat.so
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_graph.o my_graph.c 
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c 
my_graph: libmy_mat.so 

my_Knapsack.o: my_Knapsack.c 
	$(CC) $(FLAGS) -c -fPIC -o my_Knapsack.o my_Knapsack.c 
my_Knapsack: $(OBJECTS_KNAP) 
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_KNAP) 
my_Knapsack: my_Knapsack.o

.PHONY: clean all

clean:
	rm -f *.o *.so my_graph my_Kanpsack
