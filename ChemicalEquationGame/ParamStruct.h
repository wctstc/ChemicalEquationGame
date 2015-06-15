#ifndef __PARAM_STRUCT_H__
#define __PARAM_STRUCT_H__

#include <map>
#include <vector>
#include <string>
#include <stdarg.h>
using namespace std;


/*
名字：Value
说明：参数封装类*/
class ParamStruct
{
private:
	/*
	名字：Value
	说明：变量的封装
	参数：enum ValueType m_type 变量类型，STRING      基本数据类型，都转化成字符串形式，
										  PARAMSTRUCT 复合结构类型
		  string m_string 当类型为STRING时，m_string为本对象的值，当类型为PARAMSTRUCT，m_string值为""
		  ParamStruct *m_param 当类型为PARAMSTRUCT, m_param为本对象的值，当类型为STRING,m_param值为NULL*/
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
	名字：ParamStruct
	说明：构造函数，通过可变参数创建对象
	参数：int number 可变参数个数
		  ...        可变参数*/
	ParamStruct( int number, ... );
	/*
	名字：ParamStruct
	说明：构造函数，通过变量名列表创建对象
	参数：vector< string> variables 变量名列表*/
	ParamStruct( vector<string>	variables );
	/*
	名字：ParamStruct
	说明：复制构造函数
	参数：const ParamStruct &m_param 复制源*/
	ParamStruct( const ParamStruct &m_param );
	
	/*
	名字：~ParamStruct
	说明：析构函数，指针型成员变量的空间释放
	参数：无*/
	virtual ~ParamStruct();

	/*
	名字：GetValue
	说明：根据主键获取值
	参数：string key 主键
		  string value 值*/
	void GetValue( string key, string &value );
	/*
	名字：GetValue
	说明：根据主键获取值
	参数：string key 主键
		  ParamStruct value 值*/
	void GetValue( string key, ParamStruct &value );

	/*
	名字：SetValue
	说明：根据主键设置值
	参数：string key 主键
		  string value 值*/
	void SetValue( string key, string &value );
	/*
	名字：SetValue
	说明：根据主键设置值
	参数：string key 主键
		  ParamStruct value 值*/
	void SetValue( string key, ParamStruct &value );
	
private:
	/*
	名字：m_parame_map
	说明：保存参数
	参数：string 主键
		  Value* 值*/
	map< string, Value* > m_parame_map;
};


#endif