OBJ = pa1.o insert.o merge.o
LIB = readFile.a

foo : $(OBJ) $(LIB)
	g++ -o foo $(OBJ) $(LIB)

%.o: %.c
	g++ -c -o $@ $<

clean :
	rm -rf foo $(OBJ)

