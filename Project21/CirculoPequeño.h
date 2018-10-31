#pragma once
#include "CirculoPadre.h"
class CirculoP :public padre
{
public:
	CirculoP(void);
	~CirculoP(void);
	void cambiar_imagen(char*nuevo);
	void mostrar(Graphics^gr);
	void Mover(Graphics^gr,int JX,int JY);
};
CirculoP::CirculoP() :padre()
{

}

void CirculoP::cambiar_imagen(char*nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	W = (bmp->Width /8.95);
	H = (bmp->Height);
	delete bmp;
}
void CirculoP::mostrar(Graphics^gr)
{
	Bitmap^bmp = gcnew Bitmap(gcnew String(imagen));
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(indiceW*W, indiceH*H, W, H);
	System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, W/3, H/3);
	gr->DrawImage(bmp, zoom, porcion, System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
}
void CirculoP::Mover(Graphics^gr, int JX, int JY)
{
	if (indiceH == 0 && indiceW == 8)
	{
		indiceH = 0;
		indiceW = 0;
	}

	if ((y<=JY&&y+H/3>=JY )&& x<JX)
	{
		x++;
		x += dx;
	}
	if ((y <= JY&&y + H / 3 >= JY) && x>JX)
	{
		x--;
		x -= dx;
	}
	if ((x <= JX&&x + W / 3 >= JX) && y<JY)
	{
		y++;
		y += dy;
	}
	if ((x <= JX&&x + W / 3 >= JX) && y>JY)
	{
		y--;
		y -= dy;
	}
	indiceW++;

	mostrar(gr);
}
CirculoP::~CirculoP()
{

}
