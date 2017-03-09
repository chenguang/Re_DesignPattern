// DrawDoc.h : CDrawDoc 类的接口
//

#pragma once
#include "afxtempl.h"
#include "Graph.h"


//#include "Graph.h"
//#include "DrawDoc.h"
//#include "DrawView.h"
#include "Line.h"
#include "MyArc.h"
#include "MyRectangle.h"
#include "MyRoundRect.h"
#include "MyRound.h"
#include "MyEllipse.h"

class CDrawDoc : public CDocument
{
protected: // 仅从序列化创建
	CDrawDoc();
	DECLARE_DYNCREATE(CDrawDoc)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CArray<Graph*,Graph*> shapeArray;
public:
//	afx_msg void OnFileOpen();
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};


