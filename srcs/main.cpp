/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <ckatz@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:34:22 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/03 14:54:04 by ckatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <dlfcn.h>
#include "main.hpp"

void	dlerror_wrapper()
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	void		*dl_handle;
	void		(*fn_pointer)(struct settings);

	struct settings	set;

	std::string		lib1 = "./bin/sfml.so";
	std::string		lib2 = "./bin/sdl.so";
	std::string		lib3 = "./bin/glfw.so";

	const char		*l1 = lib1.c_str();
	const char		*l2 = lib2.c_str();
	const char		*l3 = lib3.c_str();

	if (ac == 3)
	{
		set.width = std::stoi(av[1]);
		set.height = std::stoi(av[2]);
		dl_handle = dlopen(l1 , RTLD_LAZY | RTLD_LOCAL);
		if (!dl_handle)
			dlerror_wrapper();
		fn_pointer = (void(*)(struct settings)) dlsym(dl_handle, "test");
		if (!fn_pointer)
			dlerror_wrapper();
		fn_pointer(set);
	}
	else
		std::cout << "Invalid arguments given. please give a width and height." << std::endl;
	return (0);
}
