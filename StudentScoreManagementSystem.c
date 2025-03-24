/*************************************************************************
 * Project:  学生成绩管理系统
 * Function: 输入学生的成绩信息、增删查改、计算、排序、统计、打印等
 *************************************************************************
 * Name:     王天锜，陈守炼
 *************************************************************************
 * time:     2025/03/25
 * version:  V0.1
 *************************************************************************
 *
 * Copyright 2025 by HangZhouDianZi University
 *
 ************************************************************************/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    SetConsoleOutputCP(936);
    int n = 0;
    int m = 0;
    int i, j, a;
    char ch;
    int first = 1;
    Node *head = ListCreate();
    int flag = 0;
    int safe = 123456;
    int safeguard;

    int mode;

    system("mode con cols=130 lines=60");
    system("color 0E");
    while (1)
    {
        SetConsoleOutputCP(936);
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n\n\n\n\t\t\t\t***********************\n\n");
        SetConsoleOutputCP(936);
        printf("\t\t\t\t本系统包含老师模式和学生模式\n\n");
        SetConsoleOutputCP(936);
        printf("\t\t\t\t老师模式包含输入、排序、修改等功能\n\n");
        SetConsoleOutputCP(936);
        printf("\t\t\t\t学生模式仅能输出\n\n");
        printf("\t\t\t\t***********************\n\n");
        printf("\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        SetConsoleOutputCP(936);
        printf("\t\t请选择老师模式（1）/学生模式（2）:");
        scanf("%d", &mode);
        system("cls");
        if (mode == 1)
        {
            SetConsoleOutputCP(936);
            printf("请输入老师密码：");
            scanf("%d", &safeguard);
            if (safeguard == safe)
            {
                system("cls");
                break;
            }
            else
            {
                SetConsoleOutputCP(936);
                printf("\n\n密码错误！");
                Sleep(1000);
                continue;
            }
        }
        else if (mode == 2)
        {

            flag += 1;
            break;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入无效，请重新选择！\n");
        }
    }
    while (1)
    {
        system("cls");

        if (mode = 1)
        {
            ch = Menu();
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("查找（4）/退出（0）：");
            scanf("%d", &ch);
        }
        switch (ch)
        {
        case 1:
            system("cls");
            InputRecord(&n, &m, head);
            first = 0;
            break;
        case 2:
            system("cls");

            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            AppendRecord(&n, m, head);
            system("pause");
            break;
        case 3:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            DeleteRecord(&n, m, head);
            system("pause");
            break;
        case 4:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByNumber(n, m, head);
            system("pause");
            break;
        case 5:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByName(n, m, head);
            system("pause");
            break;
        case 6:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            ModifyRecord(n, m, head);
            system("pause");
            break;
        case 7:
            system("cls");
            if (first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            CalculateScoreOfStudent(m, head);
            system("pause");
            break;
        case 8:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            CalculateScoreOfCourse(n, m, head);
            getch();
            break;
        case 9:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            SortbyNum(head);
            getch();
            break;
        case 10:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            SortbyName(head);
            getch();
            break;
        case 11:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            SortbyScore(head, Descending);
            getch();
            break;
        case 12:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            SortbyScore(head, Ascending);
            getch();
            break;
        case 13:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            StatisticAnalysis(n, m, head);
            getch();
            break;
        case 14:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            PrintRecord(n, m, head);
            getch();
            break;
        case 15:
            system("cls");
            if (first)
            {
                SetPosition(POS_X3, POS_Y);
                printf("系统中尚无学生成绩信息，请先输入！\n");
                getch();
                break;
            }
            WritetoFile(n, m, head);
            getch();
            break;
        case 16:
            system("cls");
            if (ReadfromFile(&n, &m, head, &first) || first)
            {
                SetPosition(POS_X1, 10);
                printf("尚未输入学生信息或文件打开失败,请先检查!\n");
                getch();
                break;
            }
            getch();
            break;
        case 0:
            system("cls");
            SetPosition(0, 10);
            printf("退出系统！\n");
            exit(0);
        default:
            system("cls");
            SetPosition(0, 10);
            printf("输入出错，请重新选择操作\n");
            system("pause");
        }
    }

    return 0;
}
