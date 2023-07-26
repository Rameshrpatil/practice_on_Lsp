#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char * argv[])
{
	char buff[100]={'\0'};
	int fdread=0,fdwrite=0,readcnt=0,writecnt=0;
	
	if(argc!=3)
	{
		printf("error: insufficent arguments");
		return -1;
	}
	if((fdread=open(argv[1],O_RDONLY))<0)
	{
		printf("unable to open the spcified file\n");
		return -1;
	}
	
	if((fdwrite=creat(argv[2],0777))<0)
	{
		printf("unable to create new file\n");
		return-1;
	}
	
	while((readcnt=read(fdread,buff,sizeof(buff)))!=0)
	{
		if(writecnt=write(fdwrite,buff,readcnt)==-1)
		{
			printf("problem in writting");
		}
	}
	close(fdread);
	close(fdwrite);
		
	return 0;
} 
	
