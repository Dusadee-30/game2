#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void setcursor(bool visible);
void gotoxy(int x, int y);
void erase_ship(int x, int y);
void erase(int x, int y);
void draw_ship(int x, int y);
void setcolor(int fg, int bg);
void createbullet(int x, int y);
void erase_bullet(int x, int y);
struct ans
{
	char ch = ' ';
	int x = 38, y = 23;
	int num[50];
	int bullet[5];
	int bulletx[5];
	int bullety[5]; 
}go;
int main()
{
	draw_ship(go.x, go.y);
	setcursor(0);
	do
	{
		if (_kbhit())
		{
			go.ch = _getch();

			if (go.ch == 'w')
			{
				go.num[0] = 1;
			}
			if (go.ch == 's')
			{
				go.num[0] = 2;
			}
			if (go.ch == 'a')
			{
				go.num[0] = 3;
			}
			if (go.ch == 'd')
			{
				go.num[0] = 4;
			}
			if (go.ch == ' ')
			{
				for (int i = 0; i < 5; i++)
				{
					if (go.bullet[i] == 0)
					{
						go.bullet[i] = 1;
						go.bulletx[i] = go.x+4;
						go.bullety[i] = go.y-1;
						createbullet(go.bulletx[i], go.bullety[i]);
						break;
					}
				}
			}

			fflush(stdin);
		}
		if (go.num[0] == 1)
		{
			draw_ship(go.x, go.y);
			
		}
		if (go.num[0] == 2 )
		{
			draw_ship(go.x, go.y);
		}
		if (go.num[0] == 3 && go.x > 0)
		{
			erase_ship(go.x, go.y);
			draw_ship(--go.x, go.y);
		}
		if (go.num[0] == 4 && go.x < 108)
		{
			erase_ship(go.x, go.y);
			draw_ship(++go.x, go.y);
		}
		for (int i = 0; i < 5; i++)
		{
			if (go.bullet[i] == 1)
			{
				erase_bullet(go.bulletx[i], go.bullety[i]);
				go.bullety[i] = go.bullety[i] - 1;
				if (go.bullety[i] > 0)
				{
					createbullet(go.bulletx[i], go.bullety[i]);
				}
				else
				{
					go.bullet[i] = 0;
				}
			}
			
		}
		Sleep(100);
		setcolor(2, 0);
	} while (go.ch != 'p');
}


void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);

}
void erase(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("  ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("            ");

}
void draw_ship(int x, int y)
{
	setcursor(0);
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" [--:0:--]  ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void createbullet(int x, int y )
{
	setcolor(6, 0);
	gotoxy(x, y);
	printf("-^-");
}
void erase_bullet(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	printf("   ");
}


