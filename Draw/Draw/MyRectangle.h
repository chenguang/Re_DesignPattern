#pragma once
#include "graph.h"

class MyRectangle :
	public Graph
{
public:
	MyRectangle(void);
public:
	~MyRectangle(void);
public:
	void draw(CDC* dc,bool changeDc = true);
};

