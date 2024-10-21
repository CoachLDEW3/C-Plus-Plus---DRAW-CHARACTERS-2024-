/************************************************************************************************
Name:		CoachLDEW
Date:	 	10.21.2024
Purpose: 	This program is a demonstration of drawing a character to a specific position the in 
			the console window. The	position is indecated using X and Y coordinates, the color 
			using an int  and the character itself
*************************************************************************************************/
#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library contains the function to control the cursor position


using namespace std;

//Function to hide the cursor
void HideCursor()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window
	//Data Structure that controls the apearance of the cursor.  It has two attributes dwSize and bVisible
	CONSOLE_CURSOR_INFO cursor;
	//This attribute changes the size of the cursor. Here it is set at 100%
	cursor.dwSize = 100;
	//This Boolean attribute sets the cursor to visible or invisible.  False is invisible
	cursor.bVisible = false;

	//Manipulates the characteristics it takes two parameters.  The ID of the console window and a data structure that
	//handles the appearance of the cursor
	//You have to pass the cursor variable by reference so that it can make changes to the actual object
	SetConsoleCursorInfo(hOut, &cursor);
}//End HideCursor()


void SetColor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return;
	/************************************************************************************************
				 0 - BLACK			6 - YELLOW			12 - LIGHTRED
				 1 - BLUE			7 - WHITE			13 - LIGHTPURPLE
				 2 - GREEN			8 - GREY			14 - LIGHTYELLOW
				 3 - AQUA			9 - LIGHTBLUE		15 - BRIGHT WHITE
				 4 - RED			10 - LIGHTGREEN
				 5 - PURPLE			11 - LIGHTAQUA
	*************************************************************************************************/
}

void GoToXY(double x, double y)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//Get the ID of the console window

	COORD coord;								//Variable of type COORD that holds the X and Y position
	coord.X = x;
	coord.Y = y;

	//Takes two parameters.  The ID of the console window and Structure of the type COORD which are the coordinates where
	//we want to position the cursor.	
	SetConsoleCursorPosition(hOut, coord);
}//End GoToXY


void DrawCharacter(unsigned char x, unsigned char y, unsigned char Color, char Character)
{
	SetColor(Color);
	GoToXY(x, y);
	cout << Character;
}


int main()
{
	bool gameOver = false;

	while (!gameOver)
	{
		//Hit the escape key to end the program
		if (GetAsyncKeyState(VK_ESCAPE)) gameOver = true;

		HideCursor();		
		DrawCharacter(4, 4, 1, 'A');
		DrawCharacter(5, 5, 2, 'B');
		DrawCharacter(6, 6, 3, 'C');
		DrawCharacter(7, 7, 4, 'D');
		DrawCharacter(8, 8, 5, 'E');
		DrawCharacter(9, 9, 6, 'F');
		DrawCharacter(10, 10, 7, 'G');
	}

	return 0;
}