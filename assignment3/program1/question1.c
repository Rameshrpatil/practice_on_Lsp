
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char* argv[])
{
	DIR *dir;
	struct dirent *entry;
	
	if(argc!=2)
	{
		printf("error: not sufficent arguments\n");
		return -1;
	}
	
	if((dir =opendir(argv[1]))==NULL)
	{
		printf("unable to open specified directory\n");
		return -1;
	}
	
	printf("contents of the directory as:\n");
	
	 
	while((entry=readdir(dir))!=NULL)
	{
		printf("Name : %s\t Inode:%d\n",entry->d_name,entry->d_ino);
		
	}
	
	closedir(dir);
	
	return 0;
}
