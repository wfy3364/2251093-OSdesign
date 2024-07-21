#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void redirect(int num, int pip[]) //输入或输出重定向
{
    close(num);
    dup(pip[num]);
    close(pip[0]);
    close(pip[1]);
}

void drop(int prime) //筛除非质数
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