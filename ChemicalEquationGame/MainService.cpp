#include "MainService.h"



MainService * MainService::GetInstance()
{
	if( m_instance == NULL )
	{
		m_instance = new MainService();
	}
	return m_instance;
}

