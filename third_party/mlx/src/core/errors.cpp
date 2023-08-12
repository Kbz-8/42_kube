/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:48:06 by maldavid          #+#    #+#             */
/*   Updated: 2023/08/12 15:56:17 by maldavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <utility>

#include "errors.h"

namespace mlx::core::error
{
	void report(e_kind kind, std::string msg, ...)
	{
		char buffer[4096];

		va_list al;
		va_start(al, msg);
		std::vsprintf(buffer, msg.c_str(), al);
		va_end(al);

		switch(kind)
		{
			case e_kind::message: std::cout << "\033[1;34m[MacroLibX] Message : \033[1;0m" << buffer << std::endl; break;
			case e_kind::warning: std::cout << "\033[1;35m[MacroLibX] Warning : \033[1;0m" << buffer << std::endl; break;
			case e_kind::error: std::cerr << "\033[1;31m[MacroLibX] Error : \033[1;0m" << buffer << std::endl; break;
			case e_kind::fatal_error:
				std::cerr << "\033[1;31m[MacroLibX] Fatal Error : \033[1;0m" << buffer << std::endl;
				std::exit(EXIT_FAILURE);
			break;
		}
	}
}
