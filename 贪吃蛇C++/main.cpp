#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<thread>
#include<mutex>
#include"GUI.h"
#include"main.h"

mutex mtx;			//互斥锁
					/*↓GAME↓*/
void menu()
{
	int n;
	system("mode con cols=65 lines=20");
	GUI(6, 12, 7, 54, 15);
	gotoxy(23, 2);
	color(14);
	cout << "贪 吃 蛇 大 作 战";
	color(11);
	gotoxy(15, 8);
	cout << "1.开始游戏";
	gotoxy(35, 8);
	cout << "2.游戏说明";
	gotoxy(15, 10);
	cout << "3.游戏记录";
	gotoxy(35, 10);
	cout << "0.退出游戏";
	if (ChooseError == 1)
	{
		color(12);
		gotoxy(19, 15);
		cout << "请输入0 - 3之间的数！！！";
	}
	gotoxy(21, 13);
	color(12);
	cout << "请选择[0 - 3]:[ ]\b\b";
	color(14);
	cin >> n;
	switch (n)
	{
	case 1:
		ChooseError = 0;
		welcome_to_game();
		break;
	case 2:
		ChooseError = 0;
		explation();
		break;
	case 0:
		exit(0);
		break;
	case 3:
		ChooseError = 0;
		GameData gd;
		gd.Print_Game_Data();
		break;
	default:
		ChooseError = 1;
		break;
	}
	return;
}

void welcome_to_game()
{
	int n;
start:
	system("mode con cols=65 lines=20");
	GUI(6, 12, 7, 54, 15);
	gotoxy(23, 2);
	color(14);
	cout << "贪 吃 蛇 大 作 战";
	color(11);
	gotoxy(15, 9);
	cout << "1.普通";
	gotoxy(27, 9);
	cout << "2.困难";
	gotoxy(38, 9);
	cout << "0.返回菜单";
	if (ChooseError == 2)
	{
		color(12);
		gotoxy(19, 15);
		cout << "请输入0 - 2之间的数！！！";
	}
	color(12);
	gotoxy(21, 13);
	cout << "请选择[0 1 2]:[ ]\b\b";
	color(14);
	cin >> n;
	switch (n)
	{
	case 1:
		srand((unsigned)time(NULL));
		ChooseError = 0;
		difficulty = 1;
		break;
	case 2:
		srand((unsigned)time(NULL));
		ChooseError = 0;
		difficulty = 2;
		break;
	case 0:
		ChooseError = 0;
		return;
	default:
		ChooseError = 2;
		goto start;
	}
	system("cls");
	GUI(6, 12, 7, 54, 15);
	gotoxy(23, 2);
	color(14);
	cout << "贪 吃 蛇 大 作 战";
	color(11);
	gotoxy(15, 9);
	cout << "1.手动";
	gotoxy(27, 9);
	cout << "2.AI";
	gotoxy(38, 9);
	cout << "0.返回菜单";
	if (ChooseError == 2)
	{
		color(12);
		gotoxy(19, 15);
		cout << "请输入0 - 2之间的数！！！";
	}
	color(12);
	gotoxy(21, 13);
	cout << "请选择[0 1 2]:[ ]\b\b";
	color(14);
	cin >> n;
	switch (n)
	{
	case 1:
		ChooseError = 0;
		Game_Mode = true;
		break;
	case 2:
		ChooseError = 0;
		Game_Mode = false;
		break;
	case 0:
		ChooseError = 0;
		return;
	default:
		ChooseError = 2;
		goto start;
	}
	system("mode con cols=59 lines=28");
	createMap();
	Snake s;
	return;
}

