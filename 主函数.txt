int main(int argc,char** argv)
{
int pwdlen=10;
int newPos;
int has_merge=1;
init_game();
srand(time(0));
fflush(stdin);
while(1)
{
//printf("\033[2J");//清屏
//printf("\033[2H");//光标复位
//printf("\033[?25l");//隐藏光标
newPos=findPos();
if(newPos==-1)
{
check_fail();
if(game.stat==FAILED)
break;
}
if(has_merge!=-1)
{
game.box[newPos]=get2or4();
}
drawBox();
inputCmd(direction);
if(direction==QUIT)
break;
else if(direction==INVALID)
continue;
else
{
has_merge=merge();
if(game.stat==DONE) break;
if(has_merge!=-1) game.step++;
}
}
drawBox();
printf("\033[;30m");
}
my_getch.h 
/*---------------------------------------
** copyright (c) 2014-12-28
** E-mail: 544397102@qq.com
** getch.c:模拟实现getch()
**--------------------------------------*/
#ifndef MYGETCH_H
#define MYGETCH_H
#include
#include //操作终端
#include
#include
#include
char my_getch()
{
int c=0;
struct termios org_opts, new_opts;
int res=0;
//保留终端原来设置
res=tcgetattr(STDIN_FILENO, &org_opts);
assert(res==0);
//从新设置终端参数
memcpy(&new_opts, &org_opts, sizeof(new_opts));
new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
c=getchar();
//恢复中断设置
res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);assert(res==0);
return c;
}
#endif