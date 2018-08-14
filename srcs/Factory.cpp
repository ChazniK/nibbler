/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:54:27 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/14 16:11:27 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

// throw error if dlhandle isn't working
void	dlerrorWrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit( EXIT_FAILURE );
}

// This will create and return the correct dynamic library
// need to add a check to see if it's the same library or not
Interface	*Factory::createLibrary(int libNum)
{
	void			*dl_handle;
	Interface*		(*fn_pointer)( void );
	std::string		library;

	if (libNum == 5)
		library = "../bin/sfml.so";
	dl_handle = dlopen( "bin/sfml.so", RTLD_LAZY | RTLD_LOCAL );
	if ( !dl_handle )
		dlerrorWrapper();
	fn_pointer = (Interface*(*)(void)) dlsym(dl_handle, "CreateDisplay");
	if (!fn_pointer)
		dlerrorWrapper();
	this->dlGraphics = fn_pointer();
	return (this->dlGraphics);
}

void	Factory::deleteLibrary(Interface* & dlGraphics)
{
	(void)dlGraphics;
	std::cout << "deleted" << std::endl;
	//delete this->dlGraphics;
}
