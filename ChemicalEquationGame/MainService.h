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


	//ͳ��
	void LoadAtomStatistics();
	void LoadEquationStatistics();

	//����
	//vector<AtomStatistics> GetAtomStatisticsByLvSort();
	//vector<AtomStatistics> GetAtomStatisticsByNumberSort();

	//����
	vector<char*> Create( int size );

	//���
	int Check( vector<char*> items );

	//��ȡ����
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