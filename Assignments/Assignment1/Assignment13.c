//Execute permission for the directory : sub directory to trace

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int Mode = 0;
	
	if(argc != 3)
	{
		printf("Invalid no of arguments\n");
		return -1;
	}

	printf("Usage : Name_of_executable Name_of_file Mode\n");

	if(strcasecmp(argv[2],"Read") == 0)
	{
		Mode = R_OK;
	}
	else if(strcasecmp(argv[2],"Write") == 0)
	{
		Mode = W_OK;
	}
	else if(strcasecmp(argv[2],"Execute") == 0)
	{
		Mode = X_OK;
	}
	else
	{
		Mode = R_OK;
	}
	
	if(access(argv[1], mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("You can access %s file in %s mode\n",argv[1],argv[2]);
    }

	return 0;
}
