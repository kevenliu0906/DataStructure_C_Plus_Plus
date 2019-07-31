#include "stdafx.h"
#include "List_te_CS.h"

//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//��¦�䵲���(�@��)
//template
//<typename Cell>
template <class Cell>
ListLink_te_CS<Cell> ::ListLink_te_CS()
//�غc�禡
{
	Data_E = Cell;
	Next_cs_pr = NULL;
}
//------------------------------------------------------------------
//template
//<typename Cell>
template <class Cell>
ListLink_te_CS<Cell>::~ListLink_te_CS()
//�Ѻc�禡
{

}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//�@���䵲
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
List_te_CS<Cell, ListName>::List_te_CS()
//�غc�禡
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
//�Ѻc�禡
{
	FreeData_Fn();
}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
void List_te_CS<Cell, ListName>::Create_Fn(Cell CellData_E)
//�إ��䵲
// CellData_E: ���إ��䵲��ƪ����e
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
//����䵲���`��Ƽƥ�
// �^��: �䵲���`��Ƽƥ�
{
	return (ListDataCount_i);
}
//------------------------------------------------------------------
//template
//<typename Cell,
// typename ListName>
template <class Cell, class ListName>
Cell List_te_CS<Cell, ListName>::GetListData_Fn(int ListDataPos_i)
//����䵲�������
// ListDataPos_i: ��������@�q���䵲���
// �^��: �^�Ǹ��䵲�������
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
//�����䵲���
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