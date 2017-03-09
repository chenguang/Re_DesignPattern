// DrawView.cpp : CDrawView 类的实现
//

#include "stdafx.h"
#include "Draw.h"
#include "Graph.h"
#include "DrawDoc.h"
#include "DrawView.h"
#include "Line.h"
#include "MyArc.h"
#include "MyRectangle.h"
#include "MyRoundRect.h"
#include "MyRound.h"
#include "MyEllipse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	ON_COMMAND(ID_LINE, &CDrawView::OnLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_ARC, &CDrawView::OnArc)
	ON_COMMAND(ID_RECTANGLE, &CDrawView::OnRectangle)
	ON_COMMAND(ID_ROUNDRECT, &CDrawView::OnRoundrect)
	ON_COMMAND(ID_ROUND, &CDrawView::OnRound)
	ON_COMMAND(ID_ELLIPSE, &CDrawView::OnEllipse)
	ON_COMMAND(ID_RED, &CDrawView::OnRed)
	ON_COMMAND(ID_GREEN, &CDrawView::OnGreen)
	ON_COMMAND(ID_BLUE, &CDrawView::OnBlue)
	ON_COMMAND(ID_MOUSE, &CDrawView::OnMouse)
	ON_COMMAND(ID_RED_BRUSH, &CDrawView::OnRedBrush)
	ON_COMMAND(ID_GREEN_BRUSH, &CDrawView::OnGreenBrush)
	ON_COMMAND(ID_BLUE_BRUSH, &CDrawView::OnBlueBrush)
	ON_COMMAND(ID_EDIT_REDO, &CDrawView::OnRedo)
	ON_COMMAND(ID_EDIT_UNDO, &CDrawView::OnUndo)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CDrawView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ARC, &CDrawView::OnUpdateArc)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CDrawView::OnUpdateRectangle)
	ON_UPDATE_COMMAND_UI(ID_ROUNDRECT, &CDrawView::OnUpdateRoundrect)
	ON_UPDATE_COMMAND_UI(ID_ROUND, &CDrawView::OnUpdateRound)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CDrawView::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_MOUSE, &CDrawView::OnUpdateMouse)
	ON_UPDATE_COMMAND_UI(ID_RED, &CDrawView::OnUpdateRed)
	ON_UPDATE_COMMAND_UI(ID_GREEN, &CDrawView::OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(ID_BLUE, &CDrawView::OnUpdateBlue)
	ON_UPDATE_COMMAND_UI(ID_RED_BRUSH, &CDrawView::OnUpdateRedBrush)
	ON_UPDATE_COMMAND_UI(ID_GREEN_BRUSH, &CDrawView::OnUpdateGreenBrush)
	ON_UPDATE_COMMAND_UI(ID_BLUE_BRUSH, &CDrawView::OnUpdateBlueBrush)
END_MESSAGE_MAP()

// CDrawView 构造/析构

CDrawView::CDrawView()
: shape(1)
//, pShape(NULL)
, begin(0)
, end(0)
{
	// TODO: 在此处添加构造代码
	color=RGB(255,0,0);
	brushColor=RGB(0,255,0);
	pGraph[1] = new Line;
	pGraph[2] = new MyArc;
	pGraph[3] = new MyRectangle;
	pGraph[4] = new MyRoundRect;
	pGraph[5] = new MyRound;
	pGraph[6] = new MyEllipse;
	tempPicNum = 0;
	
}


CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘制

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	INT_PTR i=pDoc->shapeArray.GetCount();
	for(INT_PTR j=0;j<i;j++)
		pDoc->shapeArray[j]->draw(pDC);
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序



void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(shape<1||shape>7)
		return;

	pGraph[shape]->SetPoint(point,point);

	::SetCapture(this->m_hWnd);
	CView::OnLButtonDown(nFlags, point);
	
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(::GetCapture()==this->m_hWnd)
	{
		CClientDC dc(this);		
		

		CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
		CBrush *oldBrush = dc.SelectObject(brush);
		dc.SetROP2(R2_NOT);
		
		pGraph[shape]->draw(&dc,false);
		pGraph[shape]->SetEndPoint(point);
		pGraph[shape]->draw(&dc,false);		

		dc.SelectObject(oldBrush);
	}
	CView::OnMouseMove(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(::GetCapture()==this->m_hWnd)
	{
		CClientDC dc(this);	
		dc.SetROP2(R2_NOT);		
		pGraph[shape]->draw(&dc,false);

		dc.SetROP2(R2_COPYPEN);

		pGraph[shape]->SetEndPoint(point);
		
		Graph *g;
		switch(shape)
		{
		case 1:
			g=new Line();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		case 2:
			g=new MyArc();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		case 3:
			g=new MyRectangle();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		case 4:
			g=new MyRoundRect();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		case 5:
			g=new MyRound();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		case 6:
			g=new MyEllipse();
			g->SetPoint(pGraph[shape]->begin,pGraph[shape]->end);
			g->SetColor(color,brushColor);
			break;
		}

		g->draw(&dc);
		CDrawDoc* pDoc = GetDocument();
		pDoc->shapeArray.Add(g);
		tempPicNum = pDoc->shapeArray.GetSize();
		for (int i = tempPicNum; i < pDoc->shapeArray.GetSize(); i++){
		pDoc->shapeArray.RemoveAt(i);
		}
		pDoc->SetModifiedFlag();
	}

	::ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=1;
}

void CDrawView::OnArc()
{
	this->shape=2;
	// TODO: 在此添加命令处理程序代码
}

void CDrawView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=3;
}

