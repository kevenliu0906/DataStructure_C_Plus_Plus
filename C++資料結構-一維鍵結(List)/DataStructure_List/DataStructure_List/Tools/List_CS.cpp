#include "stdafx.h"
#include "List_CS.h"


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//��¦�䵲���(�@��)
ListLink_CS::ListLink_CS()
//�غc�禡
{
	Next_cs_pr = NULL;
	Content_i = 0;
}
//-----------------------------------------------------------------------------
ListLink_CS::~ListLink_CS()
//�Ѻc�禡
{

}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//�@���䵲
List_CS::List_CS()
//�غc�禡
{
	ListDataCount_i = 0;
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//-----------------------------------------------------------------------------
List_CS::~List_CS()
//�Ѻc�禡
{
	FreeData_Fn();
}
//-----------------------------------------------------------------------------
void List_CS::Create_Fn(int  Data_i)
//�إ��䵲
// Data_i: ���إ��䵲��ƪ����e
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
//���J�䵲���
// ListDataPos_i: ���J��m
// Data_i: �����J�����
// �^��: true(���J���\); false(���J����)
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

	if (ListDataPos_i == 1)   //���J��}�C���Ĥ@��
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
//����䵲���`��Ƽƥ�
// �^��: �䵲���`��Ƽƥ�
{
	return (ListDataCount_i);
}
//-----------------------------------------------------------------------------
int List_CS::GetListData_Fn(int ListDataPos_i)
//����䵲�������
// ListDataPos_i: ��������@�q���䵲���
// �^��: �^�Ǹ��䵲�������
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
//�����Ʀb�䵲������m
// Data_i: ��������
// �^��: �Ӹ�Ʀb�䵲������m
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
//�R���䵲
// StartPosition_i: �R�����_�l��m
// DeleteCount_i: �R���ƶq
// �^��: true(�R�����\); false(�R������)
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

		if (Target_cs_pr == NULL)  // �N������Tail�w�g�Q����
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
// �����䵲���
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