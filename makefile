OFILES = llist.o flight.o main.o
HFILES = flight.h llist.h
debug: $(OFILES)
	gcc -g -o flight $(OFILES)

flight: $(OFILES)
	gcc -g -o flight $(OFILES)

main.o: main.c $(HFILES)
	gcc -g -c main.c

flight.o: flight.c $(HFILES)
	gcc -g -c flight.c

llist.o: llist.c $(HFILES)
	gcc -g -c llist.c

clean:
	/bin/rm -f *.o
