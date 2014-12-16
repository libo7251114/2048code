/*检索空位，即为0的值
*/
int findPos()
{
int i,count=0,pos;
for(i=0;i<16;i++)
empty[i]=-1;
for(i=0;i<16;i++)
{
if(game.box[i]==0)
empty[count++]=i;
}
if(count==0)
return -1;//game over
pos=empty[rand()%count];
//printf("pos=%d\n",pos);
return pos;
}
int merge()//不可以移动时返回-1
{
int box_4x4[4][4];
int i,j,deep;
int has_move=-1,merge_line=0;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
box_4x4[i][j]=game.box[i*4+j];
if(direction==RIGHT)
{
//printf("RIGHT");
for(i=0;i<4;i++)
{
deep=3;
merge_line=0;
for(j=3;j>=0;j--)
{
if(box_4x4[i][j]!=0)
{
box_4x4[i][deep]=box_4x4[i][j];
if(deep!=j) box_4x4[i][j]=0;
if(deep<3 && merge_line==0 && box_4x4[i][deep]==box_4x4[i][deep+1] )
{ game.point+=box_4x4[i][deep+1]; box_4x4[i][deep+1]*=2;
box_4x4[i][deep]=0; merge_line=1; }
else deep--;
}
}
}
}
if(direction==LEFT)
{
//printf("LEFT");
for(i=0;i<4;i++)
{
deep=0;
merge_line=0;
for(j=0;j<4;j++)
{
if(box_4x4[i][j]!=0)
{
box_4x4[i][deep]=box_4x4[i][j];
if(deep!=j) box_4x4[i][j]=0;
if(deep>0 && merge_line==0 && box_4x4[i][deep]==box_4x4[i][deep-1] )
{ game.point+=box_4x4[i][deep-1]; box_4x4[i][deep-1]*=2;
box_4x4[i][deep]=0; merge_line=1; }
else deep++;
}
}
}
}
if(direction==UP)
{
//printf("UP");
for(j=0;j<4;j++)
{
deep=0;
merge_line=0;
for(i=0;i<4;i++)
{
if(box_4x4[i][j]!=0)
{
box_4x4[deep][j]=box_4x4[i][j];
if(deep!=i) box_4x4[i][j]=0;
if(deep>0 && merge_line==0 && box_4x4[deep][j]==box_4x4[deep-1][j])
{ game.point+=box_4x4[deep-1][j]; box_4x4[deep-1][j]*=2;
box_4x4[deep][j]=0; merge_line=1; }
else deep++;
}
}
}
}
if(direction==DOWN)
{
//printf("DOWN");
for(j=0;j<4;j++)
{
merge_line=0;
deep=3;
for(i=3;i>=0;i--)
{
if(box_4x4[i][j]!=0)
{
box_4x4[deep][j]=box_4x4[i][j];
if(deep!=i) box_4x4[i][j]=0;
if(deep<3 && merge_line==0 && box_4x4[deep][j]==box_4x4[deep+1][j])
{ game.point+=box_4x4[deep+1][j]; box_4x4[deep+1][j]*=2;
box_4x4[deep][j]=0; merge_line=1; }
else deep--;
}
}
}
}
for(i=0;i<4;i++)
for(j=0;j<4;j++)
if(game.box[i*4+j]!=box_4x4[i][j])
{
game.box[i*4+j]=box_4x4[i][j];
has_move=1;
if(game.box[i*4+j]==2048) game.stat=DONE;
}
return has_move;
}