/* 터미널 타자 연습기 프로젝트
   2013.6.10 
   조원 임원균 이경문 박성민 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<termio.h>
#include<string.h>
#define ENTER 10
#define ESC 27
#define BACKSPACE 127
/* 변수 start */
int selectnumber;

/* 변수 end */

/* 함수선언 start */
void firstscreen();
int getch();
void sit_practice();
void word_practice();
int short_practice();
int long_practice();

/* 함수선언 end */


/* 메인 함수 start */
int main(void)
{
	while(1)
	{
		firstscreen();
		if(selectnumber==1)
		{
			sit_practice();
			continue;
		}
		else if(selectnumber==2)
		{
			word_practice();
			continue;
		}
		else if(selectnumber==3)
		{
			short_practice();
			continue;
		}
		else if(selectnumber==4)
		{
			long_practice();
			continue;
		}
		else if(selectnumber==5)
		{
			system("clear");
			break;
		}
	}

	return 0;
}
/* 메인 함수 end */


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
}
	
/* 자리 연습 함수 끝*/

/* 낱말 연습 start */

void word_practice(void)
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
	int process=0, miss=0, accuracy=0;

	for(i=0 ; i<=20 ; i++)
	{
		system("clear");
		
		printf(">>영문 타자 연습 프로그램 : 자리 연습 <<\n");
		printf("진행도 : %d%%		\n",process*5);
		printf("오타수 : %d			\n",miss);
		printf("정확도 : %d%%		\n\n",accuracy);
		
		//20번일때 엔터를 누르면 for문을 빠져나감
		if(i==20)
		{
			printf("엔터를 누르면 메뉴로 복귀합니다");
			che[20]=getch();
			if(che[20]==10)
			{
				break;
			}
		}


		//랜덤 숫자 배정
		rand_number = rand()%100;
		
		//문자출력
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
			//문자받기
			che[k]=getch();

			//###이면 메뉴로 복귀
			if((che[0]=='#')&&(che[1]=='#')&&(che[2]=='#'))
			{
				printf("%c", che[2]);
				firstscreen();
			}

			//엔터시 넘어감
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
			//문자 판단-글자 틀림
			if((word[rand_number][n]!=che[n])&&(word[rand_number][n]!='\0'))
			{
				n=0;
				miss++;
				break;
			}
			//문자 판단-전부 맞음
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


/* 낱말 연습 end */



/* 짧은 글 연습 start */


int short_practice(void)
{
	time_t start,end,diff=0; //처음 입력받을 때부터 현재까지의 시간, 마지막으로 입력받을 때부터 현재까지 시간, 마지막에서 처음 시간 차이
	int speed[5]={0}; //각 문장마다 입력받을 타수를 저장하는 배열
	int best=0; // 최고타수로 조건에 따라 바뀜
	int end_count=0; //몇번의 문장이 입력되었는지 카운트하는 변수
	int pro=0; // 진행도
	int acc=0; // 정확도
	int err=0; // 틀린글자수
	float cor=0; // 맞은글자수
	int ran,d;
	int n;
	char input_new,input; //getch받은걸 출력시킬 때 사용
	int prac=0; // ran에 의해 임의로 선택된 문장을 출력할 때 사용
	char short_input[15][100]; //getch에 받은 문자들을 저장 1차원 부분에 15는 의미없음, 어차피 최대한 5번만 받으니까..
	char short_prac[30][100]={{"Courage is resistance to fear, mastery of fear - not absence of fear"},{"Poetry is the mother tongue of mankind"},{"Misery loves company"},{"Man is but a reed, the weaken in nature, but he is a thinking read"},{"Who reflects too much will accomplish little"},{"Man should keep his friendship in constant repair"},{"The right people in the right jobs"},{"Time is the rider that breaks youth"},{"A deep distress hat humanized my soul"},{"Who reflects too much will accomplish little"},{"Nature does not proceed by leaps"},{"Man is a voluntary agent"},{"Men have no right to what is not reasonable"},{"Wealth brings with it many anxieties"},{"Being in a ship is being in a jail, with the chance of being drowned"},{"Life is a progress from want to want, not from enjoyment to enjoyment"},{"Life is half spent before we know what it is"},{"The first virtue of a painting is to be a feast for the eyes"},{"Love truth, but pardon error"},{"It is a wise father that knows his own child"},{"A map apt to promise is apt to forget"},{"We are not hypocrites in our sleep"},{"Genius does what it must, and talent does what it can"},{"The right people in the right jobs"},{"Experience is the only prophecy of wise men"},{"You never miss the water till the well runs dry"},{"A little learning is a dangerous thing"},{"No one can be more wise than destiny"},{"Old men are always young enough to learn, with profit"},{"Music has charms to soothe a savage breast"}};
	srand(time(NULL));
	while(1){
		system("clear");
		printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
		printf("진행도 : %3d%% 현재타수 : %4d 최고타수 : %4d 정확도 : %3d%%\n",pro,speed[end_count],best,acc);
			if(end_count==5)
			{
				printf("1을누르면 메뉴로 돌아갑니다");
				while(1)
				{
					scanf("%d", &n);
					if(n==1)
					{
						return 0;
					}
					else
					{
						continue;
					}
				}
			}
		ran=rand()%30;
			for(prac=0;short_prac[ran][prac]!='\0';prac++){
				printf("%c",short_prac[ran][prac]);
														  } // 위에 선언한 30개의 문장중에 하나를 선택해서 글자를 차례로 반복문을 돌려 출력하는데 이때 널문자를 만날 때까지 출력한다는 조건.
		printf("\n");
again:
			for(input=0;input<=prac;input++){ //d부분은 크게 상관할필요없음 다시 입력받으면 다시 초기화되기에, 중요한건 getch로 받은걸 short_input배열에 저장하고 이를 이 문장 바로 위에 랜덤으로 선택받아 출력된 문자의 수만큼 출력하도록함 (실제 한컴타자연습에도 그 글자 이상 입력시 자동으로 넘어가기에 이렇게 처리함.
					d=0;
plz:
					short_input[d][input]=getch();
					if(input==prac){
						while(short_input[d][input]!=10){
							if(short_input[d][input]==27){
								return 0;
							}
							else if(short_input[d][input]==127){
							if(short_input[d][input-1]==short_prac[ran][input-1]){
										cor--;
																					}
							else if(short_input[d][input-1]!=short_prac[ran][input-1]){
										err--;
																					}
						short_input[d][input-1] = '\0';
						short_input[d][input] = '\0';
						input-=2;
						goto check;
							}
							short_input[d][input]='\0';
							goto plz;
						}
					}
					if(input==0){
					start=time(NULL); //input==0 일때이므로 처음 입력받을 때 시간을 체크하는 것이다.
								}
					else{
					end=time(NULL); //끝시간을 체크하는건데 반복문에 의해 계속 초기화되다가 결국 마지막 글자를 입력했을 때 초기화가 멈추므로 끝시간을 체크하게된다.
						}
					if(short_input[d][input]==27){
							return 0;
												 } // esc 눌렀을 때 프로그램 끝내기
					if(short_input[d][input]==10){
							break;
												 } // 엔터입력시 getch로 받은 short_input를 출력하는 반복문을 나가면서 새로운 short_prac 문장이 나오게 된다. 즉, 다음 문장으로 넘어감.
					if(short_input[d][input]==127){
						if(input!=0){
							if(short_input[d][input-1]==short_prac[ran][input-1]){
										cor--;
																			   	}
							else if(short_input[d][input-1]!=short_prac[ran][input-1]){
										err--;
																					}
						short_input[d][input-1] = '\0';
						short_input[d][input] = '\0';
						input-=2; //백스페이스 처리로 백스페이스 누르는 자리 바로 뒤에가 같다면 cor--;처리 다르다면 err--;처리하면서 정확도에 문제없에 처리한다.
						goto check;
									}
						else{
							goto again; //만약 처음부터 백스페이를 입력하게되면 정확도에 영향이 없도록 다시 처음부터 getch로 받아서 출력할 수 있도록 처리했다.
							}
													}			
					if(short_prac[ran][input]==short_input[d][input]){
								cor++;
																	}
					else if(short_prac[ran][input]!=short_input[d][input]){
								err++;
																			} //getch로 받아서 입력할 때 위의 문장과 같다면 cor++; 다르다면 err++;
check:
					if((cor+err)==0){
							acc=0; 
									} // 이 경우는 cor도 0이고 err도 0일때의 경우로 처음 프로그램 실행시 또는 치다가 모든 글자를 지웠을 경우로 acc에 쓰레기값이 들어가지 않도록 0으로 초기화.
					else{
							acc=((float)cor/(cor+err))*100;
						} //정확도를 입력한 메세지의 숫자 (cor+err) 분에 맞은글자수 cor로 나타낸것이고 바로 위의 주석의 설명이 나온 이유는 cor+err을 분모로 배치했기에 분모가 0이되면 쓰레기값이 되기때문이다. 
		diff=end-start+1; // 걸린시간을 end와 start의 차이로 계산하는데 이때 첫 글자를 입력시 diff가 0이 되며 생기는 오류를 막기위해 항상 1초 이상이 되도록 1을 더해준다.
						speed[end_count]=(cor/diff)*60; // 타수를 계산한 것으로 걸린시간 (초) 분에 맞게 입력된 글자 곱하기 60으로 계산했다.
		input_new=0;
		system("clear");
		printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
		printf("진행도 : %3d%% 현재타수 : %4d 최고타수 : %4d 정확도 : %3d%% \n",pro,speed[end_count],best,acc);
					for(prac=0;short_prac[ran][prac]!='\0';prac++){
						printf("%c",short_prac[ran][prac]);
																	}					
		printf("\n");
					while(input_new<=input){
						printf("%c",short_input[d][input_new]);
						input_new++;
											} // 값을 입력할 때마다 clear를 시켜주면서 사용자가 입력한 문자를 출력시키는 코드
	}
end_count++; // 엔터를 눌렀을 때 for문에서 빠져나오면서 다음 문장으로 넘어갈 때마다 end_count를 하나씩 올리면서 카운팅한다
if(speed[end_count-1]>speed[end_count]){
	best=speed[end_count-1];
}
else{
	best=speed[end_count];
} //최고타수를 입력할 때 전의 타수가 더 높다면 그 타수를 출력, 현재 타수가 더 높다면 그 타수를 출력하도록 하는 코드
end=0;
acc=0;
err=0;
cor=0;
pro=(end_count/5.0)*100; // 다음 문장으로 넘어갈 때마다 정확도와 맞은글자 틀린 글자를 0으로 초기화해주고 진행도를 20%씩 올려주는 코드
	}
	return 0;
}
/* 짧은 글 end */

/* 긴 글 start */

int long_practice(void)
{
	char text[4][10][100] = {{"The Selfish Giant ",
		"Every afternoon, as they were coming from school, the children used ",
		"to go and play in the Giant's garden. ",
		"It was a large lovely garden, with soft green grass. Here and there ",
		"over the grass stook beautiful flowers like stars, and there were ",
		"twelve peachtrees that in the springtime broke out into delicate blos-",
		"soms of pink and pear I, and in the autumn bore rich fruit. The birds ",
		"sat in the trees and sang so sweetly that the children used to stop ",
		"their games in order to listen to them. \"How happy we are here!\" they ",
		"cried to each other. "},
		 {"Rapunzel ",
		"There once lived a man and his wife, who had long wished for a child, ",
		"but in vain. Now there was at the back of their house a little window ",
		"which over looked a beautiful garden full of the finest vegetables and ",
		"flowers; but there was a high wall all round it, and no one ventured ",
		"into it, for it belonged to a witch of great might, and of whom all ",
		"the world was afraid. One day, when the wife was standing at the win-",
		"dow, and looking into the garden, she saw a bed filled with the finest ",
		"rampion; and it looked so fresh and green that she began to wish for ",
		"some; and at length she longed for it greatly. "},
		{"Narcissus ",
		"Long, long ago, there lived in Greece a young boy named Narcissus. ",
		"All day long he tended his sheep in the hills, and drove them from ",
		"place to place to find the very best pasture. ",
		"One day he came to a little stream and wanted to drink from it. The ",
		"water was very clear and reflected everything that leaned over it. ",
		"While Narcissus was waiting for the sheep to drink, he chanced to see ",
		"his own face in the water. ",
		"He had never seen his likeness before, and he was so pleased with the ",
		"pretty picture that he looked at it for a long time. "}, 
		{"Gulliver's Travels ",
		"I am Lemuel Gulliver. I was born in England. When I grew up, I had a ",
		"great wish to go round the world, and in the year 1699, I got on board ",
		"a ship bound for the South Seas. For some time things went all right. ",
		"But one day a great storm drove us far to the south and at last the ",
		"whip ran on a rock and split her bow. We let down a boat and left the ",
		"wreck. But a big wave sank the boat, and I lost sight of my poor ",
		"friends. ",
		"I swam on and on, and just when I felt I must give myself up, I found ",
		"I could touch the sand. I was now safe. "}}; 

	while (1){
		char input[10][100], c; //input배열 => 사용자 입력값
		int h, i, j, N[4][10], ch, cor = 0, err = 0, accur = 0, speed = 0, line_count = 0, ch_count;
		//ch 현재글자 cor 맞은개수, err 틀린개수, accur 정확도, speed 현재타수, line_count 현재 행, ch_count 행의 글자수 
	
		time_t start = 0, end = 0;
		srand(time(NULL));
		//input배열 초기화
		for (j = 0; j < 10; j++)
			for (h = 0; h < 100; h++)
				input[j][h] = '\0';
	
		//각 행 별 글자수
		for (i = 0; i < 4; i++)
			for (j = 0; j < 10; j++)
				N[i][j] = strlen(text[i][j]); //N배열은 초기 행 별 글자수 받을때만 한번 씀

		i = rand() % 4; //무작위 text 출력을 위한 난수 생성

		while (line_count < 10){
			if (cor + err != 0)
				accur = (cor * 100) / (cor + err); //정확도 : 맞은개수 / 전체 * 100
			else
				accur = 0; //정확도 초기값(입력글자수 = 0)

			//밑에서 입력했던 글자들을 지우고 정확도와 현재타수를 보여주는 정보창이 맨위에 출력되도록 화면정리
			system("clear");
			printf(">> 영문 타자 연습 프로그램 : 긴 글 연습 <<\n");
			printf("정확도 : %d%%	현재타수 : %d\n\n", accur, speed);
			ch_count = N[i][line_count]; //현재 행의 글자 수
			//0행부터 4행까지 본문 1p. 출력
			if (line_count < 5)
			{
				for (j = 0; j < 5; j++)
					printf("%s\n", text[i][j]); //본문 5줄 출력
				printf("\n");
			}
				//5행부터 9행까지 본문 2p. 출력
			if (line_count >= 5)
			{
				for (j = 5; j < 10; j++)
					printf("%s\n", text[i][j]); //본문 5줄 출력
				printf("\n");
			}
				//0행부터 4행까지 사용자 입력
			if (line_count < 5)
			{
				for (j = 0; j < line_count; j++)
					printf("%s\n", input[j]); //전에 입력했던 문장들 보여줌
				for (h = 0; h <= ch; h++)
					printf("%c", input[line_count][h]); //지금 문장에 입력한 글자들 보여줌
			}
				//5행부터 9행까지 사용자 입력
			if (line_count >= 5)
			{
				for (j = 5; j < line_count; j++)
					printf("%s\n", input[j]); //전에 입력했던 문장들 보여줌
				for (h = 0; h <= ch; h++)
					printf("%c", input[line_count][h]); //지금 문장에 입력한 글자들 보여줌
			}
			input[line_count][ch] = getch(); //문자를 하나 입력받는다
			//본문의 글자를 정확히 입력했을 경우 맞은개수 +1
			if (input[line_count][ch] == text[i][line_count][ch])
				cor++; 
			else //그렇지 않은 경우 틀린개수 +1
				err++; 
			//도중에 esc키를 누르면, 메뉴로 복귀
			if (input[line_count][ch] == ESC)
				return;
			//도중에 Enter키를 누르지 못하게 함
			if (input[line_count][ch] == ENTER)
			{
				input[line_count][ch] = '\0'; //문자 입력 무시
				err--; //엔터키를 눌러서 틀렸던 글자 만회
				ch--; //원래 키 누르기 전 현재 글자 위치 복귀
			}
			//도중에 백스페이스키를 누를 경우
			if (input[line_count][ch] == BACKSPACE)
			{
				//첫 글자만 아니면
				if (ch > 0){
				//전에 쓴 글자가 틀렸을 경우 추가적으로 틀린글자 복구
				if (input[line_count][ch-1] != text[i][line_count][ch-1])
					err--; 
				ch -= 2; //이전 두칸 가서
				input[line_count][ch+2] = '\0'; //키 누른 위치를 비우고
				input[line_count][ch+1] = '\0'; //지우려던 위치를 비움
				err--; //백스페이스키 눌러서 증가한 틀린글자 수 만회
				}
				else //첫 글자위치에서는 백스페이스키를 누르지 못하게 함
				{
					input[line_count][ch] = '\0'; //문자 입력 무시
					err--; //백스페이스키 눌러서 틀렸던 글자 만회
					ch--; //원래 키 누르기 전 글자 위치 복귀
				}
			}
			if (ch == ch_count-1) //행 끝까지 입력하였으면
			{
				line_count++; //다음 행으로 넘어가기
				ch = -1; //현재글자 초기화, 바로 다음에 +1되서 ch=0으로 넘어갈꺼니깐
			}
			//시간 시점 = 문자입력시점, 기점은 시간의 흐름에 따라 변화
			if (start != 0)
				end = time(NULL)+1; // 1초부터 시간이 흐름
			else
				start = time(NULL);
			//걸린 시간이 0이 아닌경우 현재타수는 맞은개수/걸린시간(기점-시점) * 60(초)
			if (end - start != 0)
				speed = (cor * 60) / (end - start);
			ch++;
			//긴글 연습 끝났을 경우
			if (line_count == 10)
			{
				printf("\n\nEnter키를 누르면 메뉴로 돌아갑니다.\n");
				printf("계속하려면 아무 키나 누르세요...");
				if ((c = getch()) == ENTER) //Enter를 입력하면 긴글 연습 종료
					return;
				//다른 키를 누르면 while문에 의해 처음으로 돌아간다
			}
		}
	}
	return 0;
}

/* 긴 글 end */
