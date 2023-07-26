#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	int max=0;
	char filename[256];
	char name[100]={'\0'};
	
	if(argc!=2)
	{
		printf("error:not sufficent arguments\n");
		return -1;
	}
	
	if((dir=opendir(argv[1]))==NULL)
	{
		printf("error : unable to open the specified directory\n");
			return -1;
	}
	
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&filestat);
		
		if(S_ISREG(filestat.st_mode))
		{
			if(max<(int)filestat.st_size)
			{
				memset(filename,0,sizeof(filename));
				
				strcpy(filename,entry->d_name);
				max=(int)filestat.st_size;
			}
		}
		memset(&filestat,0,sizeof(filestat));
	}
	printf("file with maximum size :%s \nSize: %d\n",filename,max);
	
	closedir(dir);
	return 0;
}
