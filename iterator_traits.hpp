/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:43:58 by opacaud           #+#    #+#             */
/*   Updated: 2022/03/23 13:59:43 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

//////////////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/iterator/iterator_traits/?kw=iterator_traits	  		//
// https://en.cppreference.com/w/cpp/iterator/iterator_traits						  		//
// std::iterator_traits is the type trait class that provides uniform interface		  		//
// to the properties of LegacyIterator types.										  		//
// (https://en.cppreference.com/w/cpp/named_req/Iterator :							  		//
// The LegacyIterator requirements describe types that can be used to identify		  		//
// and traverse the elements of a container.)										  		//
// This makes it possible to implement algorithms only in terms of iterators.		  		//
// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits	  		//
// Therefore, the C++ standard library provides a special template structure				//
// to define the iterator traits. This structure contains all relevant information			//
// regarding an iterator. It is used as a common interface for all the type					//
// definitions an iterator should have (the category, the type of the elements , and so on)	//
//////////////////////////////////////////////////////////////////////////////////////////////

# include <cstddef>
# include "random_access_iterator.hpp"

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:

			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:

			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef random_access_iterator_tag		iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:

			typedef ptrdiff_t						difference_type;
			typedef T								value_type;
			typedef const T *						pointer;
			typedef const T &						reference;
			typedef random_access_iterator_tag		iterator_category;
	};
}

#endif
