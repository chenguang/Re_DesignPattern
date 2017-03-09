#pragma once
#include "graph.h"

class MyArc :
	public Graph
{
public:
	MyArc(void);
public:
	~MyArc(void);
public:
	void draw(CDC* dc,bool changeDc = true);
};

