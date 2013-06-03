#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<termio.h>

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
	system("clear");

	srand(time(NULL));
	char word[3][20]={"name","salad","birthday"};
	
	char che[20]={0};
	int i, rand_number;
	int process=0, miss=0, pass=1, accuracy=0, try_number=0;

	for(i=0 ; i<20 ; i++)
	{
		system("clear");
		
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d%%		\n",process*5);
		printf("오타수 : %d			\n",miss);
		printf("정확도 : %d%%		\n\n",accuracy);

		rand_number = rand()%3;

		printf("%c", word[rand_number][20]);
		printf("-");
		
		while(1)
		{
			int j=0;
			che=getch();

			if((che[j]=='\r')||(che[j]=='\n'))
			{
				break;
			}
			printf("%c", che[j]);
			j++;
		}
		
		while(1)
		{
			int j=0;
			if(che[j]!=word[rand_number][j])
			{
				miss++;
				break;
			}
		}
	}
	return 0;
}
