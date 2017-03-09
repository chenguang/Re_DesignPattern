#pragma once
#include "graph.h"

class Arc :
	public Graph
{
public:
	Arc(void);
public:
	~Arc(void);
public:
	void draw(CDC* dc);
};

