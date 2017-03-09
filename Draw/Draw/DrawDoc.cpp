// DrawDoc.cpp : CDrawDoc ���ʵ��
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


// CDrawDoc ����/����

CDrawDoc::CDrawDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDrawDoc::~CDrawDoc()
{
}

BOOL CDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	this->shapeArray.RemoveAll();
	CDocument::DeleteContents();
	return TRUE;
}




// CDrawDoc ���л�

void CDrawDoc::Serialize(CArchive& ar)
{
	this->shapeArray.Serialize(ar);

	INT_PTR i;

	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
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
		// TODO: �ڴ���Ӽ��ش���
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


// CDrawDoc ���

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


// CDrawDoc ����

//void CDrawDoc::OnFileOpen()
//{
//	// TODO: �ڴ���������������
//}

BOOL CDrawDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
//	this->OnNewDocument();

	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  �ڴ������ר�õĴ�������

	return TRUE;
}
