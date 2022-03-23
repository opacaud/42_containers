/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:43:51 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 09:43:51 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EGAL_HPP
# define EGAL_HPP

//////////////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/algorithm/equal/?kw=equal			    //
// Compares the elements in the range [first1,last1) with those in the range       	    //
// beginning at first2, and returns true if all of the elements in both ranges match.	    //
// Pred represents a binary function that accepts two elements as argument		    //
// (one of each of the two sequences, in the same order),				    //
// and returns a value convertible to bool. The value returned 				    //
// indicates whether the elements are considered to match in the context of this function.  //
// The function shall not modify any of its arguments.				    	    //
// This can either be a function pointer or a function object.				    //
//////////////////////////////////////////////////////////////////////////////////////////////

#include "is_integral.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool equal(typename ft::enable_if<!ft::is_integral<InputIterator1>::value, InputIterator1>::type first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};
}

#endif
