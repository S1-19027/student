#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
/*
  �������ܣ� ����һ��������
  ��ʽ������ ��
  �������أ�Node���͵�ָ��
*/
Node *ListCreate()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
        newNode->next = NULL;
    return newNode;
}
/*
  �������ܣ� ����һ�����
  ��ʽ������ ѧ�ţ��������������γ������ֺܷ�ƽ����
  ��������ֵ��Node���͵�ָ��
*/
Node *CreateNode(long num, const char *name, float scores[], int courseCount, float sum, float aver)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data.num = num;
    strncpy(newNode->data.name, name, NAME_LEN);
    for (int i = 0; i < courseCount; i++)
    {
        newNode->data.score[i] = scores[i];
    }
    newNode->data.sum = sum > 0.0 ? sum : 0.0;
    newNode->data.aver = aver > 0.0 ? aver : 0.0;
    newNode->next = NULL;
    return newNode;
}

/*
  �������ܣ� ���һ�����
  ��ʽ������ ͷ�ڵ㣬ѧ�ţ��������������γ������ֺܷ�ƽ����
  ��������ֵ����
*/
void AppendNode(Node *head, long num, const char *name, float scores[], int courseCount, float sum, float aver)
{
    Node *newNode = CreateNode(num, name, scores, courseCount, sum, aver);
    if (newNode == NULL)
        return;

    if (head == NULL)
    {
        head = ListCreate();
        head->next = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL) // �ҵ�β�ڵ�
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
/*
  �������ܣ��������
  ��ʽ������ ͷ�ڵ�
  ��������ֵ����
*/
void FreeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/*
  �������ܣ� ��ʾϵͳ���˵��� ��ȡ�����û�����Ĳ���ѡ������ظ�������
  ��ʽ������ ��
  ��������ֵ���û����������ѡ�int��
*/
int Menu(void)
{
    int posy = 5;
    int option; // �����û�����Ĳ������ŵı���
    int i, j;
    SetPosition(POS_X3, posy);
    SetConsoleOutputCP(936);
    printf("ѧ���ɼ�����ϵͳ\n"); // ���ϵͳ��
    // ���ϵͳ���͹���˵��֮������ж̺���
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // ���ϵͳ֧�ֵĹ��ܺͶ�Ӧ�Ĺ��ܴ���
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, ++posy);
    SetConsoleOutputCP(936);
    printf("1.����ѧ����Ϣ");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("2.����ѧ���ɼ�");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("3.ɾ��ѧ����Ϣ");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("4.��ѧ�Ų��Ҽ�¼");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("5.���������Ҽ�¼");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("6.�޸�ѧ����Ϣ");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("7.����ѧ���ɼ�");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("8.����γ̳ɼ�");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("9.��ѧ������");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("10.����������");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("11.���ܳɼ���������");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("12.���ܳɼ���������");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("13.ѧ���ɼ�ͳ��");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("14.��ӡѧ����¼");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("15.ѧ����¼����");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("16.�Ӵ��̶�ȡѧ����¼");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("0.�˳�");
    // ���ϵͳ֧�ֵĹ�����������ʾ��֮������ж̺���
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // ��ʾ�û�������Ҫִ�еĹ��ܴ���
    SetPosition(POS_X1, ++posy);
    printf("��ѡ������Ҫ���еĲ���[0~16]: [  ]\b\b\b");
    scanf("%d", &option);
    return option;
}

