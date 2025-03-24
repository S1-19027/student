#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
/*
  函数功能： 创建一个空链表
  形式参数： 无
  函数返回：Node类型的指针
*/
Node *ListCreate()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
        newNode->next = NULL;
    return newNode;
}
/*
  函数功能： 建立一个结点
  形式参数： 学号，姓名，分数，课程数，总分和平均分
  函数返回值：Node类型的指针
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
  函数功能： 添加一个结点
  形式参数： 头节点，学号，姓名，分数，课程数，总分和平均分
  函数返回值：无
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
        while (temp->next != NULL) // 找到尾节点
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
/*
  函数功能：清空链表
  形式参数： 头节点
  函数返回值：无
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
  函数功能： 显示系统主菜单， 获取键盘用户输入的操作选项，并返回给主函数
  形式参数： 无
  函数返回值：用户键盘输入的选项，int型
*/
int Menu(void)
{
    int posy = 5;
    int option; // 保存用户输入的操作代号的变量
    int i, j;
    SetPosition(POS_X3, posy);
    SetConsoleOutputCP(936);
    printf("学生成绩管理系统\n"); // 输出系统名
    // 输出系统名和功能说明之间的两行短横线
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // 输出系统支持的功能和对应的功能代号
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, ++posy);
    SetConsoleOutputCP(936);
    printf("1.输入学生信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("2.增加学生成绩");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("3.删除学生信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("4.按学号查找记录");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("5.按姓名查找记录");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("6.修改学生信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("7.计算学生成绩");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("8.计算课程成绩");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("9.按学号排序");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("10.按姓名排序");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("11.按总成绩降序排序");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("12.按总成绩升序排序");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("13.学生成绩统计");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("14.打印学生记录");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("15.学生记录存盘");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("16.从磁盘读取学生记录");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("0.退出");
    // 输出系统支持的功能与输入提示语之间的两行短横线
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // 提示用户输入所要执行的功能代号
    SetPosition(POS_X1, ++posy);
    printf("请选择你想要进行的操作[0~16]: [  ]\b\b\b");
    scanf("%d", &option);
    return option;
}

/*
  函数功能： 设置文字输出的起始位置
  形式参数： 文字输出起始位置的坐标x,y，int 类型
  函数返回值：void
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
  函数功能： 输入学生信息
  形式参数： n,m: int *, stu: STU *
  函数返回值：void
*/
void InputRecord(int *n, int *m, Node *head)
{
    int i, j;
    int posy = 6;
    SetConsoleOutputCP(936);
    SetPosition(POS_X2, posy); // 设置光标位置，即需要显示的位置
    printf("输入学生人数(n<%d):", STU_NUM);
    scanf("%d", n);
    SetConsoleOutputCP(936);
    SetPosition(POS_X2, posy += 2); // 设置光标位置，即需要显示的位置
    printf("输入课程数(m<%d):", COURSE_NUM);
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
    printf("输入学生学号、姓名和各个科目的成绩:");
    for (i = 0; i < *n; i++)
    {
        SetConsoleOutputCP(936);
        SetPosition(POS_X2, ++posy);
        printf("输入第%d个学生信息:\t", i + 1);
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
  函数功能： 计算学生成绩
  形式参数： n,m: int , stu: STU *
  函数返回值：void
*/
void CalculateScoreOfStudent(int m, Node *head)
{
    SetConsoleOutputCP(936);
    printf("每个学生各门课程的总分和平均分为：\n");
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
        printf("第%d个学生：总分=%.2f, 平均分=%.2f\n", i + 1, temp->data.sum, temp->data.aver);
        i += 1;
        temp = temp->next;
    }
}

/*
  函数功能： 计算课程成绩
  形式参数： n,m: int , stu: STU *
  函数返回值：void
*/
void CalculateScoreOfCourse(int n, int m, Node *head)
{
    int i, j;
    float sum[COURSE_NUM], aver[COURSE_NUM];
    int posy = 7;
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, posy);
    printf("各门课程总分和平均分的计算结果为：");

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
        printf("第%d门课程: 总分 = %.2f, 平均分 = %.2f\n", j + 1, sum[j], aver[j]);
    }
}
/*
  函数功能： 输出学生人数n,课程数m,以及每个学生信息到student.txt中
  形式参数： n,m: int , stu: STU *
  函数返回值：void
*/
void WritetoFile(int n, int m, Node *head)
{
    int i, j;
    // 定义文件指针
    FILE *fp;
    // 打开文件，指定对文件的处理方式为写入，并让指针指向文件
    if ((fp = fopen("student.txt", "w")) == NULL)
    {
        SetConsoleOutputCP(936);
        printf("文件student.txt无法正常打开！");
        exit(0);
    }
    // 将数据按指定格式写入文件，包括学生数n,课程门数m，每位学生的信息
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
    // 关闭文件
    fclose(fp);
    // 提示用户存盘操作完毕
    SetConsoleOutputCP(936);
    printf("存盘完毕！\n");
}

