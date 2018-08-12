/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:49:37 by mafernan          #+#    #+#             */
/*   Updated: 2018/08/11 12:13:24 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CPP
# define DEBUG_CPP

# include <iostream>

class Debug {
	public:
		Debug( void ) {};
		~Debug( void ) {};

		static void	print(std::string string, bool flag) {
			std::string	RED = "\033[1;31m";
			std::string	RESET = "\033[0m";
			if (flag == true)
				std::cout << RED << string << RESET << std::endl;
		};
};

#endif
