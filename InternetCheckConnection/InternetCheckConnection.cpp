// InternetCheckConnection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <Windows.h>
#include <WinInet.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib,"wininet.lib")

int main(int argc, char* argv[])
{    
    if(argc > 3)
    {
        printf("输入参数错误！\n");
        printf("使用下面的命令查看帮助：\nInternetCheckConnection /?\n");
        printf("\n按任意键退出程序...\n");
        _getch();
        exit(1);
    }

    if(argc == 2 && strcmp(argv[1], "/?") == 0)
    {
        printf("InternetCheckConnection 用法：\n\n");
        printf("InternetCheckConnection /?        查看此帮助信息\n");
        printf("InternetCheckConnection           检测是否可连接到网络，可连接返回1，否则返回0\n");
        printf("InternetCheckConnection time n    检测是否可连接到网络，可连接返回1，否则每隔\n");
        printf("                                  time毫秒检测1次，最多检测n次\n\n");
        printf("按任意键退出程序...\n");
        _getch();
        exit(0);
    }
    else if(argc == 1)
    {
        bool ping = InternetCheckConnectionA("http://www.baidu.com/", FLAG_ICC_FORCE_CONNECTION, 0);
        if(ping)
        {
            printf("网络正常连接！\n");
            return 1;
        }
        else
        {
            printf("网络未正常连接！\n");
            return 0;
        }
    }
    else if(argc == 3)
    {
        int timeDelay = atoi(argv[1]);
        int n = atoi(argv[2]);
        timeDelay = (timeDelay<0) ? 0 : timeDelay;
        n = (n<1) ? 1 : n;

        bool ping = false;
        while(n--)
        {
            static int count = 0;
            ping = InternetCheckConnectionA("http://www.baidu.com/", FLAG_ICC_FORCE_CONNECTION, 0);
            if(ping)
            {
                printf("网络正常连接！\n");
                return 1;
            }
            else
            {
                if(n != 0)
                {
                    printf("已检测 %d 次，网络未正常连接！\n", ++count);
                    Sleep(timeDelay);
                }
            }
        }
        printf("网络未正常连接！\n");
        return 0;
    }
    else
    {
        printf("输入参数错误！\n");
        printf("使用下面的命令查看帮助：\nICSController /?\n");
        printf("\n按任意键退出程序...\n");
        _getch();
        exit(1);
    }

}

