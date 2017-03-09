#include "StdAfx.h"
#include "MyRoundRect.h"

MyRoundRect::MyRoundRect(void)
{
	shape=4;
}

MyRoundRect::~MyRoundRect(void)
{
}

void MyRoundRect::draw(CDC* dc,bool changeDc)
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

	dc->RoundRect(begin.x,begin.y,end.x,end.y,8,8);

	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}
