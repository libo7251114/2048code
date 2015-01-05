void main()
{
 Init(); CTRL c;
 while(true)
 {
  c = GetControl();
  DispatchControl(c);  // ���˳�ʱ����ʾ�Ի�����ѯ�û��Ƿ��˳�
  if (c == CTRL_QUIT)
  {
   HWND wnd = GetHWnd();
   if (MessageBox(wnd, "��Ҫ�˳���Ϸ��", "����", MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
    Quit();
  }
 }
}
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