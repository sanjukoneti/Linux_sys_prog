#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
  int fd;
  char option;

  fd=open("/dev/tg_my_dev",O_RDWR);

  if(fd <0){ printf("can not open file..\n");
	 return -1;
  }

  while(1)
  {
	  printf("please enter your option\n 1.write 2.read , 3.exit \n");
	  scanf("%c",&option);

	  switch(option)
	{
		case '1':
			printf("enter the string");
			scanf("%s",write_buf);
			printf("data written...\n");
		write(fd,write_buf,strlen(write_buf)+1);
		printf("DONE....\n");
		break;

		case '2':

			printf("Data is reading");
		read(fd,read_buf,strlen(read_buf));
		printf("Data=%s",read_buf);
		break;

		case '3':
		close(fd);
		exit(1);
		break;

		default:
		printf("enter valid option=%c\n",option);
		break;

	}

  }
	close(fd);
}
