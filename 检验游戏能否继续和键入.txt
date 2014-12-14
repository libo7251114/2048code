/*检验游戏是否能否继续*/
void check_fail()
{
int i,j;
for(i=0;i<4;i++)
for(j=0;j<3;j++)
if(game.box[i*4+j]==game.box[i*4+j+1])
return;
for(j=0;j<4;j++)
for(i=0;i<3;i++)
if(game.box[i*4+j]==game.box[(i+1)*4+j])
return;
game.stat=FAILED;
}
/*2和4出现的概率比为3/1*/
int get2or4()
{
int x=rand()%4;
return x>3 ? 4:2;
}
/*接收键盘的键入，方向键由三个char类型字符表示：
上：27 91 65
下：27 91 66
右：27 91 67
左：27 91 68
*/
void inputCmd()
{
char c=my_getch();
if(c==27)
{
c=my_getch();
if(c==91)
{
c=my_getch();
if(c==65)
direction=UP;
if(c==66)
direction=DOWN;
if(c==67)
direction=RIGHT;
if(c==68)
direction=LEFT;
//printf("%d ",c);
}
}
else if(c=='\n')
direction=QUIT;
else
direction=INVALID;
}