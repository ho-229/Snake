#pragma once
#define U 1
#define D 2
#define L 3 
#define R 4
#define PAUSE 0
#define GAME_DATA_SIZE sizeof DATA

#include<deque>
#include<ctime>
using namespace std;

typedef struct
{
	size_t x;
	size_t y;
}COORDINATE;

typedef struct
{
	int Score;
	int Endgamestatus;
	int Difficulty;
	tm game_time;
}DATA;

class Food
{
public:
	COORDINATE food_coord;
	bool food_kind;				//true:粉苹果;false:红苹果
	void createfood(deque<COORDINATE> & s_coord);
};

class GameData
{
public:
	void In_Game_Data(int, int);
	void In_Game_Best(int, int);
	void Print_Game_Data();
private:
	DATA game_data[7];
	DATA game_best;
};

class Snake
{
public:
	Snake();
	~Snake();
private:
	Food f;
	int status = NULL, sleeptime = 200, score;
	int endgamestatus = 0;		//游戏结束的情况，1：撞到墙；2：咬到自己；3：主动退出游戏。
	deque<COORDINATE>snake_coord;
	GameData data;
private:
	void move();
	void Print_snake();
	void keyboardControl();
	void AI_Control();
	bool snake_is_alive();
	void Print_Score(clock_t);
	void end_game();
};

int ChooseError;
int difficulty = 0;
bool Game_Mode;					//ture:手动;false:AI

void menu();
void welcome();
void welcome_to_game();
void explation();
void Aboutauthor();
void createMap();