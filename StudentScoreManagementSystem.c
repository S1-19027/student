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
#define STU_NUM 50      //教学班学生人数上限
#define COURSE_NUM 10   //一学期的课程上限
#define NAME_LEN 10     //学生姓名（字符串）最大长度
#define POS_X1 35       //1、菜单页，第一列所有功能输出起始位置的x坐标值；2、排序之后输出提示起点的X坐标值
#define POS_X2 40       //输入模块的提示语句起点的X坐标值
#define POS_X3 50       //第一次，调用输入模块或磁盘数据读入模块功能以外的其他功能，提示“系统中尚无学生成绩信息，请先输入”的起始位置的X坐标值
#define POS_X4 65       //菜单页，第二列所有功能输出起始位置的x坐标值；
#define POS_Y 3        //排序之后输出提示起点的Y坐标值

//结构体类型定义
typedef struct student
{
    long num;                       //学号
    char name[NAME_LEN];            //姓名
    float score[COURSE_NUM];        //每门课程成绩
    float sum;                      //总分
    float aver;                     //平均分
    struct student *next;     //指向下一个节点
}STU;


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
  函数功能： 显示系统主菜单， 获取键盘用户输入的操作选项，并返回给主函数
  形式参数： 无
  函数返回值：用户键盘输入的选项，int型
*/
int Menu(void)
{
    int posy = 5;
    int option;                         //保存用户输入的操作代号的变量
    int i,j;
    SetPosition(POS_X3,posy);
    printf("老师版本学生管理系统\n");      //输出系统名
    //输出系统名和功能说明之间的两行短横线
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //输出系统支持的功能和对应的功能代号
    SetPosition(POS_X1,++posy);
    printf("1.输入学生信息");
    SetPosition(POS_X4,posy);
    printf("2.增加学生成绩");
    SetPosition(POS_X1,posy+=2);
    printf("3.删除学生信息");
    SetPosition(POS_X4,posy);
    printf("4.按学号查找记录");
    SetPosition(POS_X1,posy+=2);
    printf("5.按姓名查找记录");
    SetPosition(POS_X4,posy);
    printf("6.修改学生信息");
    SetPosition(POS_X1,posy+=2);
    printf("7.计算学生成绩");
    SetPosition(POS_X4,posy);
    printf("8.计算课程成绩");
    SetPosition(POS_X1,posy+=2);
    printf("9.按学号排序");
    SetPosition(POS_X4,posy);
    printf("10.按姓名排序");
    SetPosition(POS_X1,posy+=2);
    printf("11.按总成绩降序排序");
    SetPosition(POS_X4,posy);
    printf("12.按总成绩升序排序");
    SetPosition(POS_X1,posy+=2);
    printf("13.学生成绩统计");
    SetPosition(POS_X4,posy);
    printf("14.打印学生记录");
    SetPosition(POS_X1,posy+=2);
    printf("15.学生记录存盘");
    SetPosition(POS_X4,posy);
    printf("16.从磁盘读取学生记录");
    SetPosition(POS_X1,posy+=2);
    printf("0.退出");
    //输出系统支持的功能与输入提示语之间的两行短横线
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    //提示用户输入所要执行的功能代号
    SetPosition(POS_X1,++posy);
    printf("请选择你想要进行的操作[0~16]: [  ]\b\b\b");
    scanf("%d",&option);
    return option;
}


/*
  函数功能： 输入学生信息
  形式参数： n,m: int *
*/
STU * Create(int *n,int *m)
{
    STU *pnew,*ptail,*head=NULL;
    int i,j;
    int posy = 6;
    SetPosition(POS_X2,posy);              //设置光标位置，即需要显示的位置
    printf("输入学生人数(n<%d):", STU_NUM);
    scanf("%d",n);
    SetPosition(POS_X2,posy += 2);         //设置光标位置，即需要显示的位置
    printf("输入课程数(m<%d):", COURSE_NUM);
    scanf("%d",m);
    for(i=0; i<2; i++)
    {
        SetPosition(POS_X1,++posy);
        for(j=0; j<55; j++)
        {
            printf("-");
        }
    }
    SetPosition(POS_X2,++posy);
    printf("输入学生学号、姓名和各个科目的成绩:");
    SetPosition(POS_X2,++posy);
    printf("输入第1个学生信息:\t");
    pnew=(STU*)malloc(sizeof(STU));
    scanf("%ld%s",&pnew->num,pnew->name);
    for(i=0; i<*m; i++)
    {
        scanf("%f",&pnew->score[i]);
    }
    head=pnew;
    ptail=pnew;
    for(i=1; i<*n; i++)
    {
        pnew=(STU*)malloc(sizeof(STU));
        SetPosition(POS_X2,++posy);
        printf("输入第%d个学生信息:\t",i+1);
        scanf("%ld%s",&pnew->num, pnew->name);
        for(j=0; j<*m; j++)
        {
            scanf("%f",&pnew->score[j]);
        }
        ptail->next=pnew;
        ptail=pnew;
    }
    ptail->next=NULL;
    return head;
}


