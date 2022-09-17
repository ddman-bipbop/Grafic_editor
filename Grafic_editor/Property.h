#pragma once
#include "IncludeLibrary.h"

struct RGB
{
	int R = 0;
	int G = 0;
	int B = 0;

};
struct Property 
{
	RGB   currentColor;							// текущий цвет
	bool  pen = true;							// перо
	int   thickness = 1;						// толщина пера
	bool  eraser = false;						// стирка
	int   currentX, currentY;					// текущие положение пера в X и Y
	bool  clear = false;						// очистить полотно
	bool  saveImage = false, loadImage = false;	// сохранить, загрузить изображение

};