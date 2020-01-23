OBJ = pa2.o averN.o second.o

foo : $(OBJ)
	g++ -o foo $(OBJ)

%.o: %.c
	g++ -c -o $@ $<

clean :
	rm -rf foo $(OBJ)

