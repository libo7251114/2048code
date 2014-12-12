#include"my_getch.h"
#include"math.h"
#include"time.h"
#define SPACE() printf(" ")
#define RED_NUM(n) printf("\033[;31m%4d",(n))
#define GREEN_NUM(n) printf("\033[;32m%4d",(n))
#define BLUE_NUM(n) printf("\033[;34m%4d",(n))
#define YELLOW_NUM(n) printf("\033[;33m%4d",(n))
#define PURPLE_NUM(n) printf("\033[;35m%4d",(n))
#define DEEPGREEN_NUM(n) printf("\033[;36m%4d",(n))
/*根据不同的number进行不同的宏替换，输出不同颜色的数字*/
void printNum(const int num)
{
if(num==0)
SPACE();
else if(num==1024 || num==32)
RED_NUM(num);
else if(num==2 || num==64 )
BLUE_NUM(num);
else if(num==4 || num==128)
GREEN_NUM(num);
else if(num==8 || num==256)
YELLOW_NUM(num);
else if(num==16 || num==512)
PURPLE_NUM(num);
else
DEEPGREEN_NUM(num);
}
enum game_stat{PLAYING,FAILED,EXITED,DONE};
enum cmd{UP,DOWN,LEFT,RIGHT,QUIT,INVALID};
enum cmd direction;
short empty[16];
struct Game
{
int box[16];
enum game_stat stat;
int step;
unsigned long int point;
}game;
void init_game()
{
int i;
for(i=0;i<16;i++)
game.box[i]=0;
game.stat=PLAYING;
game.step=0;
game.point=0;
}