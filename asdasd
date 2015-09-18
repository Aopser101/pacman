#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

bool valid_move(char next_position){
	if (next_position == 'X'){
		return false;
	}
	else{
		return true;
	}
}

void drawmap(char map[][10]){
	for (int row = 0; row<10; row++){
		for (int column = 0; column<10; column++){
			cout << map[row][column];
		}
		cout << '\n';
	}
}

int main(){
	int i, j, x = 5, y = 5, ch;
	char map[10][10] = {
		"XXXXXXXXX",
		"X     XXX",
		"X XXX XXX",
		"X XXX XXX",
		"X XXX XXX",
		"X XXX  XX",
		"X XXX  XX",
		"XoXXX  XX",
		"X      XX",
		"XXXXXXXXX",
	};
	cout << "Welcome to Matthew Wang's text-based PAC-MAN. The objective of the game" << '\n';
	cout << "is to get to the 'o'. Use the arrow keys to move around." << '\n';
	cout << "Press ESC to quit playing" << '\n' << '\n';
	drawmap(map);
	while (true){
		ch = getch();
		switch (ch)
		{
		case 72:	// move up
			if (x - 1 >= 0){
				system("CLS");
				if (valid_move(map[x - 1][y]) == true){
					map[x][y] = ' ';
					x--;
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				if (x == 7 && y == 1){
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
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				if (x == 7 && y == 1){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case 80:	// move down
			if (x + 1<10){
				system("CLS");
				if (valid_move(map[x + 1][y]) == true){
					map[x][y] = ' ';
					x++;
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				if (x == 7 && y == 1){
					cout << "Congratulations, you won! Press Esc to exit the game.";
				}
			}
			break;
		case 77:	//move right
			if (y + 1<10){
				system("CLS");
				if (valid_move(map[x][y + 1]) == true){
					map[x][y] = ' ';
					y++;
					map[x][y] = '+';
					drawmap(map);
				}
				else{
					drawmap(map);
				}
				if (x == 7 && y == 1){
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
