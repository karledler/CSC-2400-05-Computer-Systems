/*
 * chatclient.c - An echo client
 */

#include "nethelp.h"
#define MAX_CLIENT 10
//void HandleFeedback(void *);

int main(int argc, char **argv) 
{
    int clientfd, port;
    char *host, buf[MAXLINE];
    int n, k;
	char *names[MAX_CLIENT];
	char *token;
	int i = 0;
	int join = 0; //0 for false, client did not join yet

    if (argc != 3) {
	  fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	  exit(0);
    }
    host = argv[1];
    port = atoi(argv[2]);

    clientfd = open_clientfd(host, port);

    fgets(buf, MAXLINE, stdin);

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
			if( strncmp(names[i], token, strlen(token))== 0)
			{
			free(names[i]);
			names[i]=NULL;
			}
		}
		}
	}

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

/*
void * HandleFeedback(void * fd)
{
int clientfd = int(fd);

while(1)
{
	n = readline(clientfd, buf, MAXLINE);
	if(n<= 0) break;
	write(1, buf, n);
}
return NULL;
}
*/
