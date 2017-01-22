/*
 * echoserver.c - A sequential echo server
 */
#include "nethelp.h"

void echo(int connfd);

int main(int argc, char **argv) 
{
    int listenfd, connfd, port;
    struct sockaddr clientaddr;
    int clientlen=sizeof(struct sockaddr);
	
	pthread_t tid;

    if (argc != 2) {
	   fprintf(stderr, "usage: %s <port>\n", argv[0]);
	   exit(0);
    }
    port = atoi(argv[1]);

    listenfd = open_listenfd(port);
    while (1) {
	   connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientlen);  
	 if(connfd > 0)
         {
        pthread_create(&tid, NULL, echo, (void*)connfd);
	}//echo(connfd);    /* Service client */
	 
    }
}

/*
 * echo - read and echo text lines until client closes connection
 */
void echo(int connfd) 
{
    size_t n; 
    char buf[MAXLINE]; 

    while((n = readline(connfd, buf, MAXLINE)) > 0) {
       printf("server received %d bytes\n", n);
       printf("[%s]\n", buf);
       write(connfd, buf, n);
    }
    close(connfd);   /* Close connection with client */
}
