#include "StdAfx.h"
#include "Line.h"


Line::Line(void)
{
	shape=1;
}

Line::~Line(void)
{
}

void Line::draw(CDC * dc,bool changeDc)
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
	dc->MoveTo(begin);
	dc->LineTo(end);
	if(changeDc)
	{
		dc->SelectObject(oldPen);
		dc->SelectObject(oldBrush);
	}
}

//void Line::Serialize(CArchive& ar)
//{
//	if (ar.IsStoring())
//	{	// storing code
//	}
//	else
//	{	// loading code
//	}
//}
