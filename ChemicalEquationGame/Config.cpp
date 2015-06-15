#include "StdAfx.h"
#include "Config.h"

Config::Config( void )
{

}

Config::Config( CString fileName )
{
	m_fileName = fileName;
}

Config::~Config(void)
{
}

void Config::SetFile( CString fileName )
{
	m_fileName = fileName;
}

void Config::SetKeyValue( CString setion, CString key, CString value )
{
	int ret = ::WritePrivateProfileString( setion, key, value, m_fileName );
}


void Config::GetKeyValue( CString setion, CString key, CString &value, CString defaultValue )
{
	char temp[200];
	int tem =  ::GetPrivateProfileString( setion, key, defaultValue, temp, 200, m_fileName );
	value = temp;
}

void Config::SetKeyValue( CString setion, CString key, CString value, CString fileName )
{
	::WritePrivateProfileString( setion, key, value, fileName );
}
void Config::GetKeyValue( CString setion, CString key, CString &value, CString defaultValue, CString fileName )
{
	char temp[200];
	::GetPrivateProfileString( setion, key, defaultValue, temp, 200, fileName );
	value = temp;
}

