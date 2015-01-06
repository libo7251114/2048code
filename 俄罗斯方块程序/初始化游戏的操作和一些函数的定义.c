// 初始化游戏
void Init()
{
 initgraph(640, 480);
 srand((unsigned)time(NULL)); // 显示操作说明
 setfont(14, 0, "宋体");
 outtextxy(20, 330, "操作说明");
 outtextxy(20, 350, "上：旋转");
 outtextxy(20, 370, "左：左移");
 outtextxy(20, 390, "右：右移");
 outtextxy(20, 410, "下：下移");
 outtextxy(20, 430, "空格：沉底");
 outtextxy(20, 450, "ESC：退出"); // 设置坐标原点
 setorigin(220, 20); // 绘制游戏区边界
 rectangle(-1, -1, WIDTH * SIZE, HEIGHT * SIZE);
 rectangle((WIDTH + 1) * SIZE - 1, -1, (WIDTH + 5) * SIZE, 4 * SIZE); // 开始新游戏
 NewGame();
}
// 退出游戏
void Quit()
{
 closegraph();
 exit(0);
}
// 开始新游戏
void NewGame()
{
 // 清空游戏区
 setfillstyle(BLACK);
 bar(0, 0, WIDTH * SIZE - 1, HEIGHT * SIZE - 1);
 ZeroMemory(g_World, WIDTH * HEIGHT); // 生成下一个方块
 g_NextBlock.id = rand() % 7;
 g_NextBlock.dir = rand() % 4;
 g_NextBlock.x = WIDTH + 1;
 g_NextBlock.y = HEIGHT - 1; // 获取新方块
 NewBlock();
}
// 结束游戏
void GameOver()
{
 HWND wnd = GetHWnd();
 if (MessageBox(wnd, "游戏结束。\n您想重新来一局吗？", "游戏结束", MB_YESNO | MB_ICONQUESTION) == IDYES)
  NewGame();
 else
  Quit();
}
// 获取控制命令
CTRL GetControl(bool _onlyresettimer)
{
 static DWORD oldtime = GetTickCount(); // 重置计时器
 if (_onlyresettimer)
 {
  oldtime = GetTickCount();
  return CTRL_DOWN; // 仅仅为了重置计时器，随便返回一个值
 } // 获取控制值
 while(true)
 {
  // 如果超时，自动下落一格
  DWORD newtime = GetTickCount();
  if (newtime - oldtime >= 500)
  {
   oldtime = newtime;
   return CTRL_DOWN;
  }  // 如果有按键，返回按键对应的功能
  if (kbhit())
  {
   switch(getch())
   {
    case 'w':
    case 'W': return CTRL_ROTATE;
    case 'a':
    case 'A': return CTRL_LEFT;
    case 'd':
    case 'D': return CTRL_RIGHT;
    case 's':
    case 'S': return CTRL_DOWN;
    case 27: return CTRL_QUIT;
    case ' ': return CTRL_SINK;
    case 0:
    case 0xE0:
     switch(getch())
     {
      case 72: return CTRL_ROTATE;
      case 75: return CTRL_LEFT;
      case 77: return CTRL_RIGHT;
      case 80: return CTRL_DOWN;
     }
   }
  }
 }
}