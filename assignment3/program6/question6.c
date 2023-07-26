#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char * argv[])
{
	 DIR *dir;
	struct dirent *entry;
	char oldpath[256]={'\0'};
	char newpath[256]={'\0'};


	if(argc!=3)
	{
		printf("error: insufficent arguments");
		return -1;
	}
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("unable to open the spcified directory\n");
		return -1;
	}
	
	 
	while( (entry=readdir(dir))!=NULL)
	{ 
		sprintf(oldpath,"%s/%s",argv[1],entry->d_name);
		sprintf(newpath,"%s/%s",argv[2],entry->d_name);
		
		rename(oldpath,newpath);
		memset(&oldpath,0,sizeof(oldpath));
		memset(&newpath,0,sizeof(newpath));

	}
	closedir(dir); 		
	return 0;
} 
	
