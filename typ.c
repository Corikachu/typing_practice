#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<termio.h>

/* 변수 start */
int selectnumber;

/* 변수 end */

/* 함수선언 start */
void firstscreen();
int getch();
void sit_practice();

/* 함수선언 end */

int main(void)
{
	firstscreen();
	if(selectnumber==1)
	{
		sit_practice();
	}
	return 0;
}


/* 프로그램 실행화면 */
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

/* getch 선언 */
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

/*자리 연습 함수*/
void  sit_practice(void)
{
	system("clear");

	srand(time(NULL));
	char ch[52]={'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O',
				'P','Q','R','S','T','U','V','W','X','Y','Z',
				'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
				'p','q','r','s','t','u','v','w','x','y','z'};
	char che;
	int i, rand_number;
	int process=0, miss=0, pass=1, accuracy=0, try_number=0;
	
	/* 자리 연습 시작 */
	for(i=0 ; i<=20 ; i++)
	{
		system("clear");
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d%%		\n", process*5);
		printf("오타수 : %d			\n", miss);
		printf("정확도 : %d%%		\n\n", accuracy);
	
		/* 마지막 통계를 보여주며 엔터를 누를시만 메뉴로 복귀*/
		if(i==20)
		{
			printf("\n");
			printf("엔터키를 입력하면 메인으로 돌아갑니다");
			
			while(1)
			{
				che=getch();
		 		if((che=='\r')||(che=='\n'))
				{
					break;
				}
			}
			break;
		}
		
		/* pass로 입력된 키가 같은경우에만 다시 랜덤을 출력*/
		if(pass==1) 
		{
			rand_number = rand()%52;
		}
				
		printf("%c\n", ch[rand_number]);
		printf("-");
		
		che=getch();

		if(che == ch[rand_number]) // 입력된 키가 같은경우
		{
			process++; 
			pass=1;
		}
	
		if(che != ch[rand_number]) // 입력된 키가 다를경우
		{
			i--;
			miss++;
			pass=0;
		}
		
		if(che == 27) // esc입력시 메뉴복귀
		{
			break;
		}

		/*정확도 계산*/
		try_number++;
		accuracy = ((float)process/try_number)*100;

	}
	/*자리 연습 끝*/
	firstscreen();
}
/* 자리 연습 함수 끝*/


