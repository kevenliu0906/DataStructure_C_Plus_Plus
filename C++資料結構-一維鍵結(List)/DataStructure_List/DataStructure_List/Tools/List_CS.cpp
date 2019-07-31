#include "stdafx.h"
#include "List_CS.h"


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//基礎鍵結資料(一維)
ListLink_CS::ListLink_CS()
//建構函式
{
	Next_cs_pr = NULL;
	Content_i = 0;
}
//-----------------------------------------------------------------------------
ListLink_CS::~ListLink_CS()
//解構函式
{

}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//一維鍵結
List_CS::List_CS()
//建構函式
{
	ListDataCount_i = 0;
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//-----------------------------------------------------------------------------
List_CS::~List_CS()
//解構函式
{
	FreeData_Fn();
}
//-----------------------------------------------------------------------------
void List_CS::Create_Fn(int  Data_i)
//建立鍵結
// Data_i: 欲建立鍵結資料的內容
{
	//------ Initial ...
	ListLink_CS    *NewListData_cs_pr = new ListLink_CS();

	//---------------------------------------

	NewListData_cs_pr->Content_i = Data_i;
	NewListData_cs_pr->Next_cs_pr = NULL;

	if (ListDataCount_i == 0)
	{
		Head_cs_pr = NewListData_cs_pr;
		Tail_cs_pr = NewListData_cs_pr;
	}
	else
	{
		Tail_cs_pr->Next_cs_pr = NewListData_cs_pr;
		Tail_cs_pr = NewListData_cs_pr;
	}

	ListDataCount_i++;
}
//-----------------------------------------------------------------------------
bool List_CS::Insert_Fn(int ListDataPos_i, int Data_i)
//插入鍵結資料
// ListDataPos_i: 插入位置
// Data_i: 欲插入的資料
// 回傳: true(插入成功); false(插入失敗)
{
	ListLink_CS     *Target_cs_pr = NULL;
	ListLink_CS     *Front_Target_cs_pr = NULL;
	ListLink_CS     *NewData_cs_pr = NULL;

	if (ListDataPos_i < 1 || ListDataPos_i > ListDataCount_i)
		return false;

	NewData_cs_pr = new ListLink_CS();
	NewData_cs_pr->Content_i = Data_i;
	NewData_cs_pr->Next_cs_pr = NULL;

	for (int i_i = 1; i_i <= ListDataPos_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else
		{
			Front_Target_cs_pr = Target_cs_pr;
			Target_cs_pr = Target_cs_pr->Next_cs_pr;
		}
	}

	if (ListDataPos_i == 1)   //插入到陣列的第一筆
	{
		NewData_cs_pr->Next_cs_pr = Head_cs_pr;
		Head_cs_pr = NewData_cs_pr;
	}
	else
	{
		NewData_cs_pr->Next_cs_pr = Target_cs_pr;
		Front_Target_cs_pr->Next_cs_pr = NewData_cs_pr;
	}

	ListDataCount_i++;

	return true;
}
//-----------------------------------------------------------------------------
int List_CS::GetListDataCount_Fn()
//獲取鍵結的總資料數目
// 回傳: 鍵結的總資料數目
{
	return (ListDataCount_i);
}
//-----------------------------------------------------------------------------
int List_CS::GetListData_Fn(int ListDataPos_i)
//獲取鍵結內的資料
// ListDataPos_i: 欲獲取哪一段的鍵結資料
// 回傳: 回傳該鍵結內的資料
{
	//----- Initial ...
	ListLink_CS     *Target_cs_pr = NULL;

	//---------------------------------------

	if (ListDataPos_i < 1 || ListDataPos_i > ListDataCount_i)
		return (-1);

	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else if (i_i == ListDataCount_i)
			Target_cs_pr = Tail_cs_pr;
		else
			Target_cs_pr = Target_cs_pr->Next_cs_pr;

		if (i_i == ListDataPos_i)
			break;
	}

	if (Target_cs_pr == NULL)
		return (-1);
	else
		return (Target_cs_pr->Content_i);
}
//-----------------------------------------------------------------------------
int List_CS::GetListDataPosition_Fn(int Data_i)
//獲取資料在鍵結中的位置
// Data_i: 欲獲取資料
// 回傳: 該資料在鍵結中的位置
{
	//------ Initial ...
	ListLink_CS    *Target_cs_pr = NULL;
	int            TargetPosition_i = -1;

	//----------------------------------

	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else if (i_i == ListDataCount_i)
			Target_cs_pr = Tail_cs_pr;
		else
			Target_cs_pr = Target_cs_pr->Next_cs_pr;

		if (Target_cs_pr->Content_i == Data_i)
		{
			TargetPosition_i = i_i;
			break;
		}
	}

	return (TargetPosition_i);
}
//-----------------------------------------------------------------------------
bool List_CS::Delete_Fn(int StartPosition_i, int DeleteCount_i)
//刪除鍵結
// StartPosition_i: 刪除的起始位置
// DeleteCount_i: 刪除數量
// 回傳: true(刪除成功); false(刪除失敗)
{
	ListLink_CS     *Target_cs_pr = NULL;
	ListLink_CS     *Delete_cs_pr = NULL;
	ListLink_CS     *Front_Target_cs_pr = NULL;

	if (StartPosition_i < 1 || StartPosition_i > ListDataCount_i || (StartPosition_i + DeleteCount_i - 1) > ListDataCount_i)
		return false;

	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else
		{
			Front_Target_cs_pr = Target_cs_pr;
			Target_cs_pr = Target_cs_pr->Next_cs_pr;
		}

		if (StartPosition_i == i_i)
		{
			break;
		}
	}

	while (DeleteCount_i > 0)
	{
		Delete_cs_pr = Target_cs_pr;
		Target_cs_pr = Target_cs_pr->Next_cs_pr;
		
		if (Delete_cs_pr == Head_cs_pr)
		{
			Head_cs_pr = Target_cs_pr;
		}
		else
		{
			Front_Target_cs_pr->Next_cs_pr = Target_cs_pr;
		}

		if (Target_cs_pr == NULL)  // 代表原先的Tail已經被移除
			Tail_cs_pr = Front_Target_cs_pr;

		delete(Delete_cs_pr);
		
		ListDataCount_i--;
		DeleteCount_i--;
	}
	if (ListDataCount_i == 0)
	{
		Head_cs_pr = NULL;
		Tail_cs_pr = NULL;
	}
	return true;
}
//-----------------------------------------------------------------------------
void List_CS::FreeData_Fn()
// 釋放鍵結資料
{
	//----- Initial ...
	int          DataCount_i = ListDataCount_i;
	ListLink_CS  *Target_cs_pr = NULL;
	//--------------------------------------

	while (DataCount_i)
	{
		Target_cs_pr = Head_cs_pr;
		Head_cs_pr = Head_cs_pr->Next_cs_pr;

		delete (Target_cs_pr);
		DataCount_i--;
	}

	ListDataCount_i = 0;
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//-----------------------------------------------------------------------------