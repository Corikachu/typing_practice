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
	char word[100][30]={"add", "salad", "ad", "as", "dad", "Dallas", "fall", "Alaska", "LA", "all",
						"ask", "from", "close", "make", "sure", "see", "old", "with", "lesson", "point",
						"elementary", "what", "new", "help", "listen", "grade", "age", "guess", "play", "here",
						"teacher", "many", "head", "happy", "country", "very", "warm", "like", "soccer", "nature",
						"name", "read", "meet", "year", "give", "ahead", "movie", "much", "address", "email",
						"get", "family", "song", "thank", "friend", "number", "class", "now", "pop", "member",
						"picture", "fat", "grandparent", "long", "painting", "cartoon", "online", "dog", "same", "dark",
						"different", "fashion", "star", "wavy", "welcome", "think", "curly", "engineer", "gather", "communication",
						"cute", "best", "diligent", "short", "cousin", "party", "small", "parent", "big", "live",
						"tall", "black", "twin", "find", "right", "live", "bank", "birthday", "blond", "sport"};
	
	char che[20];
	int i, rand_number ,j=0,k=0,n=0;
	int process=0, miss=0, pass=1, accuracy=0, try_number=0;

	for(i=0 ; i<=20 ; i++)
	{
		system("clear");
		
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d%%		\n",process*5);
		printf("오타수 : %d			\n",miss);
		printf("정확도 : %d%%		\n\n",accuracy);
		
		if(i==20)
		{
			printf("엔터를 누르면 메뉴로 복귀합니다");
			che[20]=getch();
			if(che[20]==10)
			{
				break;
			}
		}


		rand_number = rand()%100;
		
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

			if(che[k]=='\n')
			{
				k=0;
				break;
			}

			printf("%c", che[k]);

			k++;
		}
		
		while(1)
		{
			if((word[rand_number][n]!=che[n])&&(word[rand_number][n]!='\0'))
			{
				n=0;
				miss++;
				break;
			}
			if(word[rand_number][n]=='\0')
			{
				n=0;
				break;
			}
			n++;
		}
		process++;
		accuracy = (float)100*(process-miss)/(process);

	}
}


