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
	srand(time(NULL));
	char ch[52]={'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O',
				'P','Q','R','S','T','U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
				'p','q','r','s','t','u','v','w','x','y','z'};
	char che;
	int i, rand_number;
	int process=0, miss=0, accuracy=1;

	for(i=0 ; i<20 ; i++)
	{
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d\%		\n",process);
		printf("오타수 : %d			\n",miss);
		printf("정확도 : %d\%		\n\n",100/accuracy);

		rand_number = rand()%52;		
		printf("%c\n", ch[rand_number]);
		printf("-");
		
		while(1)
		{
			che=getch();

			if(che == ch[rand_number])
			{
				printf("%c", che);
				process += 5;
				system("clear");
				break;
			}
			
			else if(che != ch[rand_number])
			{
				miss++;
			}		
		}
	}
	// first스크린
}
