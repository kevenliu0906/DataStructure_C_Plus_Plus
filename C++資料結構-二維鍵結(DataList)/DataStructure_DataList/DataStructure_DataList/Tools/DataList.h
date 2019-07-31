#pragma once
#include "List_CS.h"

//基礎二維鍵結資料
class DataListLink_CS
{
public:
	DataListLink_CS   *NextList_cs_pr;
	List_CS           CellList_cs;
	int               CellListName_i;

	DataListLink_CS();
	~DataListLink_CS();
};

//二維鍵結
class DataList_CS
{
public:
	DataList_CS();
	~DataList_CS();
	void Create_Fn(int  ListName_i);
	bool AddListData_Fn(int ListPosition, int CellData_i);
	int  GetListCount_Fn();
	int  GetListName_Fn(int ListPosition_i);
	int  GetListDataCount_Fn(int ListPosition_i);
	int  GetListData_Fn(int ListPosition_i, int ListDataPosition_i);
	int  GetListPosition_Fn(int ListName_i);
	bool FreeListData_Fn(int ListPosition_i);
	void FreeData_Fn();

protected:
	DataListLink_CS   *HeadList_cs_pr;
	DataListLink_CS   *TailList_cs_pr;
	int               ListCount_i;
};
