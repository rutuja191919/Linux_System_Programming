#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#pragma pack(1)

struct Student
{
    int RollNo;
    char Sname[20];
    float Marks;
    int Age;
};

int main()
{
    int fd = 0, Ret = 0;
    char Buffer[1024];
    struct Student sobj;
    
    sobj.RollNo = 12;
    sobj.Marks = 89.99;
    sobj.Age = 25;
    strcpy(sobj.Sname, "Sneha");

    fd = creat("Student.txt", 0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    write(fd, &sobj, sizeof(sobj));

    return 0;
}