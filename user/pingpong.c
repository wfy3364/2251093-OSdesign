#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void redirect(int num, int pip[]) //���������ض���
{
    close(num);
    dup(pip[num]);
    close(pip[0]);
    close(pip[1]);
}

void drop(int prime) //ɸ��������
{
    int num;
    while (read(0, &num, sizeof(num)))
    {
        if (num % prime != 0)
        {
            write(1, &num, sizeof(num));
        }
    }
}