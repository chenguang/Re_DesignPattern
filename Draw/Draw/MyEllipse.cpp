#include "StdAfx.h"
#include "MyEllipse.h"


MyEllipse::MyEllipse(void)
{
	shape=6;
}

MyEllipse::~MyEllipse(void)
{
}

void MyEllipse::draw(CDC* dc,bool changeDc)
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
	dc->Ellipse(begin.x,begin.y,end.x,end.y);
	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}