/*
  函数功能： 计算学生成绩
  形式参数： n,m: int , head: STU *
  函数返回值：void
*/
void CalculateScoreOfStudent(int n, int m, STU *head)
{
    STU *temp;
    temp=head;
    int i,j;
    printf("每个学生各门课程的总分和平均分为：\n");
    while(temp!=NULL)
    {
        temp->sum = 0;
        for(j=0; j<m; j++)
        {
            temp->sum += temp->score[j];
        }
        temp->aver = temp->sum/m;
        printf("第%d个学生：总分=%.2f, 平均分=%.2f\n", i+1,temp->sum, temp->aver);
        temp=temp->next;
        i++;
    }
}


/*
  函数功能： 计算课程成绩
  形式参数： n,m: int , head: STU *
  函数返回值：void
*/
void CalculateScoreOfCourse(int n, int m, STU *head)
{
    int i,j;
    STU *temp;
    float sum[COURSE_NUM], aver[COURSE_NUM];
    int posy = 7;
    SetPosition(POS_X1,posy);
    printf("各门课程总分和平均分的计算结果为：");
    for(j=0; j<m; j++)
    {
        temp=head;
        sum[j] = 0;
        while(temp!=NULL)
        {   sum[j] += temp->score[j];
            temp=temp->next;
        }
        aver[j]= sum[j]/n;
        SetPosition(POS_X1,++posy);
        printf("第%d门课程: 总分 = %.2f, 平均分 = %.2f\n", j+1,sum[j], aver[j]);
    }
}



