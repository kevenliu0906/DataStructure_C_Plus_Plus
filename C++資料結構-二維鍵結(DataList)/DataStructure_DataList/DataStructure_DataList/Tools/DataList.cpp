#include "stdafx.h"
#include "DataList.h"


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//��¦�䵲���(�G��)
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
//�G���䵲
DataList_CS::DataList_CS()
//�غc�禡
{
	HeadList_cs_pr = NULL;
	TailList_cs_pr = NULL;
	ListCount_i = 0;
}
//-----------------------------------------------------------------------------
DataList_CS::~DataList_CS()
//�Ѻc�禡
{
	FreeData_Fn();
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListCount_Fn()
//����G���䵲���䵲�ƶq
// �^��: �䵲���ƶq
{
	return (ListCount_i);
}
//-----------------------------------------------------------------------------
int DataList_CS::GetListName_Fn(int ListPosition_i)
//����G���䵲���䵲�W��
// ListPosition_i: ���w�䵲��m
// �^��: �䵲�W��
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
//�إߤG���䵲
// ListName_i: ���إ��䵲���W��
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
//�[�J���
// ListPosition_i: ���w���䵲��m
// CellData_i: ���
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
//����G���䵲�����w�䵲������Ƽƶq
// ListPosition_i: ���w���䵲��m
// �^��: ��ƪ��ƶq
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
//����G���䵲�����w�䵲�������w���
// ListPosition_i: ���w���䵲��m
// ListDataPosition_i: ���w����Ʀ�m
// �^��: ���
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
//����G���䵲�����w�䵲������m
// ListName_i: ���w���䵲�W��
// �^��: ��m
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
//�����S�w��m���䵲���
// ListPosition_i: �䵲���w��m
// �^��: true(�R�����\); false(�R������)
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
// �����䵲���
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