#include "StdAfx.h"
#include "MyRound.h"

MyRound::MyRound(void)
{
	shape=5;
}

MyRound::~MyRound(void)
{
}

void MyRound::draw(CDC* dc,bool changeDc)
{
	int x = end.x-begin.x;
	int y = end.y-begin.y;
	int l = abs(x)>abs(y)?y:x;

	CBrush *oldBrush;
	CPen *oldPen;
	CBrush b(this->brushColor);
	CPen pen(PS_SOLID,1,color);
	if(changeDc)
	{		
		oldBrush = dc->SelectObject(&b);		
		oldPen = dc->SelectObject(&pen);
	}
	dc->Ellipse(begin.x,begin.y,begin.x+l,begin.y+l);
	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}
