#include<stdio.h>
#include<fcntl.h>

int main(int argc,char*argv[])
{

	int fd=0;
	char buff [20]={"\0"};
	if(argc!=3)
	{
		printf("error: insufficent arguments\n");
		
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("unable to open file\n");
		
	}
	
	lseek(fd,argv[2],SEEK_SET);
	
	read(fd,buff,20);
	
	close(fd);
	
}
	
