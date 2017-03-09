// DrawDoc.h : CDrawDoc ��Ľӿ�
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
protected: // �������л�����
	CDrawDoc();
	DECLARE_DYNCREATE(CDrawDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CArray<Graph*,Graph*> shapeArray;
public:
//	afx_msg void OnFileOpen();
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
};


