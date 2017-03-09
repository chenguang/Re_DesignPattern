#include "StdAfx.h"
#include "MyArc.h"



MyArc::MyArc(void)
{
	shape=2;
}

MyArc::~MyArc(void)
{
}

void MyArc::draw(CDC* dc,bool changeDc)
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
	CRect rect(this->begin,this->end);
	dc->Arc(&rect,begin,end);
	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}
