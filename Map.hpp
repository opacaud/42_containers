/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:10 by opacaud           #+#    #+#             */
/*   Updated: 2022/03/23 12:53:24 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

/////////////////////////////////////////////////////////////////////////////////////////////
// https://en.cppreference.com/w/cpp/container/map									 	   //
// Map is a sorted associative container that contains key-value pairs with unique keys.   //
// Keys are sorted by using the comparison function Compare.							   //
/////////////////////////////////////////////////////////////////////////////////////////////

# include <iostream>

# include "enable_if.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "map_iterator.hpp"
# include "Pair.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	// https://www.cplusplus.com/reference/functional/less/
	// Default Compare in template of map
	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T & x, const T & y) const
		{
			return (x < y);
		};
	};

	/////////////////////////////////////////////////////////

	// Nodes that compose the tree
	template <class T>
	struct Tnode
	{
		T		m_value;
		Tnode	*m_left_node;
		Tnode	*m_right_node;
		Tnode	*m_parent_node;
		int		m_balance;
		int		m_height;
		bool	m_end;
		
		Tnode(T value, Tnode *left_node, Tnode *right_node, Tnode* parent_node, int balance, int height, bool end)
			: m_value(value), m_left_node(left_node), m_right_node(right_node), m_parent_node(parent_node), m_balance(balance), m_height(height), m_end(end)
		{

		};

		~Tnode()
		{

		};
	};

	/////////////////////////////////////////////////////////

	template < 	class Key,
				class T,
				class Compare = ft::less<Key>,
				class Alloc = std::allocator< ft::pair<const Key,T> > >
	class map
	{
		public:

			// MEMBER TYPES
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef pair<const Key, T>											value_type;
			typedef Compare														key_compare;
			typedef Tnode<value_type>											node_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::difference_type					difference_type;
			typedef typename allocator_type::size_type							size_type;
			typedef map_iterator<value_type, node_type*>                  		iterator;
			typedef map_iterator<const value_type, node_type*>            		const_iterator;
			typedef ft::reverse_iterator<iterator>                        		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                  		const_reverse_iterator;

		protected :

			node_allocator	m_alloc;
			key_compare		m_compare;
			size_type		m_size;
			node_type		*m_root;
		
		public :

			// MEMBER CLASS
			// https://www.cplusplus.com/reference/map/map/value_comp/
			class value_compare
			{ 
				friend class map;
				
				protected:
				
					Compare comp;
					value_compare(Compare c)
						: comp(c)	  			// constructed with map's comparison object
					{

					};
				
				public:

			  		typedef bool		result_type;
			  		typedef value_type	first_argument_type;
			  		typedef value_type	second_argument_type;
			  		
					bool operator()(const value_type & x, const value_type & y) const
			  		{
			  			return (comp(x.first, y.first));
			  		};
			};

			// MEMBER FUNCTIONS
				// empty = default
			explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
				: m_alloc(alloc), m_compare(comp), m_size(0), m_root(NULL)
			{
				initialize();
			};

				// range
			template <class InputIterator>
			map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
				: m_alloc(alloc), m_compare(comp), m_size(0), m_root(NULL)
			{
				insert(first, last);
			};

				// copy constructor
			map(const map & x)
				: m_alloc(x.m_alloc), m_compare(x.m_compare), m_size(0), m_root(NULL)
			{
				*this = x;
			};

			~map()
			{
				destroy_all_nodes_from(m_root);
			};

			map & operator=(const map & x)
			{
				if (this != &x)
				{
					destroy_all_nodes_from(m_root);
					insert(x.begin(), x.end());
				}
				return (*this);
			};

				// iterators
			iterator	begin()
			{
				node_type	*node;

				node = m_root;
				while (node && node->m_left_node)
					node = node->m_left_node;
				return (iterator(node));
			};

			const_iterator	begin() const
			{
				node_type	*node;

				node = m_root;
				while (node && node->m_left_node)
					node = node->m_left_node;
				return (const_iterator(node));
			};

			iterator	end()
			{
				node_type	*node;

				node = m_root;
				while (node && node->m_end == false)
					node = node->m_right_node;
				return (iterator(node));
			};

			const_iterator	end() const
			{
				node_type	*node;

				node = m_root;
				while (node && node->m_end == false)
					node = node->m_right_node;
				return (const_iterator(node));
			};

			reverse_iterator	rbegin()
			{
				return (reverse_iterator(end()--));
			};

			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(end()--));
			};

			reverse_iterator	rend()
			{
				return (reverse_iterator(begin()));
			};

			const_reverse_iterator	rend() const
			{
				return (const_reverse_iterator(begin()));
			};

				// capacity
			bool	empty() const
			{
				if (m_size == 0)
					return (true);
				return (false);
			};

			size_type	size() const
			{
				return (m_size);
			};
			
			size_type	max_size() const
			{
				return (m_alloc.max_size());
			};

				// element access
			mapped_type &	at(const key_type & k)
			{
				node_type *curr;

				curr = get_node_from_a_key(k, m_root);
				if (curr)
					return curr->m_value.second;
				insert(value_type(k, mapped_type()));
				return (get_node_from_a_key(k, m_root)->m_value.second);
			};

			const mapped_type &	at(const key_type & k) const
			{
				node_type *curr;

				curr = get_const_node_from_a_key(k, m_root);
				if (curr)
					return (curr->m_value.second);
				insert(value_type(k, mapped_type()));
				return (get_const_node_from_a_key(k, m_root)->m_value.second);
			};

			mapped_type &	operator[](const key_type & k)
			{
				node_type *curr;

				curr = get_node_from_a_key(k, m_root);
				if (curr)
					return (curr->m_value.second);
				insert(value_type(k, mapped_type()));
				return (get_node_from_a_key(k, m_root)->m_value.second);
			};

				// modifiers
			pair<iterator, bool>	insert(const value_type & val)			// single element
			{
				size_t		initial_size;
				bool		inserted;

				initial_size = size();
				inserted = false;
				m_root = create_root_or_insert_node(val, m_root, NULL);
				if (size() != initial_size)
					inserted = true;
				return (pair<iterator, bool>(get_node_from_a_key(val.first, m_root), inserted));
			};

			iterator	insert(iterator position, const value_type & val) 	// with hint (useless)
			{
				(void)position;
				insert(val);
				return (get_node_from_a_key(val.first, m_root));
			};

			template <class InputIterator> 									// range
			void	insert(InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			};
			
			void	erase(iterator position)
			{
				erase(position->first);
			};

			size_type	erase(const key_type & k)
			{
				size_t	initial_size;

				initial_size = size();
				m_root = search_and_delete_node_from_key(m_root, k);
				if (initial_size != size())
					return (1);
				return (0);
			};

			void	erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first++);
				}
			};

			void	swap(map & x)
			{
				node_type		*tmp_root = m_root;
				size_type		tmp_size = m_size;
				node_allocator	tmp_alloc = m_alloc;
				key_compare		tmp_cmp = m_compare;

				m_root = x.m_root;
				m_size = x.m_size;
				m_alloc = x.m_alloc;
				m_compare = x.m_compare;

				x.m_root = tmp_root;
				x.m_size = tmp_size;
				x.m_alloc = tmp_alloc;
				x.m_compare = tmp_cmp;
			};

			void	clear()
			{
				destroy_all_nodes_from(m_root);
			};

				// observers
			key_compare	key_comp() const
			{
				return (m_compare);
			};
			
			value_compare	value_comp() const			
			{											// Returns an object of class value_compare,
				return (value_compare(key_compare()));	// constructed from the Compare parameter used
			};											// to build the map (less by default)

				// operations
			iterator	find(const key_type & k)
			{
				iterator	it;

				it = begin();
				while (it != end() && (*it).first != k)
					it++;
				return (it);
			};
			
			const_iterator	find(const key_type & k) const
			{
				const_iterator	it;

				it = begin();
				while (it != end() && (*it).first != k)
					it++;
				return (it);
			};
			
			size_type	count(const key_type & k) const
			{
				if (get_const_node_from_a_key(k, m_root))
					return (1);
				return (0);
			};
			
			iterator	lower_bound(const key_type & k)
			{
				iterator it;
				key_compare mycomp;
				
				it = begin();
				mycomp = key_comp();
				while (it != end() && mycomp((*it).first, k))
					it++;
				return (it);
			};
			
			const_iterator	lower_bound(const key_type & k) const
			{
				const_iterator it;
				key_compare mycomp;
				
				it = begin();
				mycomp = key_comp();
				while (it != end() && mycomp((*it).first, k))
					it++;
				return (it);
			};
			
			iterator	upper_bound(const key_type & k)
			{
				iterator it;
				key_compare mycomp;
				
				it = begin();
				mycomp = key_comp();
				while (it != end() && mycomp((*it).first, k))
					it++;
				if (it != end() && (*it).first == k)
					it++;
				return (it);
			};
			
			const_iterator	upper_bound(const key_type & k) const
			{
				const_iterator it;
				key_compare mycomp;
				
				it = begin();
				mycomp = key_comp();
				while (it != end() && mycomp((*it).first, k))
					it++;
				if (it != end() && (*it).first == k)
					it++;
				return (it);
			};
			
			pair<const_iterator, const_iterator>	equal_range(const key_type & k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};
			
			pair<iterator, iterator>	equal_range(const key_type & k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			};

				// allocator
			allocator_type	get_allocator() const
			{
				return (m_alloc);
			};

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

			// node_type	*get_root()
			// {
			// 	return (m_root);
			// }

			// void print_tree_graphic(node_type *curr, int space)
			// {
			//     if (!curr)
			//         return;
			//     space += 1;
			//     print_tree_graphic(curr->m_right_node, space);
			//     for (int i = 1; i < space; i++)
			//         std::cout << "\t";
			//     std::cout << curr->m_value.first << std::endl;
			//     // std::cout << curr->m_value.first << " - " << curr->m_height << std::endl;
			//     // std::cout << curr->m_value.first;
			// 	// std::cout << " (";
			// 	// if (curr->m_parent_node)
			// 	// 	std::cout << " p: " << curr->m_parent_node->m_value.first << " - ";
			// 	// if (curr->m_left_node)
			// 	// 	std::cout << " lc: " << curr->m_left_node->m_value.first << " - ";
			// 	// if (curr->m_right_node)
			// 	// 	std::cout << " rc: " << curr->m_right_node->m_value.first;
			// 	// std::cout << " )" << std::endl;
			//     print_tree_graphic(curr->m_left_node, space);
			// }

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

		private :

			node_type	*new_node(const value_type & val, node_type *parent)
			{
				node_type *tmp = m_alloc.allocate(1);
				m_alloc.construct(tmp, node_type(val, NULL, NULL, parent, 0, 0, false));
				m_size++;
				return (tmp);
			};

			node_type	*min_from_node(node_type *node)
			{
				node_type *curr = node;
				while (curr->m_left_node != NULL)
					curr = curr->m_left_node;
				return (curr);
			};

			node_type	*max_from_node(node_type *node)
			{
				node_type *curr = node;
				while (curr->m_right_node != NULL)
					curr = curr->m_right_node;
				return (curr);
			};

			node_type	*create_root_or_insert_node(const value_type & val, node_type *curr, node_type *parent)
			{
				if (!m_root)
				{
					node_type *last_node;
					m_root = new_node(val, NULL);
					last_node = new_node(value_type(key_type(), mapped_type()), m_root);
					m_size--;
					m_root->m_right_node = last_node;
					last_node->m_end = true;
					m_root->m_height = 0;
					return (m_root);
				}
				if (m_root->m_end)
				{
					node_type *new_root;
					new_root = new_node(val, NULL);
					m_root->m_parent_node = new_root;
					new_root->m_right_node = m_root;
					new_root->m_height = 0;
					m_root = new_root;
					return (m_root);
				}
				return (insert_node(val, curr, parent));
			};

			int max(int a, int b)
			{
			    if (a > b)
			        return (a);
			    return (b);
			}

			int get_height(node_type *node)
			{
			    if (!node)
			        return (0);
			    return (node->m_height);
			}

			int get_balance(node_type *node)
			{
			    if (!node)
			        return (0);
			    return (get_height(node->m_left_node) - get_height(node->m_right_node));
			}
	
			node_type   *rotate_right(node_type *parent)
			{
			    node_type   *left_child = parent->m_left_node;
			    node_type   *right_g_child = left_child->m_right_node;

			    left_child->m_right_node = parent;
				left_child->m_parent_node = parent->m_parent_node;
			    parent->m_left_node = right_g_child;
				if (left_child->m_end == false)
					parent->m_parent_node = left_child;
				if (right_g_child)
					right_g_child->m_parent_node = parent;

			    parent->m_height = max(get_height(parent->m_left_node), get_height(parent->m_right_node)) + 1;
			    left_child->m_height = max(get_height(left_child->m_left_node), get_height(left_child->m_right_node)) + 1;

			    return (left_child);
			}

			node_type   *rotate_left(node_type *parent)
			{
			    node_type   *right_child = parent->m_right_node;
			    node_type   *left_g_child = right_child->m_left_node;

			    right_child->m_left_node = parent;
				right_child->m_parent_node = parent->m_parent_node;
			    parent->m_right_node = left_g_child;
				if (right_child->m_end == false)
					parent->m_parent_node = right_child;
				if (left_g_child)
					left_g_child->m_parent_node = parent;

			    parent->m_height = max(get_height(parent->m_left_node), get_height(parent->m_right_node)) + 1;
			    right_child->m_height = max(get_height(right_child->m_left_node), get_height(right_child->m_right_node)) + 1;

			    return (right_child);
			}

			node_type	*insert_node(const value_type & val, node_type *curr, node_type *parent)
			{
				if (!curr)
					return (new_node(val, parent));
				if (curr->m_end == true)
				{
					node_type *to_insert;
					to_insert = new_node(val, parent);
					to_insert->m_height = 1;
					curr->m_parent_node = to_insert;
					to_insert->m_right_node = curr;
					return (to_insert);
				}
				if (m_compare(val.first, curr->m_value.first))
					curr->m_left_node = insert_node(val, curr->m_left_node, curr);
				else if (m_compare(curr->m_value.first, val.first))
					curr->m_right_node = insert_node(val, curr->m_right_node, curr);
				else
					return (curr);
				curr->m_height = 1 + max(get_height(curr->m_left_node), get_height(curr->m_right_node));
				key_type left_key;
				if (curr->m_left_node)
					left_key = curr->m_left_node->m_value.first;
				else
					left_key = key_type();
				int balance = get_balance(curr);
    			if (balance > 1 && get_balance(curr->m_left_node) >= 0)
    			    return (rotate_right(curr));
    			if (balance > 1 && get_balance(curr->m_left_node) < 0)
    			{
    			    curr->m_left_node = rotate_left(curr->m_left_node);
    			    return (rotate_right(curr));
    			}
    			if (balance < -1 && get_balance(curr->m_right_node) <= 0)
    			    return (rotate_left(curr));
    			if (balance < -1 && get_balance(curr->m_right_node) > 0)
    			{
    			    curr->m_right_node = rotate_right(curr->m_right_node);
    			    return (rotate_left(curr));
    			}
				return (curr);
			};

			node_type	*search_and_delete_node_from_key(node_type *curr, const key_type & key)
			{
				if (!curr || curr->m_end == true)
					return (curr);
				if (m_compare(key, curr->m_value.first))
					curr->m_left_node = search_and_delete_node_from_key(curr->m_left_node, key);
				else if (m_compare(curr->m_value.first, key))
					curr->m_right_node = search_and_delete_node_from_key(curr->m_right_node, key);
				else		// end of recursion when key k is found in curr
				{
					if (!curr->m_left_node || !curr->m_right_node)		// if curr has 0 or 1 child
					{
						node_type *tmp;
						if (curr->m_left_node)
							tmp = curr->m_left_node;
						else
							tmp = curr->m_right_node;
						if (!curr->m_left_node && !curr->m_right_node)
						{
							tmp = curr;
							m_alloc.destroy(tmp);
							m_alloc.deallocate(tmp, 1);
							curr = NULL;
							m_size--;
						}
						else
						{
							node_type *tmp2;
							tmp->m_parent_node = curr->m_parent_node;
							tmp2 = curr;
							curr = tmp;
							m_alloc.destroy(tmp2);
							m_alloc.deallocate(tmp2, 1);
							m_size--;
						}
					}
					else												// if curr has 2 children
					{
						node_type *tmp;
						if (curr->m_right_node->m_end == false)
							tmp = min_from_node(curr->m_right_node); // getting (in tmp) the node just after curr (41) : 42 here
						else
							tmp = curr->m_left_node;
						/*
						  parent(39)
						     \
							 curr(41)(to delete)
							 /	\
						    40	 43
								/
							  tmp(42)
						*/
						if (tmp != curr->m_right_node)
						{
							tmp->m_right_node = curr->m_right_node;		// reversing parent and child to respect order
							curr->m_right_node->m_parent_node = tmp;
						}
						/*
						  parent(39)		   parent(39)
						     \					  \
							 curr(41)			 curr(41)
							 /	\				 /	\
						    40	 43     -->	    40	tmp(42)
								/					  \
							  tmp(42)				   43
						*/
						tmp->m_left_node = curr->m_left_node;
						curr->m_left_node->m_parent_node = tmp;
						tmp->m_parent_node->m_left_node = NULL;			// not forgetting second child of curr
						/*
						  parent(39)		   			parent(39)
						     \					  			\
							curr(41)(to delete)		   	   curr(41)(to delete)
							/	\					   	   /  \
						   40    tmp(42)   		-->	   	NULL  tmp(42)
								  \							  / \
							       43			   			40  43
						*/
						tmp->m_parent_node = curr->m_parent_node;		// bypassing the node to delete
						/*
						  parent(39)		  			parent(39)
						     \					 			\		curr(41)(to delete)
							 curr(41)(to delete)		 	tmp(42)
								\				 			 / \
						    	tmp(42)     	-->	  	   40   43
								/  \
							   40  43
						*/
						if (m_root == curr)
							m_root = tmp;
						m_alloc.destroy(curr);
						m_alloc.deallocate(curr, 1);
						m_size--;
						curr = tmp;										// make curr point at the node that is now where was the deleted one
						/*
							 parent(39)
								\
							    curr(42)
								/ \
						       40  43
						*/
					}
				}
				if (!curr)
    			    return (curr);
    			curr->m_height = 1 + max(get_height(curr->m_left_node), get_height(curr->m_right_node));
				int balance = get_balance(curr);
    			if (balance > 1 && get_balance(curr->m_left_node) >= 0)
    			    return (rotate_right(curr));
    			if (balance > 1 && get_balance(curr->m_left_node) < 0)
    			{
    			    curr->m_left_node = rotate_left(curr->m_left_node);
    			    return (rotate_right(curr));
    			}
    			if (balance < -1 && get_balance(curr->m_right_node) <= 0)
    			    return (rotate_left(curr));
    			if (balance < -1 && get_balance(curr->m_right_node) > 0)
    			{
    			    curr->m_right_node = rotate_right(curr->m_right_node);
    			    return (rotate_left(curr));
    			}
    			return (curr);
			};

			void	destroy_all_nodes_from(node_type *curr)
			{
				if (!curr)
					return ;
				destroy_all_nodes_from(curr->m_left_node);
				destroy_all_nodes_from(curr->m_right_node);
				m_alloc.destroy(curr);
				m_alloc.deallocate(curr, 1);
				if (m_size > 0)
					m_size--;
				if (curr == m_root)
					m_root = 0;
			};

			node_type	*get_node_from_a_key(const key_type & key, node_type *curr)
			{
				if (!curr || curr->m_end)
					return (NULL);
				if (m_compare(key, curr->m_value.first))
					return (get_node_from_a_key(key, curr->m_left_node));
				else if (m_compare(curr->m_value.first, key))
					return (get_node_from_a_key(key, curr->m_right_node));
				else
					return (curr);
			};

			node_type	*get_const_node_from_a_key(const key_type & key, node_type *curr) const
			{
				if (!curr || curr->m_end)
					return (NULL);
				if (m_compare(key, curr->m_value.first))
					return (get_const_node_from_a_key(key, curr->m_left_node));
				else if (m_compare(curr->m_value.first, key))
					return (get_const_node_from_a_key(key, curr->m_right_node));
				else
					return (curr);
			};

			void	initialize()
			{
				insert(value_type(key_type(), mapped_type()));
				m_root->m_end = true;
				if (m_size > 0)
					m_size--;
			};

	};

	// NON MEMBER FUNCTIONS
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		return (!(lhs == rhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		return (lhs < rhs || lhs == rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		return (rhs < lhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const ft::map<Key,T,Compare,Alloc> & lhs, const ft::map<Key,T,Compare,Alloc> & rhs)
	{
		return (lhs > rhs || lhs == rhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	void	swap(ft::map<Key,T,Compare,Alloc> & x, ft::map<Key,T,Compare,Alloc> & y)
	{
		x.swap(y);
	};
}

#endif
