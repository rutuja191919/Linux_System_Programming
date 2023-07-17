#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat sobj;

	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	printf("Executable_Name Name_of_the_file\n");

	stat(argv[1],&sobj);

	printf("File name : %s\n",argv[1]);
    printf("File size is : %li\n",sobj.st_size);
	printf("Inode number : %li\n",sobj.st_ino);
    printf("Number of links : %li\n",sobj.st_nlink);    
    printf("File system number : %li\n",sobj.st_dev);
    printf("Number of blocks : %li\n",sobj.st_blocks);


	return 0;
}
