#pragma once
#include "graph.h"

class MyEllipse :
	public Graph
{
public:
	MyEllipse(void);
public:
	~MyEllipse(void);
public:
	void draw(CDC* dc,bool changeDc = true);
};

