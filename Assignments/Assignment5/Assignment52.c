#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#pragma pack(1)

struct Employee
{
    int Eid;
    char Ename[20];
    float Salary;
    int Age;
};

int main()
{
    int fd = 0, Ret = 0;
    char Buffer[1024];
    char Name[20];
    struct Employee eobj, eobj1;

    eobj.Eid = 100;
    strcpy(eobj.Ename, "Sneha");
    eobj.Salary = 20000;
    eobj.Age = 26;

    printf("Enter the name of the file\n");
    scanf("%s",Name);

    fd = creat(Name, 0777);

    if(fd == -1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    write(fd, &eobj, sizeof(eobj));

    fd = open(Name, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    Ret = read(fd, &eobj1, sizeof(eobj));

    printf("Employee Details\n");
    printf("%d\n",eobj1.Eid);
    printf("%s\n",eobj1.Ename);
    printf("%.2f\n",eobj1.Salary);
    printf("%d\n",eobj1.Age);

    close(fd);
    
    return 0;
}