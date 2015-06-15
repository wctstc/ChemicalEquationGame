#ifndef __MAIN_SERVICE_H__
#define __MAIN_SERVICE_H__


class MainService
{
private:
	MainService(void);
	~MainService(void);
public:
	static MainService *GetInstance( );


public:
	void LoadElement();
	void LoadChemicalEquation();
	void LoadElementStatistics();
	void LoadChemicalEquation();

private:
	static MainService *m_instance;
};


#endif