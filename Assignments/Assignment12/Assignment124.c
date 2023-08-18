//Map file in memory and read the mapped file

#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0, i = 0, n = 0, errno = 0;
    struct stat statbuf;
    char *ptr = NULL;

    if(argc < 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd  = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fstat(fd, &statbuf);

    ptr = (char *)mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED, fd,0);  //return value is void * thus typecast

    if(ptr == MAP_FAILED)
    {
        printf("Mapping failed\n");
        return -1;
    }
    close(fd);

    printf("Contents of the file is : \n");

    n = write(1, ptr, statbuf.st_size);
    if(n != statbuf.st_size)
    {
        printf("Unable to read\n");
        return -1;
    }
    
    errno = munmap(ptr, statbuf.st_size);
    if(errno != 0)
    {
        printf("Unmapping failed\n");
        return -1;
    }

    return 0;
}
