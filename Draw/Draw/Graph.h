#pragma once

// Graph ÃüÁîÄ¿±ê

class Graph  : public CObject
{
public:
	Graph();
	virtual ~Graph();
public:
	virtual void draw(CDC * dc,bool changeDc = true) ;
public:
	CPoint begin;
public:
	CPoint end;
public:
	virtual void SetPoint(CPoint begin, CPoint end);
public:
	void SetBeginPoint(CPoint b);
public:
	void SetEndPoint(CPoint e);
public:
	virtual void Serialize(CArchive& ar);
public:
	COLORREF color;
public:
	COLORREF brushColor;
public:
	void SetColor(COLORREF color, COLORREF brushColor);
public:
	int shape;
};


