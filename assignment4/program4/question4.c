#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>

#define LEN 10

int main(int argc,char * argv[])
{
	int fd1=0,fd2=0;
	DIR * dir;
	struct dirent *entry;
	char buff[100]={'\0'};
	int ret=0;
	
	if(argc!=2)
	{
		printf("error: insufficent arguments");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("unable to open the spcified directory\n");
		return -1;
	}
	
	if((ret=creat("demo",0777))<0)
	{
		printf("unable to create directory");
		return -1;
	}
	fd2=open("demo",O_WRONLY|O_APPEND);
	if(fd2==-1)
	{
		printf("unable to open file");
		return -1;
	}	
	 
	while( (entry=readdir(dir))!=NULL)
	{ 
		//sprintf(buff,"%s/%s",argv[1],entry->d_name);
		 fd1=open("entry->d_name",O_RDONLY);
		if(fd1==-1)
		{
		printf("unable to open file\n\n");
		}	
	 	read(fd1,buff,LEN);
		write(fd2,buff,LEN);
		

	}
	
	close(fd1);
	close(fd2);
	
	closedir(dir); 		

	return 0;
} 

	