void explation()
{
	int i, j = 1, ch;
	system("mode con cols=100 lines=30");
	color(13);
	gotoxy(42, 3);
	cout << "游 戏 说 明";
	color(15);
	for (i = 6; i <= 22; i++)
	{
		for (j = 20; j <= 75; j++)
		{
			gotoxy(j, i);
			if (i == 6 || i == 22) cout << "=";
			else if (j == 20 || j == 75) cout << "||";
		}
	}
	color(11);
	gotoxy(30, 8);
	cout << "tip1: 不能撞墙，不能咬到自己（困难模式）";
	color(10);
	gotoxy(30, 11);
	cout << "tip2: 用↑.↓.←.→分别控制蛇的移动";
	color(14);
	gotoxy(30, 14);
	cout << "tip3: F1 为加速，F2 为减速";
	color(11);
	gotoxy(30, 17);
	cout << "tip4: 按空格键暂停游戏，再按空格键继续";
	color(12);
	gotoxy(30, 20);
	cout << "tip5: Esc ：退出游戏";
	color(14);
	gotoxy(30, 23);
	cout << "返回菜单-------0  关于作者-------1 选择:";
	cin >> ch;
	if (ch == 1)
		Aboutauthor();
	else
		menu();
	return;
}

void Aboutauthor()
{
	int i, j = 1;
	system("mode con cols=100 lines=30");
	color(13);
	gotoxy(42, 3);
	cout << "关 于 作 者";
	color(15);
	for (i = 6; i <= 22; i++)
	{
		for (j = 20; j <= 75; j++)
		{
			gotoxy(j, i);
			if (i == 6 || i == 22) cout << "=";
			else if (j == 20 || j == 75) cout << "||";
		}
	}
	color(11);
	gotoxy(30, 8);
	cout << "作者：(17)14 黄飞翰";
	color(10);
	gotoxy(30, 11);
	cout << "QQ:2189684957";
	color(14);
	gotoxy(30, 14);
	cout << "Programming Language: C++";
	color(11);
	gotoxy(30, 17);
	cout << "2019/4/30";
	color(13);
	gotoxy(30, 20);
	cout << "Made With Microsoft Visual Studio 2017";
	color(14);
	gotoxy(37, 23);
	cout << "按任意键返回菜单...";
	_getch();
	menu();
}

void createMap()
{
	int i, j;
	for (i = 0; i < 58; i += 2)
	{
		gotoxy(i, 0);
		color(5);
		cout << "□";
		gotoxy(i, 26);
		cout << "□";
	}
	for (i = 1; i < 26; i++)
	{
		gotoxy(0, i);
		cout << "□";
		gotoxy(56, i);
		cout << "□";
	}
	for (i = 2; i < 56; i += 2)
	{
		for (j = 1; j < 26; j++)
		{
			gotoxy(i, j);
			color(2);
			cout << "■";
		}
	}
}

void welcome()
{
	time_t now;
	tm lt;
	time(&now);
	localtime_s(&lt, &now);
	system("mode con cols=110 lines=30");
	gotoxy(35, 1);
	color(15);
	cout << "/^\\/^\\";
	gotoxy(34, 2);
	cout << "|__|  O|";
	gotoxy(33, 2);
	color(15);
	cout << "_";
	gotoxy(25, 3);
	color(15);
	cout << "\\/";
	gotoxy(31, 3);
	color(15);
	cout << "/";
	gotoxy(37, 3);
	color(15);
	cout << " \\_/";
	gotoxy(41, 3);
	color(15);
	cout << " \\";
	gotoxy(26, 4);
	color(15);
	cout << "\\____";
	gotoxy(32, 4);
	cout << "_________/";
	gotoxy(31, 4);
	color(15);
	cout << "|";
	gotoxy(43, 4);
	color(15);
	cout << "\\";
	gotoxy(32, 5);
	color(15);
	cout << "\\_______";
	gotoxy(44, 5);
	color(15);
	cout << "\\";
	gotoxy(39, 6);
	cout << "|     |                  \\";
	gotoxy(38, 7);
	cout << "/      /                   \\";
	gotoxy(37, 8);
	cout << "/      /                    \\ \\";
	gotoxy(35, 9);
	cout << "/      /                       \\ \\";
	gotoxy(34, 10);
	cout << "/     /                          \\  \\";
	gotoxy(33, 11);
	cout << "/     /             _----_         \\   \\";
	gotoxy(32, 12);
	cout << "/     /           _-~      ~-_         |  |";
	gotoxy(31, 13);
	cout << "(      (        _-~    _--_    ~-_     _/  |";
	gotoxy(32, 14);
	cout << "\\     ~-____-~    _-~    ~-_    ~-_-~    /";
	gotoxy(33, 15);
	cout << "~-_           _-~          ~-_       _-~";
	gotoxy(35, 16);
	cout << "~--______-~                ~-___-~\n";
	color(14);
	gotoxy(40, 19);
	cout << "贪   吃   蛇   大   作   战";
	if (lt.tm_mon + 1 == 12 && lt.tm_mday == 24)	/*小燕我喜欢你*/
	{
		color(13);
		gotoxy(48, 21);
		cout << "生日快乐!";
	}
}
						/*↑GAME↑*/
						/*↓SNAKE↓*/
