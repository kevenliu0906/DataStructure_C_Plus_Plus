#pragma once

//======================================================================================
//========================= 一維鍵結之資料樣板 ===========================================
//======================================================================================
// [注意]: 若是class宣告成樣板型式的話(class template)
//         則class內的函式實作部分則要在.h做完，不可將實作部分挪到.cpp中
//         否則會造成外部.cpp無法使用該class

// 一維鏈結之資料樣板
template
<typename Cell>
class ListLink_te_CS
{
public:
	ListLink_te_CS<Cell>   *Next_cs_pr;
	Cell   Data_E;

	ListLink_te_CS();
	~ListLink_te_CS();
};

//------------------------------------------------------------------
//基礎鍵結資料(一維)
template
<typename Cell>
ListLink_te_CS<Cell> ::ListLink_te_CS()
//建構函式
{
	//Data_E = Cell;
	Next_cs_pr = NULL;
}
//------------------------------------------------------------------
template
<typename Cell>
ListLink_te_CS<Cell>::~ListLink_te_CS()
//解構函式
{

}
//------------------------------------------------------------------


//======================================================================================
//=========================== 一維鍵結之樣板 ============================================
//======================================================================================
// [注意]: 若是class宣告成樣板型式的話(class template)
//         則class內的函式實作部分則要在.h做完，不可將實作部分挪到.cpp中
//         否則會造成外部.cpp無法使用該class

//一維鏈結之樣板
template
<typename Cell,
 typename ListName>
class List_te_CS
{
public:
	List_te_CS();
	~List_te_CS();
	void Create_Fn(Cell CellData_E);
	int  GetListDataCount_Fn();
	Cell GetListData_Fn(int ListDataPos_i);
	int  GetListDataPosition_Fn(Cell CellData_E);
	bool Delete_Fn(int StartPosition_i, int DeleteCount_i);
	bool Insert_Fn(int ListDataPosition_i, Cell CellData_E);
	void FreeData_Fn();

protected:
	ListLink_te_CS<Cell>  *Head_cs_pr;
	ListLink_te_CS<Cell>  *Tail_cs_pr;
	int   ListDataCount_i;
};

//------------------------------------------------------------------
//一維鍵結
template
<typename Cell,
 typename ListName>
List_te_CS<Cell, ListName>::List_te_CS()
//建構函式
{
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
List_te_CS<Cell, ListName>::~List_te_CS()
//解構函式
{
	FreeData_Fn();
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
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
template
<typename Cell,
 typename ListName>
int List_te_CS<Cell, ListName>::GetListDataCount_Fn()
//獲取鍵結的總資料數目
// 回傳: 鍵結的總資料數目
{
	return (ListDataCount_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
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
template
<typename Cell,
 typename ListName>
int List_te_CS<Cell, ListName>::GetListDataPosition_Fn(Cell CellData_E)
//獲取資料在鍵結中的位置
// CellData_E: 欲獲取資料
// 回傳: 該資料在鍵結中的位置
{
	//------ Initial ...
	ListLink_te_CS<Cell>   *Target_cs_pr = NULL;
	int   TargetPosition_i = -1;
	//---------------------------------------

	for (int i_i = 1; i_i <= ListDataCount_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else
			Target_cs_pr = Target_cs_pr->Next_cs_pr;

		if (Target_cs_pr->Data_E == CellData_E)
		{
			TargetPosition_i = i_i;
			break;
		}
	}

	return (TargetPosition_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
bool List_te_CS<Cell, ListName>::Delete_Fn(int StartPosition_i, int DeleteCount_i)
//刪除鍵結
// StartPosition_i: 刪除的起始位置
// DeleteCount_i: 刪除數量
// 回傳: true(刪除成功); false(刪除失敗)
{
	//------ Initial ...
	ListLink_te_CS<Cell>   *Delete_cs_pr = NULL;
	ListLink_te_CS<Cell>   *Target_cs_pr = NULL;
	ListLink_te_CS<Cell>   *Front_Target_cs_pr = NULL;

	//---------------------------------------
	if (StartPosition_i < 1 || StartPosition_i > ListDataCount_i || (StartPosition_i + DeleteCount_i - 1) > ListDataCount_i)
		return false;

	for (int i_i = 1; i_i <= StartPosition_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else
		{
			Front_Target_cs_pr = Target_cs_pr;
			Target_cs_pr = Target_cs_pr->Next_cs_pr;
		}
	}

	while (DeleteCount_i)
	{
		if (StartPosition_i == 1)
		{
			Head_cs_pr = Target_cs_pr->Next_cs_pr;
		}
		else
			Front_Target_cs_pr->Next_cs_pr = Target_cs_pr->Next_cs_pr;

		Delete_cs_pr = Target_cs_pr;
		Target_cs_pr = Target_cs_pr->Next_cs_pr;

		if (Delete_cs_pr == Tail_cs_pr)
			Tail_cs_pr = Front_Target_cs_pr;

		delete (Delete_cs_pr);
		DeleteCount_i--;
		ListDataCount_i--;
	}

	if (ListDataCount_i == 0)
	{
		Head_cs_pr = NULL;
		Tail_cs_pr = NULL;
	}

	return true;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
bool List_te_CS<Cell, ListName>::Insert_Fn(int ListDataPosition_i, Cell CellData_E)
//插入鍵結資料
// ListDataPos_i: 插入位置
// Data_i: 欲插入的資料
// 回傳: true(插入成功); false(插入失敗)
{
	//------ Initial ...
	ListLink_te_CS<Cell>   *NewData_cs_pr = NULL;
	ListLink_te_CS<Cell>   *Front_Target_cs_pr = NULL;
	ListLink_te_CS<Cell>   *Target_cs_pr = NULL;

	//---------------------------------------

	if (ListDataPosition_i<1 || ListDataPosition_i>ListDataCount_i)
		return false;

	NewData_cs_pr = new ListLink_te_CS<Cell>();
	NewData_cs_pr->Data_E = CellData_E;
	NewData_cs_pr->Next_cs_pr = NULL;

	for (int i_i = 1; i_i <= ListDataPosition_i; i_i++)
	{
		if (i_i == 1)
			Target_cs_pr = Head_cs_pr;
		else
		{
			Front_Target_cs_pr = Target_cs_pr;
			Target_cs_pr = Target_cs_pr->Next_cs_pr;
		}
	}

	if (ListDataPosition_i == 1)   //插入到陣列的第一筆
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
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
void List_te_CS<Cell, ListName>::FreeData_Fn()
//釋放鍵結資料
{
	//------ Initial ...
	ListLink_te_CS<Cell>   *Target_cs_pr = NULL;

	//---------------------------------------

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