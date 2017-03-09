#pragma once
#include "graph.h"
#include "atltypes.h"

class Line :
	public Graph
{
public:
	Line(void);
public:
	~Line(void);

public:
	void draw(CDC * dc,bool changeDc = true);
public:
//	virtual void Serialize(CArchive& ar);
};

