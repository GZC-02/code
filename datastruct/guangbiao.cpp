#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
#define  TITLE  "学生信息管理系统"
#define  AUTHOR "作者:杨源鑫"
#define  DATE   "日期:2017年8月22日"
//定义枚举Keyboard的键值数据 
enum 
{
	UP = 72,
	DOWN = 80 ,
	LEFT = 75 ,
	RIGHT = 77 ,
	ENTER = 13 ,
	ESC = 27 ,
};
 
//定义要显示的菜单 
char *menu[] = 
{
	"＊学生信息添加＊",
	"＊学生信息查找＊",
	"＊学生信息打印＊",
	"＊学生信息修改＊",
	"＊学生信息删除＊",
	"＊    退出    ＊",
};
//定义结构体
CONSOLE_CURSOR_INFO cci; 
//定义默认的坐标位置  	
COORD pos = {0,0};
//显示菜单 
void showmenu(HANDLE hOut ,char **menu , int size , int index) ;
//获取用户输入 
int  get_userinput(int *index , int size) ;
int main()
{
    int i;
    int ret ;
    int index = 0 ;
    HANDLE hOut;
    SetConsoleTitleA(TITLE);
    //获取当前的句柄---设置为标准输出句柄 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //获取光标信息
    GetConsoleCursorInfo(hOut, &cci); 
	//设置光标大小   
    cci.dwSize = 1; 
	//设置光标不可见 FALSE   
    cci.bVisible =  0; 
    //设置(应用)光标信息
    SetConsoleCursorInfo(hOut, &cci);   
    while(1)
    {
    	showmenu(hOut , menu , NR(menu) , index);
		ret = get_userinput(&index , NR(menu));
		if(ret == ESC)
			break ;
		if(ret == ENTER)
		{
			switch(index)
			{
				case 0:           break ;  	//学生信息添加
				case 1:           break ;  	//学生信息查找
				case 2:           break ;  	//学生信息打印
				case 3:           break ;  	//学生信息修改
				case 4:           break ;  	//学生信息删除
				case 5:           return 0 ;//退出
			}
		}
	}
    return 0;
}
 
void showmenu(HANDLE hOut ,char **menu , int size , int index)
{
	int i ; 
	system("cls");	
	//设置显示的文本的颜色 
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | 0x8); 
	//初始化控制台显示的X,Y轴的坐标 
	pos.X = 30;
	pos.Y = 0 ;
	//设置显示到控制台终端的具体位置 
	SetConsoleCursorPosition(hOut,pos);    
	//调用printf在控制台对应的位置上输出 
	printf("%s",TITLE);
	pos.X = 32;
	pos.Y = 1 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",AUTHOR);
	pos.X = 30;
	pos.Y = 2 ;
	SetConsoleCursorPosition(hOut,pos);    
	printf("%s",DATE);
	for(i = 0 ; i < size ; i++)
	{
		//如果i==index表示在当前选项的位置，默认初始化显示是第一项，显示为红色，
		//当按下上下按键选择的时候，光标会移动，也就看到了列表选择的现象 
		if(i == index)
		{
			//红色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | 0x8); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    
    		printf("%s",menu[i]);
		}
		//否则显示为白色 
		else
		{
			//白色 
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
			pos.X = 30;
    		pos.Y = 5+i;
    		//设置光标坐标
    		SetConsoleCursorPosition(hOut,pos);    //设置光标坐标
    		printf("%s",menu[i]);
		}
	}
	//刷新标准输出缓冲区 
	fflush(stdout);
}
 
//获取用户输入的接口 
int  get_userinput(int *index , int size)
{
	int ch ;
	ch = getch();
	switch(ch)
	{
		//上 
		//如果选择上，那么光标向上移动 
		case UP : if(*index > 0)  *index -= 1 ;  break; 
		//下 
		//如果选择下，那么光标向下移动 
		case DOWN :if(*index < size -1)  *index += 1 ;  break;
		//左 
		case LEFT: 
		case 97:return 0 ;
		//右 
		case RIGHT:return 0 ;
		//回车 
		case ENTER: return ENTER ;
		//ESC
		case ESC: return ESC ;
	}
	return 0 ;
}
