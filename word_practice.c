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

void main(void)
{
	system("clear");

	srand(time(NULL));
	char word[3][30]={"name","salad","birthday"};
	
	char che[20];
	int i, rand_number ,j=0,k=0,n=0;
	int process=0, miss=0, pass=1, accuracy=0, try_number=0;

	for(i=0 ; i<20 ; i++)
	{
		system("clear");
		
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d%%		\n",process*5);
		printf("오타수 : %d			\n",miss);
		printf("정확도 : %d%%		\n\n",accuracy);

		rand_number = rand()%3;
		
		while(1)
		{
			printf("%c", word[rand_number][j]);
			if(word[rand_number][j]=='\0')
			{
				j=0;
				break;
			}
			j++;
		}

		printf("\n-");
		
		while(1)
		{
			che[k]=getch();

			if((che[0]=='#')&&(che[1]=='#')&&(che[2]=='#'))
			{
				printf("%c", che[2]);
				break;
			}
			else if(che[k]==10)
			{
				k=0;
				break;
			}

			printf("%c", che[k]);

			k++;
		}
		
		while(1)
		{
			if(word[rand_number][n]!=che[n])
			{
				n=0;
				miss++;
				break;
			}
			
		}
		process++;
		accuracy = (float)(process-miss)/(process);
	}
}


