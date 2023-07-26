#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *entry;
	struct stat filestat;
	char name[100]={'\0'};
	
	if(argc!=2)
	{
		printf("error :not sufficent arguments\n");
		return -1;	
	}

	if( (dir=opendir(argv[1]))==NULL)
	{
		printf("unable to open spcified directory \n");
		return -1;
	}
	
	printf("contents of directory as\n");
	
	while((entry=readdir(dir))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&filestat);
		
		printf("%30s: ",entry->d_name);
	
		if(S_ISREG(filestat.st_mode))
			printf("Regular file\n");
		else if(S_ISDIR(filestat.st_mode))
			printf("Directory");
		else if(S_ISDIR(filestat.st_mode))
			printf("Link");
	}
	
	closedir(dir);
	
	return 0;
}
