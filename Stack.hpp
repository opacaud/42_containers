/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:26 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 14:14:34 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// https://en.cppreference.com/w/cpp/container/stack  																//
// The std::stack class is a container adaptor that gives the programmer											//
// the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.							//
// The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.	//
// The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.	//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# include <iostream>
# include "Vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			// MEMBER TYPES
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			// MEMBER FUNCTIONS
			explicit stack(const container_type & ctnr = container_type())
				: c(ctnr)
			{

			};

			stack(const stack & other)
			{
				*this = other;
			};

			stack &	operator=(stack const & other)
			{
				if (this != &other)
				{
					c = other.c;
				}
				return (*this);
			};

			~stack()
			{

			};

				// element access
			reference	top()
			{
				return (c.back());
			};

			const_reference	top() const
			{
				return (c.back());
			};

				// capacity
			bool	empty() const
			{
				return (c.empty());
			};

			size_type	size() const
			{
				return (c.size());
			};

				// modifiers
			void	push(const value_type & value)
			{
				c.push_back(value);
			};

			void	pop()
			{
				c.pop_back();
			};

			// So that non member functions can access the protected attribute
			template <class T1, class Container1> friend bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
			template <class T1, class Container1> friend bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
			template <class T1, class Container1> friend bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
			template <class T1, class Container1> friend bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
			template <class T1, class Container1> friend bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
			template <class T1, class Container1> friend bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

		protected:

			// MEMBER OBJECTS
			Container	c;
	};

	// NON MEMBER FUNCTIONS
	template <class T1, class Container1>
	bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c == rhs.c);
	};

	template <class T1, class Container1>
	bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c != rhs.c);
	};

	template <class T1, class Container1>
	bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c < rhs.c);
	};

	template <class T1, class Container1>
	bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c <= rhs.c);
	};

	template <class T1, class Container1>
	bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c > rhs.c);
	};

	template <class T1, class Container1>
	bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs)
	{
		return (lhs.c >= rhs.c);
	};
}

#endif
