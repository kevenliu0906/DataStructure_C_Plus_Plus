#pragma once

//基礎一維鍵結資料
class ListLink_CS
{
public:
	int           Content_i;
	ListLink_CS   *Next_cs_pr;

	ListLink_CS();
	~ListLink_CS();
};

//一維鍵結
class List_CS
{
public:
	List_CS();
	~List_CS();
	void Create_Fn(int  Data_i);
	bool Insert_Fn(int  ListDataPos_i, int Data_i);
	int  GetListDataCount_Fn();
	int  GetListData_Fn(int ListDataPos_i);
	int  GetListDataPosition_Fn(int Data_i);
	bool Delete_Fn(int StartPosition_i, int DeleteCount_i);
	void FreeData_Fn();

private:
	int          ListDataCount_i;
	ListLink_CS  *Head_cs_pr;
	ListLink_CS  *Tail_cs_pr;
};
