#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "pathfinding.h"
using namespace std;

bool valid_move(char next_position){
	if (next_position == 'X'){
		return false;
	}
	else{
		return true;
	}
}

int updatepoints(int score, char c){
	if (c == '.'){
		return score + 1;
	}
	else{
		return score;
	}
}

void drawmap(char map[][30]){
	for (int row = 0; row<10; row++){
		for (int column = 0; column<30; column++){
			cout << map[row][column];
		}
		cout << '\n';
	}
}

int main(){
	Graph grid(30, 10);
	add_rect(grid, 0, 0, 1, 10);
	add_rect(grid, 1, 0, 30, 1);
	add_rect(grid, 12, 1, 13, 2);
	add_rect(grid, 16, 1, 17, 2);
	add_rect(grid, 12, 2, 13, 3);
	add_rect(grid, 16, 2, 17, 3);
	add_rect(grid, 12, 3, 17, 4);
	add_rect(grid, 1, 9, 30, 10);
	add_rect(grid, 29, 1, 30, 9);
	add_rect(grid, 4, 5, 25, 6);
	time_t start = time(0);
	char map[10][30] = {
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X...........X   X...........X",
		"X...........X   X...........X",
		"X.. ........XXXXX...........X",
		"X...........................X",
		"X...XXXXXXXXXXXXXXXXXXXXX...X",
		"X...........................X",
		"X...........................X",
		"X...........................X",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	};
	int i, j, x = 3, y = 3, ch, score = 0;
	cout << "Welcome to Matthew Wang's text-based PAC-MAN. The objective of the game" << '\n';
	cout << "is to get to eat all of the dots. Use the arrow keys to move around." << '\n';
	cout << "Press ESC to quit playing" << '\n' << '\n';
	drawmap(map);
	while (true){
		ch = _getch();
		switch (ch)
		{
		case 72:	// move up
			if (x - 1 >= 0){
				system("CLS");
				if (valid_move(map[x - 1][y]) == true){
					map[x][y] = ' ';
					x--;
					score = updatepoints(score, map[x][y]);
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				cout << "Score: " << score << "." << '\n';
				double seconds_since_start = difftime(time(0), start);
				cout << "You have been playing for " << seconds_since_start << " seconds" << '\n';
				if (score == 179){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case 75:	// move left
			if (y - 1 >= 0){
				system("CLS");
				if (valid_move(map[x][y - 1]) == true){
					map[x][y] = ' ';
					y--;
					score = updatepoints(score, map[x][y]);
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				cout << "Score: " << score << "." << '\n';
				double seconds_since_start = difftime(time(0), start);
				cout << "You have been playing for " << seconds_since_start << " seconds" << '\n';
				if (score == 179){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case 80:	// move down
			if (x + 1<30){
				system("CLS");
				if (valid_move(map[x + 1][y]) == true){
					map[x][y] = ' ';
					x++;
					score = updatepoints(score, map[x][y]);
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				cout << "Score: " << score << "." << '\n';
				double seconds_since_start = difftime(time(0), start);
				cout << "You have been playing for " << seconds_since_start << " seconds" << '\n';
				if (score == 179){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case 77:	//move right
			if (y + 1<30){
				system("CLS");
				if (valid_move(map[x][y + 1]) == true){
					map[x][y] = ' ';
					y++;
					score = updatepoints(score, map[x][y]);
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				cout << "Score: " << score << "." << '\n';
				double seconds_since_start = difftime(time(0), start);
				cout << "You have been playing for " << seconds_since_start << " seconds" << '\n';
				if (score == 179){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case VK_ESCAPE:
			goto exit;
			break;
		default:
			break;
		}
	}
exit:
	return 0;
}
