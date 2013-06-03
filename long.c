#include <stdio.h>
#include <termio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ENTER 10
#define ESC 27
#define BACKSPACE 127
int getch(void)
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
	tcsetattr(0, TCSAFLUSH, & save);
	return ch;
}

int main(void)
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
				end = time(NULL);
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
