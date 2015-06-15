#pragma once

class Config
{
public:
	Config(void);
	Config( CString fileName );
public:
	~Config(void);

public:
	void SetFile( CString fileName );
	void SetKeyValue( CString setion, CString key, CString value );
	void GetKeyValue( CString setion, CString key, CString &value, CString defaultValue = "" );

public:
	static void SetKeyValue( CString setion, CString key, CString value, CString fileName );
	static void GetKeyValue( CString setion, CString key, CString &value, CString defaultValue, CString fileName );
private:
	CString m_fileName;
};
