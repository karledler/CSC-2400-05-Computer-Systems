CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lpthread -lnsl -lrt -lsocket

OBJS = nethelp.o chatserver.o chatclient.o

all: xchatserver xchatclient

nethelp.o: nethelp.c
	$(CC) $(CFLAGS) -c nethelp.c

chatserver.o: chatserver.c
	$(CC) $(CFLAGS) -c chatserver.c

chatclient.o: chatclient.c
	$(CC) $(CFLAGS) -c chatclient.c

xchatserver: chatserver.o nethelp.o
	$(CC) $(LDFLAGS) -o $@ chatserver.o nethelp.o

xchatclient: chatclient.o nethelp.o
	$(CC) $(LDFLAGS) -o $@ chatclient.o nethelp.o

clean:
	rm -f xchatserver xchatclient *.o *~ core