Snake::Snake()
{
	COORDINATE snake_head;
	snake_head.x = 24;
	snake_head.y = 5;
	snake_coord.push_front(snake_head);
	for (size_t i = 1; i <= 4; i++)
	{
		snake_head.x = 24 + 2 * i;
		snake_coord.push_front(snake_head);
	}
	this->Print_snake();
	this->f.createfood(snake_coord);
	if (Game_Mode)
	{
		thread KeyboardControlThread([&]() {
			this->keyboardControl();
		});
		thread SnakeMoveThread([=]() {
			clock_t start = clock();
			while (this->snake_is_alive() && !this->endgamestatus)
			{
				mtx.lock();
				this->move();
				mtx.unlock();
				this->Print_Score(start);
				Sleep(this->sleeptime);
			}
		});
		KeyboardControlThread.join();
		SnakeMoveThread.join();
	}
	else
			this->AI_Control();
	this->end_game();
}

Snake::~Snake()
{
	snake_coord.clear();
}

void Snake::Print_snake()
{
	color(14);
	for (size_t i = 0; i < snake_coord.size(); i++)
	{
		gotoxy(snake_coord[i].x, snake_coord[i].y);
		cout << "★";
	}
}

void Snake::move()
{
	COORDINATE nexthead;
	if (status == U)
	{
		nexthead.x = snake_coord[0].x;
		nexthead.y = snake_coord[0].y - 1;
		snake_coord.push_front(nexthead);
		if (nexthead.x == f.food_coord.x && nexthead.y == f.food_coord.y)
		{
			this->Print_snake();
			if (f.food_kind == true)
				score += 20;
			else if (f.food_kind == false)
				score += 10;
			f.createfood(snake_coord);
		}
		else
		{
			this->Print_snake();
			gotoxy(snake_coord[snake_coord.size() - 1].x, snake_coord[snake_coord.size() - 1].y);
			color(2);
			cout << "■";
			snake_coord.pop_back();
		}
	}
	else if (status == D)
	{
		nexthead.x = snake_coord[0].x;
		nexthead.y = snake_coord[0].y + 1;
		snake_coord.push_front(nexthead);
		if (nexthead.x == f.food_coord.x && nexthead.y == f.food_coord.y)
		{
			this->Print_snake();
			if (f.food_kind == true)
				score += 20;
			else if (f.food_kind == false)
				score += 10;
			f.createfood(snake_coord);
		}
		else
		{
			this->Print_snake();
			gotoxy(snake_coord[snake_coord.size() - 1].x, snake_coord[snake_coord.size() - 1].y);
			color(2);
			cout << "■";
			snake_coord.pop_back();
		}
	}
	else if (status == L)
	{
		nexthead.x = snake_coord[0].x - 2;
		nexthead.y = snake_coord[0].y;
		snake_coord.push_front(nexthead);
		if (nexthead.x == f.food_coord.x && nexthead.y == f.food_coord.y)
		{
			this->Print_snake();
			if (f.food_kind == true)
				score += 20;
			else if (f.food_kind == false)
				score += 10;
			f.createfood(snake_coord);
		}
		else
		{
			this->Print_snake();
			gotoxy(snake_coord[snake_coord.size() - 1].x, snake_coord[snake_coord.size() - 1].y);
			color(2);
			cout << "■";
			snake_coord.pop_back();
		}
	}
	else if (status == R)
	{
		nexthead.x = snake_coord[0].x + 2;
		nexthead.y = snake_coord[0].y;
		snake_coord.push_front(nexthead);
		if (nexthead.x == f.food_coord.x&&nexthead.y == f.food_coord.y)
		{
			this->Print_snake();
			if (f.food_kind == true)
				score += 20;
			else if (f.food_kind == false)
				score += 10;
			f.createfood(snake_coord);
		}
		else
		{
			this->Print_snake();
			gotoxy(snake_coord[snake_coord.size() - 1].x, snake_coord[snake_coord.size() - 1].y);
			color(2);
			cout << "■";
			snake_coord.pop_back();
		}
	}
	return;
}

