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
		if (strcmp(argv[2],(char*)entry->d_name)==0)
		{
			printf("%s file is prsent in directory \n",argv[2]);
			break;
		}
	}
	closedir(dir); 		
	return 0;
} 
	
