$(CC)=gcc

appl :
	$(CC)  main.c calc_add.c -o appl

clean:
	rm -f *.o  appl


