#include "ParamStruct.h"

ParamStruct::ParamStruct( int number, ... )
{
	va_list varibles;
	va_start( varibles, number );

	for( int i =0; i < number; i ++ )
	{
		string key = va_arg( varibles, string );
		if( !key.empty() )
		{
			m_parame_map.insert( pair< string, Value * >( key , NULL ) );
		}
	}
}

ParamStruct::ParamStruct(vector<string> variables)
{
	int size = variables.size();
	for( int i =0; i < size; i ++ )
	{
		m_parame_map.insert( pair< string, Value * >( variables[i] , NULL ) );
	}
}

ParamStruct::ParamStruct( const ParamStruct &m_param )
{
	Value *value;
	for( map<string, Value*>::iterator it_map = m_param.m_parame_map.begin(); it_map != m_param.m_parame_map.end(); it_map++ )
	{
		value = new Value();
		value->m_type = it_map->second->m_type;
		if( it_map->second->m_type == Value::STRING )
		{
			value->m_string = it_map->second->m_string;
		}
		else if( it_map->second->m_type == Value::PARAMSTRUCT )
		{
			value = new decltype( it_map->second->m_param )
		}
		m_parame_map.insert( pair< string, Value* )
	}
}

ParamStruct::~ParamStruct(void)
{
	map< string, Value * >::iterator it_map = m_parame_map.begin();
	for( ; it_map != m_parame_map.end(); it_map++ )
	{
		if( it_map->second != NULL )
		{
			if( it_map->second.m_param != NULL )
			{
				delete it_map->second.m_param;
				it_map->second.m_param = NULL;
			}
			delete it_map->second;
			it_map->second = NULL;
		}
	}
}