/*
  �������ܣ� ���������������ʼλ��
  ��ʽ������ ���������ʼλ�õ�����x,y��int ����
  ��������ֵ��void
*/
void SetPosition(int x, int y)
{
    HANDLE hOut;
    COORD pos;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

/*
  �������ܣ� ����ѧ����Ϣ
  ��ʽ������ n,m: int *, stu: STU *
  ��������ֵ��void
*/
void InputRecord(int *n, int *m, Node *head)
{
    int i, j;
    int posy = 6;
    SetConsoleOutputCP(936);
    SetPosition(POS_X2, posy); // ���ù��λ�ã�����Ҫ��ʾ��λ��
    printf("����ѧ������(n<%d):", STU_NUM);
    scanf("%d", n);
    SetConsoleOutputCP(936);
    SetPosition(POS_X2, posy += 2); // ���ù��λ�ã�����Ҫ��ʾ��λ��
    printf("����γ���(m<%d):", COURSE_NUM);
    scanf("%d", m);
    for (i = 0; i < 2; i++)
    {
        SetConsoleOutputCP(936);
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    SetConsoleOutputCP(936);
    SetPosition(POS_X2, ++posy);
    printf("����ѧ��ѧ�š������͸�����Ŀ�ĳɼ�:");
    for (i = 0; i < *n; i++)
    {
        SetConsoleOutputCP(936);
        SetPosition(POS_X2, ++posy);
        printf("�����%d��ѧ����Ϣ:\t", i + 1);
        float num;
        char name[NAME_LEN];
        float score[COURSE_NUM];
        scanf("%ld%s", &num, name);
        for (j = 0; j < *m; j++)
        {
            scanf("%f", &score[j]);
        }
        AppendNode(head, num, name, score, *m, 0.0, 0.0);
    }
}

/*
  �������ܣ� ����ѧ���ɼ�
  ��ʽ������ n,m: int , stu: STU *
  ��������ֵ��void
*/
void CalculateScoreOfStudent(int m, Node *head)
{
    SetConsoleOutputCP(936);
    printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
    Node *temp = head->next;
    int i = 0, j;
    while (temp != NULL)
    {

        for (j = 0; j < m; j++)
        {
            temp->data.sum += temp->data.score[j];
        }
        temp->data.aver = temp->data.sum / m;
        SetConsoleOutputCP(936);
        printf("��%d��ѧ�����ܷ�=%.2f, ƽ����=%.2f\n", i + 1, temp->data.sum, temp->data.aver);
        i += 1;
        temp = temp->next;
    }
}

/*
  �������ܣ� ����γ̳ɼ�
  ��ʽ������ n,m: int , stu: STU *
  ��������ֵ��void
*/
void CalculateScoreOfCourse(int n, int m, Node *head)
{
    int i, j;
    float sum[COURSE_NUM], aver[COURSE_NUM];
    int posy = 7;
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, posy);
    printf("���ſγ��ֺܷ�ƽ���ֵļ�����Ϊ��");

    for (j = 0; j < m; j++)
    {
        Node *temp = head->next;
        sum[j] = 0;
        while (temp != NULL)
        {
            sum[j] += temp->data.score[j];
            temp = temp->next;
        }
        aver[j] = sum[j] / n;
        SetConsoleOutputCP(936);
        SetPosition(POS_X1, ++posy);
        printf("��%d�ſγ�: �ܷ� = %.2f, ƽ���� = %.2f\n", j + 1, sum[j], aver[j]);
    }
}
/*
  �������ܣ� ���ѧ������n,�γ���m,�Լ�ÿ��ѧ����Ϣ��student.txt��
  ��ʽ������ n,m: int , stu: STU *
  ��������ֵ��void
*/
void WritetoFile(int n, int m, Node *head)
{
    int i, j;
    // �����ļ�ָ��
    FILE *fp;
    // ���ļ���ָ�����ļ��Ĵ���ʽΪд�룬����ָ��ָ���ļ�
    if ((fp = fopen("student.txt", "w")) == NULL)
    {
        SetConsoleOutputCP(936);
        printf("�ļ�student.txt�޷������򿪣�");
        exit(0);
    }
    // �����ݰ�ָ����ʽд���ļ�������ѧ����n,�γ�����m��ÿλѧ������Ϣ
    fprintf(fp, "%10d%10d\n", n, m);
    Node *temp = head->next;
    while (temp != NULL)
    {
        fprintf(fp, "%10ld%10s\n", temp->data.num, temp->data.name);
        for (j = 0; j < m; j++)
        {
            fprintf(fp, "%10.1f", temp->data.score[j]);
        }
        fprintf(fp, "%10.1f%10.1f\n", temp->data.sum, temp->data.aver);
        temp = temp->next;
    }
    // �ر��ļ�
    fclose(fp);
    // ��ʾ�û����̲������
    SetConsoleOutputCP(936);
    printf("������ϣ�\n");
}

/*
  �������ܣ� �����еĴ����ļ�student.txt�У�����ѧ������,�γ���,�Լ�ÿ��ѧ����Ϣ���ڴ��ж�Ӧ
             ����n, m�ͽṹ������stu�У�������־����first��ֵ��0
  ��ʽ������ n,m, first: int * , stu: STU *
  ��������ֵ��int(����1���������ļ�ʧ�ܣ�����0�������ɹ��Ӵ��̶������ݣ�
*/
int ReadfromFile(int *n, int *m, Node *head, int *first)
{
    // �����ļ�ָ��
    FILE *fp;
    int i, j;
    int posy = 8;
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, posy);
    // ���ļ���ָ�����ļ��Ĵ���ʽΪд�룬����ָ��ָ���ļ�
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        SetConsoleOutputCP(936);
        printf("�����ļ�student.txt�޷���");
        return 1;
    }
    // �����ݰ�ָ����ʽ�Ӵ����ļ�����������ѧ����n,�γ�����m��ÿλѧ������Ϣ
    fscanf(fp, "%10d%10d", n, m);

    for (i = 0; i < *n; i++)
    {

        long num;
        char name[NAME_LEN];
        ;
        float score[COURSE_NUM], sum, aver;
        fscanf(fp, "%10ld", &num);
        fscanf(fp, "%10s", name);
        for (j = 0; j < *m; j++)
        {
            fscanf(fp, "%10f", &score[j]);
        }
        fscanf(fp, "%10f%10f", &sum, &aver);
        AppendNode(head, num, name, score, *m, sum, aver);
    }
    *first = 0; // �޸ı�־����
    // �ر��ļ�
    fclose(fp);
    SetConsoleOutputCP(936);
    printf("���ݴӴ��̶�ȡ��ϣ�");
    return 0;
}