void Snake::keyboardControl()
{
	status = R;
	while (endgamestatus == 0)
	{
		if (GetAsyncKeyState(VK_UP) && status != D)
			status = U;
		else if (GetAsyncKeyState(VK_DOWN) && status != U)
			status = D;
		else if (GetAsyncKeyState(VK_LEFT) && status != R)
			status = L;
		else if (GetAsyncKeyState(VK_RIGHT) && status != L)
			status = R;
		if (GetAsyncKeyState(VK_SPACE))
		{
			int Temp = status;
			status = PAUSE;
			Sleep(100);
			while (!GetAsyncKeyState(VK_SPACE));
			status = Temp;
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			endgamestatus = 3;
			break;
		}
		if (GetAsyncKeyState(VK_F1))
			sleeptime = 100;
		else if (GetAsyncKeyState(VK_F2))
			sleeptime = 300;
		else
			sleeptime = 200;
		Sleep(50);
	}
	return;
}

void Snake::Print_Score(clock_t start)
{
	int s;
	color(14);
	gotoxy(12, 27);
	cout << "总分:";
	color(13);
	cout << score;
	clock_t stop = clock();
	s = (stop - start) / CLK_TCK;
	color(14);
	gotoxy(33, 27);
	cout << "用时:";
	color(11);
	cout << s << "s";
}

bool Snake::snake_is_alive()
{
	if (snake_coord[0].x == 0 || snake_coord[0].x == 56 || snake_coord[0].y == 0 || snake_coord[0].y == 26)
	{
		endgamestatus = 1;
		return false;
	}
	if (difficulty == 2)
	{
		for (size_t i = 1; i < snake_coord.size(); i++)
		{
			if (snake_coord[0].x == snake_coord[i].x&&snake_coord[0].y == snake_coord[i].y)
			{
				endgamestatus = 2;
				return false;
			}
		}
	}
	return true;
}

void Snake::end_game()
{
	int ch;
	system("mode con cols=100 lines=30");
	GUI(3, 23, 18, 80, 15);
	this->data.In_Game_Data(score, endgamestatus);
	this->data.In_Game_Best(score, endgamestatus);
	if (endgamestatus == 1)
	{
		gotoxy(34, 5);
		color(12);
		cout << "对不起，您撞到墙了。游戏结束！";
	}
	else if (endgamestatus == 2)
	{
		gotoxy(34, 5);
		color(12);
		cout << "对不起，您咬到自己了，游戏结束！";
	}
	if (score <= 100 && score > 0)
	{
		color(14);
		gotoxy(45, 8);
		cout << "☆";
		Sleep(300);
		gotoxy(48, 8);
		cout << "★";
		Sleep(300);
		gotoxy(51, 8);
		cout << "☆";
	}
	else if (score <= 200 && score > 100)
	{
		color(14);
		gotoxy(45, 8);
		cout << "★";
		Sleep(300);
		gotoxy(48, 8);
		cout << "★";
		Sleep(300);
		gotoxy(51, 8);
		cout << "☆";
	}
	else if (score > 200)
	{
		color(14);
		gotoxy(45, 8);
		cout << "★";
		Sleep(300);
		gotoxy(48, 8);
		cout << "★";
		Sleep(300);
		gotoxy(51, 8);
		cout << "★";
	}
	gotoxy(23, 18);
	color(14);
	cout << "我要重新玩一局-------1";
	gotoxy(53, 18);
	cout << "不玩了，退出吧-------2";
	gotoxy(45, 21);
	color(11);
	cin.clear();
	cout << "选择：";
	cin >> ch;
	if (ch == 2)
		exit(0);
	else
		return;
}

