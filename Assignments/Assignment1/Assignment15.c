#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int fd = 0, Ret = 0;
	char *Buffer = NULL;

	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	printf("Executable_Name Name_of_the_file No_of_bytes\n");
    
	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}

	Buffer = (char *)malloc(atoi(argv[2]));

	Ret = read(fd,Buffer,atoi(argv[2]));

	if(Ret == 0)
	{
		printf("Unable to read the data from file\n");
		return -1;
	}
	
	write(1,Buffer,Ret);

	return 0;
}
