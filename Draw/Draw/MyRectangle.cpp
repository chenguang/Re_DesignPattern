#include "StdAfx.h"
#include "MyRectangle.h"


MyRectangle::MyRectangle(void)
{
	shape=3;
}

MyRectangle::~MyRectangle(void)
{
}

void MyRectangle::draw(CDC* dc,bool changeDc)
{
	CBrush *oldBrush;
	CPen *oldPen;
	CBrush b(this->brushColor);
	CPen pen(PS_SOLID,1,color);
	if(changeDc)
	{		
		oldBrush = dc->SelectObject(&b);		
		oldPen = dc->SelectObject(&pen);
	}
	dc->Rectangle(begin.x,begin.y,end.x,end.y);
	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}
