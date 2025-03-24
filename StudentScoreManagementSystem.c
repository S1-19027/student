/*************************************************************************
 * Project:  ѧ���ɼ�����ϵͳ
 * Function: ����ѧ���ĳɼ���Ϣ����ɾ��ġ����㡢����ͳ�ơ���ӡ��
 *************************************************************************
 * Name:     ����蟣�������
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
        printf("\t\t\t\t��ϵͳ������ʦģʽ��ѧ��ģʽ\n\n");
        SetConsoleOutputCP(936);
        printf("\t\t\t\t��ʦģʽ�������롢�����޸ĵȹ���\n\n");
        SetConsoleOutputCP(936);
        printf("\t\t\t\tѧ��ģʽ�������\n\n");
        printf("\t\t\t\t***********************\n\n");
        printf("\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        SetConsoleOutputCP(936);
        printf("\t\t��ѡ����ʦģʽ��1��/ѧ��ģʽ��2��:");
        scanf("%d", &mode);
        system("cls");
        if (mode == 1)
        {
            SetConsoleOutputCP(936);
            printf("��������ʦ���룺");
            scanf("%d", &safeguard);
            if (safeguard == safe)
            {
                system("cls");
                break;
            }
            else
            {
                SetConsoleOutputCP(936);
                printf("\n\n�������");
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
            printf("������Ч��������ѡ��\n");
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
            printf("���ң�4��/�˳���0����");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
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
                printf("��δ����ѧ����Ϣ���ļ���ʧ��,���ȼ��!\n");
                getch();
                break;
            }
            getch();
            break;
        case 0:
            system("cls");
            SetPosition(0, 10);
            printf("�˳�ϵͳ��\n");
            exit(0);
        default:
            system("cls");
            SetPosition(0, 10);
            printf("�������������ѡ�����\n");
            system("pause");
        }
    }

    return 0;
}
