#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
pid_t ret;
pid_t myid;
/* fork another process */
ret = fork();
if (ret < 0) { /* error occurred */
printf("Fork Failed");
return 1;
}
myid = getpid();
printf(ret = [%d], myid = [%d]\n, ret, myid);
return 0;
}
