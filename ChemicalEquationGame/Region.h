#pragma once

#include <vector>
#include <string>

using namespace std;

#define  X_DIR 0
#define  Y_DIR 1

class Region
{
public:
	Region(void);
public:
	~Region(void);


public:
	int MainRegion();
	int GameRegion();

public:
	void ClearScreenRegion();

	int MessageLoop( );

	int MessageLoopGame();

	int OnItem( char *item );
	int OnCancel( );


	void FrashSelected( );
	void FrashSort();

	int Judge( );

	void Match( );
	void LoadData();
private:
	class Point
	{
	public:
		int m_x;
		int m_y;
	} m_point,m_gap,m_limit[2],m_sort;

	vector< string > m_selectItem;
	vector< string > m_item;
};