void Snake::AI_Control()
{
	clock_t start = clock();
	this->sleeptime = 100;
	while (endgamestatus == 0 && this->snake_is_alive())
	{
		if (f.food_coord.x < snake_coord[0].x)
		{
			for (size_t j = 0; j < snake_coord[0].x - f.food_coord.x; j += 2)
			{
				for (size_t i = 1; i < snake_coord.size(); i++)
				{
					if (snake_coord[i].x == snake_coord[0].x - j && snake_coord[i].y == snake_coord[0].y)
					{
						if (snake_coord[snake_coord.size() - 1].y > snake_coord[0].y && status != U)
							status = D;
						else
							status = U;
						goto start_move;
					}
				}
			}
			if (status != R)
				status = L;
			goto start_move;
		}
		if (f.food_coord.x > snake_coord[0].x)
		{
			for (size_t j = 0; j < f.food_coord.x - snake_coord[0].x; j += 2)
			{
				for (size_t i = 1; i < snake_coord.size(); i++)
				{
					if (snake_coord[i].x == snake_coord[0].x + j && snake_coord[i].y == snake_coord[0].y)
					{
						if (snake_coord[snake_coord.size() - 1].y > snake_coord[0].y && status != U)
							status = D;
						else
							status = U;
						goto start_move;
					}
				}
			}
			if (status != L)
				status = R;
			goto start_move;
		}
		if (f.food_coord.y < snake_coord[0].y)
		{
			for (size_t j = 0; j < snake_coord[0].y - f.food_coord.y; j++)
			{
				for (size_t i = 1; i < snake_coord.size(); i++)
				{
					if (snake_coord[i].x == snake_coord[0].x && snake_coord[i].y == snake_coord[0].y - j)
					{
						if (snake_coord[snake_coord.size() - 1].x > snake_coord[0].x && status != L)
							status = R;
						else
							status = L;
						goto start_move;
					}
				}
			}
			if (status != D)
				status = U;
			goto start_move;
		}
		if (f.food_coord.y > snake_coord[0].y)
		{
			for (size_t j = 0; j < f.food_coord.y - snake_coord[0].y; j++)
			{
				for (size_t i = 1; i < snake_coord.size(); i++)
				{
					if (snake_coord[i].x == snake_coord[0].x && snake_coord[i].y == snake_coord[0].y + j)
					{
						if (snake_coord[snake_coord.size() - 1].x > snake_coord[0].x && status != L)
							status = R;
						else
							status = L;
						goto start_move;
					}
				}
			}
			if (status != U)
				status = D;
			goto start_move;
		}
	start_move:

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			endgamestatus = 3;
			return;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			int Temp = status;
			status = PAUSE;
			Sleep(100);
			while (!GetAsyncKeyState(VK_SPACE));
			status = Temp;
		}

		this->move();
		this->Print_Score(start);
		Sleep(100);
	}
}
/*↑SNAKE↑*/
/*↓FOOD↓*/
void Food::createfood(deque<COORDINATE> & s_coord)
{
	int temp = 0;
	for (size_t i = 0; i < 5; i++)
		if (rand() % 2 == 0)
			temp++;
	if (temp >= 4)
		food_kind = true;
	else
		food_kind = false;
start:
	do
	{
		food_coord.x = rand() % 52 + 2;
	} while (food_coord.x % 2 != 0);
	food_coord.y = rand() % 24 + 1;
	for (size_t i = 0; i < s_coord.size(); i++)
	{
		if (s_coord[i].x == food_coord.x && s_coord[i].y == food_coord.y)
			goto start;
	}
	gotoxy(food_coord.x, food_coord.y);
	if (food_kind == true)
		color(13);
	else if (food_kind == false)
		color(12);
	cout << "●";
}
/*↑FOOD↑*/
/*↓GAMEDATA↓*/
void GameData::In_Game_Data(int score, int endgamestatus)
{
	int number = 0, i;
	time_t now;
	time(&now);
	ifstream out("Game_Data.dat", ios::binary | ios::in);
	if (out.is_open())
	{
		while (out.read((char*)(&game_data[number]), GAME_DATA_SIZE))
			number++;
		out.close();
	}
	if (number < 7)
	{
		game_data[number].Score = score;
		game_data[number].Difficulty = difficulty;
		game_data[number].Endgamestatus = endgamestatus;
		localtime_s(&game_data[number].game_time, &now);
		number++;
	}
	else
	{
		for (i = 0; i < number; i++)
			game_data[i] = game_data[i + 1];
		game_data[6].Score = score;
		game_data[6].Difficulty = difficulty;
		game_data[6].Endgamestatus = endgamestatus;
		localtime_s(&game_data[6].game_time, &now);
	}
	ofstream in("Game_Data.dat", ios::binary | ios::trunc);
	if (in.is_open())
	{
		for (i = 0; i < number; i++)
			in.write((char*)(&game_data[i]), GAME_DATA_SIZE);
		in.close();
	}
	return;
}

