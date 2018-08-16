/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 13:08:26 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/16 14:06:03 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"

// constructor
Display::Display(void)
{

}

// deconstructor
Display::~Display(void)
{
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
}

void	Display::CloseWindow( void )
{
	Debug::print("close window", true);
}

// get the key inputs
Keys	Display::getKey(void)
{
	if (this->_event.type == SDL_PRESSED)
	{
		Debug::print("key pressed", true);
	}
	return Keys::UNKNOWN;
}

// get the events
bool	Display::PollEvents( void )
{
	if (SDL_PollEvent(&this->_event))
	{
		if (this->_event.type == SDL_QUIT)
			return false;
	}
	return true;
}

// render the background & border
void	Display::BackGround( void )
{
	Debug::print("Draw a background", true);
}

// Render background/apple/snake/border
void	Display::Render(int foodX, int foodY, std::vector<Block> snake)
{
	(void)foodX;
	(void)foodY;
	(void)snake;

	// The window is open: could enter program loop here (see SDL_PollEvent())

	//std::cout << "wait 3 seconds" << std::endl;
	//SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example
	SDL_SetRenderDrawColor(this->_ren, 255, 0, 0, 255);
	SDL_RenderClear(this->_ren);
	//SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
	SDL_RenderPresent(this->_ren);
}

// initilize screen size
void	Display::Init(int width, int height)
{
	this->_width = width;
	this->_height = height;
	SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2
	// Create an application window with the following settings:
	this->_window = SDL_CreateWindow(
			"Snake in SDL",		                // window title
			SDL_WINDOWPOS_UNDEFINED,			// initial x position
			SDL_WINDOWPOS_UNDEFINED,            // initial y position
			this->_width,                              // width, in pixels
			this->_height,                             // height, in pixels
			0                  // flags - see below
			);
	// Check that the window was successfully created
	if (this->_window == NULL) {
		// In the case that the window could not be made...
		std::cout << "Could not create window" << std::endl;
	}
	this->_ren = SDL_CreateRenderer(this->_window, -1, 0);
}

// return instance of display object.
Interface * CreateDisplay( void )
{
	return new Display;
}
// delete new instance of it
void	DeleteDisplay(Display * display)
{
	delete display;
}
