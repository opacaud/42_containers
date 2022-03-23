/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:02 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 14:12:48 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare  			//
// Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).  	//
// The result of comparing these first non-matching elements is the result of the lexicographical comparison.	//
// If both sequences compare equal until one of them ends,														//
// the shorter sequence is lexicographically less than the longer one.											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "is_integral.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	};

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	};
}

#endif