void GameData::In_Game_Best(int score, int endgamestatus)
{
	time_t now;
	time(&now);
	ifstream out("Game_Best_Data.dat", ios::binary | ios::in);
	if (out.is_open())
	{
		out.read((char*)(&game_best), GAME_DATA_SIZE);
		out.close();
		if (score < game_best.Score)
		{
			gotoxy(42, 11);
			color(13);
			cout << "您的得分是:" << score;
			gotoxy(40, 13);
			cout << "离最高分还差:" << game_best.Score - score;
		}
		else
		{
			gotoxy(43, 11);
			color(13);
			cout << "新纪录:" << score;
			game_best.Score = score;
			game_best.Difficulty = difficulty;
			game_best.Endgamestatus = endgamestatus;
			localtime_s(&game_best.game_time, &now);
			ofstream in("Game_Best_Data.dat", ios::binary | ios::trunc);
			in.write((char*)(&game_best), GAME_DATA_SIZE);
			in.close();
		}
	}
	else
	{
		gotoxy(43, 11);
		color(13);
		cout << "新纪录:" << score;
		game_best.Score = score;
		game_best.Difficulty = difficulty;
		game_best.Endgamestatus = endgamestatus;
		localtime_s(&game_best.game_time, &now);
		ofstream in("Game_Best_Data.dat", ios::binary | ios::trunc);
		in.write((char*)(&game_best), GAME_DATA_SIZE);
		in.close();
	}
	return;
}

