
#include "UIBase.h"

#include "Region.h"
#include "ElementData.h"


#include <conio.h>
int main()
{
	ElementData eledata;
	/*gotoxy( 10,10 );

	for( int i = 0 ; i < 16; i++ )
	{
		for( int j = 0; j < 16; j++ )
		{
			setcolor( 5, 10 );
			printf( "O");
		}
		printf( "\n" );
	}

	printf( "hello world");

	char c;
	readxy( 20,10,c );

	setcolor( 7, 15 );
	printf ("%c%c%c%c",c,c,c,c );*/

	Region region;
	int ret = region.MainRegion();
	region.ClearScreenRegion();
	switch( ret )
	{
	case 1:
		region.GameRegion();
	}

	printf("hello");
	char c;
	char tmp[10];
	for( int i = 0; i < 5; i++ )
	{
		readxy( i, 0, c );
		tmp[i] = c;
		tmp[i+1] = '\0';
	}

	print( 0,2, tmp );
	 

	while(true)
	{
		printf( "%d\n", _getch() );
	}


	return 0;
}
