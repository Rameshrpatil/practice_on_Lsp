#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char* args[])
{
	DIR *dir;
	int ret=0;
	if (argc!=2)
	{
		printf("insufficent arguments");
		return -1;
	}
	
	ret= mkdir(args[1],0777);
	if(ret<0)
	{
		printf("unable to create directory");
		return -1;
	}
	
	
	return 0;
}