void CDrawView::OnRoundrect()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=4;
}

void CDrawView::OnRound()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=5;
}

void CDrawView::OnEllipse()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=6;
}

void CDrawView::OnRed()
{
	// TODO: 在此添加命令处理程序代码
	color=RGB(255,0,0);
}

void CDrawView::OnGreen()
{
	// TODO: 在此添加命令处理程序代码
	color=RGB(0,255,0);
}

void CDrawView::OnBlue()
{
	// TODO: 在此添加命令处理程序代码
	color=RGB(0,0,255);
}

void CDrawView::OnMouse()
{
	// TODO: 在此添加命令处理程序代码
	this->shape=0;
}

void CDrawView::OnRedBrush()
{
	// TODO: 在此添加命令处理程序代码
	this->brushColor=RGB(255,0,0);
}

void CDrawView::OnGreenBrush()
{
	// TODO: 在此添加命令处理程序代码
	this->brushColor=RGB(0,255,0);
}

void CDrawView::OnBlueBrush()
{
	// TODO: 在此添加命令处理程序代码
	this->brushColor=RGB(0,0,255);
}

void CDrawView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==1);
}

void CDrawView::OnUpdateArc(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==2);
}

void CDrawView::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==3);
}

void CDrawView::OnUpdateRoundrect(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==4);
}

void CDrawView::OnUpdateRound(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==5);
}

void CDrawView::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==6);
}

void CDrawView::OnUpdateMouse(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->shape==0);
}

void CDrawView::OnUpdateRed(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->color==RGB(255,0,0));
}

void CDrawView::OnUpdateGreen(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->color==RGB(0,255,0));
}

void CDrawView::OnUpdateBlue(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->color==RGB(0,0,255));
}

void CDrawView::OnUpdateRedBrush(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->brushColor==RGB(255,0,0));
}

void CDrawView::OnUpdateGreenBrush(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->brushColor==RGB(0,255,0));		
}

void CDrawView::OnUpdateBlueBrush(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(this->brushColor==RGB(0,0,255));
}

void CDrawView::OnUndo()
{
	CDrawDoc* pDoc = GetDocument();
	int i;
	CClientDC dc(this);

	dc.SetROP2(R2_NOTXORPEN);
	if (tempPicNum - 1 < 0)
		return;
	Graph* g = pDoc->shapeArray.GetAt(--tempPicNum);
	
	g->draw(&dc);
	pDoc->SetModifiedFlag();
}

void CDrawView::OnRedo()
{
	CDrawDoc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.SetROP2(R2_NOTXORPEN);
	if (pDoc == NULL)
		return;
	if (tempPicNum + 1 > pDoc->shapeArray.GetSize())
		return;
	Graph* g = pDoc->shapeArray.GetAt(tempPicNum++);

	g->draw(&dc);
}
