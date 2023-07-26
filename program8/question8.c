#include<stdio.h>
#include<fcntl.h>

int main(int argc,char* argv[])
{
	int fd=0;
	int ret=0;
	int arr[2000];
	if(argc!=2)
	{
		printf("Error: insufficent arguments");
		return -1;
	}

	fd=open(argv[1],O_RDONLY);
	
	if (fd== -1)
	{
		printf("error: unable to open the  file \n");
	}
	else
	{
		printf("file gets opened with fd=%d\n",fd);
	}

	ret = read(fd,arr,2000);
	//if(ret !=5)
	//{
	//	printf("Unable to read contents\n");
	//}
	printf("read contents are: %s",arr);

		
	return 0;
} 
