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
	RGB   currentColor;							// ������� ����
	bool  pen = true;							// ����
	int   thickness = 1;						// ������� ����
	bool  eraser = false;						// ������
	int   currentX, currentY;					// ������� ��������� ���� � X � Y
	bool  clear = false;						// �������� �������
	bool  saveImage = false, loadImage = false;	// ���������, ��������� �����������

};