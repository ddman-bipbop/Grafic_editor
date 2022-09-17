#pragma once
#include "IncludeLibrary.h"

struct Description 
{
	char* text = new char[75];// буфер для текста. Например чисел
	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);// шрифт
	SDL_Color colorFront = { 255, 255, 255, 0 };
	SDL_Color colorBack = { 150, 0, 150, 0 };
	SDL_Color colorBlack = { 0, 0, 0, 0 };

	char textColor[6] = "Color";
	SDL_Rect rectTextColor = { 1030,25,125,30 };

	// красный цвет
	char textR[5] = "R = ";
	SDL_Rect rectTextR = { 1040,100,70,30 };
	SDL_Rect rectTextRedValue = { 1100,103,50,25 };
	SDL_Rect rectRedSquad = { 1010,103,25,25 };
	SDL_Rect rectRedLine = { 1020,150,169,3 };
	SDL_Rect rectRedSquareValue = { 1030,138,25,25 };

	// зелёный цвет
	char textG[5] = "G = ";
	SDL_Rect rectTextG = { 1040,180,70,30 };
	SDL_Rect rectTextGreenValue = { 1100,183,50,25 };
	SDL_Rect rectGreenSquad = { 1010,183,25,25 };
	SDL_Rect rectGreenLine = { 1020,233,169,3 };
	SDL_Rect rectGreenSquareValue = { 1030,221,25,25 };

	// синий цвет
	char textB[5] = "B = ";
	SDL_Rect rectTextB = { 1040,260,70,30 };
	SDL_Rect rectTextBlueValue = { 1100,263,50,25 };
	SDL_Rect rectBlueSquad = { 1010,263,25,25 };
	SDL_Rect rectBlueLine = { 1020,313,169,3 };
	SDL_Rect rectBlueSquareValue = { 1030,301,25,25 };

	// текущий цвет
	SDL_Rect rectWhiteSquad = { 1050,360,100,50 };
	SDL_Rect rectCurrentColor = { 1055,365,90,40 };

	// кнопка CLEAR
	char textClear[6] = "Clear";
	SDL_Rect rectTextClear = { 1035,810,120,30 };
	SDL_Rect rectWhiteSquadClear = { 1025,800,150,50 };
	
	// толщина пера
	char textTickness[9] = "Tickness";
	SDL_Rect rectTextTickness = { 1005,440,140,30 };
	SDL_Rect rectTextTicknessValue = { 1150,443,50,25 };
	SDL_Rect rectTicknessLine = { 1020,500,169,3 };
	SDL_Rect rectTicknessSquareValue = { 1030,488,25,25 };

	// стирка
	char textEraser[9] = "Eraser";
	SDL_Rect rectTextEraser = { 1060,553,120,30 };
	SDL_Rect rectEraserWhiteSquare = { 1010,550,40,40 };
	SDL_Rect rectSelectEraser = { 1016,556,29,29 };

	// перо
	char textPen[9] = "Pen";
	SDL_Rect rectTextPen = { 1060,623,60,30 };
	SDL_Rect rectPenWhiteSquare = { 1010,620,40,40 };
	SDL_Rect rectSelectPen = { 1016,626,29,29 };

	// update
	char textUpdate[7] = "Update";
	SDL_Rect rectTextUpdate = { 400,860,100,30 };

	// сохранить
	char textSave[5] = "Save";
	SDL_Rect rectTextSave = { 30,860,70,30 };
	SDL_Rect rectSaveSquare = { 25,855,80,40 };

	// загрузить
	char textLoad[5] = "Load";
	SDL_Rect rectTextLoad = { 130,860,70,30 };
	SDL_Rect rectLoadSquare = { 125,855,80,40 };

	// координаты 

	// X
	int tempX = 0;
	char* textX = new char[75];// буфер для текста. Например чисел
	SDL_Rect rectX = { 800,860,50,30 };

	char textCoord[2] = ";";
	SDL_Rect rectCoord = { 850,860,30,30 };

	int tempY = 0;
	char* textY = new char[75];// буфер для текста. Например чисел
	SDL_Rect rectY = { 880,860,50,30 };

};