// �ַ���������
void DispatchControl(CTRL _ctrl)
{
 switch(_ctrl)
 {
  case CTRL_ROTATE: OnRotate(); break;
  case CTRL_LEFT:  OnLeft(); break;
  case CTRL_RIGHT: OnRight(); break;
  case CTRL_DOWN:  OnDown(); break;
  case CTRL_SINK:  OnSink(); break;
  case CTRL_QUIT:  break;
 }
}
// �����µķ���
void NewBlock()
{
 g_CurBlock.id = g_NextBlock.id,  g_NextBlock.id = rand() % 7;
 g_CurBlock.dir = g_NextBlock.dir, g_NextBlock.dir = rand() % 4;
 g_CurBlock.x = (WIDTH - 4) / 2;
 g_CurBlock.y = HEIGHT + 2; // �����·���ֱ���оֲ���ʾ
 WORD c = g_Blocks[g_CurBlock.id].dir[g_CurBlock.dir];
 while((c & 0xF) == 0)
 {
  g_CurBlock.y--;
  c >>= 4;
 } // �����·���
 DrawBlock(g_CurBlock); // ������һ������
 setfillstyle(BLACK);
 bar((WIDTH + 1) * SIZE, 0, (WIDTH + 5) * SIZE - 1, 4 * SIZE - 1);
 DrawBlock(g_NextBlock);
}
// ������
void DrawBlock(BLOCKINFO _block, DRAW _draw)
{
 WORD b = g_Blocks[_block.id].dir[_block.dir];
 int x, y; int color = BLACK;
 switch(_draw)
 {
  case SHOW: color = g_Blocks[_block.id].color; break;
  case HIDE: color = BLACK; break;
  case FIX: color = g_Blocks[_block.id].color / 3; break;
 }
 setfillstyle(color); for(int i=0; i<16; i++)
 {
  if (b & 0x8000)
  {
   x = _block.x + i % 4;
   y = _block.y - i / 4;
   if (y < HEIGHT)
   {
    if (_draw != HIDE)
     bar3d(x * SIZE + 2, (HEIGHT - y - 1) * SIZE + 2, (x + 1) * SIZE - 4, (HEIGHT - y) * SIZE - 4, 3, true);
    else
     bar(x * SIZE, (HEIGHT - y - 1) * SIZE, (x + 1) * SIZE - 1, (HEIGHT - y) * SIZE - 1);
   }
  }
  b <<= 1;
 }
}
// ���ָ�������Ƿ���Է���
bool CheckBlock(BLOCKINFO _block)
{
 WORD b = g_Blocks[_block.id].dir[_block.dir];
 int x, y; for(int i=0; i<16; i++)
 {
  if (b & 0x8000)
  {
   x = _block.x + i % 4;
   y = _block.y - i / 4;
   if ((x < 0) || (x >= WIDTH) || (y < 0))
    return false;   if ((y < HEIGHT) && (g_World[x][y]))
    return false;
  }
  b <<= 1;
 } return true;
}
// ��ת����
void OnRotate()
{
 // ��ȡ������ת�� x ƫ����
 int dx;
 BLOCKINFO tmp = g_CurBlock;
 tmp.dir++;     if (CheckBlock(tmp)) { dx = 0;  goto rotate; }
 tmp.x = g_CurBlock.x - 1; if (CheckBlock(tmp)) { dx = -1; goto rotate; }
 tmp.x = g_CurBlock.x + 1; if (CheckBlock(tmp)) { dx = 1;  goto rotate; }
 tmp.x = g_CurBlock.x - 2; if (CheckBlock(tmp)) { dx = -2; goto rotate; }
 tmp.x = g_CurBlock.x + 2; if (CheckBlock(tmp)) { dx = 2;  goto rotate; }
 return;rotate:
 // ��ת
 DrawBlock(g_CurBlock, HIDE);
 g_CurBlock.dir++;
 g_CurBlock.x += dx;
 DrawBlock(g_CurBlock);
}