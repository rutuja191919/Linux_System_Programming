#include<stdio.h>
#include<fcntl.h>
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
	printf("Usage : Name_of_executable Name_of_file_to_open Mode\n");
	if(strcasecmp(argv[2],"Read") == 0)
	{
		Mode = O_RDONLY;
	}
	else if(strcasecmp(argv[2],"Write") == 0)
	{
		Mode = O_WRONLY;
	}
	else
	{
		Mode = O_RDONLY;
	}
	
	fd = open(argv[1], Mode);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	else
	{
		printf("File opened successfully with fd : %d",fd);
	}
	
	return 0;
}
