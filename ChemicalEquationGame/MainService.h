#ifndef __MAIN_SERVICE_H__
#define __MAIN_SERVICE_H__

#include "Struct.h"

#include <vector>
using namespace std;

class MainService
{
private:
	MainService(void);
	~MainService(void);
public:
	static MainService *GetInstance( );


public:
	void LoadAtom();
	void LoadMolecule();
	void LoadEquation();


	//统计
	void LoadAtomStatistics();
	void LoadEquationStatistics();

	//排序
	//vector<AtomStatistics> GetAtomStatisticsByLvSort();
	//vector<AtomStatistics> GetAtomStatisticsByNumberSort();

	//创建
	vector<char*> Create( int size );

	//检测
	int Check( vector<char*> items );

	//获取数据
	int GetAtomIDByName( char * );
	char *GetMoleculeNameByID( int );
	int GetMoleculeIDByName( char * );
private:
	static MainService *m_instance;

public:
	//Data m_data;
	vector< Atom >      m_atom_table;
	vector< Molecule >  m_fenzi;
	vector< Equation >  m_equations;
};


#endif