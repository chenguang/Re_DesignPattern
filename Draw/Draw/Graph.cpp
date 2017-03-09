// Graph.cpp : 实现文件
//


#include "stdafx.h"
#include "Draw.h"
#include "Graph.h"


// Graph

Graph::Graph()
: begin(0)
, end(0)
, shape(0)
{
}

Graph::~Graph()
{
}


// Graph 成员函数

void Graph::draw(CDC * dc,bool changeDc) 
{

}
void Graph::SetPoint(CPoint begin, CPoint end)
{
	this->begin=begin;
	this->end=end;
}

void Graph::SetBeginPoint(CPoint b)
{
	begin=b;
}

void Graph::SetEndPoint(CPoint e)
{
	end=e;
}

void Graph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<<begin<<end<<color<<brushColor;
	}
	else
	{	// loading code
		ar>>begin>>end>>color>>brushColor;
	}
}

void Graph::SetColor(COLORREF color, COLORREF brushColor)
{
	this->color=color;
	this->brushColor=brushColor;
}
