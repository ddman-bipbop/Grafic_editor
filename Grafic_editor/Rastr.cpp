#include "Rastr.h"


void Rastr::draw_text(SDL_Renderer* ren, char* text, SDL_Rect rect, TTF_Font* my_font, SDL_Color front_color, SDL_Color back_color)
{
	//SDL_Color fore_color = { 130, 140, 50 };
	//SDL_Color back_color = { 0, 0, 0 };
	SDL_Surface* textSurface = NULL;
	textSurface = TTF_RenderText_Shaded(my_font, text, front_color, back_color);
	// создаем поверхность
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_RenderCopy(ren, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textSurface);
}



void Rastr::Draw(SDL_Renderer* renderer, SDL_Event event, Description& des)
{

	
		// Область рисования
		for (size_t i = 0; i < W; i++)
		{
			for (size_t j = 0; j < H; j++)
			{
				rect.x = pixel * i;
				rect.y = pixel * j;
				SDL_SetRenderDrawColor(renderer, arr[i][j].R, arr[i][j].G, arr[i][j].B, 0);
				SDL_RenderFillRect(renderer, &rect);

				if (event.button.button == SDL_BUTTON_LEFT && event.button.x > 0 && event.button.x < W * pixel &&
					event.button.y > 0 && event.button.y < H * pixel)
				{
					if (prop.eraser)
					{
						arr[event.button.x / pixel][event.button.y / pixel].R = 0; // посередине
						arr[event.button.x / pixel][event.button.y / pixel].G = 0; //
						arr[event.button.x / pixel][event.button.y / pixel].B = 0; //

						if (!(event.button.x <= pixel))
						{
							arr[event.button.x / pixel - 1][event.button.y / pixel].R = 0; // лево
							arr[event.button.x / pixel - 1][event.button.y / pixel].G = 0; //
							arr[event.button.x / pixel - 1][event.button.y / pixel].B = 0; //
						}

						if (!(event.button.x >= W * pixel - pixel))
						{
							arr[event.button.x / pixel + 1][event.button.y / pixel].R = 0; // право
							arr[event.button.x / pixel + 1][event.button.y / pixel].G = 0; //
							arr[event.button.x / pixel + 1][event.button.y / pixel].B = 0; //
						}

						if (!(event.button.y <= pixel))
						{
							arr[event.button.x / pixel][event.button.y / pixel - 1].R = 0; // верх
							arr[event.button.x / pixel][event.button.y / pixel - 1].G = 0; //
							arr[event.button.x / pixel][event.button.y / pixel - 1].B = 0; //
						}

						if (!(event.button.y >= H * pixel - pixel))
						{
							arr[event.button.x / pixel][event.button.y / pixel + 1].R = 0; // низ
							arr[event.button.x / pixel][event.button.y / pixel + 1].G = 0; //
							arr[event.button.x / pixel][event.button.y / pixel + 1].B = 0; //
						}

						if (!(event.button.y >= H * pixel - pixel) && !(event.button.x >= W * pixel - 2 * pixel))
						{
							arr[event.button.x / pixel + 1][event.button.y / pixel + 1].R = 0; // низ право
							arr[event.button.x / pixel + 1][event.button.y / pixel + 1].G = 0; //
							arr[event.button.x / pixel + 1][event.button.y / pixel + 1].B = 0; //
						}

						if (!(event.button.y >= H * pixel - pixel) && !(event.button.x <= 2 * pixel))
						{
							arr[event.button.x / pixel - 1][event.button.y / pixel + 1].R = 0; // низ лево
							arr[event.button.x / pixel - 1][event.button.y / pixel + 1].G = 0; //
							arr[event.button.x / pixel - 1][event.button.y / pixel + 1].B = 0; //
						}
						if (!(event.button.y <= pixel) && !(event.button.x >= W * pixel - 2 * pixel))
						{
							arr[event.button.x / pixel + 1][event.button.y / pixel - 1].R = 0; // верх право
							arr[event.button.x / pixel + 1][event.button.y / pixel - 1].G = 0; //
							arr[event.button.x / pixel + 1][event.button.y / pixel - 1].B = 0; //
						}
						if (!(event.button.y <= pixel) && !(event.button.x <= 2 * pixel))
						{
							arr[event.button.x / pixel - 1][event.button.y / pixel - 1].R = 0; // верх лево
							arr[event.button.x / pixel - 1][event.button.y / pixel - 1].G = 0; //
							arr[event.button.x / pixel - 1][event.button.y / pixel - 1].B = 0; //
						}
					}
					if (prop.pen)
					{
						switch (prop.thickness)
						{
						case 1:
							arr[event.button.x / pixel][event.button.y / pixel].R = prop.currentColor.R;
							arr[event.button.x / pixel][event.button.y / pixel].G = prop.currentColor.G;
							arr[event.button.x / pixel][event.button.y / pixel].B = prop.currentColor.B;
							break;
						case 2:
							arr[event.button.x / pixel][event.button.y / pixel].R = prop.currentColor.R; // посередине
							arr[event.button.x / pixel][event.button.y / pixel].G = prop.currentColor.G; //
							arr[event.button.x / pixel][event.button.y / pixel].B = prop.currentColor.B; //

							if (!(event.button.x <= pixel)) {
								arr[event.button.x / pixel - 1][event.button.y / pixel].R = prop.currentColor.R; // лево
								arr[event.button.x / pixel - 1][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel - 1][event.button.y / pixel].B = prop.currentColor.B; //
							}

							if (!(event.button.x >= W * pixel - pixel))
							{
								arr[event.button.x / pixel + 1][event.button.y / pixel].R = prop.currentColor.R; // право
								arr[event.button.x / pixel + 1][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel + 1][event.button.y / pixel].B = prop.currentColor.B; //
							}

							if (!(event.button.y <= pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel - 1].R = prop.currentColor.R; // верх
								arr[event.button.x / pixel][event.button.y / pixel - 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel - 1].B = prop.currentColor.B; //
							}

							if (!(event.button.y >= H * pixel - pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel + 1].R = prop.currentColor.R; // низ
								arr[event.button.x / pixel][event.button.y / pixel + 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel + 1].B = prop.currentColor.B; //
							}

							break;
						case 3:
							arr[event.button.x / pixel][event.button.y / pixel].R = prop.currentColor.R; // посередине
							arr[event.button.x / pixel][event.button.y / pixel].G = prop.currentColor.G; //
							arr[event.button.x / pixel][event.button.y / pixel].B = prop.currentColor.B; //

							if (!(event.button.x <= pixel))
							{
								arr[event.button.x / pixel - 1][event.button.y / pixel].R = prop.currentColor.R; // лево
								arr[event.button.x / pixel - 1][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel - 1][event.button.y / pixel].B = prop.currentColor.B; //
							}

							if (!(event.button.x >= W * pixel - pixel))
							{
								arr[event.button.x / pixel + 1][event.button.y / pixel].R = prop.currentColor.R; // право
								arr[event.button.x / pixel + 1][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel + 1][event.button.y / pixel].B = prop.currentColor.B; //
							}

							if (!(event.button.y <= pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel - 1].R = prop.currentColor.R; // верх
								arr[event.button.x / pixel][event.button.y / pixel - 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel - 1].B = prop.currentColor.B; //
							}

							if (!(event.button.y >= H * pixel - pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel + 1].R = prop.currentColor.R; // низ
								arr[event.button.x / pixel][event.button.y / pixel + 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel + 1].B = prop.currentColor.B; //
							}

							if (!(event.button.y >= H * pixel - pixel) && !(event.button.x >= W * pixel - 2 * pixel))
							{
								arr[event.button.x / pixel + 1][event.button.y / pixel + 1].R = prop.currentColor.R; // низ право
								arr[event.button.x / pixel + 1][event.button.y / pixel + 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel + 1][event.button.y / pixel + 1].B = prop.currentColor.B; //
							}

							if (!(event.button.y >= H * pixel - pixel) && !(event.button.x <= 2 * pixel))
							{
								arr[event.button.x / pixel - 1][event.button.y / pixel + 1].R = prop.currentColor.R; // низ лево
								arr[event.button.x / pixel - 1][event.button.y / pixel + 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel - 1][event.button.y / pixel + 1].B = prop.currentColor.B; //
							}
							if (!(event.button.y <= pixel) && !(event.button.x >= W * pixel - 2 * pixel))
							{
								arr[event.button.x / pixel + 1][event.button.y / pixel - 1].R = prop.currentColor.R; // верх право
								arr[event.button.x / pixel + 1][event.button.y / pixel - 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel + 1][event.button.y / pixel - 1].B = prop.currentColor.B; //
							}
							if (!(event.button.y <= pixel) && !(event.button.x <= 2 * pixel))
							{
								arr[event.button.x / pixel - 1][event.button.y / pixel - 1].R = prop.currentColor.R; // верх лево
								arr[event.button.x / pixel - 1][event.button.y / pixel - 1].G = prop.currentColor.G; //
								arr[event.button.x / pixel - 1][event.button.y / pixel - 1].B = prop.currentColor.B; //
							}

							if (!(event.button.y >= H * pixel - 2 * pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel + 2].R = prop.currentColor.R; // низ низ
								arr[event.button.x / pixel][event.button.y / pixel + 2].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel + 2].B = prop.currentColor.B; //
							}

							if (!(event.button.y <= 2 * pixel))
							{
								arr[event.button.x / pixel][event.button.y / pixel - 2].R = prop.currentColor.R; // верх верх
								arr[event.button.x / pixel][event.button.y / pixel - 2].G = prop.currentColor.G; //
								arr[event.button.x / pixel][event.button.y / pixel - 2].B = prop.currentColor.B; //
							}
							if (!(event.button.x >= W * pixel - 2 * pixel))
							{
								arr[event.button.x / pixel + 2][event.button.y / pixel].R = prop.currentColor.R; // право право
								arr[event.button.x / pixel + 2][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel + 2][event.button.y / pixel].B = prop.currentColor.B; //
							}
							if (!(event.button.x <= 2 * pixel))
							{
								arr[event.button.x / pixel - 2][event.button.y / pixel].R = prop.currentColor.R; // лево лево
								arr[event.button.x / pixel - 2][event.button.y / pixel].G = prop.currentColor.G; //
								arr[event.button.x / pixel - 2][event.button.y / pixel].B = prop.currentColor.B; //
							}
						}
					}



				}

			}
		}
	
	
	
}



