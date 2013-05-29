#include<stdio.h>


int selectnumber;

void firstscreen(void)
{
	system("clear");
	printf(">>영문 타자 연습 프로그램<<\n");
	printf("1. 자리 연습		2. 낱말 연습\n");
	printf("3. 짧은 글 연습		4. 긴 글 연습\n");
	printf("5. 프로그램 종료\n\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &selectnumber);
}

int main(void)
{
	firstscreen();
	printf("%d", selectnumber);
	return 0;
}
