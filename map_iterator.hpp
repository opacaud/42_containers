/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:06 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 14:12:54 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

/////////////////////////////////////////////////
// Custom iterator for iterate through a map.  //
/////////////////////////////////////////////////

# include "Map.hpp"

namespace ft
{
    template <class T, class ptr_on_node>
    class map_iterator
    {
        public :
        
	        typedef ptrdiff_t			difference_type;
            	typedef T				value_type;
	        typedef value_type *			pointer;
	        typedef value_type &			reference;
	        typedef ft::bidirectional_iterator_tag	iterator_category;
        
        protected :

            ptr_on_node m_ptr;
        
        public :
        
            map_iterator()
                : m_ptr(NULL)
            {

            };

            map_iterator(ptr_on_node ptr)
                : m_ptr(ptr)
            {

            };

            map_iterator(map_iterator const & rhs)
                : m_ptr(rhs.m_ptr)
            {

            };

            map_iterator &  operator=(map_iterator const & rhs)
            {
                if (this != &rhs)
                    m_ptr = rhs.m_ptr;
                return (*this);
            };

			~map_iterator()
            {

            };

			map_iterator &  operator++(void)
			{
				if (m_ptr && m_ptr->m_right_node)
				{
					m_ptr = m_ptr->m_right_node;
					while (m_ptr && m_ptr->m_left_node)
						m_ptr = m_ptr->m_left_node;
				}
				else
				{
					ptr_on_node tmp = m_ptr;
					m_ptr = m_ptr->m_parent_node;
                    		/* Loop
				        parent 4                              parent 4        		 			 parent 4                      		m_ptr (parent 4)
				         /      	                      /             		 			   /                       	         /
                        		A 1                                  A 1             		 	    		m_ptr (pointe sur A 1)                 tmp (pointe sur A 1)
				       /  \                                 /  \             		             		/   \			              /   \
				     B 0   C 2                        	  B 0   m_ptr (pointe sur C 2)             	      B 0    tmp (pointe sur C 2)	    B 0   C 2
                     		     /      \                             /      \                             		      /	      \			            /       \
                    		   D -1     m_ptr (pointe sur E 3)   	 D -1    tmp (pointe sur E 3)         		    D -1        E 3		          D -1       E 3
				*/
					while (m_ptr && m_ptr->m_left_node != tmp)
					{
						tmp = m_ptr;
						m_ptr = m_ptr->m_parent_node;
					}
				}
				return (*this);
			};

            map_iterator    operator++(int)
            {
                map_iterator it = *this;
                ++(*this);
                return (it);
            };

			map_iterator &  operator--(void)
			{
				if (m_ptr->m_left_node)
                {
                    m_ptr = m_ptr->m_left_node;
                    while (m_ptr->m_right_node)
                        m_ptr = m_ptr->m_right_node;
                }
                else
                {
                    ptr_on_node tmp = m_ptr;
                    m_ptr = m_ptr->m_parent_node;
                    while (m_ptr && m_ptr->m_right_node != tmp)
                    {
                        tmp = m_ptr;
                        m_ptr = m_ptr->m_parent_node;
                    }
                }
				return (*this);
			};

            map_iterator    operator--(int)
            {
                map_iterator it = *this;
                --(*this);
                return (it);
            };

			reference	operator*() const
			{
				return (m_ptr->m_value);
			};

            pointer operator->() const
            {
                return (&(operator*()));
            };

            ptr_on_node get_ptr()
            {
                return (m_ptr);
            };

            ptr_on_node get_ptr() const
            {
                return (m_ptr);
            };

			operator map_iterator<const T, ptr_on_node>() const
			{
				return (map_iterator<const T, ptr_on_node>(m_ptr));
			};

            template <class ite>
            bool    operator==(const map_iterator<ite, ptr_on_node> & b) const
            {
                return (get_ptr() == b.get_ptr());
            };

            template <class ite>
            bool    operator!=(const map_iterator<ite, ptr_on_node> & b) const
            {
                return (get_ptr() != b.get_ptr());
            };
	};
}

#endif
