#include "stdafx.h"
#include "List_te_CS.h"

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//基礎鍵結資料(一維)
//template
//<typename Cell>
template <class Cell>
ListLink_te_CS<Cell> ::ListLink_te_CS()
//建構函式
{
	Data_E = Cell;
	Next_cs_pr = NULL;
}
//------------------------------------------------------------------
//template
//<typename Cell>
template <class Cell>
ListLink_te_CS<Cell>::~ListLink_te_CS()
//解構函式
{

}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//一維鍵結
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
List_te_CS<Cell, ListName>::List_te_CS()
//建構函式
{
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
List_te_CS<Cell, ListName>::~List_te_CS()
//解構函式
{
	FreeData_Fn();
}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
void List_te_CS<Cell, ListName>::Create_Fn(Cell CellData_E)
//建立鍵結
// CellData_E: 欲建立鍵結資料的內容
{
	//------ Initial ...
	ListLink_te_CS<Cell>    *NewData_cs_pr = NULL;

	//---------------------------------------

	NewData_cs_pr = new ListLink_te_CS<Cell>();
	NewData_cs_pr->Data_E = CellData_E;
	NewData_cs_pr->Next_cs_pr = NULL;

	if (ListDataCount_i == 0)
	{
		Head_cs_pr = NewData_cs_pr;
		Tail_cs_pr = NewData_cs_pr;
	}
	else
	{
		Tail_cs_pr->Next_cs_pr = NewData_cs_pr;
		Tail_cs_pr = NewData_cs_pr;
	}

	ListDataCount_i++;

}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
int List_te_CS<Cell, ListName>::GetListDataCount_Fn()
//獲取鍵結的總資料數目
// 回傳: 鍵結的總資料數目
{
	return (ListDataCount_i);
}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
Cell List_te_CS<Cell, ListName>::GetListData_Fn(int ListDataPos_i)
//獲取鍵結內的資料
// ListDataPos_i: 欲獲取哪一段的鍵結資料
// 回傳: 回傳該鍵結內的資料
{
	//------ Initial ...
	ListLink_te_CS<Cell>    *TargetData_cs_pr = NULL;

	//---------------------------------------

	for (int i_i = 1; i_i <= ListDataPos_i; i_i++)
	{
		if (i_i == 1)
			TargetData_cs_pr = Head_cs_pr;
		else
			TargetData_cs_pr = TargetData_cs_pr->Next_cs_pr;
	}

	return (TargetData_cs_pr->Data_E);

}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
void List_te_CS<Cell, ListName>::FreeData_Fn()
//釋放鍵結資料
{
	ListLink_te_CS<Cell>   *Target_cs_pr = NULL;

	while (ListDataCount_i > 0)
	{
		Target_cs_pr = Head_cs_pr;
		Head_cs_pr = Head_cs_pr->Next_cs_pr;

		delete (Target_cs_pr);
		ListDataCount_i--;
	}

	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
	ListDataCount_i = 0;
}
//------------------------------------------------------------------