
#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <iostream>
# include <ncurses.h>

class Display {
	public:
		Display( void );
		~Display( void );
		int	menu( void );
		void	update( int score, int lives );
		void	print( void );
		void 	resolution( void );
		void 	settings( void );
		void 	lives( void );
		void 	difficulty( void );
		void 	score( void );
		void	library( void );
		void	reset( void );
		int	 	getLibrary( void );
		int	 	getLives( void );
		int	 	getLevel( void );
		int		screenHeight( void );
		int		screenWidth( void );
	private:
		int	_library = 5;
		int	_level = 1;
		int	_screenWidth = 400;
		int	_screenHeight = 400;
		int	_score = 0;
		int	_time = 0;
		int	_lives = 3;
		int	_width = 5;

};


int	barmenu(const char **array, const int row, const int col, const int arraylength, const int width, int menulength, int selection);


#endif
