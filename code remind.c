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
code[i][j]=temp[i];/*�Ѵ���õ��м�����ƻ���*/                   
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
code[i][j]=temp[j];/*�Ѵ���õ��м�����ƻ���*/                    
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
code[3-i][j]=temp[i];/*�Ѵ���õ��м�����ƻ���*/                    
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
code[i][3-j]=temp[j];/*�Ѵ���õ��м�����ƻ���*/                   
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
}