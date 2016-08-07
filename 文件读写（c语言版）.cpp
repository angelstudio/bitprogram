// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	FILE *in,*out;
	int ch=0;
	if (argc != 3) {
		fprintf(stderr, "������ʽ����\n");
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "�򲻿��ļ�:%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "�޷�д��:%s\n", argv[2]);
		fclose(in);
		exit(EXIT_FAILURE);
	}
	while ((ch==getc(in))!=EOF) {
		if (putc(ch, out) == EOF)
			break;
	}
	if (ferror(in)) {
		printf("��ȡ�ļ�%sʧ��", argv[1]);
	}
	if (ferror(out)) {
		printf("д���ļ�%sʧ��", argv[2]);
	}
	printf("�ɹ�");
	fclose(in);
	fclose(out);
	return 0;
}