/*
  函数功能： 从已有的磁盘文件student.txt中，读出学生人数,课程数,以及每个学生信息到内存中对应
             变量n, m和结构体数组stu中，并将标志变量first的值清0
  形式参数： n,m, first: int * , stu: STU *
  函数返回值：int(返回1，表明打开文件失败，返回0，表明成功从磁盘读出数据）
*/
int ReadfromFile(int *n, int *m, Node *head, int *first)
{
    // 定义文件指针
    FILE *fp;
    int i, j;
    int posy = 8;
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, posy);
    // 打开文件，指定对文件的处理方式为写入，并让指针指向文件
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        SetConsoleOutputCP(936);
        printf("磁盘文件student.txt无法打开");
        return 1;
    }
    // 将数据按指定格式从磁盘文件读出，包括学生数n,课程门数m，每位学生的信息
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
    *first = 0; // 修改标志变量
    // 关闭文件
    fclose(fp);
    SetConsoleOutputCP(936);
    printf("数据从磁盘读取完毕！");
    return 0;
}

/*
  函数功能： 增加学生记录1~多条学生记录
  形式参数： n： int * , m:int， stu: STU *
  函数返回值：int(返回1，表明打开文件失败，返回0，表明成功从磁盘读出数据）
*/
void AppendRecord(int *n, int m, Node *head)
{
    int i, j;
    int num_record;
    SetConsoleOutputCP(936);
    printf("请输入需要增加的学生记录条数：");
    scanf("%d", &num_record);
    while (*n + num_record > STU_NUM)
    {
        SetConsoleOutputCP(936);
        printf("要增加的记录条数太多，请重新输入：");
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
            printf("输入第%d个学生信息:\t", i + 1);
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
    printf("添加完毕！\n");
    return;
}

/*
  函数功能： 按学号查找学生记录
  形式参数： n, m: int， stu: STU *
  函数返回值：void
*/
void SearchByNumber(int n, int m, Node *head)
{
    long id;
    int i, j;
    SetConsoleOutputCP(936);
    printf("请输入你要查找的学生的学号：");
    scanf("%ld", &id);
    Node *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data.num == id)
        {
            SetConsoleOutputCP(936);
            printf("找到了，该学号对应的学生信息为：\n");
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
    printf("没有找到这个学号对应的学生记录\n");
    return;
}
/*
  函数功能： 按姓名查找学生记录
  形式参数： n, m: int， stu: STU *
  函数返回值：void
*/
void SearchByName(int n, int m, Node *head)
{
    int flag = 1;
    int i, j;
    int k = 0;
    char name[NAME_LEN];
    printf("请输入你要查找的学生的姓名：");
    scanf("%s", name);
    Node *temp = head->next;
    while (temp != NULL)

    {
        if (strcmp(temp->data.name, name) == 0)
        {
            printf("找到了，第%d学生信息为：\n", ++k);
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
        printf("没有找到这个姓名对应的学生记录\n");
    }
    return;
}
/*
  函数功能： 删除指定学号的学生记录
  形式参数： n：int*， m: int， stu: STU *
  函数返回值：void
*/
void DeleteRecord(int *n, int m, Node *head)
{
    int i, j;
    long id;
    char ch;
    SetConsoleOutputCP(936);
    printf("请输入你要删除学生信息对应的学号：");
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
        printf("没有找到该生记录!\n");
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
        printf("找到了该学生的记录，信息为：\n");
        printf("%10ld%15s", temp->data.num, temp->data.name);
        for (j = 0; j < m; j++)
        {
            printf("%10.2f", temp->data.score[j]);
        }
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("请确认是否要删除这条记录？(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        // 选择
        if (ch == 'Y' || ch == 'y')
        {
            prev->next = temp->next;
            free(temp);
            SetConsoleOutputCP(936);
            printf("删除完毕\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("找到了这个学生的记录，但不删除\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入出错\n");
            return;
        }
    }
}

/*
  函数功能： 修改指定学号的学生记录
  形式参数： n，m: int， stu: STU *
  函数返回值：void
*/
void ModifyRecord(int n, int m, Node *head)
{
    int i, j;
    long id;
    char ch;

    SetConsoleOutputCP(936);
    printf("请输入需要修改信息对应的学号:");
    scanf("%ld", &id);
    Node *temp = head->next;
    while (temp != NULL)
    {

        if (temp->data.num == id)
        {
            SetConsoleOutputCP(936);
            printf("找到了该学生的记录，信息为:\n");
            printf("%10ld%15s", temp->data.num, temp->data.name);
            for (j = 0; j < m; j++)
            {
                printf("%10.2f", temp->data.score[j]);
            }
            printf("%10.2f%10.2f\n");

            SetConsoleOutputCP(936);
            printf("请确认是否需要修改？(Y/N或y/n):");
            getchar();
            scanf("%c", &ch);

            if (ch == 'Y' || ch == 'y')
            {
                SetConsoleOutputCP(936);
                printf("请输入要修改的学生信息:");
                scanf("%ld%s", &temp->data.num, temp->data.name);
                temp->data.sum = 0;
                for (j = 0; j < m; j++)
                {
                    scanf("%f", temp->data.score[j]);
                    temp->data.sum += temp->data.score[j];
                }
                temp->data.aver = temp->data.sum / m;
                SetConsoleOutputCP(936);
                printf("修改完毕\n");
                return;
            }

            else if (ch == 'N' || ch == 'n')
            {
                SetConsoleOutputCP(936);
                printf("找到了该学生记录，但不修改\n");
                return;
            }

            else
            {
                SetConsoleOutputCP(936);
                printf("输入出错！\n");
                return;
            }
        }
    }
    SetConsoleOutputCP(936);
    printf("没有找到这个学生的记录!\n");
    return;
}

/*
  函数功能： 输出所有学生记录
  形式参数： n，m: int， stu: STU *
  函数返回值：void
*/
void PrintRecord(int n, int m, Node *head)
{
    int i, j;
    SetConsoleOutputCP(936);
    printf("学号\t\t姓名\t\t");
    for (j = 0; j < m; j++)
    {
        printf("课程%d\t\t", j + 1);
    }
    printf("总分\t\t平均分\n");
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
  函数功能： 按照学生姓名字典顺序对所有学生记录从小到大排序
  形式参数： n，m: int， stu: STU *
  函数返回值：void
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
                // 交换学生数据
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
    SetConsoleOutputCP(936);
    printf("按姓名字典对学生记录排序完毕");
    return;
}
/*
  函数功能： 按照学号对所有学生记录从小到大排序
  形式参数： n，m: int， stu: STU *
  函数返回值：void
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
    printf("按学号从小到大对学生记录排序完毕");
}

/*
  函数功能： 按照学生成绩总分对所有学生记录升序或降序排序
  形式参数： n，m: int， stu: STU *
  函数返回值：void
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
    printf("按学生成绩总分对学生记录排序完毕");
}

/*
  函数功能： 规定降序排序规则
  形式参数： a,b: float
  函数返回值：int
*/
int Descending(float a, float b)
{
    return a > b;
}

/*
  函数功能： 规定升序排序规则
  形式参数： a,b: float
  函数返回值：int
*/
int Ascending(float a, float b)
{
    return a < b;
}

/*
  函数功能： 统计并输出各个分数段学生人数及占比
  形式参数： n，m: int， stu: STU *
  函数返回值：void
*/
void StatisticAnalysis(int n, int m, Node *head)
{
    int i, j, t[6];
    Node *temp = head->next;
    for (j = 0; j < m; j++)
    {
        SetConsoleOutputCP(936);
        printf("\n课程%d成绩统计结果为：\n", j + 1);
        printf("分数段\t人数\t占比\n");

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
    printf("\n学生成绩平均分统计结果为：\n");
    printf("分数段\t人数\t占比\n");
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
