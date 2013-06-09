#include <stdio.h>
#include <termio.h>
#include <time.h>
int getch(void){
	int ch;
	struct termios buf;
	struct termios save;
	tcgetattr(0,&save);
	buf=save;
	buf.c_lflag&=~(ICANON|ECHO);
	buf.c_cc[VMIN]=1;
	buf.c_cc[VTIME]=0;
	tcsetattr(0,TCSAFLUSH,&buf);
	ch=getchar();
	tcsetattr(0,TCSAFLUSH,&save);
	return ch;
}
int main(void)
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
	char input_new,input; //getch받은걸 출력시킬 때 사용
	int prac=0; // ran에 의해 임의로 선택된 문장을 출력할 때 사용
	char short_input[15][100]; //getch에 받은 문자들을 저장 1차원 부분에 15는 의미없음, 어차피 최대한 5번만 받으니까..
	char short_prac[30][100]={{"Courage is resistance to fear, mastery of fear - not absence of fear"},{"Poetry is the mother tongue of mankind"},{"Misery loves company"},{"Man is but a reed, the weaken in nature, but he is a thinking read"},{"Who reflects too much will accomplish little"},{"Man should keep his friendship in constant repair"},{"The right people in the right jobs"},{"Time is the rider that breaks youth"},{"A deep distress hat humanized my soul"},{"Who reflects too much will accomplish little"},{"Nature does not proceed by leaps"},{"Man is a voluntary agent"},{"Men have no right to what is not reasonable"},{"Wealth brings with it many anxieties"},{"Being in a ship is being in a jail, with the chance of being drowned"},{"Life is a progress from want to want, not from enjoyment to enjoyment"},{"Life is half spent before we know what it is"},{"The first virtue of a painting is to be a feast for the eyes"},{"Love truth, but pardon error"},{"It is a wise father that knows his own child"},{"A map apt to promise is apt to forget"},{"We are not hypocrites in our sleep"},{"Genius does what it must, and talent does what it can"},{"The right people in the right jobs"},{"Experience is the only prophecy of wise men"},{"You never miss the water till the well runs dry"},{"A little learning is a dangerous thing"},{"No one can be more wise than destiny"},{"Old men are always young enough to learn, with profit"},{"Music has charms to soothe a savage breast"}};
	srand(time(NULL));
	while(1){
		system("clear");
		printf(">> 영문 타자 연습 프로그램 : 짧은 글 연습 <<\n");
		printf("진행도 : %3d%% 현재타수 : %4d 최고타수 : %4d 정확도 : %3d%%\n",pro,speed[end_count],best,acc);
			if(end_count==5){
				return 0;
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
