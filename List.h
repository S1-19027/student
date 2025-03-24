#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define STU_NUM 50    // 教学班学生人数上限
#define COURSE_NUM 10 // 一学期的课程上限
#define NAME_LEN 10   // 学生姓名（字符串）最大长度
#define POS_X1 35     // 1、菜单页，第一列所有功能输出起始位置的x坐标值；2、排序之后输出提示起点的X坐标值
#define POS_X2 40     // 输入模块的提示语句起点的X坐标值
#define POS_X3 50     // 第一次，调用输入模块或磁盘数据读入模块功能以外的其他功能，提示“系统中尚无学生成绩信息，请先输入”的起始位置的X坐标值
#define POS_X4 65     // 菜单页，第二列所有功能输出起始位置的x坐标值；
#define POS_Y 3       // 排序之后输出提示起点的Y坐标值

// 结构体类型定义
typedef struct student
{
    long num;                // 学号
    char name[NAME_LEN];     // 姓名
    float score[COURSE_NUM]; // 每门课程成绩
    float sum;               // 总分
    float aver;              // 平均分
} STU;

// 链表节点定义
typedef struct Node
{
    STU data;          // 学生数据
    struct Node *next; // 指向下一个节点的指针
} Node;

// 链表操作函数声明
Node *ListCreate();                                                                                              // 创建空链表
Node *CreateNode(long num, const char *name, float scores[], int courseCount, float sum, float aver);            // 创建新节点
void AppendNode(Node *head, long num, const char *name, float scores[], int courseCount, float sum, float aver); // 在链表末尾添加节点
void FreeList(Node *head);                                                                                       // 释放链表内存

int Menu(void);                                                 // 操作菜单
void SetPosition(int x, int y);                                 // 设置输出内容在控制台窗口中的起始位置
void InputRecord(int *n, int *m, Node *head);                   // 输入学生信息
void AppendRecord(int *n, int m, Node *head);                   // 增加学生信息
void DeleteRecord(int *n, int m, Node *head);                   // 删除学生信息（指删除整条记录）
void SearchByNumber(int n, int m, Node *head);                  // 按学号查询学生信息
void SearchByName(int n, int m, Node *head);                    // 按姓名查询学生信息
void ModifyRecord(int n, int m, Node *head);                    // 修改学生信息
void CalculateScoreOfStudent(int m, Node *head);                // 计算学生的总分和平均分
void CalculateScoreOfCourse(int n, int m, Node *head);          // 计算某门课程的总分和平均分
void SortbyNum(Node *head);                                     // 按学号排序
void SortbyName(Node *head);                                    // 按姓名排序
void SortbyScore(Node *head, int (*compare)(float a, float b)); // 按每个学生平均分进行排序
int Ascending(float a, float b);                                // 升序排序
int Descending(float a, float b);                               // 降序排序
void StatisticAnalysis(int n, int m, Node *head);               // 统计并输出各个分数段学生人数及占比
void PrintRecord(int n, int m, Node *head);                     // 打印学生成绩
void WritetoFile(int n, int m, Node *head);                     // 将学生信息保存至文件student.txt中
int ReadfromFile(int *n, int *m, Node *head, int *first);       // 将学生信息从文件student.txt中读出，存入内存，方便对学生信息进行处理

#endif // LIST_H