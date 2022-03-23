/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:16 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 11:30:36 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

//////////////////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/utility/pair/?kw=pair 					//
// This class couples together a pair of values, which may be of different types (T1 and T2).	//
// The individual values can be accessed through its public members first and second.		//
//////////////////////////////////////////////////////////////////////////////////////////////////

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		// MEMBER TYPES
		typedef T1 first_type;
		typedef T2 second_type;

		// MEMBER OBJECTS
		first_type	first;
		second_type	second;

		// MEMBER FUNCTIONS
			// default constructor
		pair() : first(), second()
		{

		};
		
			// copy constructor
		template <class U, class V>
		pair(const pair<U, V> & pr) : first(pr.first), second(pr.second)
		{

		};

			// initialization constructor
		pair(const first_type & a, const second_type & b) : first(a), second(b)
		{

		};

		pair(const pair & c) : first(c.first), second(c.second)
		{

		};

		pair &	operator=(const pair & pr)
		{
			if (this != &pr)
			{
				first = pr.first;
				second = pr.second;
			}
			return (*this);
		};
	};

	// NON MEMBER FUNCTIONS
	template <class T1, class T2>
	bool	operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	};

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	};
}

#endif