/*
  函数功能： 输出学生人数n,课程数m,以及每个学生信息到student.txt中
  形式参数： n,m: int , head: STU *
  函数返回值：void
*/
void WritetoFile(int n,int m, STU *head)
{
    STU* temp=head;
    int i, j;
    //定义文件指针
    FILE *fp;
    //打开文件，指定对文件的处理方式为写入，并让指针指向文件
    if((fp=fopen("C:\\Users\\32227\\Desktop\\StudentScoreManage-mentSystem\\student.txt","w"))==NULL)
    {
        printf("文件student.txt无法正常打开！");
        exit(0);
    }
    //将数据按指定格式写入文件，包括学生数n,课程门数m，每位学生的信息
    fprintf(fp,"%10d%10d\n",n,m);
    while(temp!=NULL)
    {
        fprintf(fp,"%10ld%10s\n",temp->num,temp->name);
        for(j=0; j<m; j++)
        {
            fprintf(fp,"%10.1f",temp->score[j]);
        }
        fprintf(fp,"%10.1f%10.1f\n",temp->sum,temp->aver);
        temp=temp->next;
    }
    //关闭文件
    fclose(fp);
    //提示用户存盘操作完毕
    printf("存盘完毕！\n");
}
/*
  函数功能： 从已有的磁盘文件student.txt中，读出学生人数,课程数,以及每个学生信息到内存中对应
             变量n, m和结构体数组stu中，并将标志变量first的值清0
  形式参数： n,m, first: int * , head: STU *
  函数返回值：int(返回1，表明打开文件失败，返回0，表明成功从磁盘读出数据）
*/
int ReadfromFile(int *n, int *m, STU *head, int *first)
{
    STU *temp=head;
	FILE *fp; //定义文件指针
    int i,j;
    int posy = 8;
    SetPosition(POS_X1,posy);
    //打开文件，指定对文件的处理方式为读出，并让指针指向文件
    if((fp=fopen("C:\\Users\\32227\\Desktop\\StudentScoreManage-mentSystem\\student.txt","r"))==NULL)
    {
        printf("磁盘文件student.txt无法打开");
        return 1;
    }
    //将数据按指定格式从磁盘文件读出，包括学生数n,课程门数m，每位学生的信息
    fscanf(fp,"%10d%10d",n,m);
    printf("%10d%10d\n",*n,*m);
    while(temp!=NULL)
    {
        fscanf(fp,"%10ld",&temp->num);
        printf("%10ld",temp->num);
        fscanf(fp,"%10s",temp->name);
        printf("%10s",temp->name);
        for(j=0; j<*m; j++)
        {
            fscanf(fp, "%10f", &temp->score[j]);
            printf("%10f", temp->score[j]);
        }
        fscanf(fp, "%10f%10f",&temp->sum, &temp->aver);
        printf("%10f%10f\n",temp->sum, temp->aver);
        temp=temp->next;
    }
    *first = 0;  //修改标志变量
	//关闭文件
    fclose(fp);
    printf("数据从磁盘读取完毕！");
    return 0;
}
/*
  函数功能： 增加学生记录1~多条学生记录
  形式参数： n： int * , m:int， ptail: STU *
  函数返回值：int(返回1，表明打开文件失败，返回0，表明成功从磁盘读出数据）
*/
void AppendRecord(int* n, int m, STU *head)
{
    STU *pnew=head,*pt,*pnew1;
    while(pnew!=NULL){
        pt=pnew;
        pnew=pnew->next;
    }
    int i,j;
    int num_record;
    printf("请输入需要增加的学生记录条数：");
    scanf("%d",&num_record);
    while(*n+num_record>STU_NUM)
    {
        printf("要增加的记录条数太多，请重新输入：");
        scanf("%d",&num_record);
    }
    for(i=*n; i<*n+num_record; i++)
    {
        pnew1=(STU*)malloc(sizeof(STU));
        printf("输入第%d个学生信息:\t",i+1);
        scanf("%ld%s",&pnew1->num, pnew1->name);
        for(j=0; j<m; j++)
        {
            scanf("%f",&pnew1->score[j]);
        }
        pt->next=pnew1;
        pt=pnew1;
    }
    pt->next=NULL;
    *n = *n + num_record;
    printf("添加完毕！\n");
}
/*
  函数功能： 按学号查找学生记录
  形式参数： n, m: int， head: STU *
  函数返回值：void
*/
void SearchByNumber(int n, int m, STU *head)
{
    int flag1;
    STU *temp=head;
    long id;
    int i, j;
    printf("请输入你要查找的学生的学号：");
    scanf("%ld",&id);
    while(temp!=NULL)
    {
        flag1=0;
        if(temp->num==id)
        {
            printf("找到了，该学号对应的学生信息为：\n");
            printf("%10ld%15s",temp->num,temp->name);
            for(j=0; j<m; j++)
            {
                if(temp->score[j]<60){
                    					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
printf("%10.2f",temp->score[j]);                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                    flag1=1;
                }
                else
                    printf("%10.2f",temp->score[j]);

            }
            printf("%10.2f%10.2f", temp->sum,temp->aver);
            if(flag1==1)
                printf("\n\t\t*****有科目不及格，请准备补考！！*****\n");
            return;
        }
        temp=temp->next;
    }
    printf("没有找到这个学号对应的学生记录\n");
    return;
}
/*
  函数功能： 按姓名查找学生记录
  形式参数： n, m: int， head: STU *
  函数返回值：void
*/
void SearchByName(int n, int m, STU *head)
{
    STU*temp=head;
    int flag = 1;
    int i, j;
    int k = 0;
    char name[NAME_LEN];
    printf("请输入你要查找的学生的姓名：");
    scanf("%s",name);
    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            printf("找到了，第%d学生信息为：\n",++k);
            printf("%10ld%15s",temp->num,temp->name);
            for(j=0; j<m; j++)
        {

            if(temp->score[j]<60){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("%10.2f",temp->score[j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
            }
            else
                printf("%10.2f",temp->score[j]);

        }
            printf("%10.2f%10.2f\n", temp->sum,temp->aver);
            flag = 0;
        }
        temp=temp->next;
    }
    if(flag)
    {
        printf("没有找到这个姓名对应的学生记录\n");
    }
    return;
}
/*
  函数功能： 删除指定学号的学生记录
  形式参数： n：int*， m: int， head: STU *
  函数返回值：void
*/
STU * DeleteRecord(int* n, int m, STU *head)   {
    STU *temp=head;
    STU *last;
    int i, j;
    long id;
    char ch;
    printf("请输入你要删除学生信息对应的学号：");
    scanf("%ld",&id);
    if(head->num == id)
        {
            printf("找到了该学生的记录，信息为：\n");
            printf("%10ld%15s",head->num,head->name);
            for(j=0; j<m; j++)
            {
                printf("%10.2f",head->score[j]);
            }
            printf("%10.2f%10.2f\n", head->sum,head->aver);
            printf("请确认是否要删除这条记录？(Y/y, N/n):");
            getchar();
            scanf("%c",&ch);
            if(ch=='Y'||ch=='y')
            {
                head=head->next;
                free(temp);
                temp=head;
                (*n)--;
                printf("删除完毕\n");
                return head;
            }
            else if(ch=='N'||ch=='n')
            {
                printf("找到了这个学生的记录，但不删除\n");
                return head;
            }
            else
            {
                printf("输入出错\n");
                return head;
            }
        }
    temp=head->next;
    last=head;
    while(temp!=NULL)
    {
        if(temp->num == id)
        {
            printf("找到了该学生的记录，信息为：\n");
            printf("%10ld%15s",temp->num,temp->name);
            for(j=0; j<m; j++)
            {
                printf("%10.2f",temp->score[j]);
            }
            printf("%10.2f%10.2f\n", temp->sum,temp->aver);
            printf("请确认是否要删除这条记录？(Y/y, N/n):");
            getchar();
            scanf("%c",&ch);
            if(ch=='Y'||ch=='y')
            {
                last->next=temp->next;
                printf("删除完毕\n");
                return head;
            }
            else if(ch=='N'||ch=='n')
            {
                printf("找到了这个学生的记录，但不删除\n");
                return head;
            }
            else
            {
                printf("输入出错\n");
                return head;
            }
        }
        temp=temp->next;
        last=last->next;
    }
    printf("没有找到该生记录!\n");
    return head;
}
/*
  函数功能： 修改指定学号的学生记录
  形式参数： n，m: int， head: STU *
  函数返回值：void
*/
void ModifyRecord(int n, int m, STU *head)
{
    int i,j;
    long id;
    char ch;
    STU *temp=head;

    printf("请输入需要修改信息对应的学号:");
    scanf("%ld", &id);

    while(temp!=NULL)
    {
        if(temp->num==id)
        {
            printf("找到了该学生的记录，信息为:\n");
            printf("%10ld%15s",temp->num,temp->name);
            for(j=0; j<m; j++)
            {
                printf("%10.2f",temp->score[j]);
            }
            printf("%10.2f%10.2f\n", temp->sum,temp->aver);

            printf("请确认是否需要修改？(Y/N或y/n):");
            getchar();
            scanf("%c", &ch);

            if(ch == 'Y'|| ch == 'y')
            {
                printf("请输入要修改的学生信息:");
                scanf("%ld%s",&temp->num,&temp->name);
                temp->sum = 0;
                for(j=0; j<m; j++)
                {
                    scanf("%f",&temp->score[j]);
                    temp->sum += temp->score[j];
                }
                temp->aver = temp->sum/m;
                printf("修改完毕\n");
                return;
            }

            else if(ch == 'N' || ch == 'n')
            {
                printf("找到了该学生记录，但不修改\n");
                return;
            }

            else
            {
                printf("输入出错！\n");
                return;
            }
        }
        temp=temp->next;
    }
    printf("没有找到这个学生的记录!\n");
    return;
}

