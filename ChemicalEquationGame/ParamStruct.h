#ifndef __PARAM_STRUCT_H__
#define __PARAM_STRUCT_H__

#include <map>
#include <vector>
#include <string>
#include <stdarg.h>
using namespace std;


/*
���֣�Value
˵����������װ��*/
class ParamStruct
{
private:
	/*
	���֣�Value
	˵���������ķ�װ
	������enum ValueType m_type �������ͣ�STRING      �����������ͣ���ת�����ַ�����ʽ��
										  PARAMSTRUCT ���Ͻṹ����
		  string m_string ������ΪSTRINGʱ��m_stringΪ�������ֵ��������ΪPARAMSTRUCT��m_stringֵΪ""
		  ParamStruct *m_param ������ΪPARAMSTRUCT, m_paramΪ�������ֵ��������ΪSTRING,m_paramֵΪNULL*/
	struct Value
	{
		enum ValueType
		{
			STRING,
			PARAMSTRUCT
		} m_type;
		string m_string;
		ParamStruct *m_param;
		Value()
		{
			m_type = STRING;
			m_string = "";
			m_param = NULL;
		}
		~Value()
		{
			if( NULL != m_param )
			{
				delete m_param;
				m_param = NULL;
			}
		}
	};
public:
	/*
	���֣�ParamStruct
	˵�������캯����ͨ���ɱ������������
	������int number �ɱ��������
		  ...        �ɱ����*/
	ParamStruct( int number, ... );
	/*
	���֣�ParamStruct
	˵�������캯����ͨ���������б�������
	������vector< string> variables �������б�*/
	ParamStruct( vector<string>	variables );
	/*
	���֣�ParamStruct
	˵�������ƹ��캯��
	������const ParamStruct &m_param ����Դ*/
	ParamStruct( const ParamStruct &m_param );
	
	/*
	���֣�~ParamStruct
	˵��������������ָ���ͳ�Ա�����Ŀռ��ͷ�
	��������*/
	virtual ~ParamStruct();

	/*
	���֣�GetValue
	˵��������������ȡֵ
	������string key ����
		  string value ֵ*/
	void GetValue( string key, string &value );
	/*
	���֣�GetValue
	˵��������������ȡֵ
	������string key ����
		  ParamStruct value ֵ*/
	void GetValue( string key, ParamStruct &value );

	/*
	���֣�SetValue
	˵����������������ֵ
	������string key ����
		  string value ֵ*/
	void SetValue( string key, string &value );
	/*
	���֣�SetValue
	˵����������������ֵ
	������string key ����
		  ParamStruct value ֵ*/
	void SetValue( string key, ParamStruct &value );
	
private:
	/*
	���֣�m_parame_map
	˵�����������
	������string ����
		  Value* ֵ*/
	map< string, Value* > m_parame_map;
};


#endif