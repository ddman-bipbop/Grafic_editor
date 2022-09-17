#pragma once
#include "IncludeLibrary.h"
#include "Property.h"
#include "Description.h"

const int W = 200;
const int H = 170;
const int pixel = 5;

struct Rastr
{
	Property prop;
	SDL_Rect rect = { 0, 0, pixel, pixel };
	RGB arr[W][H];
	// ����������� �����������
	void Draw(SDL_Renderer* renderer, SDL_Event event, Description& des);
	// ����������� ���� � ����������
	void DrawProp(SDL_Renderer* renderer, SDL_Event event, Description& des);
	// ����� �����
	void draw_text(SDL_Renderer* ren, char* text, SDL_Rect rect, TTF_Font* my_font, SDL_Color front_color, SDL_Color back_color);
	
	// ��������� ����������� � ����
	bool SaveImage(RGB arr[W][H]);
	// ��������� ����������� �� �����
	bool LoadImage(RGB arr[W][H]);

};