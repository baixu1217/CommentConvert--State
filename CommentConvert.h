#ifndef __COMMENTCONVERT_H__
#define __COMMENTCONVERT_H__

#include<stdlib.h>
#include<stdio.h>

typedef enum CONVERT_STATE
{
	 NULL_STATE,
	 C_STATE,
	 CPP_STATE,
	 END_STATE
}StateType;

#define INPUTFILENAME "input.c.txt"               //输入的文件，将要读取的文件
#define OUTPUTFILENAME "output.c.txt"             //将读取的文件按要求输出到“output.c”文件中

void CommentConvert();                            //注释转换
void ConvertWork(FILE* read,FILE* write);         //进行转换
void DoCState(FILE* read,FILE* write);            //对于c注释
void DoCppState(FILE* read,FILE* write);          //对于c++注释
void DoNullState(FILE* read,FILE* write);
#endif // __COMMENTCONVERT_H__
