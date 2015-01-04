j=((unsigned)rand())%4;            
}
while(code[i][j]!=0);            
if(((unsigned)rand())%4==0)            
{                
code[i][j]=4;            
}            
else            
{                
code[i][j]=2;/*随机选一个空格填上2或4*/            
}            
move++;/*增加次数*/       
 }       
 print();/*显示*/        
input=getch();/*输入方向*/        
change=0;        
switch(input)        
{            
case '0':/*退出*/                
printf("Are you sure to exit?(y/n)");                
input=getchar();                
if(input=='y'||input=='Y')                    
exit(0);               
 break;            
case 'W':            
case 'w':/*上*/               
 for(j=0;j<=3;j++)               
 {                   
for(i=0;i<=3;i++)                   
 {                        
temp[i]=code[i][j];/*把一列数移到中间变量*/                   
 }                    
temp[4]=0;                   
 change=change+add();                    
for(i=0;i<=3;i++)                   
 {                        
code[i][j]=temp[i];/*把处理好的中间变量移回来*/                   
 }               
 }                
break;            
case 'A':            
case 'a':/*左*/               
 for(i=0;i<=3;i++)                
{                   
 for(j=0;j<=3;j++)                    
{                        
temp[j]=code[i][j];/*把一行数移到中间变量*/                    
}                    
temp[4]=0;                    
change=change+add();                    
for(j=0;j<=3;j++)                    
{                        
code[i][j]=temp[j];/*把处理好的中间变量移回来*/                    
}                
}                
break;            
case 'S':            
case 's':/*下*/                
for(j=0;j<=3;j++)                
{                   
 for(i=0;i<=3;i++)                    
{                        
temp[i]=code[3-i][j];/*把一列数移到中间变量*/                    
}                    
temp[4]=0;                    
change=change+add();                   
 for(i=0;i<=3;i++)                    
{                        
code[3-i][j]=temp[i];/*把处理好的中间变量移回来*/                    
}                
}                
break;           
 case 'D':            
case 'd':/*右*/                
for(i=0;i<=3;i++)                
{                    
for(j=0;j<=3;j++)                    
{                        
temp[j]=code[i][3-j];/*把一行数移到中间变量*/                    
}                    
temp[4]=0;                    
change=change+add();                   
 for(j=0;j<=3;j++)                    
{                        
code[i][3-j]=temp[j];/*把处理好的中间变量移回来*/                   
 }                
}               
 break;        
}       
 gameover=1;        
for(i=0;i<=3;i++)            
for(j=0;j<=3;j++)                
if(code[i][j]==0)                    
gameover=0;/*所有格子都填满则游戏结束*/    
}    
printf("Game over!\n");   
 getch();    
return 0;
}