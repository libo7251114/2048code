#include <graphics.h>
#include <conio.h>
#include <time.h> /////////////////////////////////////////////
// 定义常量、枚举量、结构体、全局变量
/////////////////////////////////////////////#define WIDTH 10  // 游戏区宽度
#define HEIGHT 22  // 游戏区高度
#define SIZE 20  // 每个游戏区单位的实际像素// 定义操作类型
enum CTRL
{
 CTRL_ROTATE,      // 方块旋转
 CTRL_LEFT, CTRL_RIGHT, CTRL_DOWN, // 方块左、右、下移动
 CTRL_SINK,       // 方块沉底
 CTRL_QUIT       // 退出游戏
};// 定义绘制方块的方法
enum DRAW
{
 SHOW, // 显示方块
 HIDE, // 隐藏方块
 FIX  // 固定方块
};// 定义七种俄罗斯方块
struct BLOCK
{
 WORD dir[4]; // 方块的四个旋转状态
 COLORREF color; // 方块的颜色
} g_Blocks[7] = { {0x0F00, 0x4444, 0x0F00, 0x4444, RED},  // I
     {0x0660, 0x0660, 0x0660, 0x0660, BLUE},  // 口
     {0x4460, 0x02E0, 0x0622, 0x0740, MAGENTA}, // L
     {0x2260, 0x0E20, 0x0644, 0x0470, YELLOW}, // 反L
     {0x0C60, 0x2640, 0x0C60, 0x2640, CYAN},  // Z
     {0x0360, 0x4620, 0x0360, 0x4620, GREEN}, // 反Z
     {0x4E00, 0x4C40, 0x0E40, 0x4640, BROWN}}; // T// 定义当前方块、下一个方块的信息
struct BLOCKINFO
{
 byte id; // 方块 ID
 char x, y; // 方块在游戏区中的坐标
 byte dir:2; // 方向
} g_CurBlock, g_NextBlock;// 定义游戏区
BYTE g_World[WIDTH][HEIGHT] = {0}; /////////////////////////////////////////////
// 函数声明
/////////////////////////////////////////////void Init();           // 初始化游戏
void Quit();           // 退出游戏
void NewGame();           // 开始新游戏
void GameOver();          // 结束游戏
CTRL GetControl(bool _onlyresettimer = false);   // 获取控制命令
void DispatchControl(CTRL _ctrl);      // 分发控制命令
void NewBlock();          // 生成新的方块
bool CheckBlock(BLOCKINFO _block);      // 检测指定方块是否可以放下
void DrawBlock(BLOCKINFO _block, DRAW _draw = SHOW); // 画方块
void OnRotate();          // 旋转方块
void OnLeft();           // 左移方块
void OnRight();           // 右移方块
void OnDown();           // 下移方块
void OnSink();           // 沉底方块 