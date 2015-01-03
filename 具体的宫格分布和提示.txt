void drawBox()
{
int *box=game.box;
printf("\033[2J");//清屏
printf("\033[2H");//光标复位
printf("\033[?25l");//隐藏光标
printf(" steps: %8d points: %10lu \n",game.step,game.point);
printf("\033[;30m---------------------------------\n");
printf("\033[;30m| | | | |\n");
//printf("| %4d | %4d | %4d | %4d |\n",box[0],box[1],box[2],box[3]);
printf("\033[;30m| ");
printNum(box[0]); printf("\033[;30m | ");
printNum(box[1]); printf("\033[;30m | ");
printNum(box[2]); printf("\033[;30m | ");
printNum(box[3]); printf("\033[;30m |\n");
printf("\033[;30m| | | | |\n");
printf("\033[;30m+-------+-------+-------+-------+\n");
printf("\033[;30m| | | | |\n");
//printf("| %4d | %4d | %4d | %4d |\n",box[4],box[5],box[6],box[7]);
printf("\033[;30m| ");
printNum(box[4]); printf("\033[;30m | ");
printNum(box[5]); printf("\033[;30m | ");
printNum(box[6]); printf("\033[;30m | ");
printNum(box[7]); printf("\033[;30m |\n");
printf("\033[;30m| | | | |\n");
printf("\033[;30m+-------+-------+-------+-------+\n");
printf("\033[;30m| | | | |\n");
//printf("| %4d | %4d | %4d | %4d |\n",box[8],box[9],box[10],box[11]);
printf("\033[;30m| ");
printNum(box[8]); printf("\033[;30m | ");
printNum(box[9]); printf("\033[;30m | ");
printNum(box[10]); printf("\033[;30m | ");
printNum(box[11]); printf("\033[;30m |\n");
printf("\033[;30m| | | | |\n");
printf("\033[;30m+-------+-------+-------+-------+\n");
printf("\033[;30m| | | | |\n");
//printf("| %4d | %4d | %4d | %4d |\n",box[12],box[13],box[14],box[15]);
printf("\033[;30m| ");
printNum(box[12]); printf("\033[;30m | ");
printNum(box[13]); printf("\033[;30m | ");
printNum(box[14]); printf("\033[;30m | ");
printNum(box[15]); printf("\033[;30m |\n");
printf("\033[;30m| | | | |\n");
printf("\033[;30m---------------------------------\n");
if(game.stat==FAILED)
printf(" oh,failed! try again.\n");
else if(game.stat==DONE)
printf(" yeah,you won! \n");
else
}