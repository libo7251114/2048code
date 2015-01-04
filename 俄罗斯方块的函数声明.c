#include <graphics.h>
#include <conio.h>
#include <time.h> /////////////////////////////////////////////
// ���峣����ö�������ṹ�塢ȫ�ֱ���
/////////////////////////////////////////////#define WIDTH 10  // ��Ϸ�����
#define HEIGHT 22  // ��Ϸ���߶�
#define SIZE 20  // ÿ����Ϸ����λ��ʵ������// �����������
enum CTRL
{
 CTRL_ROTATE,      // ������ת
 CTRL_LEFT, CTRL_RIGHT, CTRL_DOWN, // �������ҡ����ƶ�
 CTRL_SINK,       // �������
 CTRL_QUIT       // �˳���Ϸ
};// ������Ʒ���ķ���
enum DRAW
{
 SHOW, // ��ʾ����
 HIDE, // ���ط���
 FIX  // �̶�����
};// �������ֶ���˹����
struct BLOCK
{
 WORD dir[4]; // ������ĸ���ת״̬
 COLORREF color; // �������ɫ
} g_Blocks[7] = { {0x0F00, 0x4444, 0x0F00, 0x4444, RED},  // I
     {0x0660, 0x0660, 0x0660, 0x0660, BLUE},  // ��
     {0x4460, 0x02E0, 0x0622, 0x0740, MAGENTA}, // L
     {0x2260, 0x0E20, 0x0644, 0x0470, YELLOW}, // ��L
     {0x0C60, 0x2640, 0x0C60, 0x2640, CYAN},  // Z
     {0x0360, 0x4620, 0x0360, 0x4620, GREEN}, // ��Z
     {0x4E00, 0x4C40, 0x0E40, 0x4640, BROWN}}; // T// ���嵱ǰ���顢��һ���������Ϣ
struct BLOCKINFO
{
 byte id; // ���� ID
 char x, y; // ��������Ϸ���е�����
 byte dir:2; // ����
} g_CurBlock, g_NextBlock;// ������Ϸ��
BYTE g_World[WIDTH][HEIGHT] = {0}; /////////////////////////////////////////////
// ��������
/////////////////////////////////////////////void Init();           // ��ʼ����Ϸ
void Quit();           // �˳���Ϸ
void NewGame();           // ��ʼ����Ϸ
void GameOver();          // ������Ϸ
CTRL GetControl(bool _onlyresettimer = false);   // ��ȡ��������
void DispatchControl(CTRL _ctrl);      // �ַ���������
void NewBlock();          // �����µķ���
bool CheckBlock(BLOCKINFO _block);      // ���ָ�������Ƿ���Է���
void DrawBlock(BLOCKINFO _block, DRAW _draw = SHOW); // ������
void OnRotate();          // ��ת����
void OnLeft();           // ���Ʒ���
void OnRight();           // ���Ʒ���
void OnDown();           // ���Ʒ���
void OnSink();           // ���׷��� 