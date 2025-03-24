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
    int i, j;
    char ch;
    int first = 1;
    Node *head = ListCreate();

    system("mode con cols=130 lines=60");
    system("color 0E");
    while (1)
    {
        system("cls");
        ch = Menu();
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
