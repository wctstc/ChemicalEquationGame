#include "MainService.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
using namespace std;


MainService *MainService::m_instance = NULL;

MainService *MainService::GetInstance()
{
	if( m_instance == NULL )
	{
		m_instance = new MainService();
	}
	return m_instance;
}
MainService::MainService(void)
{
	LoadAtom();
	LoadMolecule();
	LoadEquation();
}

MainService::~MainService(void)
{

}


void MainService::LoadAtom()
{
	char elements_name[][5] = {
		"H",  "He", "Li", "Pi",  "Pe",
		"C",   "N",  "O",  "F", "Ne",
		"Na", "Mg", "Al", "Si",  "P",
		"S",  "Cl", "Ya",  "K", "Ca"
	};
	Atom element;
	for( int i = 0; i < 20; i++ )
	{
		element.number = i;
		strcpy_s( element.name, elements_name[i] );

		m_atom_table.push_back( element );
	}
}

void MainService::LoadMolecule()
{
/*	char elements_name[][5] =  
	{
		"H2","C","CO2","O2","H2O"
	};

	Molecule fenzi;
	int number;
	int size = sizeof( elements_name )/sizeof(elements_name[0]);
	for( int i = 0; i < size; i++ )
	{
		fenzi.id = i;
		

		int length = strlen( elements_name[i] );

		for( int j = 0; j < length; )
		{
			char name[5] = {'\0'};
			int t = 1;
			name[0] = elements_name[i][j];
			number = elements_name[i][j+1] >= '0'&& elements_name[i][j+1] <= 9?elements_name[i][j+1]-'0':1;
			if( elements_name[i][j+t] > '9' || elements_name[i][j+t] < '0' )
			{
				name[1] = elements_name[i][j+1];
				t = 2;
				number = elements_name[i][j+2] >= '0'&& elements_name[i][j+2] <= 9?elements_name[i][j+1]-'0':1;
			}

			fenzi.items.push_back( Molecule::Item( GetAtomIDByName(name), number ) );

			j+=(t+1);
		}
		strcpy_s( fenzi.name, elements_name[i] );

		m_fenzi.push_back( fenzi );
	}*/

}


void MainService::LoadEquation()
{/*
	Equation equation1;

	equation1.id = 1;
	equation1.fyw.push_back( 0 );
	equation1.fyw.push_back( 3 );
	equation1.scw.push_back( 4 );
	m_equations.push_back( equation1 );

	Equation equation2;
	equation2.id = 2;
	equation2.fyw.push_back( 1 );
	equation2.fyw.push_back( 3 );
	equation2.scw.push_back( 2 );
	m_equations.push_back( equation2 );*/
}


vector<char*> MainService::Create( int size )
{
	vector< char* > items;

	while( items.size() < size )
	{
		int select = rand()%m_equations.size();
		Equation equation = m_equations[select];

		vector< Molecule >::iterator it = equation.reactant.begin();
		for( ; it != equation.reactant.end(); it++ )
			items.insert( items.begin()+ rand()%(items.size()+1),it->name );


		it = equation.resultant.begin();
		for( ; it != equation.resultant.end(); it++ )
			items.insert( items.begin()+ rand()%(items.size() +1), it->name );
	}

	while( items.size() !=  size )
	{
		items.pop_back();
	}
	return items;
}


int MainService::Check(vector<char*> items)
{
	vector<Molecule> temp;

	for( int i =0; i < items.size(); i++ )
	{
		temp.push_back( m_data.GetAtomByName( items[i]) );
	}

	vector< Equation >::iterator it = m_equations.begin();
	for( ; it != m_equations.end(); it++ )
	{
		bool ctn = true;
		vector< int >::iterator it_f = it->reactant.begin();
		for( ; it_f != it->reactant.end(); it_f++ )
		{
			ctn = true;
			int id = (*it_f);
			for( int i = 0; i < temp.size(); i++ )
			{
				if( temp[i] == id )
				{
					ctn = false;
					break;
				}
			}
			if( ctn == true )
			{
				break;
			}
		}
		if( ctn == true )
		{
			continue;
		}
		
		for( it_f = it->resultant.begin() ; it_f != it->resultant.end(); it_f++ )
		{
			ctn = true;
			int id = (*it_f);
			for( int i = 0; i < temp.size(); i++ )
			{
				if( temp[i] == id )
				{
					ctn = false;
					break;
				}
			}
			if( ctn == true )
			{
				break;
			}
		}
		if( ctn == false )
		{
			return 1;
		}
	}

	return -1;
	
}
