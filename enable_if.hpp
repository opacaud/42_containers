/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:43:48 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 09:43:48 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/type_traits/enable_if/              //
// The type T is enabled as member type enable_if::type if Cond is true.   //
/////////////////////////////////////////////////////////////////////////////

namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if
	{
		
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif
