#pragma once

//======================================================================================
//========================= �@���䵲����Ƽ˪O ===========================================
//======================================================================================
// [�`�N]: �Y�Oclass�ŧi���˪O��������(class template)
//         �hclass�����禡��@�����h�n�b.h�����A���i�N��@��������.cpp��
//         �_�h�|�y���~��.cpp�L�k�ϥθ�class

// �@���쵲����Ƽ˪O
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
//��¦�䵲���(�@��)
template
<typename Cell>
ListLink_te_CS<Cell> ::ListLink_te_CS()
//�غc�禡
{
	//Data_E = Cell;
	Next_cs_pr = NULL;
}
//------------------------------------------------------------------
template
<typename Cell>
ListLink_te_CS<Cell>::~ListLink_te_CS()
//�Ѻc�禡
{

}
//------------------------------------------------------------------


//======================================================================================
//=========================== �@���䵲���˪O ============================================
//======================================================================================
// [�`�N]: �Y�Oclass�ŧi���˪O��������(class template)
//         �hclass�����禡��@�����h�n�b.h�����A���i�N��@��������.cpp��
//         �_�h�|�y���~��.cpp�L�k�ϥθ�class

//�@���쵲���˪O
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
//�@���䵲
template
<typename Cell,
 typename ListName>
List_te_CS<Cell, ListName>::List_te_CS()
//�غc�禡
{
	Head_cs_pr = NULL;
	Tail_cs_pr = NULL;
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
List_te_CS<Cell, ListName>::~List_te_CS()
//�Ѻc�禡
{
	FreeData_Fn();
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
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
template
<typename Cell,
 typename ListName>
int List_te_CS<Cell, ListName>::GetListDataCount_Fn()
//����䵲���`��Ƽƥ�
// �^��: �䵲���`��Ƽƥ�
{
	return (ListDataCount_i);
}
//------------------------------------------------------------------
template
<typename Cell,
 typename ListName>
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
template
<typename Cell,
 typename ListName>
int List_te_CS<Cell, ListName>::GetListDataPosition_Fn(Cell CellData_E)
//�����Ʀb�䵲������m
// CellData_E: ��������
// �^��: �Ӹ�Ʀb�䵲������m
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
//�R���䵲
// StartPosition_i: �R�����_�l��m
// DeleteCount_i: �R���ƶq
// �^��: true(�R�����\); false(�R������)
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
//���J�䵲���
// ListDataPos_i: ���J��m
// Data_i: �����J�����
// �^��: true(���J���\); false(���J����)
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

	if (ListDataPosition_i == 1)   //���J��}�C���Ĥ@��
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
//�����䵲���
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