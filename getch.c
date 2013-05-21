#include<stdio.h>
#include<termio.h>

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
int getch()
{
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf=save;
	buf.c_lflag&=~(ICANON|ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);
	return ch;
}

int main(void)
{
	int ch;
	ch=getch();
	if(ch=='a')
	{
		printf("good");
	}
	else
	{
		printf("bad");
	}
	return 0;
}

