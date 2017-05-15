#include "header.h"

int main( int argc, char *argv[] )
{
	PDC_set_function_key( FUNCTION_KEY_SHUT_DOWN, ALT_X );

	initscr();
	resize_term( 30, 120 );
	start_color();
	init_pair( 1, COLOR_WHITE, COLOR_BLUE);
	init_pair( 2, COLOR_WHITE, COLOR_BLACK);

	cbreak();
	noecho();
	clear();
	nodelay( stdscr, 1 );
	curs_set(0);
	refresh();

	keypad( stdscr, TRUE );
	mousemask( ALL_MOUSE_EVENTS, NULL );
	int max_row, max_col;
	getmaxyx( stdscr, max_row, max_col );

	do_lesson( max_row, max_col );
	endwin();
	return 0;
}

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					  LPSTR lpszCmdLine, int nCmdShow)
{
	char *argv[30];
	int i, argc = 1;

	argv[0] = "newtest";
	for( i = 0; lpszCmdLine[i]; i++)
		if( lpszCmdLine[i] != ' ' && (!i || lpszCmdLine[i - 1] == ' '))
			argv[argc++] = lpszCmdLine + i;

	for( i = 0; lpszCmdLine[i]; i++)
		if( lpszCmdLine[i] == ' ')
			lpszCmdLine[i] = '\0';

	return main( argc, (char **)argv);
}
