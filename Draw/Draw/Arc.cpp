#include "StdAfx.h"
#include "Arc.h"

Arc::Arc(void)
{
}

Arc::~Arc(void)
{
}

void Arc::draw(CDC* dc)
{
	CRect rect(this->begin,this->end);
	dc->Arc(&rect,begin,end);
}

