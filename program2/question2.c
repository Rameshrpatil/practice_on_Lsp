#include<stdio.h>

int main(int argc,char *argv[])
{
	if(argv!=2)
	{	
		printf("error: insuffient arguments");
		return -1;
	}
	printf("the name is:%s",args[1]);

	return 0;
}
