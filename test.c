<<<<<<< HEAD
test.c
:wq

=======
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
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

void sit_practice(void)
{
	srand(time(NULL));
	char ch[5]={'a','b','c','d','e'};
	char che;
	int i,k;
	static int a=0,b=0,c=100;

	for(i=1 ; i<=20 ; i++)
	{
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d\%		",a);
		printf("오타수 : %d		",b);
		printf("정확도 : %d\%		\n\n",c); 

		k=rand()%5;
		printf("%c\n",ch[k]);
		printf("-");
		che=getch();
		printf("%c", che);

		if(ch[k]==che)
		{
			a += 5;
		}
		if(ch[k]!=che)
		{
			b++;
		}
		if(b!=0)
		{
			c=c/b;
		}
		
		system("clear");

		if(i==20)
		{
			firstscreen();
		}
	}
}

int main(void)
{
	firstscreen();
	if(selectnumber==1)
	{
		sit_practice();
	}
	return 0;
}
>>>>>>> 8499dd8113be28211e8d3e72321dfc37bc903bdd
