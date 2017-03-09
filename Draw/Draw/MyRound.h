#pragma once
#include "graph.h"

class MyRound :
	public Graph
{
public:
	MyRound(void);
public:
	~MyRound(void);
public:
	void draw(CDC* dc,bool changeDc = true);
};