void Rastr::DrawProp(SDL_Renderer* renderer, SDL_Event event, Description& des)
{
	// Цвет
	draw_text(renderer, des.textColor, des.rectTextColor, des.my_font, des.colorFront, des.colorBack);

	// Красный цвет
	draw_text(renderer, des.textR, des.rectTextR, des.my_font, des.colorFront, des.colorBack); // текст R
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(renderer, &des.rectRedSquad);	// красный квадрат
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectRedLine);	// линия
	SDL_RenderFillRect(renderer, &des.rectRedSquareValue);	// ползунок
	if (event.button.x >= des.rectRedSquareValue.x && event.button.x <= des.rectRedSquareValue.x + des.rectRedSquareValue.w &&
		event.button.y >= des.rectRedSquareValue.y && event.button.y <= des.rectRedSquareValue.y + des.rectRedSquareValue.h &&
		event.button.button == SDL_BUTTON_LEFT &&
		event.button.x >= des.rectRedLine.x && event.button.x <= des.rectRedLine.x + des.rectRedLine.w)
	{
		des.rectRedSquareValue.x = event.button.x - des.rectRedSquareValue.w / 2;
		prop.currentColor.R = 1.7 * des.rectRedSquareValue.x - 1713;
		if (prop.currentColor.R > 255) prop.currentColor.R = 255;
	}
	itoa(prop.currentColor.R, des.text, 10);
	draw_text(renderer, des.text, des.rectTextRedValue, des.my_font, des.colorFront, des.colorBack);

	// Зелёный цвет
	draw_text(renderer, des.textG, des.rectTextG, des.my_font, des.colorFront, des.colorBack); // текст G
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(renderer, &des.rectGreenSquad);	// зелёный квадрат
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectGreenLine);	// линия
	SDL_RenderFillRect(renderer, &des.rectGreenSquareValue);	// ползунок
	if (event.button.x >= des.rectGreenSquareValue.x && event.button.x <= des.rectGreenSquareValue.x + des.rectGreenSquareValue.w &&
		event.button.y >= des.rectGreenSquareValue.y && event.button.y <= des.rectGreenSquareValue.y + des.rectGreenSquareValue.h &&
		event.button.button == SDL_BUTTON_LEFT &&
		event.button.x >= des.rectGreenLine.x && event.button.x <= des.rectGreenLine.x + des.rectGreenLine.w)
	{
		des.rectGreenSquareValue.x = event.button.x - des.rectGreenSquareValue.w / 2;
		prop.currentColor.G = 1.7 * des.rectGreenSquareValue.x - 1713;
		if (prop.currentColor.G > 255) prop.currentColor.G = 255;
	}
	itoa(prop.currentColor.G, des.text, 10);
	draw_text(renderer, des.text, des.rectTextGreenValue, des.my_font, des.colorFront, des.colorBack);

	// Синий цвет
	draw_text(renderer, des.textB, des.rectTextB, des.my_font, des.colorFront, des.colorBack); // текст B
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectBlueSquad);	// синий квадрат
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectBlueLine);	// линия
	SDL_RenderFillRect(renderer, &des.rectBlueSquareValue);	// ползунок
	if (event.button.x >= des.rectBlueSquareValue.x && event.button.x <= des.rectBlueSquareValue.x + des.rectBlueSquareValue.w &&
		event.button.y >= des.rectBlueSquareValue.y && event.button.y <= des.rectBlueSquareValue.y + des.rectBlueSquareValue.h &&
		event.button.button == SDL_BUTTON_LEFT &&
		event.button.x >= des.rectBlueLine.x && event.button.x <= des.rectBlueLine.x + des.rectBlueLine.w)
	{
		des.rectBlueSquareValue.x = event.button.x - des.rectBlueSquareValue.w / 2;
		prop.currentColor.B = 1.7 * des.rectBlueSquareValue.x - 1713;
		if (prop.currentColor.B > 255) prop.currentColor.B = 255;
	}
	itoa(prop.currentColor.B, des.text, 10);
	draw_text(renderer, des.text, des.rectTextBlueValue, des.my_font, des.colorFront, des.colorBack);

	// Текущий цвет
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectWhiteSquad);
	SDL_SetRenderDrawColor(renderer, prop.currentColor.R, prop.currentColor.G, prop.currentColor.B, 0);
	SDL_RenderFillRect(renderer, &des.rectCurrentColor);

	// Кнопка CLEAR
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectWhiteSquadClear);
	draw_text(renderer, des.textClear, des.rectTextClear, des.my_font, des.colorBlack, des.colorFront);
	if (event.button.x >= des.rectWhiteSquadClear.x && event.button.x <= des.rectWhiteSquadClear.x + des.rectWhiteSquadClear.w &&
		event.button.y >= des.rectWhiteSquadClear.y && event.button.y <= des.rectWhiteSquadClear.y + des.rectWhiteSquadClear.h &&
		event.button.button == SDL_BUTTON_LEFT) 
	{
		for (size_t i = 0; i < W; i++)
		{
			for (size_t j = 0; j < H; j++)
			{
				arr[i][j].R = 0;
				arr[i][j].G = 0;
				arr[i][j].B = 0;
			}
		}
	}

	// Толщина пера
	draw_text(renderer, des.textTickness, des.rectTextTickness, des.my_font, des.colorFront, des.colorBack);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectTicknessLine);	// линия
	SDL_RenderFillRect(renderer, &des.rectTicknessSquareValue);	// ползунок
	if (event.button.x >= des.rectTicknessSquareValue.x && event.button.x <= des.rectTicknessSquareValue.x + des.rectTicknessSquareValue.w &&
		event.button.y >= des.rectTicknessSquareValue.y && event.button.y <= des.rectTicknessSquareValue.y + des.rectTicknessSquareValue.h &&
		event.button.button == SDL_BUTTON_LEFT &&
		event.button.x >= des.rectTicknessLine.x && event.button.x <= des.rectTicknessLine.x + des.rectTicknessLine.w)
	{
		des.rectTicknessSquareValue.x = event.button.x - des.rectTicknessSquareValue.w / 2;
		prop.thickness = 0.02 * des.rectTicknessSquareValue.x - 19;
		if (prop.thickness > 3) prop.thickness = 3;
	}
	itoa(prop.thickness, des.text, 10);
	draw_text(renderer, des.text, des.rectTextTicknessValue, des.my_font, des.colorFront, des.colorBack);

	// Выбор инструментов

	// Стирка
	draw_text(renderer, des.textEraser, des.rectTextEraser, des.my_font, des.colorFront, des.colorBack);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectEraserWhiteSquare);
	if (!prop.eraser) 
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderFillRect(renderer, &des.rectSelectEraser);
	}
	else 
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderFillRect(renderer, &des.rectSelectEraser);
	}
		
	if (event.button.x >= des.rectEraserWhiteSquare.x && event.button.x <= des.rectEraserWhiteSquare.x + des.rectEraserWhiteSquare.w &&
		event.button.y >= des.rectEraserWhiteSquare.y && event.button.y <= des.rectEraserWhiteSquare.y + des.rectEraserWhiteSquare.h &&
		event.button.button == SDL_BUTTON_LEFT)
	{
		
		
		prop.eraser = true;
		prop.pen = false;
	}

	// Перо
	draw_text(renderer, des.textPen, des.rectTextPen, des.my_font, des.colorFront, des.colorBack);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &des.rectPenWhiteSquare);
	if (!prop.pen) 
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderFillRect(renderer, &des.rectSelectPen);
	}
	else 
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
		SDL_RenderFillRect(renderer, &des.rectSelectPen);
	}
		
	if (event.button.x >= des.rectPenWhiteSquare.x && event.button.x <= des.rectPenWhiteSquare.x + des.rectPenWhiteSquare.w &&
		event.button.y >= des.rectPenWhiteSquare.y && event.button.y <= des.rectPenWhiteSquare.y + des.rectPenWhiteSquare.h &&
		event.button.button == SDL_BUTTON_LEFT)
	{
		prop.eraser = false;
		prop.pen = true;
	}

	// Кнопка Update
	draw_text(renderer, des.textUpdate, des.rectTextUpdate, des.my_font, des.colorBlack, des.colorFront);
	if (event.button.x >= des.rectTextUpdate.x && event.button.x <= des.rectTextUpdate.x + des.rectTextUpdate.w &&
		event.button.y >= des.rectTextUpdate.y && event.button.y <= des.rectTextUpdate.y + des.rectTextUpdate.h &&
		event.button.button == SDL_BUTTON_LEFT)
	{
		prop.saveImage = false;
		prop.loadImage = false;
	}

	// Кнопка Save
	if (!prop.saveImage)
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	else
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(renderer, &des.rectSaveSquare);
	draw_text(renderer, des.textSave, des.rectTextSave, des.my_font, des.colorBlack, des.colorFront);
	if (event.button.x >= des.rectSaveSquare.x && event.button.x <= des.rectSaveSquare.x + des.rectSaveSquare.w &&
		event.button.y >= des.rectSaveSquare.y && event.button.y <= des.rectSaveSquare.y + des.rectSaveSquare.h &&
		event.button.button == SDL_BUTTON_LEFT && !prop.saveImage)
	{
		prop.saveImage = true;
		if (prop.saveImage)
		{
			SaveImage(arr);
		}
		
	}
		
	// Кнопка Load
	if (!prop.loadImage)
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	else
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(renderer, &des.rectLoadSquare);
	draw_text(renderer, des.textLoad, des.rectTextLoad, des.my_font, des.colorBlack, des.colorFront);
	if (event.button.x >= des.rectLoadSquare.x && event.button.x <= des.rectLoadSquare.x + des.rectLoadSquare.w &&
		event.button.y >= des.rectLoadSquare.y && event.button.y <= des.rectLoadSquare.y + des.rectLoadSquare.h &&
		event.button.button == SDL_BUTTON_LEFT && !prop.loadImage)
	{
		prop.loadImage = true;
		if (prop.loadImage)
		{
			LoadImage(arr);
		}

	}

	// Координаты 

	// Х
	
	if (event.button.x / pixel > 0 && event.button.x / pixel <= W) des.tempX = event.button.x / pixel;
	itoa(des.tempX, des.textX, 10);
	draw_text(renderer, des.textX, des.rectX, des.my_font, des.colorFront, des.colorBack);

	draw_text(renderer, des.textCoord, des.rectCoord, des.my_font, des.colorFront, des.colorBack);

	if (event.button.y / pixel > 0 && event.button.y / pixel <= H) des.tempY = event.button.y / pixel;
	itoa(des.tempY, des.textY, 10);
	draw_text(renderer, des.textY, des.rectY, des.my_font, des.colorFront, des.colorBack);
}



bool Rastr::SaveImage(RGB arr[W][H])
{
	string filename; // название файла
	cout << "*** Сохранение в файл ***\nВведите названия файла.txt" << endl;
	cin >> filename;
	ofstream oFile(filename, ios_base::out | ios_base::trunc);
	for (size_t i = 0; i < W; i++)
	{
		for (size_t j = 0; j < H; j++) 
		{
			oFile << arr[i][j].R << " " << arr[i][j].G << " " << arr[i][j].B << endl;
		}
	}
	oFile.close();
	
	return true;
}



bool Rastr::LoadImage(RGB arr[W][H])
{
	string filename; // название файла
	cout << "*** Загрузить из файла ***\nВведите названия файла.txt" << endl;
	cin >> filename;
	ifstream iFile(filename, ios_base::in);
	if (!iFile.is_open()) // если файл не открыт
	{
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
		return false;
	}
	else
	{
		for (size_t i = 0; i < W; i++)
		{
			for (size_t j = 0; j < H; j++) 
			{
				iFile >> arr[i][j].R;
				iFile >> arr[i][j].G;
				iFile >> arr[i][j].B;
			}
		}
	}
	iFile.close();
	return true;
}