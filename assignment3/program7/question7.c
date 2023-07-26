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
	struct stat filestat;
	int max=0;
	char name[100]={'\0'};


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
	
	 
	while( (entry=readdir(dir))!=NULL)
	{ 
		 sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&filestat);
		
		if(S_ISREG(filestat.st_mode))
		{
			if((int)filestat.st_size==0)
			{
				remove(name);
			}
		}
		memset(&filestat,0,sizeof(filestat));
	
	}
	closedir(dir); 		
	return 0;
} 
	
