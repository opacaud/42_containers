/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:19 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 15:20:54 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

//////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/iterator/RandomAccessIterator/		//
// Random-access iterators are iterators that can be used to access elements	//
// at an arbitrary offset position relative to the element they point to,	//
// offering the same functionality as pointers.			  		//
// Input     <---     Forward     <---     Bidirectional     <--- Random access	//
// Ouput									//
// https://www.geeksforgeeks.org/random-access-iterators-in-cpp/		//
//////////////////////////////////////////////////////////////////////////////////

# include <iostream>

namespace ft
{
	// https://en.cppreference.com/w/cpp/iterator/iterator_tags
	// Defines the category of an iterator. Each tag is an empty type.
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <class T>
	class random_access_iterator
	{
		public :

			typedef ptrdiff_t			difference_type;
			typedef T				value_type;
			typedef T *				pointer;
			typedef T &				reference;
			typedef random_access_iterator_tag	iterator_category;

			random_access_iterator()
				: m_base(NULL)
			{

			};

			explicit random_access_iterator(pointer base)
				: m_base(base)
			{

			};

			random_access_iterator(const random_access_iterator & rhs)
				: m_base(rhs.m_base)
			{

			};

			random_access_iterator & operator=(const random_access_iterator & rhs)
			{
				if (this != &rhs)
					m_base = rhs.m_base;
				return (*this);
			};

			virtual ~random_access_iterator()
			{

			};

			// Implicit conversion from iterator to const_iterator
			// https://bytes.com/topic/c/answers/503867-implementing-const_iterator-iterator
			// https://www.cplusplus.com/forum/beginner/259040/
			operator random_access_iterator<T const>() const
			{
				return (random_access_iterator<T const>(m_base));
			};

			reference	operator*() const
			{
				return (*m_base);
			};

			random_access_iterator	operator+(const difference_type & n) const	// it + n
			{
				return (random_access_iterator(m_base + n));
			};

			random_access_iterator	operator-(const difference_type & n) const	// it - n
			{
				return (random_access_iterator(m_base - n));
			};

			random_access_iterator & operator++()					// it++
			{
				++m_base;
				return (*this);
			};

			random_access_iterator operator++(int)					// ++it
			{
				random_access_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			random_access_iterator & operator--()					// it--
			{
				--m_base;
				return (*this);
			};

			random_access_iterator operator--(int)					// --it
			{
				random_access_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			random_access_iterator & operator+=(difference_type n)			// it += n
			{
				m_base += n;
				return (*this);
			};
			
			random_access_iterator & operator-=(difference_type n)			// it-= n
			{
				m_base -= n;
				return (*this);
			};

			//https://stackoverflow.com/questions/8777845/overloading-member-access-operators
			/*
			it must return a pointer that can be used to select what the pointer dereference operator arrow is pointing at.
			The extra functionality is provided for convenience, so you do not have to call
			a->->func();
			You can simply do:
			a->func();
			*/
			pointer	operator->() const						// it->value
			{
				return (&(operator*()));
			};

			reference operator[](difference_type n) const				// it[n]
			{
				return (m_base[n]);
			};

			pointer	base() const
			{
				return (m_base);
			};

///////////////////
		friend std::ostream & operator<<(std::ostream & o, random_access_iterator<T> & rhs)
		{
			o << *rhs.m_base;
			return (o);
		}
///////////////////

		private :

			T	*m_base;
	};

	// NON MEMBER FUNCTION OVERLOADS
	template <class T>													// it == it2
	bool	operator==(const ft::random_access_iterator<T> & lhs, const ft::random_access_iterator<T> & rhs)
	{
		return (lhs.base() == rhs.base());
	};

	// Second versions are used to compare an iterator (T1) with a const iterator (T2)
	template <class T1, class T2>												// const it == it2 or it == const it2
	bool	operator==(const ft::random_access_iterator<T1> & lhs, const ft::random_access_iterator<T2> & rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <class T>													// it != it2
	bool	operator!=(const ft::random_access_iterator<T> & lhs, const ft::random_access_iterator<T> & rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class T1, class T2>												// const it != it2 or it != const it2
	bool	operator!=(const ft::random_access_iterator<T1> & lhs, const ft::random_access_iterator<T2> & rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class T>													// it < it2
	bool	operator<(const ft::random_access_iterator <T>& lhs, const ft::random_access_iterator <T>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class T1, class T2>												// const it < it2 or it < const it2
	bool	operator<(const ft::random_access_iterator <T1>& lhs, const ft::random_access_iterator <T2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class T>													// it > it2
	bool	operator>(const ft::random_access_iterator <T>& lhs, const ft::random_access_iterator <T>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class T1, class T2>												// const it > it2 or it > const it2
	bool	operator>(const ft::random_access_iterator <T1>& lhs, const ft::random_access_iterator <T2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class T>													// it <= it2
	bool	operator<=(const ft::random_access_iterator<T> & lhs, const ft::random_access_iterator<T> & rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class T1, class T2>												// const it <= it2 or it <= const it2
	bool	operator<=(const ft::random_access_iterator<T1> & lhs, const ft::random_access_iterator<T2> & rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class T>													// it >= it2
	bool	operator>=(const ft::random_access_iterator<T> & lhs, const ft::random_access_iterator<T> & rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class T1, class T2>												// const it >= it2 or it >= const it2
	bool	operator>=(const ft::random_access_iterator<T1> & lhs, const ft::random_access_iterator<T2> & rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class T>
	random_access_iterator<T>	operator+(typename ft::random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T> & it)
	{
		return (it + n);												// n + it
	};

	template <class T>
	typename random_access_iterator<T>::difference_type	operator-(const random_access_iterator<T> & lhs, const random_access_iterator<T> & rhs)
	{
		return (lhs.base() - rhs.base());										// it - it2
	};

	// Second version is used to substract an iterator (T1) to a const iterator (T2) or the other way around
	template <class T1, class T2>
	typename random_access_iterator<T1>::difference_type	operator-(const random_access_iterator<T1> & lhs, const random_access_iterator<T2> & rhs)
	{
		return (lhs.base() - rhs.base());										// const it - it or it - const it
	};
}

#endif
