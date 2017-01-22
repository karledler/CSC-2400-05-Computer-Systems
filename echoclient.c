/*
 * echoclient.c - An echo client
 */

#include "nethelp.h"

int main(int argc, char **argv) 
{
    int clientfd, port;
    char *host, buf[MAXLINE];
    int n;

    if (argc != 3) {
	  fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	  exit(0);
    }
    host = argv[1];
    port = atoi(argv[2]);

    clientfd = open_clientfd(host, port);

    fgets(buf, MAXLINE, stdin);
    while (strncmp(buf, "exit", 4) != 0) 
    {
	   write(clientfd, buf, strlen(buf));
	   n = readline(clientfd, buf, MAXLINE);
       if(n <= 0) break;
	   write(1, buf, n);
       fgets(buf, MAXLINE, stdin);
    }
    close(clientfd);
    exit(0);
}
