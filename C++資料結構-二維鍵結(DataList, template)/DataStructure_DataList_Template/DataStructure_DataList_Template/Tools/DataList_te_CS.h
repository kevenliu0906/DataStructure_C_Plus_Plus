#pragma once
#include "List_te_CS.h"

//======================================================================================
//========================= �G���䵲����Ƽ˪O ===========================================
//======================================================================================
// [�`�N]: �Y�Oclass�ŧi���˪O��������(class template)
//         �hclass�����禡��@�����h�n�b.h�����A���i�N��@��������.cpp��
//         �_�h�|�y���~��.cpp�L�k�ϥθ�class

// �G���쵲����Ƽ˪O
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
//��¦�䵲���(�G��)
template
<typename Cell,
 typename ListName>
DataListLink_te_CS<Cell, ListName>::DataListLink_te_CS()
//�غc�禡
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
//=========================== �G���䵲���˪O ============================================
//======================================================================================
// [�`�N]: �Y�Oclass�ŧi���˪O��������(class template)
//         �hclass�����禡��@�����h�n�b.h�����A���i�N��@��������.cpp��
//         �_�h�|�y���~��.cpp�L�k�ϥθ�class

//�G���쵲���˪O
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
//�غc�禡
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
//�Ѻc�禡
{
	FreeData_Fn();
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
void DataList_te_CS<Cell, ListName, DataListName>::Create_Fn(ListName TempListName_LNE)
//�إߤG���䵲
// TempListName_LNE: ���إ��䵲���W��
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
//�[�J���
// ListPosition_i: ���w���䵲��m
// CellData_E: ���
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
//����G���䵲���䵲�ƶq
// �^��: �䵲���ƶq
{
	return (ListCount_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName,
 typename DataListName>
ListName DataList_te_CS<Cell, ListName, DataListName>::GetListName_Fn(int ListPosition_i)
//����G���䵲���䵲�W��
// ListPosition_i: ���w�䵲��m
// �^��: �䵲�W��
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
//����G���䵲�����w�䵲������Ƽƶq
// ListPosition_i: ���w���䵲��m
// �^��: ��ƪ��ƶq
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
//����G���䵲�����w�䵲�������w���
// ListPosition_i: ���w���䵲��m
// ListDataPosition_i: ���w����Ʀ�m
// �^��: ���
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
//����G���䵲�����w�䵲������m
// ListName_LNE: ���w���䵲�W��
// �^��: ��m
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
//�����S�w��m���䵲���
// ListPosition_i: �䵲���w��m
// �^��: true(�R�����\); false(�R������)
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
// �����䵲���
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