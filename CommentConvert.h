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

#define INPUTFILENAME "input.c.txt"               //������ļ�����Ҫ��ȡ���ļ�
#define OUTPUTFILENAME "output.c.txt"             //����ȡ���ļ���Ҫ���������output.c���ļ���

void CommentConvert();                            //ע��ת��
void ConvertWork(FILE* read,FILE* write);         //����ת��
void DoCState(FILE* read,FILE* write);            //����cע��
void DoCppState(FILE* read,FILE* write);          //����c++ע��
void DoNullState(FILE* read,FILE* write);
#endif // __COMMENTCONVERT_H__
