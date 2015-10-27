#include "Region.h"

#include <conio.h>
#include <stdlib.h>
#include "UIBase.h"
#include "MainService.h"

Region::Region(void)
{
}

Region::~Region(void)
{
}

int Region::MainRegion()
{
	ClearScreenRegion();

	gotoxy( 40, 0 );

	printf( "Welcome To Chemical Equation Game!!!" );

	gotoxy( 45, 10 );

	vector<char * > title;

	title.push_back( "开始游戏" );
	title.push_back( "设置" );
	title.push_back( "说明" );
	title.push_back( "背景" );
	int i = 0;
	for( vector<char *>::iterator it = title.begin(); it != title.end(); it++,i++ )
	{
		print( 45, i+10, *it );
	}

	m_point.m_x = 44;
	m_point.m_y = 10;

	m_gap.m_x = 0;
	m_gap.m_y = 1;
	return MessageLoop();
}

int Region::GameRegion()
{

	//数据加载
	vector<char *> items = MainService::GetInstance()->Create( 100 );
	for( int i = 0; i < 10; i++ )
	{
		for( int j = 0; j < 10; j++ )
		{
			print( 11+i*4, 4+j, items[i*10+j] );
		}
	}

	
	//光标参数初始化
	m_point.m_x = 10;//起始位
	m_point.m_y = 4;//起始位

	m_gap.m_x = 4;//间隔
	m_gap.m_y = 1;//间隔


	//分数
	m_sort.m_x = 55;//起始位
	m_sort.m_y = 3;//起始位

	print( m_sort.m_x, m_sort.m_y, "分数：0" );

	return MessageLoopGame();
}

void Region::ClearScreenRegion()
{
	clear( );
}

int Region::MessageLoopGame( )
{
	unsigned char c;
	Point firstPoint = m_point;

	print( m_point.m_x, m_point.m_y, "*" );
	while( true )
	{
		if( _kbhit( ) )
		{
			c = _getch( );

			//回车
			if( c == 13 )
			{
				Point selected;
				selected.m_x = ( m_point.m_x - firstPoint.m_x )/ m_gap.m_x;
				selected.m_y = ( m_point.m_y - firstPoint.m_y )/ m_gap.m_y;

				if( selected.m_x < 10 && selected.m_x >= 0 && selected.m_y < 10 && selected.m_y >= 0 )
				{
					char c;
					char buffer[10];
					for( int i = 0; true; i++ )
					{
						readxy( m_point.m_x+i+1, m_point.m_y, c );
						if( ( c >= 'a' && c <= 'z' ) || 
							( c >= 'A' && c <= 'Z' ) ||
							( c >= '0' && c <= '9' ))
						{
							buffer[i] = c;
							buffer[i+1] = '\0';
						}
						else
						{
							break;
						}
					}
					OnItem( buffer );
				}
				else if( true )
				{
					//OnOption
				}
				else if( true )
				{

					return 0;
				}
			}
			else if( c == 27 )
			{
				OnCancel();
			}

			//方向键
			if( c == 224 )
			{
				if( _kbhit() )
				{
					c = _getch();
					clearxy( m_point.m_x, m_point.m_y );
					//移动
					switch( c )
					{
					case 72://上
						m_point.m_y -= m_gap.m_y;
						break;
					case 75://左
						m_point.m_x -= m_gap.m_x;
						break;
					case 77://右
						m_point.m_x += m_gap.m_x;
						break;
					case 80://下
						m_point.m_y += m_gap.m_y;
						break;
					default:
						continue;
					}
					//重绘
					print( m_point.m_x, m_point.m_y, "*" );
				}
				
			}
		}
	}
}

int Region::MessageLoop()
{
	unsigned char c;
	Point firstPoint = m_point;

	print( m_point.m_x, m_point.m_y, "*" );
	while( true )
	{
		if( _kbhit( ) )
		{
			c = _getch( );

			//回车
			if( c == 13 )
			{
				int selected = ( m_point.m_y - firstPoint.m_y )/ m_gap.m_y;
				switch( selected )
				{
				case 0:
					return 1;
				case 1:
					break;
				case 2:
					break;
				}
				if( true )
				{
					//OnItem();
				}
				else if( true )
				{
					//OnOption
				}
				else if( true )
				{

					return 0;
				}
			}

			//方向键
			if( c != 224 )
			{
				continue;
			}
			if( _kbhit() )
			{
				c = _getch();
			}

			clearxy( m_point.m_x, m_point.m_y );
			//移动
			switch( c )
			{
			case 72://上
				m_point.m_y -= m_gap.m_y;
				break;
			case 75://左
				m_point.m_x -= m_gap.m_x;
				break;
			case 77://右
				m_point.m_x += m_gap.m_x;
				break;
			case 80://下
				m_point.m_y += m_gap.m_y;
				break;
			default:
				continue;
			}
			//重绘
			print( m_point.m_x, m_point.m_y, "*" );
		}
	}
}

int Region::OnItem(char *item)
{
	m_selectItem.push_back( string(item));
	FrashSelected( );
	
	return Judge();
}

void Region::FrashSelected()
{
	int i = 0;
	for( vector<string>::iterator it = m_selectItem.begin(); it != m_selectItem.end(); it++,i++ )
	{
		print( 10+i*4, 20, (char *)it->c_str() );
	}
	clearxy( 10+i*4, 80,20,20 );
}


void Region::FrashSort()
{
	char buffer[80] = {'\0'};
	char c;
	for( int i = 0; i < 80; i++ )
	{
		readxy( m_sort.m_x + 5 + i, m_sort.m_y, c );
		if( c == ' ' )
			break;
		buffer[i] = c;
		buffer[i+1] = '\0';
	}
	clearxy( m_sort.m_x, 80 - m_sort.m_x, m_sort.m_y, m_sort.m_y );
	int sort = atoi( buffer );
	sort += 10;
	sprintf_s( buffer, 80, "%d", sort );
	print( m_sort.m_x + 5, m_sort.m_y, buffer );
}

int Region::OnCancel()
{
	m_selectItem.pop_back();
	FrashSelected();
	return 1;
}

int Region::Judge()
{
	vector< char * > items;
	vector< string >::iterator it = m_selectItem.begin();

	for( ; it != m_selectItem.end(); it++ )
	{
		items.push_back( (char*)it->c_str() );
	}
	if( MainService::GetInstance()->Check( items ) > 0 )
	{
		Match();
		return 2;
	}
	return 1;
}

void Region::Match()
{
	int time;
	FrashSort( );
	for( time = 0; time < 10; time++ )
	{
		if( time % 2 )
		{
			setcolor( 4,10 );
		}
		else
		{
			setcolor( 10,4 );
		}
		int i = 0;
		for( vector<string>::iterator it = m_selectItem.begin(); it != m_selectItem.end(); it++,i++ )
		{
			print( 10+i*4, 20, (char *)it->c_str() );
		}
		setcolor( 14, 0 );
		clearxy( 10+i*4, 80,20,20 );
		Sleep( 100 );
	}
	m_selectItem.clear();
	FrashSelected();
}



void Region::LoadData()
{
	//int 
}