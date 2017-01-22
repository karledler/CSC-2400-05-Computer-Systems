/*
 * chatserver.c - A sequential echo server
 */
#include "nethelp.h"
#define MAX_CLIENTS 10

/*
struct client_info
{
int fd;
char *name;
}
*/
//struct client_info clients(MAX_CLIENTS);
//access using clients()fd

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
	    int k;   
        char *names[MAXBUF];
        char *token;
        int i = 0;
        int join = 0; //0 for false, client did not join yet

    while((n = readline(connfd, buf, MAXLINE)) > 0) {
       printf("server received %d bytes\n", n);
       printf("[%s]\n", buf);
       write(connfd, buf, n);

	if( strncmp(buf, "JOIN", 4) == 0)
        {
        join = 1;
        token = strtok (buf, " ");
        token = strtok (NULL, " ");

                if(token!=NULL)
                {
                names[i]=malloc(strlen(token)+1);
                strcpy(names[i],token);
                i++;
                }

        }

       if( strncmp(buf, "LEAVE", 5) == 0)
        {
                if(join==0)
                {printf("Client did not JOIN. Cannot LEAVE");}
                else
                {
                for( k=0; k < i; k++)
                {
                        if( strncmp(names[k], token, strlen(token))== 0)
                        {
                        free(names[i]);
                        names[i]=NULL;
                        }
                }
                }
        }

	if( strncmp(buf, "WHO", 3) == 3)
	{
		for(k=0; k < i; k++)
		{
		if(names[k]!=NULL)
		{
		//printf("%s\n", names[k]);
		write(connfd, names[k], n);
		}
		}
	}

	if( strncmp(buf, "HELP", 4) ==4)
	{
	//printf("Available commands:\n");
	//printf("JOIN, LEAVE, WHO, HELP \n");
	write(connfd, "Available commands: JOIN, LEAVE, WHO, HELP\n", 100);
	}
    }
    close(connfd);   /* Close connection with client */
}
