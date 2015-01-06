// ��ʼ����Ϸ
void Init()
{
 initgraph(640, 480);
 srand((unsigned)time(NULL)); // ��ʾ����˵��
 setfont(14, 0, "����");
 outtextxy(20, 330, "����˵��");
 outtextxy(20, 350, "�ϣ���ת");
 outtextxy(20, 370, "������");
 outtextxy(20, 390, "�ң�����");
 outtextxy(20, 410, "�£�����");
 outtextxy(20, 430, "�ո񣺳���");
 outtextxy(20, 450, "ESC���˳�"); // ��������ԭ��
 setorigin(220, 20); // ������Ϸ���߽�
 rectangle(-1, -1, WIDTH * SIZE, HEIGHT * SIZE);
 rectangle((WIDTH + 1) * SIZE - 1, -1, (WIDTH + 5) * SIZE, 4 * SIZE); // ��ʼ����Ϸ
 NewGame();
}
// �˳���Ϸ
void Quit()
{
 closegraph();
 exit(0);
}
// ��ʼ����Ϸ
void NewGame()
{
 // �����Ϸ��
 setfillstyle(BLACK);
 bar(0, 0, WIDTH * SIZE - 1, HEIGHT * SIZE - 1);
 ZeroMemory(g_World, WIDTH * HEIGHT); // ������һ������
 g_NextBlock.id = rand() % 7;
 g_NextBlock.dir = rand() % 4;
 g_NextBlock.x = WIDTH + 1;
 g_NextBlock.y = HEIGHT - 1; // ��ȡ�·���
 NewBlock();
}
// ������Ϸ
void GameOver()
{
 HWND wnd = GetHWnd();
 if (MessageBox(wnd, "��Ϸ������\n����������һ����", "��Ϸ����", MB_YESNO | MB_ICONQUESTION) == IDYES)
  NewGame();
 else
  Quit();
}
// ��ȡ��������
CTRL GetControl(bool _onlyresettimer)
{
 static DWORD oldtime = GetTickCount(); // ���ü�ʱ��
 if (_onlyresettimer)
 {
  oldtime = GetTickCount();
  return CTRL_DOWN; // ����Ϊ�����ü�ʱ������㷵��һ��ֵ
 } // ��ȡ����ֵ
 while(true)
 {
  // �����ʱ���Զ�����һ��
  DWORD newtime = GetTickCount();
  if (newtime - oldtime >= 500)
  {
   oldtime = newtime;
   return CTRL_DOWN;
  }  // ����а��������ذ�����Ӧ�Ĺ���
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