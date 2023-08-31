#include "header.h"

void main()
{
    int p[2], ret;

   char a[20];
    ret = pipe(p);
    if (ret < 0)
    {
	perror("pipe");
	return;
    }
    printf("p[0] = %d p[1] =%d\n", p[0], p[1]);
    if (fork() == 0)
    {		//child
	printf("child PID=%d", getpid());
	while (1)
       	{
	    sleep(1);
//	    char b[20];
	    printf("before reading in the child....\n");
	    read(p[0], a, 20);
	    printf("after reading in child  the data is %s\n", a);

	}
    } else 
    {			//parent

	printf("parent PID=%d", getpid());

	while (1)
       	{
	    sleep(2);
	   // char a[20];
	    printf("enter the data...\n");
	    scanf("%s", a);
	    write(p[1], a, strlen(a) + 1);
	}
    }
    //return 0;
}
