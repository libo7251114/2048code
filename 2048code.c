/*2048*/






int i,j;
printf("2048\n");
printf("W--UP  A--LEFT  S--DOWN  D--RIGHT  0--EXIT\n");
printf("Score:%d Move:%d\n",score,move);
printf("Made by Yanjisheng\n");
printf("|-------------------|\n");/*��ʾ����ָ���*/
for(i=0;i<=3;i++)
{
for(j=0;j<=3;j++)
{
 if(code[i][j]==0)
 {
         printf("|    ");/*0��ʾ�ո�*/
 }
 else
{
printf("|%4d",code[i][j]);/*��ʾ���ֺͷָ���*/
 }
printf("|\n|-------------------|\n");/*��ʾ����ָ���*/
 }



int i;
{
  for(i=0;i<=3;i++)
 {
if(temp[i]==0)
{
if(temp[i]!=temp[i+1])
change=1;/*��һ��0���治��0ʱ����ı�*/
temp[i]=temp[i+1];
temp[i+1]=0;
  }
}/*ȥ���м��0*/
 t++;
}
while(t<=3);/*�ظ����*/
for(i=1;i<=3;i++)
{
if(temp[i]==temp[i-1])
{
if(temp[i]!=0)
{
change=1;/*������������ͬ�������ʱ����ı�*/
score=score+temp[i];/*�ӷ�*/
}
temp[i-1]=temp[i-1]*2;
temp[i]=0;
}
}/*���������ڵ���ͬ����������*/
do
{
for(i=0;i<=3;i++)
{
if(temp[i]==0)
{
temp[i]=temp[i+1];
temp[i+1]=0;
}
}/*ȥ���м��0*/
t++;
}
while(t<=3);/*�ظ����*/
 return change;


 int gameover=0;/*�ж���Ϸ�Ƿ������1������0����*/
int i,j;
char input;
while(gameover==0)
{
if(change>=1)/*�����������ı�ʱ��������*/
{
do
{
i=((unsigned)rand())%4;
 j=((unsigned)rand())%4;
}
while(code[i][j]!=0);
if(((unsigned)rand())%4==0)
{
code[i][j]=4;
}
else
{
code[i][j]=2;/*���ѡһ���ո�����2��4*/
}
move++;/*���Ӵ���*/
 }
 print();/*��ʾ*/
input=getch();/*���뷽��*/
change=0;
switch(input)
{
case '0':/*�˳�*/
printf("Are you sure to exit?(y/n)");
input=getchar();
if(input=='y'||input=='Y')
exit(0);
 break;
case 'W':
case 'w':/*��*/
 for(j=0;j<=3;j++)
 {
for(i=0;i<=3;i++)
 {
temp[i]=code[i][j];/*��һ�����Ƶ��м����*/
 }
temp[4]=0;
 change=change+add();
for(i=0;i<=3;i++)
 {
code[i][j]=temp[i];/*�Ѵ����õ��м�����ƻ���*/
 }
 }
break;
case 'A':
case 'a':/*��*/
 for(i=0;i<=3;i++)
{
 for(j=0;j<=3;j++)
{
temp[j]=code[i][j];/*��һ�����Ƶ��м����*/
}
temp[4]=0;
change=change+add();
for(j=0;j<=3;j++)
{
code[i][j]=temp[j];/*�Ѵ����õ��м�����ƻ���*/
}
}
break;
case 'S':
case 's':/*��*/
for(j=0;j<=3;j++)
{
 for(i=0;i<=3;i++)
{
temp[i]=code[3-i][j];/*��һ�����Ƶ��м����*/
}
temp[4]=0;
change=change+add();
 for(i=0;i<=3;i++)
{
code[3-i][j]=temp[i];/*�Ѵ����õ��м�����ƻ���*/
}
}
break;
 case 'D':
case 'd':/*��*/
for(i=0;i<=3;i++)
{
for(j=0;j<=3;j++)
{
temp[j]=code[i][3-j];/*��һ�����Ƶ��м����*/
}
temp[4]=0;
change=change+add();
 for(j=0;j<=3;j++)
{
code[i][3-j]=temp[j];/*�Ѵ����õ��м�����ƻ���*/
 }
}
 break;
}
 gameover=1;
for(i=0;i<=3;i++)
for(j=0;j<=3;j++)
if(code[i][j]==0)
gameover=0;/*���и��Ӷ���������Ϸ����*/
}
printf("Game over!\n");
 getch();
return 0;
