#pragma once
#include "graph.h"

class MyRoundRect :
	public Graph
{
public:
	MyRoundRect(void);
public:
	~MyRoundRect(void);
public:
	void draw(CDC* dc,bool changeDc = true);
};

