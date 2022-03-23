/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:23 by opacaud           #+#    #+#             */
/*   Updated: 2022/03/23 13:57:43 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR
# define REV_ITERATOR

# include "iterator_traits.hpp"

//////////////////////////////////////////////////////////////////////////////////////////
// https://en.cppreference.com/w/cpp/iterator/reverse_iterator		  					//
// std::reverse_iterator is an iterator adaptor that reverses the direction				//
// of a given iterator, which must be at least a LegacyBidirectionalIterator.			//
// In other words, when provided with a bidirectional iterator,							//
// std::reverse_iterator produces a new iterator that moves from the end				//
// to the beginning of the sequence defined by the underlying bidirectional iterator.	//
//////////////////////////////////////////////////////////////////////////////////////////

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			
			// MEMBER TYPES
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

			// MEMBER FUNCTIONS
			// https://www.cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/

				// default constructor
					// Constructs a reverse iterator that points to no object.
					// The internal base iterator is value-initialized.
					// LINE 776 du code source 
					// _GLIBCXX_CONSTEXPR __normal_iterator() _GLIBCXX_NOEXCEPT
					// : _M_current(_Iterator()) { }
					// Calls the constructor of the iterator type that is called when creating this reverse_iterator.
					// Ex: ft::reverse_iterator<map_iterator> rev_end (numbers.begin());
					// Here map_iterator constructor is called.
			reverse_iterator()
				: m_base(iterator_type())
			{

			};

				// initalization constructor
					// Constructs a reverse iterator from some original iterator it.
					// The behavior of the constructed object replicates the original,
					// except that it iterates through its pointed elements in the reverse order.
			explicit reverse_iterator(iterator_type it)
				: m_base(it)
			{

			};

				// copy constructor
					// Constructs a reverse iterator from some other reverse iterator.
					// The constructed object keeps the same sense of iteration as rev_it.
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> & rev_it)
				: m_base(rev_it.base())
			{

			};

			iterator_type	base() const
			{
				return (m_base);
			};

					// https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*
					// Returns a reference or pointer to the element previous to current.
					// Internally, the function decreases a copy of its base iterator and returns the result of dereferencing it.
					// https://devblogs.microsoft.com/oldnewthing/20211112-00/?p=105908
			reference	operator*()const
			{
				iterator_type tmp = m_base;
				return (*--tmp);
			};

			reverse_iterator	operator+(const difference_type n) const
			{
				return (reverse_iterator(m_base - n));
			};

			reverse_iterator	operator-(const difference_type n) const
			{
				return (reverse_iterator(m_base + n));
			};

			reverse_iterator &	operator++()
			{
				--m_base;
				return (*this);
			};

			reverse_iterator	operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			reverse_iterator &	operator--()
			{
				++m_base;
				return (*this);
			};

			reverse_iterator	operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			reverse_iterator &	operator+=(difference_type n)
			{
				m_base -= n;
				return (*this);
			};

			reverse_iterator &	operator-=(difference_type n)
			{
				m_base += n;
				return (*this);
			};

					//https://stackoverflow.com/questions/8777845/overloading-member-access-operators
					// it must return a pointer that can be used to select what the pointer dereference operator arrow is pointing at.
					// The extra functionality is provided for convenience, so you do not have to call
					// a->->func();
					// You can simply do:
					// a->func();
			pointer	operator->() const
			{
				return (&(operator*()));
			};

			reference	operator[] (difference_type n) const
			{
				return (m_base[-n - 1]);
			};

					// Implicit conversion from iterator to const_iterator
					// https://bytes.com/topic/c/answers/503867-implementing-const_iterator-iterator
					// https://www.cplusplus.com/forum/beginner/259040/
			operator reverse_iterator<iterator_type const>() const
			{
				return (reverse_iterator<iterator_type const>(m_base));
			};

		private:

			iterator_type	m_base;
	};

	// NON MEMBER FUNCTIONS
	template <class Iterator>															// rev_it == rev_it2
	bool	operator==(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() == rhs.base());
	};

	// Second versions are used to compare an reverse_iterator (T1) with a const reverse_iterator (T2)
	template <class Iterator1, class Iterator2>											// const rev_it == rev_it2 or rev_it == const rev_it2
	bool	operator==(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <class Iterator>															// rev_it != rev_it2
	bool	operator!=(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>											// const rev_it != rev_it2 or rev_it != const rev_it2
	bool	operator!=(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator>															// rev_it > rev_it2
	bool	operator<(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>											// const rev_it > rev_it2 or rev_it > const rev_it2
	bool	operator<(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator>															// rev_it < rev_it2
	bool	operator>(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>											// const rev_it < rev_it2 or rev_it < const rev_it2
	bool	operator>(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator>															// rev_it >= rev_it2
	bool	operator<=(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>											// const rev_it >= rev_it2 or rev_it >= const rev_it2
	bool	operator<=(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator>															// rev_it <= rev_it2
	bool	operator>=(const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator1, class Iterator2>											// const rev_it <= rev_it2 or rev_it <= const rev_it2
	bool	operator>=(const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> & rev_it)
	{
		return (rev_it + n);															// n + rev_it
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator> & lhs,
		const reverse_iterator<Iterator> & rhs)
	{
		return (rhs.base() - lhs.base());												// rev_it - rev_it2
	};

	// Second version is used to substract an reverse_iterator (T1) to a const reverse_iterator (T2) or the other way around
	template <class Iterator1, typename Iterator2>
	typename reverse_iterator<Iterator1>::difference_type	operator-(const reverse_iterator<Iterator1> & lhs,
		const reverse_iterator<Iterator2> & rhs)
	{
		return (rhs.base() - lhs.base());												// const rev_it - rev_it or rev_it - const rev_it
	};
}

#endif
