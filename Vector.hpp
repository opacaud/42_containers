/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:29 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 14:15:10 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

//////////////////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/vector/vector/?kw=vector					//
// Vectors are sequence containers representing arrays that can change in size.			//
// Just like arrays, vectors use contiguous storage locations for their elements, which means 	//
// that their elements can also be accessed using offsets on regular pointers to its elements,	//
// and just as efficiently as in arrays. But unlike arrays, their size can change dynamically,	//
// with their storage being handled automatically by the container.				//
//////////////////////////////////////////////////////////////////////////////////////////////////

# include <exception>
# include <iostream>
# include <memory>
# include <string>
# include <utility>

# include "enable_if.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

			// MEMBER TYPES
			typedef T						value_type;
			typedef Alloc						allocator_type;
			typedef size_t						size_type;
			typedef ptrdiff_t					difference_type;
			typedef typename allocator_type::reference		reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef random_access_iterator<value_type> 		iterator;
			typedef random_access_iterator<const value_type>	const_iterator;
			typedef reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;

			// MEMBER FUNCTIONS
				// default constructor: Constructs an empty container
			explicit vector(const allocator_type & alloc = allocator_type())
				: m_alloc(alloc), m_start(0), m_size(0), m_end_of_capacity(0)
			{

			};

				// fill constructor: Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type())
			{
				size_type i;

				m_alloc = alloc;
				m_start = m_alloc.allocate(n);
				m_size = n;
				m_end_of_capacity = m_start + n;
				i = 0;
				while (i < n)
				{
					m_alloc.construct(m_start + i, val);
					i++;
				}
			};

				// range constructor: Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				int				i;
				InputIterator 	first_copy;
				InputIterator 	last_copy;

				m_alloc = alloc;
				first_copy = first;
				last_copy = last;
				m_size = 0;
				while (first_copy != last_copy)
				{
					m_size++;
					first_copy++;
				}	
				m_start = m_alloc.allocate(m_size);
				m_end_of_capacity = m_start + m_size;
				i = 0;
				while (first != last)
				{
					m_alloc.construct(m_start + i, *first);
					i++;
					first++;
				}
			};

				// copy constructor
			vector(const vector & x)
			{
				size_type	i;

				if (this != &x)
				{
					m_start = m_alloc.allocate(x.m_size);	
					m_size = x.m_size;
					m_end_of_capacity = m_start + m_size;
					i = 0;
					while (i < m_size)
					{
						m_alloc.construct(m_start + i, x.m_start[i]);
						i++;
					}
				}
			};

			~vector()
			{
				clear();
				m_alloc.deallocate(m_start, capacity());
			};

			vector &	operator=(vector const & x)
			{
				size_type	i;
				size_type	capacity_save;

				if (this != &x)
				{
					capacity_save = capacity();		
					if (m_start)
						m_alloc.deallocate(m_start, capacity());
					if (x.m_size < capacity_save)
					{
						m_start = m_alloc.allocate(capacity_save);
						m_end_of_capacity = m_start + capacity_save;
					}
					else
					{
						m_start = m_alloc.allocate(x.m_size);
						m_end_of_capacity = m_start + x.m_size;
					}
					m_size = x.m_size;
					i = 0;
					while (i < m_size)
					{
						m_alloc.construct(m_start + i, x.m_start[i]);
						i++;
					}
				}
				return (*this);
			};

			// ITERATORS
			iterator	begin()
			{
				return (iterator(m_start));
			};

			const_iterator	begin() const
			{
				return (const_iterator(m_start));
			};

			iterator	end()
			{
				return (iterator(m_start + m_size));
			};

			const_iterator	end() const
			{
				return (const_iterator(m_start + m_size));
			};

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(end()));
			};

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator	rend()
			{
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(begin()));
			};

			// CAPACITY
			size_type	size() const
			{
				return (m_size);
			};

			size_type	max_size() const
			{
				return (m_alloc.max_size());
			};

			void	resize(size_type n, value_type val = value_type())
			{
				if (n == m_size)
					return ;
				else if (n < m_size)
				{
					while (m_size > n)
						pop_back();
				}
				else if (n > m_size)
					insert(end(), n - m_size, val);
			};

			size_type	capacity() const
			{
				return (m_end_of_capacity - m_start);
			};

			bool	empty() const
			{
				if (m_size == 0)
					return (true);
				return (false);
			};

			void	reserve(size_t n)
			{
				pointer		tmp;
				size_type	i;

				if (n > m_alloc.max_size())
					throw std::length_error("vector::reserve");
				if (n > static_cast<size_t>(capacity()))
				{
					tmp = m_alloc.allocate(n);
					i = 0;
					while (i < m_size)
					{
						m_alloc.construct(tmp + i, m_start[i]);
						m_alloc.destroy(m_start + i);
						i++;
					}
					m_alloc.deallocate(m_start, capacity());
					m_start = tmp;
					m_end_of_capacity = m_start + n;
				}
			};

			// ELEMENT ACCESS
			reference	operator[](size_type n)
			{
				return (m_start[n]);
			};

			const_reference	operator[](size_type n) const
			{
				return (m_start[n]);
			};

			reference	at(size_type n)
			{
				if (n >= m_size)
					throw std::out_of_range("vector: Out of range exception");
				return (*(m_start + n));
			};

			const_reference	at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("vector: Out of range exception");
				return (*(m_start + n));
			};

			reference	front()
			{
				return (*m_start);
			};
			
			const_reference	front() const
			{
				return (*m_start);
			};
			
			reference	back()
			{
				return (*(m_start + m_size - 1));
			};
			
			const_reference	back() const
			{
				return (*(m_start + m_size - 1));
			};

			// MODIFIERS
				// range
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				InputIterator	first_copy;
				InputIterator	last_copy;
				size_type	range;
				size_type		i;

				range = 0;
				first_copy = first;
				last_copy = last;
				while (first_copy != last_copy)
				{
					range++;
					first_copy++;
				}
				if (range < m_size)
				{
					while (m_size > range)
						pop_back();
				}
				else if (range > m_size)
					insert(end(), range - m_size, value_type());
				i = 0;
				while (first != last)
				{
					m_alloc.construct(m_start + i, *first);
					i++;
					first++;
				}
			};

				// fill
			void	assign(size_type n, const value_type& val)
			{
				size_type	i;

				resize(n);
				i = 0;
				while (i < n)
				{
					m_start[i] = val;
					i++;
				}
			};

			void	push_back(const value_type& val)
			{
				if (m_size + 1 > capacity())
				{
					insert(end(), 1, val);
					m_start[m_size - 1] = val;
				}
				else
				{
					m_size++;
					m_alloc.construct(&back(), val);
				}
			};

			void	pop_back()
			{
				m_alloc.destroy(&back());
				m_size--;
			};

				// single element
			iterator	insert(iterator position, const value_type & val)
			{
				size_type	index;
				size_type	i;

				index = position - begin();
				if (capacity() == 0)
					m_end_of_capacity = m_start;
				if (size_type(m_end_of_capacity - (m_start + m_size)) >= 1)
				{
					m_size++;
					i = m_size - 1;
					while (i > index)
					{
						m_alloc.construct(m_start + i, *(m_start - 1 + i));
						i--;
					}
					m_alloc.construct(m_start + index, val);
				}
				else
				{
					pointer	new_start = pointer();
					size_t	new_size;
					pointer	new_end_of_capacity = pointer();
					new_size = m_size + 1;
					if (new_size <= m_size * 2)
					{
						new_start = m_alloc.allocate(m_size * 2);
						new_end_of_capacity = new_start + m_size * 2;
					}
					else
					{
						new_start = m_alloc.allocate(new_size);
						new_end_of_capacity = new_start + new_size;
					}
					i = 0;
					while (i < index)
					{
						m_alloc.construct(new_start + i, m_start[i]);
						i++;
					}
					m_alloc.construct(new_start + index, val);
					i++;
					while (i < new_size)
					{
						m_alloc.construct(new_start + i, *(m_start + i - 1));
						i++;
					}
					i = 0;
					while (i < m_size)
					{
						m_alloc.destroy(m_start + i);
						i++;
					}
					if (m_start)
						m_alloc.deallocate(m_start, capacity());
					m_start = new_start;
					m_size = new_size;
					m_end_of_capacity = new_end_of_capacity;
				}
				return (iterator(m_start + index));
			};

				// fill
			void	insert(iterator position, size_type n, const value_type & val)
			{
				size_type	index;
				size_type	i;

				index = position - begin();
				if (n == 0)
					return ;
				if (n > max_size())
					throw std::length_error("vector: new capacity cannot be greater than max_size");
				if (capacity() == 0)
					m_end_of_capacity = m_start;
				if (size_type(m_end_of_capacity - (m_start + m_size)) >= n)
				{
					m_size += n;
					i = m_size - 1;
					size_t j = 0;
					while (j < m_size - n - index)
					{
						m_alloc.construct(m_start + i, *(m_start - n + i));
						i--;
						j++;
					}
					i = 0;
					while (i < n)
					{
						m_alloc.construct(m_start + index + i, val);
						i++;
					}
				}
				else
				{
					pointer	new_start = pointer();
					size_t	new_size;
					pointer	new_end_of_capacity = pointer();
					new_size = m_size + n;
					if (new_size <= m_size * 2)
					{
						new_start = m_alloc.allocate(m_size * 2);
						new_end_of_capacity = new_start + m_size * 2;
					}
					else
					{
						new_start = m_alloc.allocate(new_size);
						new_end_of_capacity = new_start + new_size;
					}
					i = 0;
					while (i < index)
					{
						m_alloc.construct(new_start + i, m_start[i]);		// constructing unchanged start of vector
						i++;
					}
					i = 0;
					while (i < n)
					{
						m_alloc.construct(new_start + index + i, val);		// inserting
						i++;
					}
					i = 0;
					while (i < m_size - index)
					{
						m_alloc.construct(new_start + index + n + i, *(m_start + index + i));	// constructing the end (part after the insertion) of the new vector
						i++;
					}
					i = 0;
					while (i < m_size)
					{
						m_alloc.destroy(m_start + i);
						i++;
					}
					m_alloc.deallocate(m_start, capacity());
					m_start = new_start;
					m_size = new_size;
					m_end_of_capacity = new_end_of_capacity;
				}
			};

				// range
			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				size_type		index;
				InputIterator 	first_copy;
				InputIterator 	last_copy;
				size_type		range;
				size_type		i;

				index = position - begin();
				range = 0;
				first_copy = first;
				last_copy = last;
				while (first_copy != last_copy)
				{
					range++;
					first_copy++;
				}
				if (capacity() == 0)
					m_end_of_capacity = m_start;
				if (size_type(m_end_of_capacity - (m_start + m_size)) >= range)
				{
					m_size += range;
					i = m_size - 1;
					size_t j = 0;
					while (j < m_size - range - index)
					{
						m_alloc.construct(m_start + i, *(m_start - range + i));
						i--;
						j++;
					}
					i = 0;
					while (i < range)
					{
						m_alloc.construct(m_start + index + i, *first);
						first++;
						i++;
					}
				}
				else
				{
					pointer	new_start = pointer();
					size_t	new_size = m_size;
					pointer	new_end_of_capacity = pointer();
					new_size = m_size + range;
					if (new_size <= m_size * 2)
					{
						new_start = m_alloc.allocate(m_size * 2);
						new_end_of_capacity = new_start + m_size * 2;
					}
					else
					{
						new_start = m_alloc.allocate(new_size);
						new_end_of_capacity = new_start + new_size;
					}
					i = 0;
					while (i < index)
					{
						m_alloc.construct(new_start + i, m_start[i]);		// constructing unchanged start of vector
						i++;
					}
					i = 0;
					while (first != last)
					{
						m_alloc.construct(new_start + index + i, *first);	// inserting
						i++;
						first++;
					}
					i = 0;
					while (i < m_size - index)
					{
						m_alloc.construct(new_start + index + range + i, *(m_start + index + i));	// constructing the end (part after the insertion) of the new vector
						i++;
					}
					i = 0;
					while (i < m_size)
					{
						m_alloc.destroy(m_start + i);
						i++;
					}
					m_alloc.deallocate(m_start, capacity());
					m_start = new_start;
					m_size = new_size;
					m_end_of_capacity = new_end_of_capacity;
				}
			};

				//single element
			iterator	erase(iterator position)
			{
				pointer		save;
				size_type	index;

				index = position - begin();
				save = &(*position);
				if (position + 1 == end())
					pop_back();
				else
				{
					m_alloc.destroy(m_start + index);
					while (index < m_size - 1)
					{
						m_alloc.construct(m_start + index, *(m_start + index + 1));
						m_alloc.destroy(m_start + index + 1);
						index++;
					}
					m_size--;
				}
				return (iterator(save));
			};

				// range
			iterator	erase(iterator first, iterator last)
			{
				size_type	i;
				size_type	index_first;
				size_type	index_last;
				size_type	range;

				index_first = first - iterator(m_start);
				index_last = last - iterator(m_start);
				range = last - first;
				i = 0;
				while (i < index_first)
					i++;
				while (i < m_size - range)
				{
					if (i < index_last)
						m_alloc.destroy(m_start + i);
					m_alloc.construct(m_start + i, *(m_start + i + range));
					m_alloc.destroy(m_start + i + range);
					i++;
				}
				m_size -= range;
				return (iterator(first));
			};

			void	swap(vector & x)
			{
				pointer			tmp_start;
				size_t			tmp_size;
				pointer			tmp_end_of_capacity;
				allocator_type	tmp_alloc;

				if (x != *this)
				{
					tmp_start = x.m_start;
					tmp_size = x.m_size;
					tmp_end_of_capacity = x.m_end_of_capacity;
					tmp_alloc = x.m_alloc;

					x.m_start = m_start;
					x.m_size = m_size;
					x.m_end_of_capacity = m_end_of_capacity;
					x.m_alloc = m_alloc;

					m_start = tmp_start;
					m_size = tmp_size;
					m_end_of_capacity = tmp_end_of_capacity;
					m_alloc = tmp_alloc;
				}
			};

			void	clear()
			{
				if (m_start)
				{
					while (m_size > 0)
					{
						m_size--;
						m_alloc.destroy(m_start + m_size);
					}
				}
			};
	
			// ALLOCATOR
			allocator_type	get_allocator() const
			{
				return (m_alloc);
			};

		private :

			Alloc	m_alloc;
			pointer m_start;
			size_t	m_size;
			pointer m_end_of_capacity;
	};

	// NON MEMBER FUNCTIONS
	template <class T, class Alloc>
	void swap(ft::vector<T,Alloc> & x, ft::vector<T,Alloc> & y)
	{
		if (x != y)
			x.swap(y);
	};

	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
				return (false);

		typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();
		while (it_lhs != lhs.end() && it_rhs != rhs.end() &&
				*it_lhs == *it_rhs)
		{
			it_lhs++;
			it_rhs++;
		}
		return (it_lhs == lhs.end() && it_rhs == rhs.end());
	};

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		if (lhs == rhs)
			return (true);
		return (lhs < rhs);
	};

	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		if (lhs == rhs)
			return (false);
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	};

	// template <class T>
	// void	printSize(ft::vector<T> const & vct, bool print_content = true)
	// {
	// 	const typename ft::vector<T>::size_type size = vct.size();
	// 	const typename ft::vector<T>::size_type capacity = vct.capacity();
	// 	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// 	// Cannot limit capacity's max value because it's implementation dependent

	// 	std::cout << "size: " << size << std::endl;
	// 	std::cout << "capacity: " << isCapacityOk << std::endl;
	// 	std::cout << "max_size: " << vct.max_size() << std::endl;
	// 	if (print_content)
	// 	{
	// 		typename ft::vector<T>::const_iterator it = vct.begin();
	// 		typename ft::vector<T>::const_iterator ite = vct.end();
	// 		std::cout << std::endl << "Content is:" << std::endl;
	// 		for (; it != ite; ++it)
	// 			std::cout << "- " << *it << std::endl;
	// 	}
	// 	std::cout << "###############################################" << std::endl;
	// }
}

#endif
