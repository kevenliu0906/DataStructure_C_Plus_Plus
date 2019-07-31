#pragma once
#include "List_te_CS.h"

//======================================================================================
//========================= 二維鍵結之資料樣板 ===========================================
//======================================================================================
// [注意]: 若是class宣告成樣板型式的話(class template)
//         則class內的函式實作部分則要在.h做完，不可將實作部分挪到.cpp中
//         否則會造成外部.cpp無法使用該class

// 二維鏈結之資料樣板
template
<typename Cell,
 typename ListName>
class DataListLink_te_CS
{
public:
	List_te_CS<Cell, ListName> CellList_cs;
	DataListLink_te_CS  *NextList_cs_pr;

	DataListLink_te_CS();
	~DataListLink_te_CS();
};

//------------------------------------------------------------------
//基礎鍵結資料(二維)
template
<typename Cell,
 typename ListName>
DataListLink_te_CS<Cell, ListName>::DataListLink_te_CS()
//建構函式
{
	NextList_cs_pr = NULL;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
DataListLink_te_CS<Cell, ListName>::~DataListLink_te_CS()
{
	CellList_cs.FreeData_Fn();
}
//------------------------------------------------------------------


//======================================================================================
//=========================== 二維鍵結之樣板 ============================================
//======================================================================================
// [注意]: 若是class宣告成樣板型式的話(class template)
//         則class內的函式實作部分則要在.h做完，不可將實作部分挪到.cpp中
//         否則會造成外部.cpp無法使用該class

//二維鏈結之樣板
template
<typename Cell,
 typename ListName,
 typename DataListName>
class DataList_te_CS
{
public:
	DataList_te_CS();
	~DataList_te_CS();
	void Create_Fn(ListName TempListName_LNE);
	bool AddListData_Fn(int ListPosition_i, Cell CellData_E);
	int  GetListCount_Fn();
	ListName GetListName_Fn(int ListPosition_i);
	int  GetListDataCount_Fn(int ListPosition_i);
	Cell GetListData_Fn(int ListPosition_i, int ListDataPosition_i);
	int  GetListPosition_Fn(ListName ListName_LNE);
	bool FreeListData_Fn(int ListPosition_i);
	void FreeData_Fn();

protected:
	DataListLink_te_CS<Cell, ListName>     *HeadList_cs_pr;
	DataListLink_te_CS<Cell, ListName>     *TailList_cs_pr;
	int    ListCount_i;
};

//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
DataList_te_CS<Cell, ListName, DataListName>::DataList_te_CS()
//建構函式
{
	HeadList_cs_pr = NULL;
	TailList_cs_pr = NULL;
	ListCount_i = 0;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
DataList_te_CS<Cell, ListName, DataListName>::~DataList_te_CS()
//解構函式
{
	FreeData_Fn();
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
void DataList_te_CS<Cell, ListName, DataListName>::Create_Fn(ListName TempListName_LNE)
//建立二維鍵結
// TempListName_LNE: 欲建立鍵結的名稱
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>   *NewList_cs_pr = NULL;

	//----------------------------------

	NewList_cs_pr = new DataListLink_te_CS<Cell, ListName>();
	NewList_cs_pr->CellList_cs.ListName_LNE = TempListName_LNE;
	NewList_cs_pr->NextList_cs_pr = NULL;

	if (ListCount_i < 1)
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
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
bool DataList_te_CS<Cell, ListName, DataListName>::AddListData_Fn(int ListPosition_i, Cell CellData_E)
//加入資料
// ListPosition_i: 指定的鍵結位置
// CellData_E: 資料
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName> *TargetList_cs_pr = NULL;

	//------------------------------

	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
		return false;

	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	TargetList_cs_pr->CellList_cs.Create_Fn(CellData_E);

	return true;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
int DataList_te_CS<Cell, ListName, DataListName>::GetListCount_Fn()
//獲取二維鍵結的鍵結數量
// 回傳: 鍵結的數量
{
	return (ListCount_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
ListName DataList_te_CS<Cell, ListName, DataListName>::GetListName_Fn(int ListPosition_i)
//獲取二維鍵結的鍵結名稱
// ListPosition_i: 指定鍵結位置
// 回傳: 鍵結名稱
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>     *TargetList_cs_pr = NULL;

	//--------------------------------
	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
		return NULL;

	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	return (TargetList_cs_pr->CellList_cs.ListName_LNE);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
int DataList_te_CS<Cell, ListName, DataListName>::GetListDataCount_Fn(int ListPosition_i)
//獲取二維鍵結中指定鍵結內的資料數量
// ListPosition_i: 指定的鍵結位置
// 回傳: 資料的數量
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>     *TargetList_cs_pr = NULL;

	//--------------------------------
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
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
Cell DataList_te_CS<Cell, ListName, DataListName>::GetListData_Fn(int ListPosition_i, int ListDataPosition_i)
//獲取二維鍵結中指定鍵結內的指定資料
// ListPosition_i: 指定的鍵結位置
// ListDataPosition_i: 指定的資料位置
// 回傳: 資料
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>    *TargetList_cs_pr = NULL;
	int     Target_ListDataCount_i = 0;

	//---------------------------------------

	if (ListPosition_i < 1 || ListPosition_i>ListCount_i)
		return NULL;

	for (int i_i = 1; i_i <= ListPosition_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;
	}

	Target_ListDataCount_i = TargetList_cs_pr->CellList_cs.GetListDataCount_Fn();
	if (ListDataPosition_i < 1 || ListDataPosition_i > Target_ListDataCount_i)
		return NULL;

	return ((TargetList_cs_pr->CellList_cs).GetListData_Fn(ListDataPosition_i));

}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
int DataList_te_CS<Cell, ListName, DataListName>::GetListPosition_Fn(ListName ListName_LNE)
//獲取二維鍵結中指定鍵結內的位置
// ListName_LNE: 指定的鍵結名稱
// 回傳: 位置
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>    *TargetList_cs_pr = NULL;
	int   ListPos_i = -1;
	//-------------------

	for (int i_i = 1; i_i <= ListCount_i; i_i++)
	{
		if (i_i == 1)
			TargetList_cs_pr = HeadList_cs_pr;
		else
			TargetList_cs_pr = TargetList_cs_pr->NextList_cs_pr;

		if (TargetList_cs_pr->CellList_cs.ListName_LNE == ListName_LNE)
		{
			ListPos_i = i_i;
			break;
		}
	}
	return (ListPos_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
bool DataList_te_CS<Cell, ListName, DataListName>::FreeListData_Fn(int ListPosition_i)
//移除特定位置的鍵結資料
// ListPosition_i: 鍵結指定位置
// 回傳: true(刪除成功); false(刪除失敗)
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>   *TargetList_cs_pr = NULL;
	//---------------------------------------

	if (ListPosition_i < 1 || ListPosition_i > ListCount_i)
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
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
void DataList_te_CS<Cell, ListName, DataListName>::FreeData_Fn()
// 釋放鍵結資料
{
	//----- Initial ...
	DataListLink_te_CS<Cell, ListName>    *TargetList_cs_pr = NULL;
	//---------------------------------

	while (ListCount_i)
	{
		TargetList_cs_pr = HeadList_cs_pr;
		HeadList_cs_pr = HeadList_cs_pr->NextList_cs_pr;

		delete (TargetList_cs_pr);
		ListCount_i--;
	}

	HeadList_cs_pr = NULL;
	TailList_cs_pr = NULL;
	ListCount_i = 0;
}
//------------------------------------------------------------------