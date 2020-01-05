OBJ = pa3.o bst.o node.o

foo : $(OBJ)
	g++ -o foo $(OBJ)

%.o: %.c
	g++ -c -o $@ $<

clean :
	rm -rf foo $(OBJ)