/*
  �������ܣ� ����ѧ����¼1~����ѧ����¼
  ��ʽ������ n�� int * , m:int�� stu: STU *
  ��������ֵ��int(����1���������ļ�ʧ�ܣ�����0�������ɹ��Ӵ��̶������ݣ�
*/
void AppendRecord(int *n, int m, Node *head)
{
    int i, j;
    int num_record;
    SetConsoleOutputCP(936);
    printf("��������Ҫ���ӵ�ѧ����¼������");
    scanf("%d", &num_record);
    while (*n + num_record > STU_NUM)
    {
        SetConsoleOutputCP(936);
        printf("Ҫ���ӵļ�¼����̫�࣬���������룺");
        scanf("%d", &num_record);
    }
    Node *temp = head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    for (int i = 0; i < num_record; i++)
    {
        float num;
        char name[NAME_LEN];
        ;
        float score[COURSE_NUM];
        {
            SetConsoleOutputCP(936);
            printf("�����%d��ѧ����Ϣ:\t", i + 1);
            scanf("%ld%s", &num, name);
            for (j = 0; j < m; j++)
            {
                scanf("%f", &score[j]);
            }
        }
        AppendNode(temp, num, name, score, m, 0.0, 0.0);
    }
    *n = *n + num_record;
    SetConsoleOutputCP(936);
    printf("�����ϣ�\n");
    return;
}