/*
  函数功能： 输出所有学生记录
  形式参数： n，m: int， head: STU *
  函数返回值：void
*/
void PrintRecord(int n, int m, STU *head)
{
    int i, j;
    STU *temp=head;
    printf("学号\t\t姓名\t\t");
    for(j=0; j<m; j++)
    {
        printf("课程%d\t\t",j+1);
    }
    printf("总分\t\t平均分\n");

    while(temp!=NULL)
    {
        printf("%-16ld%-16s", temp->num, temp->name);
        for(j=0; j<m; j++)
        {

            if(temp->score[j]<60){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("%-16.1lf",temp->score[j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

            }
            else
                printf("%-16.1lf",temp->score[j]);

        }
        printf("%-16.1lf%-16.1lf\n",temp->sum, temp->aver);
        temp=temp->next;
    }
    return;
}
/*
  函数功能： 按照学生姓名字典顺序对所有学生记录从小到大排序
  形式参数： head: STU *
  函数返回值：void
*/

void SortbyName(STU* head)
{
    if(head == NULL || head->next == NULL)
        return;

    STU* pre ;
    STU* cur ;
    STU tmp;
    // pre->next!=NULL 链表倒数第2个节点
    for(pre=head;pre->next!=NULL;pre=pre->next)
    {
        for(cur=pre->next;cur!=NULL;cur=cur->next)
        {
            if(strcmp(pre->name , cur->name)>0)
            {
                // 交换数据域
                tmp = *cur;
                *cur = *pre;
                *pre = tmp;
                // 交换指针域
                tmp.next = cur->next;
                cur->next = pre->next;
                pre->next = tmp.next;
            }
        }
    }
    printf("按照姓名排序完毕！");
    return ;
}
/*
  函数功能： 按照学号对所有学生记录从小到大排序
  形式参数： n，m: int ，head: STU *
  函数返回值：void
*/
void SortbyNum(int n, int m, STU *head)
{
     if(head == NULL || head->next == NULL)
        return;

    STU* pre ;
    STU* cur ;
    STU tmp;
    // pre->next!=NULL 链表倒数第2个节点
    for(pre=head;pre->next!=NULL;pre=pre->next)
    {
        for(cur=pre->next;cur!=NULL;cur=cur->next)
        {
            if(pre->num > cur->num)
            {
                // 交换数据域
                tmp = *cur;
                *cur = *pre;
                *pre = tmp;
                // 交换指针域
                tmp.next = cur->next;
                cur->next = pre->next;
                pre->next = tmp.next;
            }
        }
    }
    printf("按照学号排序完毕！");
    return ;
}



/*
  函数功能： 按照学生成绩总分对所有学生记录升序排序
  形式参数： n，m: int， stu: STU *
  函数返回值：void
*/
void SortbyScoreA(int n, int m, STU *head)
{
     if(head == NULL || head->next == NULL)
        return;

    STU* pre ;
    STU* cur ;
    STU tmp;
    // pre->next!=NULL 链表倒数第2个节点
    for(pre=head;pre->next!=NULL;pre=pre->next)
    {
        for(cur=pre->next;cur!=NULL;cur=cur->next)
        {
            if(pre->sum > cur->sum)
            {
                // 交换数据域
                tmp = *cur;
                *cur = *pre;
                *pre = tmp;
                // 交换指针域
                tmp.next = cur->next;
                cur->next = pre->next;
                pre->next = tmp.next;
            }
        }
    }
    printf("按照学号升序排序完毕！");
    return ;
}

/*
  函数功能： 按照学生成绩总分对所有学生记录降序排序
  形式参数： n，m: int， head: STU *
  函数返回值：void
*/
void SortbyScoreD(int n, int m, STU *head)
{
    if(head == NULL || head->next == NULL)
        return;

    STU* pre ;
    STU* cur ;
    STU tmp;
    // pre->next!=NULL 链表倒数第2个节点
    for(pre=head;pre->next!=NULL;pre=pre->next)
    {
        for(cur=pre->next;cur!=NULL;cur=cur->next)
        {
            if(pre->sum < cur->sum)
            {
                // 交换数据域
                tmp = *cur;
                *cur = *pre;
                *pre = tmp;
                // 交换指针域
                tmp.next = cur->next;
                cur->next = pre->next;
                pre->next = tmp.next;
            }
        }
    }
    printf("按照学号降序排序完毕！");
    return ;
}




/*
  函数功能： 统计并输出各个分数段学生人数及占比
  形式参数： n，m: int， head: STU *
  函数返回值：void
*/
void StatisticAnalysis(int n, int m, STU *head)
{
    int i, j,t[6];
    STU *temp=head;
    for(j=0; j<m; j++)
    {
        temp=head;
        printf("\n课程%d成绩统计结果为：\n", j+1);
        printf("分数段\t人数\t占比\n");
        memset(t, 0, sizeof(t));
        while(temp!=NULL)
        {
            if(temp->score[j]>=0 && temp->score[j]<60)
                t[0]++;
            else  if(temp->score[j]<70)
                t[1]++;
            else  if(temp->score[j]<80)
                t[2]++;
            else  if(temp->score[j]<90)
                t[3]++;
            else  if(temp->score[j]<100)
                t[4]++;
            else  if(temp->score[j]==100)
                t[5]++;
            temp=temp->next;
        }
        for(i=0; i<6; i++)
        {
            if(i==0)
                printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i]/n*100);
            else if(i==5)
                printf("100\t%d\t%.2f%%\n", t[i], (float)t[i]/n*100);
            else
                printf("%d-%d\t%d\t%.2f%%\n", (i+5)*10, (i+5)*10+9, t[i], (float)t[i]/n*100);

        }
    }


    printf("\n学生成绩平均分统计结果为：\n");
    printf("分数段\t人数\t占比\n");
    memset(t, 0, sizeof(t));
    temp=head;
    while(temp!=NULL)
    {
        if(temp->aver>=0 && temp->aver<60)
            t[0]++;
        else  if(temp->aver<70)
            t[1]++;
        else  if(temp->aver<80)
            t[2]++;
        else  if(temp->aver<90)
            t[3]++;
        else  if(temp->aver<100)
            t[4]++;
        else  if(temp->aver==100)
            t[5]++;
        temp=temp->next;
    }
    for(i=0; i<6; i++)
    {
        if(i==0)
            printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i]/n*100);
        else if(i==5)
            printf("100\t%d\t%.2f%%\n", t[i], (float)t[i]/n*100);
        else
            printf("%d-%d\t%d\t%.2f%%\n", (i+5)*10, (i+5)*10+9, t[i], (float)t[i]/n*100);

    }
}




