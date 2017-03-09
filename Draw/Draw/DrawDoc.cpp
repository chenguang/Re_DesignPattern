// DrawDoc.cpp : CDrawDoc 类的实现
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawDoc

IMPLEMENT_DYNCREATE(CDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawDoc, CDocument)
//	ON_COMMAND(ID_FILE_OPEN, &CDrawDoc::OnFileOpen)
END_MESSAGE_MAP()


// CDrawDoc 构造/析构

CDrawDoc::CDrawDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDrawDoc::~CDrawDoc()
{
}

BOOL CDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	this->shapeArray.RemoveAll();
	CDocument::DeleteContents();
	return TRUE;
}




// CDrawDoc 序列化

void CDrawDoc::Serialize(CArchive& ar)
{
	this->shapeArray.Serialize(ar);

	INT_PTR i;

	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		i = this->shapeArray.GetCount();
		ar<<i;
		for(INT_PTR j=0;j<i;j++)
		{
			ar<<this->shapeArray[j]->shape;
			this->shapeArray[j]->Serialize(ar);
		}

	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>i;
		//		shapeArray.SetSize(i);
		shapeArray.RemoveAll();
		CDocument::DeleteContents();
		for(INT_PTR j=0;j<i;j++)
		{
			Graph *g ;//= new Graph;
			int shape;
			ar>>shape;
			switch(shape)
			{
			case 1:
				g=new Line();				
				break;
			case 2:
				g=new MyArc();		
				break;
			case 3:
				g=new MyRectangle();				
				break;
			case 4:
				g=new MyRoundRect();				
				break;
			case 5:
				g=new MyRound();				
			case 6:
				g=new MyEllipse();				
				break;
			}
			g->Serialize(ar);
			shapeArray.Add(g);
		}
	}


		//shapeArray.SetAt(j,g);
		//shapeArray[j]->
	
}


// CDrawDoc 诊断

#ifdef _DEBUG
void CDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawDoc 命令

//void CDrawDoc::OnFileOpen()
//{
//	// TODO: 在此添加命令处理程序代码
//}

BOOL CDrawDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
//	this->OnNewDocument();

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  在此添加您专用的创建代码

	return TRUE;
}
