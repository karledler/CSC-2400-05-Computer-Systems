#include <stdio.h>	//for printfm fgets
#include <stdlib.h>	//for getenv, malloc, free
#include <string.h>	//for strtok, strcpy

#include "stingarray.h" //for Insert, PrintAll, etc

#define MAX_PATHS 50
#define MAX_CMD 80

char * searchpaths[MAX_PATHS]; //search directories listed in the PATH environment
char numpaths = 0; //number of directories listed in the PATH environment

void tokenize_PATH();
//Action: save all PATH directories in the searchpaths array

void find_PATH(char * fname);
/*Input: @param fname is a filename
Action: print the PATH directory containing the filename, if any*/

void handle_quit();
// Action: clean up and exit

void handle_path();
//Action: print all PATH directories

void handle_where(char * cmd);
/*Input: @param cmd is the command "where file"
Action: extract the file name and print the PATH directory containing the file, if any*/


int main()
{
char cmd[MAX_CMD];

/*Preprocessing step: build the searchpaths data structure*/
tokenize_PATH;

	while(1) //infinite loop
	{
	printf("myshell > ");	//print the shell prompt
	fgets(cmd, MAX_CMD, stdin);	//read user command

	if(strncmp(cmd, "quit", 4) == 0)
	{handle_quit();}
	else if(strncmp(cmd, "path", 4) == 0)
	{handle_path();}
	else if(strncmp(cmd, "where", 5) == 0)
	{handle_where(cmd);}
	else
	{printf("Unrecognized command \n");}

	}

return 0;
}

void handle_quit()
//Action: clean up and exit
{
	RemoveAll(searchpaths, numpaths);
	exit(0);
}

void handle_path()
//Action: print all PATH directories
{
	PrintAll(searchpaths, numpaths);
}

void handle_where(char * cmd)
/*Input: @param cmd is the command "where file"
Action: print the path directory containing the file, if any*/
{
char * fname = NULL;
fname = strtok(cmd, "\n");  //fname points to the token "where"
fname = strtok(NULL, "\n");  //fname should point to the file to be found
if(fname != NULL)	//make sure file name has been provided
{find_PATH(fname);}	//print the directory containing the file, if any
}

int file_exists(char * fname)
//Input: @paaram fname is a filename
//Return: 1 if filename exists, 0 otherwise
{
FILE * file = fopen(fname, "r");  //returns NULL if file not found
if(file == NULL) return 0;  //file does not exist
fclose(file);  //do not leave the file open
return 1; //file exists
}

void find_PATH(char * fname)
//Input: @param fname is a filename
//Action: print the PATH directory containing the filename, if any
{
char *fullpath;
int i;

	for(i = 0; (searchpaths[i] != NULL) && (i < MAX_PATHS); i++)
	{
		fullpath = (char *)malloc(strlen(searchpaths[i]) + strlen(fname) + 2);
		sprintf(fullpath, "%s/%s", searchpaths[i], fname);
		if(file_exists(fullpath))
		{
			printf("%s\n", fullpath);
			free(fullpath);
			return;
		}
		free(fullpath);
	}
	printf("%s could not be found\n", fname);
}

void tokenize_PATH()
//Action: Save all PATH directories in the searchpaths array
{
	char *s, *token;
	char *pathbuf;
	
	s = getenv("PATH");

	if(s == NULL)
	{
		printf("PATH variable not found\n");
		return;
	}

/*Make a local copy of the PATH environment value
This is necessary to keep the PATH environment unaltered*/
pathbuf = malloc(strlen(s)+1);
strcpy(pathbuf, s);

//Tokenize the local copy of the PATH environment value
token = strtok(pathbuf, ":");
while((token != NULL) && (numpaths < MAX_PATHS-1))
{
	//insert the token into the searchpaths array
	Insert(searchpaths, token, numpaths);
	numpaths++;

	//retrieve the next token (if any)
	token = strtok(NULL, ":");
}

	//Mark the end of the search paths in the array
	searchpaths[numpaths] = NULL;

	free(pathbuf);  //no longer necessary
}
