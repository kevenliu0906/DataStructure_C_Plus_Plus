#include "stdafx.h"
#include "DataList.h"


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//基礎鍵結資料(二維)
DataListLink_CS::DataListLink_CS()
{
	NextList_cs_pr = NULL;
	CellList_cs.FreeData_Fn();
	CellListName_i = -1;
}
//-----------------------------------------------------------------------------
DataListLink_CS::~DataListLink_CS()
{
	CellList_cs.FreeData_Fn();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//二維鍵結
DataList_CS::DataList_CS()
//建構函式
{
	HeadList_cs_pr = NULL;
	TailList_cs_pr = NULL;
	ListCount_i = 0;
}
//-----------------------------------------------------------------------------
DataList_CS::~DataList_CS()
//解構函式
{
	FreeData_Fn();
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListCount_Fn()
//獲取二維鍵結的鍵結數量
// 回傳: 鍵結的數量
{
	return (ListCount_i);
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListName_Fn(int ListPosition_i)
//獲取二維鍵結的鍵結名稱
// ListPosition_i: 指定鍵結位置
// 回傳: 鍵結名稱
{
	DataListLink_CS     *TargetList_cs_pr = NULL;

	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
		return 0;
	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	return (TargetList_cs_pr->CellListName_i);
}
//-----------------------------------------------------------------------------
void DataList_CS::Create_Fn(int  ListName_i)
//建立二維鍵結
// ListName_i: 欲建立鍵結的名稱
{
	DataListLink_CS    *NewList_cs_pr = new DataListLink_CS();

	NewList_cs_pr->NextList_cs_pr = NULL;
	NewList_cs_pr->CellListName_i = ListName_i;
	//NewList_cs_pr->CellList_cs.Create_Fn(ListName_i);

	if (ListCount_i == 0)
	{
		HeadList_cs_pr = NewList_cs_pr;
		TailList_cs_pr = NewList_cs_pr;
	}
	else
	{
		TailList_cs_pr->NextList_cs_pr = NewList_cs_pr;
		TailList_cs_pr = NewList_cs_pr;
	}
	ListCount_i++;
}
//-----------------------------------------------------------------------------
bool DataList_CS::AddListData_Fn(int ListPosition, int CellData_i)
//加入資料
// ListPosition_i: 指定的鍵結位置
// CellData_i: 資料
{
	DataListLink_CS    *TargetList_cs_pr = NULL;

	if (ListPosition < 1 || ListPosition >ListCount_i)
		return false;

	for (int i_i = 1; i_i <= ListPosition; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	(TargetList_cs_pr->CellList_cs).Create_Fn(CellData_i);
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListDataCount_Fn(int ListPosition_i)
//獲取二維鍵結中指定鍵結內的資料數量
// ListPosition_i: 指定的鍵結位置
// 回傳: 資料的數量
{
	DataListLink_CS    *TargetList_cs_pr = NULL;

	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
		return 0;

	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	return ((TargetList_cs_pr->CellList_cs).GetListDataCount_Fn());
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListData_Fn(int ListPosition_i, int ListDataPosition_i)
//獲取二維鍵結中指定鍵結內的指定資料
// ListPosition_i: 指定的鍵結位置
// ListDataPosition_i: 指定的資料位置
// 回傳: 資料
{
	DataListLink_CS    *TargetList_cs_pr = NULL;
	int    ListDataCount_i = 0;

	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
		return (-1);

	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	ListDataCount_i = (TargetList_cs_pr->CellList_cs).GetListDataCount_Fn();
	if (ListDataPosition_i < 1 || ListDataPosition_i > ListDataCount_i)
		return (-1);

	return ((TargetList_cs_pr->CellList_cs).GetListData_Fn(ListDataPosition_i));
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListPosition_Fn(int ListName_i)
//獲取二維鍵結中指定鍵結內的位置
// ListName_i: 指定的鍵結名稱
// 回傳: 位置
{
	DataListLink_CS   *TargetList_cs_pr = NULL;
	int TargetListPos_i = -1;

	for (int i_i = 1; i_i <= ListCount_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;

		if (TargetList_cs_pr->CellListName_i == ListName_i)
		{
			TargetListPos_i = i_i;
			break;
		}
	}

	return (TargetListPos_i);
}
//-----------------------------------------------------------------------------
bool DataList_CS::FreeListData_Fn(int ListPosition_i)
//移除特定位置的鍵結資料
// ListPosition_i: 鍵結指定位置
// 回傳: true(刪除成功); false(刪除失敗)
{
	DataListLink_CS   *TargetList_cs_pr = NULL;

	if (ListPosition_i < 1 || ListPosition_i >ListCount_i)
		return false;
	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	(TargetList_cs_pr->CellList_cs).FreeData_Fn();
	return true;
}
//-----------------------------------------------------------------------------
void DataList_CS::FreeData_Fn()
// 釋放鍵結資料
{
	DataListLink_CS *CurrentList_cs_pr = NULL;

	while (HeadList_cs_pr != NULL)
	{
		CurrentList_cs_pr = HeadList_cs_pr;
		HeadList_cs_pr = HeadList_cs_pr->NextList_cs_pr;
		delete (CurrentList_cs_pr);
	}
	HeadList_cs_pr = NULL;
	TailList_cs_pr = NULL;
	ListCount_i = 0;
}
//-----------------------------------------------------------------------------