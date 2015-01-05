void main()
{
 Init(); CTRL c;
 while(true)
 {
  c = GetControl();
  DispatchControl(c);  // 按退出时，显示对话框咨询用户是否退出
  if (c == CTRL_QUIT)
  {
   HWND wnd = GetHWnd();
   if (MessageBox(wnd, "您要退出游戏吗？", "提醒", MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
    Quit();
  }
 }
}
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