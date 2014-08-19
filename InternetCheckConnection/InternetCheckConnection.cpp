// InternetCheckConnection.cpp : �������̨Ӧ�ó������ڵ㡣
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
        printf("�����������\n");
        printf("ʹ�����������鿴������\nInternetCheckConnection /?\n");
        printf("\n��������˳�����...\n");
        _getch();
        exit(1);
    }

    if(argc == 2 && strcmp(argv[1], "/?") == 0)
    {
        printf("InternetCheckConnection �÷���\n\n");
        printf("InternetCheckConnection /?        �鿴�˰�����Ϣ\n");
        printf("InternetCheckConnection           ����Ƿ�����ӵ����磬�����ӷ���1�����򷵻�0\n");
        printf("InternetCheckConnection time n    ����Ƿ�����ӵ����磬�����ӷ���1������ÿ��\n");
        printf("                                  time������1�Σ������n��\n\n");
        printf("��������˳�����...\n");
        _getch();
        exit(0);
    }
    else if(argc == 1)
    {
        bool ping = InternetCheckConnectionA("http://www.baidu.com/", FLAG_ICC_FORCE_CONNECTION, 0);
        if(ping)
        {
            printf("�����������ӣ�\n");
            return 1;
        }
        else
        {
            printf("����δ�������ӣ�\n");
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
                printf("�����������ӣ�\n");
                return 1;
            }
            else
            {
                if(n != 0)
                {
                    printf("�Ѽ�� %d �Σ�����δ�������ӣ�\n", ++count);
                    Sleep(timeDelay);
                }
            }
        }
        printf("����δ�������ӣ�\n");
        return 0;
    }
    else
    {
        printf("�����������\n");
        printf("ʹ�����������鿴������\nICSController /?\n");
        printf("\n��������˳�����...\n");
        _getch();
        exit(1);
    }

}

