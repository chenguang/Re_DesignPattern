// DrawView.h : CDrawView 类的接口
//

#pragma once
#include "atltypes.h"

class Graph;
class CDrawView : public CView
{
protected: // 仅从序列化创建
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// 属性
public:
	CDrawDoc* GetDocument() const;
public:
	int tempPicNum;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	int shape;
public:
	afx_msg void OnLine();
public:
	Graph *pShape;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	CPoint begin;
public:
	CPoint end;
public:
	Graph *pGraph[7];
public:
	afx_msg void OnArc();
public:
	afx_msg void OnRectangle();
public:
	afx_msg void OnRoundrect();
public:
	afx_msg void OnRound();
public:
	afx_msg void OnEllipse();
public:
	COLORREF color;
public:
	afx_msg void OnRed();
public:
	afx_msg void OnGreen();
public:
	afx_msg void OnBlue();
public:
	afx_msg void OnMouse();
public:
	afx_msg void OnRedBrush();
public:
	COLORREF brushColor;
public:
	afx_msg void OnGreenBrush();
public:
	afx_msg void OnBlueBrush();
public:
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateArc(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateRoundrect(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateRound(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateEllipse(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateMouse(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateRed(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateGreen(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateBlue(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateRedBrush(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateGreenBrush(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateBlueBrush(CCmdUI *pCmdUI);
public:
	afx_msg void OnRedo();
public:
	afx_msg void OnUndo();

};

#ifndef _DEBUG  // DrawView.cpp 中的调试版本
inline CDrawDoc* CDrawView::GetDocument() const
   { return reinterpret_cast<CDrawDoc*>(m_pDocument); }
#endif