void GameData::Print_Game_Data()
{
	int number = 0, ch, i;
start:
	system("mode con cols=100 lines=30");
	color(13);
	gotoxy(42, 3);
	printf("游 戏 记 录");
	ifstream out1("Game_Data.dat", ios::binary | ios::in), out2("Game_Best_Data.dat", ios::binary | ios::in);
	if (out1.is_open() && out2.is_open())
	{
		while (out1.read((char*)(&game_data[number]), GAME_DATA_SIZE))
			number++;
		out1.close();
		out2.read((char*)(&game_best), GAME_DATA_SIZE);
		out2.close();
		color(11);
		gotoxy(39, 5);
		cout << "注:最近 " << number << " 次游戏记录";
		GUI(6, 8 + number * 2, 25, 70, 15);
		color(14);
		gotoxy(28, 7);
		cout << "难度     失败原因      分数       日期";
		color(15);
		gotoxy(34, 7);
		cout << "|";
		gotoxy(47, 7);
		cout << "|";
		gotoxy(57, 7);
		cout << "|";
		gotoxy(26, 8);
		cout << "--------+------------+---------+------------";
		for (i = 0; i < number; i++)
		{
			if (game_data[i].Difficulty == 1)
			{
				color(11);
				gotoxy(28, i * 2 + 9);
				cout << "简单";
			}
			else if (game_data[i].Difficulty == 2)
			{
				color(12);
				gotoxy(28, i * 2 + 9);
				cout << "困难";
			}
			if (game_data[i].Endgamestatus == 1)
			{
				color(12);
				gotoxy(38, i * 2 + 9);
				cout << "撞到墙";
			}
			else if (game_data[i].Endgamestatus == 2)
			{
				color(12);
				gotoxy(37, i * 2 + 9);
				cout << "咬到自己";
			}
			else if (game_data[i].Endgamestatus == 3)
			{
				color(12);
				gotoxy(37, i * 2 + 9);
				cout << "主动退出";
			}
			color(13);
			gotoxy(51, i * 2 + 9);
			cout << game_data[i].Score;
			color(11);
			gotoxy(59, i * 2 + 9);
			cout << game_data[i].game_time.tm_year + 1900 << "/" << game_data[i].game_time.tm_mon + 1 << "/" << game_data[i].game_time.tm_mday;
			color(15);
			gotoxy(34, i * 2 + 9);
			cout << "|";
			gotoxy(47, i * 2 + 9);
			cout << "|";
			gotoxy(57, i * 2 + 9);
			cout << "|";
		}
		for (i = 0; i < number - 1; i++)
		{
			color(15);
			gotoxy(26, i * 2 + 10);
			cout << "--------+------------+---------+------------";
		}
		color(13);
		gotoxy(20, 25);
		cout << "纪录:";
		GUI(24, 26, 25, 70, 14);
		if (game_best.Difficulty == 1)
		{
			color(11);
			gotoxy(28, 25);
			cout << "简单";
		}
		else if (game_best.Difficulty == 2)
		{
			color(12);
			gotoxy(28, 25);
			cout << "困难";
		}
		if (game_best.Endgamestatus == 1)
		{
			color(12);
			gotoxy(38, 25);
			cout << "撞到墙";
		}
		else if (game_best.Endgamestatus == 2)
		{
			color(12);
			gotoxy(37, 25);
			cout << "咬到自己";
		}
		else if (game_best.Endgamestatus == 3)
		{
			color(12);
			gotoxy(37, 25);
			cout << "主动退出";
		}
		color(13);
		gotoxy(51, 25);
		cout << game_best.Score;
		color(11);
		gotoxy(59, 25);
		cout << game_best.game_time.tm_year + 1900 << "/" << game_best.game_time.tm_mon + 1 << "/" << game_best.game_time.tm_mday;
		color(14);
		gotoxy(34, 25);
		cout << "|";
		gotoxy(47, 25);
		cout << "|";
		gotoxy(57, 25);
		cout << "|";
		color(13);
		gotoxy(30, 27);
		cout << "返回菜单-------0  清空记录-------1 选择:";
		cin >> ch;
		if (ch == 1)
		{
			remove("Game_Best_Data.dat");
			remove("Game_Data.dat");
			goto start;
		}
	}
	else
	{
		GUI(6, 10, 25, 70, 15);
		color(14);
		gotoxy(43, 8);
		cout << "无 记 录！";
		gotoxy(38, 11);
		color(11);
		cout << "按任意键返回菜单...";
		_getch();
	}
	return;
}
/*↑GAMEDATA↑*/
int main()
{
	welcome();
	Sleep(1500);
	while (true)
	{
		menu();
	}
}