/*
  �������ܣ� ��ѧ�Ų���ѧ����¼
  ��ʽ������ n, m: int�� stu: STU *
  ��������ֵ��void
*/
void SearchByNumber(int n, int m, Node *head)
{
    long id;
    int i, j;
    SetConsoleOutputCP(936);
    printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
    scanf("%ld", &id);
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data.num == id)
        {
            SetConsoleOutputCP(936);
            printf("�ҵ��ˣ���ѧ�Ŷ�Ӧ��ѧ����ϢΪ��\n");
            printf("%10ld%15s", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", temp->data.score[j]);
            }
            printf("%10.2f%10.2f", temp->data.sum, temp->data.aver);
            return;
        }
        temp = temp->next;
    }
    SetConsoleOutputCP(936);
    printf("û���ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
    return;
}
/*
  �������ܣ� ����������ѧ����¼
  ��ʽ������ n, m: int�� stu: STU *
  ��������ֵ��void
*/
void SearchByName(int n, int m, Node *head)
{
    int flag = 1;
    int i, j;
    int k = 0;
    char name[NAME_LEN];
    printf("��������Ҫ���ҵ�ѧ����������");
    scanf("%s", name);
    Node *temp = head->next;
    while (temp != NULL)

    {
        if (strcmp(temp->data.name, name) == 0)
        {
            printf("�ҵ��ˣ���%dѧ����ϢΪ��\n", ++k);
            printf("%10ld%15s", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", temp->data.score[j]);
            }
            printf("%10.2f%10.2f\n", temp->data.sum, temp->data.aver);
            flag = 0;
        }
        temp = temp->next;
    }
    if (flag)
    {
        printf("û���ҵ����������Ӧ��ѧ����¼\n");
    }
    return;
}
/*
  �������ܣ� ɾ��ָ��ѧ�ŵ�ѧ����¼
  ��ʽ������ n��int*�� m: int�� stu: STU *
  ��������ֵ��void
*/
void DeleteRecord(int *n, int m, Node *head)
{
    int i, j;
    long id;
    char ch;
    SetConsoleOutputCP(936);
    printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
    scanf("%ld", &id);
    Node *temp = head->next;
    Node *prev = NULL;
    while (temp != NULL && temp->data.num != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("û���ҵ�������¼!\n");
        return;
    }
    if (prev == NULL)
    {
        head = temp->next;
        return;
    }

    else
    {
        SetConsoleOutputCP(936);
        printf("�ҵ��˸�ѧ���ļ�¼����ϢΪ��\n");
        printf("%10ld%15s", temp->data.num, temp->data.name);
        for (j = 0; j < m; j++)
        {
            printf("%10.2f", temp->data.score[j]);
        }
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("��ȷ���Ƿ�Ҫɾ��������¼��(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        // ѡ��
        if (ch == 'Y' || ch == 'y')
        {
            prev->next = temp->next;
            free(temp);
            SetConsoleOutputCP(936);
            printf("ɾ�����\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("�ҵ������ѧ���ļ�¼������ɾ��\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("�������\n");
            return;
        }
    }
}

/*
  �������ܣ� �޸�ָ��ѧ�ŵ�ѧ����¼
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void ModifyRecord(int n, int m, Node *head)
{
    int i, j;
    long id;
    char ch;

    SetConsoleOutputCP(936);
    printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ��:");
    scanf("%ld", &id);
    Node *temp = head->next;
    while (temp != NULL)
    {

        if (temp->data.num == id)
        {
            SetConsoleOutputCP(936);
            printf("�ҵ��˸�ѧ���ļ�¼����ϢΪ:\n");
            printf("%10ld%15s", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", temp->data.score[j]);
            }
            printf("%10.2f%10.2f\n");

            SetConsoleOutputCP(936);
            printf("��ȷ���Ƿ���Ҫ�޸ģ�(Y/N��y/n):");
            getchar();
            scanf("%c", &ch);

            if (ch == 'Y' || ch == 'y')
            {
                SetConsoleOutputCP(936);
                printf("������Ҫ�޸ĵ�ѧ����Ϣ:");
                scanf("%ld%s", &temp->data.num, temp->data.name);
                temp->data.sum = 0;
                for (j = 0; j < m; j++)
                {
                    scanf("%f", temp->data.score[j]);
                    temp->data.sum += temp->data.score[j];
                }
                temp->data.aver = temp->data.sum / m;
                SetConsoleOutputCP(936);
                printf("�޸����\n");
                return;
            }

            else if (ch == 'N' || ch == 'n')
            {
                SetConsoleOutputCP(936);
                printf("�ҵ��˸�ѧ����¼�������޸�\n");
                return;
            }

            else
            {
                SetConsoleOutputCP(936);
                printf("�������\n");
                return;
            }
        }
    }
    SetConsoleOutputCP(936);
    printf("û���ҵ����ѧ���ļ�¼!\n");
    return;
}

/*
  �������ܣ� �������ѧ����¼
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void PrintRecord(int n, int m, Node *head)
{
    int i, j;
    SetConsoleOutputCP(936);
    printf("ѧ��\t\t����\t\t");
    for (j = 0; j < m; j++)
    {
        printf("�γ�%d\t\t", j + 1);
    }
    printf("�ܷ�\t\tƽ����\n");
    Node *temp = head->next;
    while (temp != NULL)
    {
        printf("%-16ld%-16s", temp->data.num, temp->data.name);

        for (j = 0; j < m; j++)
        {
            printf("%-16.1lf", temp->data.score[j]);
        }
        printf("%-16.1lf%-16.1lf\n", temp->data.sum, temp->data.aver);
        temp = temp->next;
    }
    return;
}

/*
  �������ܣ� ����ѧ�������ֵ�˳�������ѧ����¼��С��������
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void SortbyName(Node *head)
{
    Node *i, *j;
    STU temp;
    for (i = head->next; i->next->next != NULL; i = i->next)
    {
        for (j = i->next; j->next != NULL; j = j->next)
        {
            if (strcmp(j->data.name, j->next->data.name))
            {
                // ����ѧ������
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    SetConsoleOutputCP(936);
    printf("�������ֵ��ѧ����¼�������");
    return;
}
/*
  �������ܣ� ����ѧ�Ŷ�����ѧ����¼��С��������
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void SortbyNum(Node *head)
{
    Node *i, *j, *k;
    STU temp;

    for (i = head->next; i != NULL; i = i->next)
    {
        k = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data.num < k->data.num)
                k = j;
        }
        if (k != i)
        {
            temp = k->data;
            k->data = i->data;
            i->data = temp;
        }
    }
    SetConsoleOutputCP(936);
    printf("��ѧ�Ŵ�С�����ѧ����¼�������");
}

/*
  �������ܣ� ����ѧ���ɼ��ֶܷ�����ѧ����¼�����������
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void SortbyScore(Node *head, int (*compare)(float a, float b))
{

    Node *i, *j, *k;
    STU temp;

    for (i = head->next; i != NULL; i = i->next)
    {
        k = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if ((*compare)(j->data.sum, k->data.sum))
                k = j;
        }
        if (k != i)
        {
            temp = k->data;
            k->data = i->data;
            i->data = temp;
        }
    }
    SetConsoleOutputCP(936);
    printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������");
}

/*
  �������ܣ� �涨�����������
  ��ʽ������ a,b: float
  ��������ֵ��int
*/
int Descending(float a, float b)
{
    return a > b;
}

/*
  �������ܣ� �涨�����������
  ��ʽ������ a,b: float
  ��������ֵ��int
*/
int Ascending(float a, float b)
{
    return a < b;
}

/*
  �������ܣ� ͳ�Ʋ��������������ѧ��������ռ��
  ��ʽ������ n��m: int�� stu: STU *
  ��������ֵ��void
*/
void StatisticAnalysis(int n, int m, Node *head)
{
    int i, j, t[6];
    Node *temp = head->next;
    for (j = 0; j < m; j++)
    {
        SetConsoleOutputCP(936);
        printf("\n�γ�%d�ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
        printf("������\t����\tռ��\n");

        memset(t, 0, sizeof(t));
        while (temp != NULL)
        {
            if (temp->data.score[j] >= 0 && temp->data.score[j] < 60)
                t[0]++;
            else if (temp->data.score[j] < 70)
                t[1]++;
            else if (temp->data.score[j] < 80)
                t[2]++;
            else if (temp->data.score[j] < 90)
                t[3]++;
            else if (temp->data.score[j] < 100)
                t[4]++;
            else if (temp->data.score[j] == 100)
                t[5]++;
            temp = temp->next;
        }

        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
                printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
            else if (i == 5)
                printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
            else
                printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
        }
    }
    SetConsoleOutputCP(936);
    printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
    printf("������\t����\tռ��\n");
    memset(t, 0, sizeof(t));
    Node *temp2 = head->next;
    while (temp2 != NULL)
    {
        if (temp2->data.aver >= 0 && temp2->data.aver < 60)
            t[0]++;
        else if (temp2->data.aver < 70)
            t[1]++;
        else if (temp2->data.aver < 80)
            t[2]++;
        else if (temp2->data.aver < 90)
            t[3]++;
        else if (temp2->data.aver < 100)
            t[4]++;
        else if (temp2->data.aver == 100)
            t[5]++;
        temp2 = temp2->next;
    }
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
            printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
        else if (i == 5)
            printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
        else
            printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
    }
}