int main()
{
    int flag=0;
    STU *head;
    int n = 0;
    int m  = 0;
    int i,j,a;
    int ch;
    int first = 1;
    int safe=123456;
    int safeguard;
    STU stu[STU_NUM];
    int mode;
    label1:
    system("mode con cols=130 lines=60");
    system("color 0E");
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("\n\n\n\n\t\t\t\t***********************\n\n");
    printf("\t\t\t\t本系统包含老师模式和学生模式\n\n");
    printf("\t\t\t\t老师模式包含输入、排序、修改等功能\n\n");
    printf("\t\t\t\t学生模式仅能输出\n\n");
    printf("\t\t\t\t***********************\n\n");
    printf("\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    printf("\t\t请选择老师模式（1）/学生模式（2）:");
    scanf("%d",&mode);
    system("cls");
    if(mode==1){
        printf("请输入老师密码：");
        scanf("%d",&safeguard);
        if(safeguard==safe){
            system("cls");
            }
        else{
            printf("\n\n密码错误！");
            Sleep(1000);
            goto label1;
        }
    }
    else{
        flag+=1;
    }
    while(1)
    {
        system("cls");
        if(mode==1){
                ch = Menu();
            }
        else{
            printf("查找（4）/退出（0）：");
            scanf("%d",&ch);
        }
        switch(ch)
        {
        case 1:
            system("cls");
            head=Create(&n,&m);
            first = 0;
            break;
        case 2:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            AppendRecord(&n,m, head);
            system("pause");
            break;
        case 3:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
             head=DeleteRecord(&n, m, head);
            system("pause");
            break;
        case 4:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByNumber(n,m,head);
            system("pause");
            break;
        case 5:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            SearchByName(n,m,head);
            system("pause");
            break;
        case 6:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            ModifyRecord(n, m,head);
            system("pause");
            break;
        case 7:
            system("cls");
            if(first)
            {
                printf("系统中尚无学生成绩信息，请先输入！\n");
                system("pause");
                break;
            }
            CalculateScoreOfStudent(n,m,head);
            system("pause");
            break;
        case 8:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            CalculateScoreOfCourse(n, m, head);
            getch();
            break;
        case 9:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            SortbyNum(n, m, head);
            getch();
            break;
        case 10:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            SortbyName( head);
            getch();
            break;
        case 11:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            SortbyScoreD(n, m, head);
            getch();
            break;
        case 12:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            SortbyScoreA(n, m, head);
            getch();
            break;
        case 13:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            StatisticAnalysis(n, m, head);
            getch();
            break;
        case 14:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            PrintRecord(n, m, head);
            getch();
            break;
        case 15:
            system("cls");
            if(first)
            {
                SetPosition(POS_X3,POS_Y);
                printf("系统中尚无学生成绩信息，请先输入!\n");
                getch();
                break;
            }
            WritetoFile(n, m, head);
            getch();
            break;
        case 16:
            system("cls");
            if(ReadfromFile(&n, &m,head,&first)||first)
            {
                SetPosition(POS_X1,10);
                printf("尚未输入学生信息或文件打开失败,请先检查!\n");
                getch();
                break;
            }
            getch();
            break;
        case 0:
            system("cls");
            SetPosition(0,10);
            printf("退出系统！\n");
            goto label1;
        default:
            system("cls");
            SetPosition(0,10);
            printf("输入出错，请重新选择操作！\n");
            system("pause");
        }
    }
    return 0;
}
