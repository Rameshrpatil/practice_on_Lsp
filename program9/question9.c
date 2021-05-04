#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd=0;
	int ret=0;
	char arr[]="ramesh patil";
	if(argc!=2)
	{
		printf("Error: insufficent arguments");
		return -1;
	}

	fd=open(argv[1],O_WRONLY|O_APPEND);
	
	if (fd== -1)
	{
		printf("error: unable to open the  file \n");
	}
	else
	{
		printf("file gets opened with fd=%d\n",fd);
	}

	ret = write(fd,arr,sizeof(arr));
	if(ret != sizeof(arr))
	{
		printf("Unable to write contents\n");
	}
	  

		
	return 0;
} 
