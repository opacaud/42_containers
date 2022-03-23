/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_real.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:44:51 by opacaud           #+#    #+#             */
/*   Updated: 2022/03/23 13:19:52 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET  		"\033[0m"
# define BLACK  		"\033[30m"			/* Black */
# define RED    		"\033[31m"			/* Red */
# define GREEN  		"\033[32m"			/* Green */
# define YELLOW 		"\033[33m"			/* Yellow */
# define BLUE   		"\033[34m"			/* Blue */
# define MAGENTA		"\033[35m"			/* Magenta */
# define CYAN   		"\033[36m"			/* Cyan */
# define WHITE  		"\033[37m"			/* White */
# define BOLDBLACK  	"\033[1m\033[30m"	/* Bold Black */
# define BOLDRED    	"\033[1m\033[31m"	/* Bold Red */
# define BOLDGREEN  	"\033[1m\033[32m"	/* Bold Green */
# define BOLDYELLOW 	"\033[1m\033[33m"	/* Bold Yellow */
# define BOLDBLUE   	"\033[1m\033[34m"	/* Bold Blue */
# define BOLDMAGENTA	"\033[1m\033[35m"	/* Bold Magenta */
# define BOLDCYAN   	"\033[1m\033[36m"	/* Bold Cyan */
# define BOLDWHITE  	"\033[1m\033[37m"	/* Bold White */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////// LARGE AND THOROUGH TESTS //////////

# include <iostream>
# include <string>
# include <list>
# include <map>
# include <stack>
# include <vector>

void print_stack_int_real(std::stack<int> stack)
{
	if (stack.empty())
		return ;

	int x = stack.top();
 
	stack.pop();
 
	print_stack_int_real(stack);
 
	std::cout << x << std::endl;
 
	stack.push(x);
}

void print_stack_list_real(std::stack< int, std::list<int> > stack)
{	
	if (stack.empty())
		return ;

	int x = stack.top();
 
	stack.pop();
 
	print_stack_list_real(stack);
 
	std::cout << x << std::endl;
 
	stack.push(x);
}

void	print_vector_int_real(std::vector<int> vec)
{
    std::vector<int>::iterator begin;
    std::vector<int>::iterator end;

    begin = vec.begin();
    end = vec.end();

    std::cout << "size(): " << vec.size() << std::endl << std::endl;
    while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

void	print_vector_str_real(std::vector<std::string> vec)
{
    std::vector<std::string>::iterator begin;
    std::vector<std::string>::iterator end;

    begin = vec.begin();
    end = vec.end();

    std::cout << "size(): " << vec.size() << std::endl << std::endl;
    while (begin != end)
	{
		std::cout << *begin << std::endl;
		begin++;
	}
}

void	print_map_int_str_real(std::map<int, std::string> map)
{
    std::map<int, std::string>::iterator begin;
    std::map<int, std::string>::iterator end;

    begin = map.begin();
    end = map.end();

    std::cout << std::endl << "size(): " << map.size() << std::endl << std::endl;
	if (map.size() == 0)
		return ;
    while (begin != end)
	{
		std::cout << "Key: " << begin->first << " - Value: " << begin->second << std::endl;
		begin++;
	}
	std::cout << std::endl;
}

int main()
{

    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "----------------------- TESTS FOR VECTOR ------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET << std::endl << std::endl;

    std::cout << BOLDBLUE    << std::endl << "----------- TESTS FOR  INT VECTORS -----------" << RESET << std::endl << std::endl;

	{

	    std::cout << BOLDGREEN   << std::endl << "---------- vec1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "default constructor - Vector.hpp - line 62" << RESET << std::endl;
		std::cout << "std::vector<int> vec1;" << RESET << std::endl << std::endl;
		std::vector<int> vec1;
		std::cout << "capacity(): " << vec1.capacity() << std::endl;
		print_vector_int_real(vec1);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "fill constructor - Vector.hpp - line 69" << RESET << std::endl;
		std::cout << "std::vector<int> vec2(100, 42);" << RESET << std::endl << std::endl;
		std::vector<int> vec2(100, 42);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;
		// print_vector_int_real(vec2);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "range constructor - Vector.hpp - line 86" << RESET << std::endl;
		std::cout << "std::vector<int> vec3(vec2.begin(), vec2.end() - 92);" << RESET << std::endl << std::endl;
		std::vector<int> vec3(vec2.begin(), vec2.end() - 92);
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec2.pop_back();" << RESET << std::endl << std::endl;
		vec2.pop_back();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec3.pop_back();" << RESET << std::endl << std::endl;
		vec3.pop_back();
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		std::cout << "size(): " << vec3.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec4 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "copy constructor - Vector.hpp - line 114" << RESET << std::endl;
		std::cout << "std::vector<int> vec4(vec2);" << RESET << std::endl << std::endl;
		std::vector<int> vec4(vec2);
		std::cout << "vec2.capacity(): " << vec2.capacity() << std::endl;
		std::cout << "vec2.size(): " << vec2.size() << std::endl;
		std::cout << "vec4.capacity(): " << vec4.capacity() << std::endl;
		std::cout << "vec4.size(): " << vec4.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Vector.hpp - line 138" << RESET << std::endl;
		std::cout << "std::vector<int> vec5 = vec3;" << RESET << std::endl << std::endl;
		std::vector<int> vec5 = vec3;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		std::cout << "vec3.size(): " << vec3.size() << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		std::cout << "vec5.size(): " << vec5.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec2.pop_back();" << RESET << std::endl << std::endl;
		vec2.pop_back();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() // single element - Vector.hpp - line 587" << RESET << std::endl;
		std::cout << "vec2.erase(vec2.begin());" << RESET << std::endl << std::endl;
		vec2.erase(vec2.begin());
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() // range - Vector.hpp - line 611" << RESET << std::endl;
		std::cout << "vec2.erase(vec2.begin(), vec2.begin() + 3);" << RESET << std::endl << std::endl;
		vec2.erase(vec2.begin(), vec2.begin() + 3);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "resize() - Vector.hpp - line 210" << RESET << std::endl;
		std::cout << "vec2.resize(60);" << RESET << std::endl << std::endl;
		vec2.resize(60);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "reserve() - Vector.hpp - line 235" << RESET << std::endl;
		std::cout << "vec2.reserve(50);" << RESET << std::endl << std::endl;
		vec2.reserve(50);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign() // range - Vector.hpp - line 305" << RESET << std::endl;
		std::cout << "vec2.assign(vec3.begin(), vec3.end());" << RESET << std::endl << std::endl;
		vec2.assign(vec3.begin(), vec3.end());
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign() // fill - Vector.hpp - line 332" << RESET << std::endl;
		std::cout << "vec2.assign(3, 84);" << RESET << std::endl << std::endl;
		vec2.assign(3, 84);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "clear() - Vector.hpp - line 661" << RESET << std::endl;
		std::cout << "vec2.clear();" << RESET << std::endl << std::endl;
		vec2.clear();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec6 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "fill constructor - Vector.hpp - line 69" << RESET << std::endl;
		std::cout << "std::vector<int> vec6(1000000);" << RESET << std::endl << std::endl;
		std::vector<int> vec6(1000000);
		std::cout << "capacity(): " << vec6.capacity() << std::endl;
		std::cout << "size(): " << vec6.size() << std::endl;
		// print_vector_int_real(vec6);
		
		std::cout << BOLDGREEN   << std::endl << "---------- vec6 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign // fill - Vector.hpp - line 332" << RESET << std::endl;
		std::cout << "vec6.assign(1, 42);" << RESET << std::endl << std::endl;
		vec6.assign(1, 42);
		std::cout << "capacity(): " << vec6.capacity() << std::endl;
		print_vector_int_real(vec6);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Vector.hpp - line 228" << RESET << std::endl;
		std::cout << "vec2.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << vec2.empty() << std::endl;
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		print_vector_int_real(vec2);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Vector.hpp - line 228" << RESET << std::endl;
		std::cout << "vec3.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << vec3.empty() << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push_back() - Vector.hpp - line 345" << RESET << std::endl;
		std::cout << "vec5.push_back(21);" << RESET << std::endl << std::endl;
		vec5.push_back(21);
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // single element - Vector.hpp - line 361" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), 84);" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), 84);
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // fill - Vector.hpp - line 425" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), 2, 168);" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), 2, 168);
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // range - Vector.hpp - line 501" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), vec3.end() - 3, vec3.end());" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), vec3.end() - 3, vec3.end());
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // fill - Vector.hpp - line 425" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.end(), 15, 168);" << RESET << std::endl << std::endl;
		vec5.insert(vec5.end(), 15, 168);
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "------ vec3 && vec5 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "swap() - Vector.hpp - line 635" << RESET << std::endl;
		std::cout << "vec5.swap(vec3);" << RESET << std::endl << std::endl;
		std::cout << std::endl << BOLDBLUE << "VEC3 BEFORE: " << RESET << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC5 BEFORE: " << RESET << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);
		vec5.swap(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC3 AFTER: " << RESET << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC5 AFTER: " << RESET << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "resize() - Vector.hpp - line 210" << RESET << std::endl;
		std::cout << "vec3.resize(6);" << RESET << std::endl << std::endl;
		vec3.resize(6);
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator[] - Vector.hpp - line 259" << RESET << std::endl;
		std::cout << "vec3[3]" << RESET << std::endl << std::endl;
		std::cout << "vec3[3]: " << vec3[3] << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "at() - Vector.hpp - line 269" << RESET << std::endl;
		std::cout << "vec3.at(5)" << RESET << std::endl << std::endl;
		std::cout << "vec3.at(5): " << vec3.at(5) << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "front() - Vector.hpp - line 283" << RESET << std::endl;
		std::cout << "vec3.front()" << RESET << std::endl << std::endl;
		std::cout << "vec3.front(): " << vec3.front() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "back() - Vector.hpp - line 293" << RESET << std::endl;
		std::cout << "vec3.back()" << RESET << std::endl << std::endl;
		std::cout << "vec3.back(): " << vec3.back() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "rbegin() - Vector.hpp - line 179" << RESET << std::endl;
		std::cout << "*vec3.rbegin()" << RESET << std::endl << std::endl;
		std::cout << "*vec3.rbegin(): " << *vec3.rbegin() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "rend() - Vector.hpp - line 189" << RESET << std::endl;
		std::cout << "*(vec3.rend() - 1)" << RESET << std::endl << std::endl;
		std::cout << "*(vec3.rend() - 1): " << *(vec3.rend() - 1) << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "max_size() - Vector.hpp - line 205" << RESET << std::endl;
		std::cout << "vec3.max_size()" << RESET << std::endl << std::endl;
		std::cout << "vec3.max_size(): " << vec3.max_size() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Vector.hpp - line 696" << RESET << std::endl;
		std::cout << "(vec3 == vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 == vec5): " << (vec3 == vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Vector.hpp - line 733" << RESET << std::endl;
		std::cout << "(vec3 > vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 > vec5): " << (vec3 > vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Vector.hpp - line 138" << RESET << std::endl;
		std::cout << "vec5 = vec3;" << RESET << std::endl << std::endl;
		vec5 = vec3;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Vector.hpp - line 696" << RESET << std::endl;
		std::cout << "(vec3 == vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 == vec5): " << (vec3 == vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator<= - Vector.hpp - line 725" << RESET << std::endl;
		std::cout << "(vec3 <= vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 <= vec5): " << (vec3 <= vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_int_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_int_real(vec5);
	
	}

    std::cout << BOLDBLUE    << std::endl << std::endl << "---------- TESTS FOR STRING VECTORS ----------" << RESET << std::endl << std::endl;

	{

    	std::cout << BOLDGREEN   << std::endl << "---------- vec1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "default constructor - Vector.hpp - line 62" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec1;" << RESET << std::endl << std::endl;
		std::vector<std::string> vec1;
		std::cout << "capacity(): " << vec1.capacity() << std::endl;
		print_vector_str_real(vec1);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "fill constructor - Vector.hpp - line 69" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec2(100, \"Forty-two!\");" << RESET << std::endl << std::endl;
		std::vector<std::string> vec2(100, "Forty-two!");
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;
		// print_vector_str_real(vec2);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "range constructor - Vector.hpp - line 86" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec3(vec2.begin(), vec2.end() - 92);" << RESET << std::endl << std::endl;
		std::vector<std::string> vec3(vec2.begin(), vec2.end() - 92);
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec2.pop_back();" << RESET << std::endl << std::endl;
		vec2.pop_back();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec3.pop_back();" << RESET << std::endl << std::endl;
		vec3.pop_back();
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		std::cout << "size(): " << vec3.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec4 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "copy constructor - Vector.hpp - line 114" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec4(vec2);" << RESET << std::endl << std::endl;
		std::vector<std::string> vec4(vec2);
		std::cout << "vec2.capacity(): " << vec2.capacity() << std::endl;
		std::cout << "vec2.size(): " << vec2.size() << std::endl;
		std::cout << "vec4.capacity(): " << vec4.capacity() << std::endl;
		std::cout << "vec4.size(): " << vec4.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Vector.hpp - line 138" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec5 = vec3;" << RESET << std::endl << std::endl;
		std::vector<std::string> vec5 = vec3;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		std::cout << "vec3.size(): " << vec3.size() << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		std::cout << "vec5.size(): " << vec5.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop_back() - Vector.hpp - line 354" << RESET << std::endl;
		std::cout << "vec2.pop_back();" << RESET << std::endl << std::endl;
		vec2.pop_back();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() // single element - Vector.hpp - line 587" << RESET << std::endl;
		std::cout << "vec2.erase(vec2.begin());" << RESET << std::endl << std::endl;
		vec2.erase(vec2.begin());
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() // range - Vector.hpp - line 611" << RESET << std::endl;
		std::cout << "vec2.erase(vec2.begin(), vec2.begin() + 3);" << RESET << std::endl << std::endl;
		vec2.erase(vec2.begin(), vec2.begin() + 3);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "resize() - Vector.hpp - line 210" << RESET << std::endl;
		std::cout << "vec2.resize(60);" << RESET << std::endl << std::endl;
		vec2.resize(60);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "reserve() - Vector.hpp - line 235" << RESET << std::endl;
		std::cout << "vec2.reserve(50);" << RESET << std::endl << std::endl;
		vec2.reserve(50);
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign() // range - Vector.hpp - line 305" << RESET << std::endl;
		std::cout << "vec2.assign(vec3.begin(), vec3.end());" << RESET << std::endl << std::endl;
		vec2.assign(vec3.begin(), vec3.end());
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign() // fill - Vector.hpp - line 332" << RESET << std::endl;
		std::cout << "vec2.assign(3, \"Eighty-four!\");" << RESET << std::endl << std::endl;
		vec2.assign(3, "Eighty-four!");
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "clear() - Vector.hpp - line 661" << RESET << std::endl;
		std::cout << "vec2.clear();" << RESET << std::endl << std::endl;
		vec2.clear();
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		std::cout << "size(): " << vec2.size() << std::endl;

		std::cout << BOLDGREEN   << std::endl << "---------- vec6 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "fill constructor - Vector.hpp - line 69" << RESET << std::endl;
		std::cout << "std::vector<std::string> vec6(1000000);" << RESET << std::endl << std::endl;
		std::vector<std::string> vec6(1000000);
		std::cout << "capacity(): " << vec6.capacity() << std::endl;
		std::cout << "size(): " << vec6.size() << std::endl;
		// print_vector_str_real(vec6);
		
		std::cout << BOLDGREEN   << std::endl << "---------- vec6 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "assign // fill - Vector.hpp - line 332" << RESET << std::endl;
		std::cout << "vec6.assign(1, \"Twenty-one!\");" << RESET << std::endl << std::endl;
		vec6.assign(1, "Twenty-one!");
		std::cout << "capacity(): " << vec6.capacity() << std::endl;
		print_vector_str_real(vec6);

		std::cout << BOLDGREEN   << std::endl << "---------- vec2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Vector.hpp - line 228" << RESET << std::endl;
		std::cout << "vec2.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << vec2.empty() << std::endl;
		std::cout << "capacity(): " << vec2.capacity() << std::endl;
		print_vector_str_real(vec2);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Vector.hpp - line 228" << RESET << std::endl;
		std::cout << "vec3.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << vec3.empty() << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push_back() - Vector.hpp - line 345" << RESET << std::endl;
		std::cout << "vec5.push_back(\"Thirty-six!\");" << RESET << std::endl << std::endl;
		vec5.push_back("Thirty-six!");
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // single element - Vector.hpp - line 361" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), \"Twelve!\");" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), "Twelve!");
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // fill - Vector.hpp - line 425" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), 2, \"Sixty-eight!\");" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), 2, "Sixty-eight!");
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // range - Vector.hpp - line 501" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.begin(), vec3.end() - 2, vec3.end());" << RESET << std::endl << std::endl;
		vec5.insert(vec5.begin(), vec3.end() - 3, vec3.end());
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // fill - Vector.hpp - line 425" << RESET << std::endl;
		std::cout << "vec5.insert(vec5.end(), 15, \"Six!\");" << RESET << std::endl << std::endl;
		vec5.insert(vec5.end(), 15, "Six!");
		std::cout << "capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "------ vec3 && vec5 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "swap() - Vector.hpp - line 635" << RESET << std::endl;
		std::cout << "vec5.swap(vec3);" << RESET << std::endl << std::endl;
		std::cout << std::endl << BOLDBLUE << "VEC3 BEFORE: " << RESET << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC5 BEFORE: " << RESET << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);
		vec5.swap(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC3 AFTER: " << RESET << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl << BOLDBLUE << "VEC5 AFTER: " << RESET << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "resize() - Vector.hpp - line 210" << RESET << std::endl;
		std::cout << "vec3.resize(6);" << RESET << std::endl << std::endl;
		vec3.resize(6);
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator[] - Vector.hpp - line 259" << RESET << std::endl;
		std::cout << "vec3[3]" << RESET << std::endl << std::endl;
		std::cout << "vec3[3]: " << vec3[3] << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "at() - Vector.hpp - line 269" << RESET << std::endl;
		std::cout << "vec3.at(5)" << RESET << std::endl << std::endl;
		std::cout << "vec3.at(5): " << vec3.at(5) << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "front() - Vector.hpp - line 283" << RESET << std::endl;
		std::cout << "vec3.front()" << RESET << std::endl << std::endl;
		std::cout << "vec3.front(): " << vec3.front() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "back() - Vector.hpp - line 293" << RESET << std::endl;
		std::cout << "vec3.back()" << RESET << std::endl << std::endl;
		std::cout << "vec3.back(): " << vec3.back() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "rbegin() - Vector.hpp - line 179" << RESET << std::endl;
		std::cout << "*vec3.rbegin()" << RESET << std::endl << std::endl;
		std::cout << "*vec3.rbegin(): " << *vec3.rbegin() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "rend() - Vector.hpp - line 189" << RESET << std::endl;
		std::cout << "*(vec3.rend() - 1)" << RESET << std::endl << std::endl;
		std::cout << "*(vec3.rend() - 1): " << *(vec3.rend() - 1) << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "max_size() - Vector.hpp - line 205" << RESET << std::endl;
		std::cout << "vec3.max_size()" << RESET << std::endl << std::endl;
		std::cout << "vec3.max_size(): " << vec3.max_size() << std::endl << std::endl;
		std::cout << "capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Vector.hpp - line 696" << RESET << std::endl;
		std::cout << "(vec3 == vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 == vec5): " << (vec3 == vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Vector.hpp - line 733" << RESET << std::endl;
		std::cout << "(vec3 > vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 > vec5): " << (vec3 > vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Vector.hpp - line 138" << RESET << std::endl;
		std::cout << "vec5 = vec3;" << RESET << std::endl << std::endl;
		vec5 = vec3;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Vector.hpp - line 696" << RESET << std::endl;
		std::cout << "(vec3 == vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 == vec5): " << (vec3 == vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);

		std::cout << BOLDGREEN   << std::endl << "---------- vec3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator<= - Vector.hpp - line 725" << RESET << std::endl;
		std::cout << "(vec3 <= vec5)" << RESET << std::endl << std::endl;
		std::cout << "(vec3 <= vec5): " << (vec3 <= vec5) << std::endl << std::endl;
		std::cout << "vec3.capacity(): " << vec3.capacity() << std::endl;
		print_vector_str_real(vec3);
		std::cout << std::endl;
		std::cout << "vec5.capacity(): " << vec5.capacity() << std::endl;
		print_vector_str_real(vec5);
	
	}

    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "------------------------- TESTS  STACK --------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET << std::endl << std::endl;

    std::cout << BOLDBLUE    << std::endl << "------------ TESTS FOR INT STACKS ------------" << RESET << std::endl << std::endl;

	{

		std::cout << BOLDGREEN   << std::endl << "---------- stk1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "default constructor - Stack.hpp - line 42" << RESET << std::endl;
		std::cout << "std::stack<int> stk1;" << RESET << std::endl << std::endl;
		std::stack<int> stk1;
		std::cout << "size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);

		std::cout << BOLDGREEN   << std::endl << "---------- stk1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Stack.hpp - line 79" << RESET << std::endl;
		std::cout << "stk1.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << stk1.empty() << std::endl;
		std::cout << "size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);

		std::cout << BOLDGREEN   << std::endl << "---------- stk1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk1.push(42);" << RESET << std::endl << std::endl;
		stk1.push(42);
		std::cout << "empty(): " << stk1.empty() << std::endl;
		std::cout << "size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);

		std::cout << BOLDGREEN   << std::endl << "---------- stk2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Stack.hpp - line 53" << RESET << std::endl;
		std::cout << "std::stack<int> stk2 = stk1;" << RESET << std::endl << std::endl;
		std::stack<int> stk2 = stk1;
		std::cout << "stk1.size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);
		std::cout << std::endl;
		std::cout << "stk2.size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);
	
		std::cout << BOLDGREEN   << std::endl << "------ stk3 && stk2 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "copy constructor - Stack.hpp - line 48" << RESET << std::endl;
		std::cout << "std::stack<int> stk3(stk2);" << RESET << std::endl << std::endl;
		std::stack<int> stk3(stk2);
		std::cout << "stk2.size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);
		std::cout << std::endl;
		std::cout << "stk3.size(): " << stk3.size() << std::endl;
		print_stack_int_real(stk3);

		std::cout << BOLDGREEN   << std::endl << "---------- stk2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk2.push(84);" << RESET << std::endl << std::endl;
		stk2.push(84);
		std::cout << "size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);

		std::cout << BOLDGREEN   << std::endl << "---------- stk2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop() - Stack.hpp - line 95" << RESET << std::endl;
		std::cout << "stk2.pop();" << RESET << std::endl << std::endl;
		stk2.pop();
		std::cout << "size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);

		std::cout << BOLDGREEN   << std::endl << "------ stk1 && stk2 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Stack.hpp - line 116" << RESET << std::endl;
		std::cout << "(stk1 == stk2)" << RESET << std::endl << std::endl;
		std::cout << "(stk1 == stk2): " << (stk1 == stk2) << std::endl << std::endl;
		std::cout << "stk1.size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);
		std::cout << "stk2.size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);

		std::cout << BOLDGREEN   << std::endl << "---------- stk1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk1.push(16);" << RESET << std::endl << std::endl;
		stk1.push(16);
		std::cout << "size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);

		std::cout << BOLDGREEN   << std::endl << "------ stk1 && stk2 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Stack.hpp - line 140" << RESET << std::endl;
		std::cout << "(stk1 > stk2)" << RESET << std::endl << std::endl;
		std::cout << "(stk1 > stk2): " << (stk1 > stk2) << std::endl << std::endl;
		std::cout << "stk1.size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);
		std::cout << "stk2.size(): " << stk2.size() << std::endl;
		print_stack_int_real(stk2);
		
		std::cout << BOLDGREEN   << std::endl << "---------- stk1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "top() - Stack.hpp - line 68" << RESET << std::endl;
		std::cout << "stk1.top()" << RESET << std::endl << std::endl;
		std::cout << "top(): " << stk1.top() << std::endl;
		std::cout << "size(): " << stk1.size() << std::endl;
		print_stack_int_real(stk1);
	
	}

    std::cout << BOLDBLUE    << std::endl << std::endl << "----------- TESTS FOR  LIST STACKS -----------" << RESET << std::endl << std::endl;

	{

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "default constructor - Stack.hpp - line 42" << RESET << std::endl;
		std::cout << "std::stack< int, std::list<int> > stk_lst1;" << RESET << std::endl << std::endl;
		std::stack< int, std::list<int> > stk_lst1;
		std::cout << "size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);
		
		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Stack.hpp - line 79" << RESET << std::endl;
		std::cout << "stk_lst1.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << stk_lst1.empty() << std::endl;
		std::cout << "size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk_lst1.push(42);" << RESET << std::endl << std::endl;
		stk_lst1.push(42);
		std::cout << "empty(): " << stk_lst1.empty() << std::endl;
		std::cout << "size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst2 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Stack.hpp - line 53" << RESET << std::endl;
		std::cout << "std::stack< int, std::list<int> > stk_lst2 = stk_lst1;" << RESET << std::endl << std::endl;
		std::stack< int, std::list<int> > stk_lst2 = stk_lst1;
		std::cout << "stk_lst1.size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);
		std::cout << std::endl;
		std::cout << "stk_lst2.size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);
	
		std::cout << BOLDGREEN   << std::endl << "------ stk3 && stk2 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "copy constructor - Stack.hpp - line 48" << RESET << std::endl;
		std::cout << "std::stack< int, std::list<int> > stk_lst3(stk_lst2);" << RESET << std::endl << std::endl;
		std::stack< int, std::list<int> > stk_lst3(stk_lst2);
		std::cout << "stk2.size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);
		std::cout << std::endl;
		std::cout << "stk3.size(): " << stk_lst3.size() << std::endl;
		print_stack_list_real(stk_lst3);

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst2 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk_lst2.push(84);" << RESET << std::endl << std::endl;
		stk_lst2.push(84);
		std::cout << "size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst2 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "pop() - Stack.hpp - line 95" << RESET << std::endl;
		std::cout << "stk_lst2.pop();" << RESET << std::endl << std::endl;
		stk_lst2.pop();
		std::cout << "size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);

		std::cout << BOLDGREEN   << std::endl << "-- stk_lst1 && stk_lst2 --" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator== - Stack.hpp - line 116" << RESET << std::endl;
		std::cout << "(stk_lst1 == stk_lst2)" << RESET << std::endl << std::endl;
		std::cout << "(stk_lst1 == stk_lst2): " << (stk_lst1 == stk_lst2) << std::endl << std::endl;
		std::cout << "stk_lst1.size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);
		std::cout << "stk_lst2.size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);
	
		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "push() - Stack.hpp - line 90" << RESET << std::endl;
		std::cout << "stk_lst1.push(16);" << RESET << std::endl << std::endl;
		stk_lst1.push(16);
		std::cout << "size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);

		std::cout << BOLDGREEN   << std::endl << "-- stk_lst1 && stk_lst2 --" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Stack.hpp - line 140" << RESET << std::endl;
		std::cout << "(stk_lst1 > stk_lst2)" << RESET << std::endl << std::endl;
		std::cout << "(stk_lst1 > stk_lst2): " << (stk_lst1 > stk_lst2) << std::endl << std::endl;
		std::cout << "stk_lst1.size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);
		std::cout << "stk_lst2.size(): " << stk_lst2.size() << std::endl;
		print_stack_list_real(stk_lst2);

		std::cout << BOLDGREEN   << std::endl << "-------- stk_lst1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "top() - Stack.hpp - line 68" << RESET << std::endl;
		std::cout << "stk_lst1.top()" << RESET << std::endl << std::endl;
		std::cout << "top(): " << stk_lst1.top() << std::endl;
		std::cout << "size(): " << stk_lst1.size() << std::endl;
		print_stack_list_real(stk_lst1);
	}

    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "-------------------------- TESTS  MAP ---------------------------" << RESET;
    std::cout << BOLDMAGENTA << std::endl << "-----------------------------------------------------------------" << RESET << std::endl << std::endl;

    std::cout << BOLDBLUE    << std::endl << "------------ TESTS FOR  INT PAIRS ------------" << RESET << std::endl << std::endl;

	{

		std::cout << BOLDGREEN   << std::endl << "----------- p1 -----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "initialization constructor - Pair.hpp - line 50" << RESET << std::endl;
		std::cout << "std::pair<int, int> p1(42, 41);" << RESET << std::endl << std::endl;
		std::pair<int, int> p1(42, 41);
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;

		std::cout << BOLDGREEN   << std::endl << "-------- p2 && p1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Pair.hpp - line 97" << RESET << std::endl;
		std::cout << "std::pair<int, int> p2(43, 40);" << RESET << std::endl << std::endl;
		std::cout << "(p1 > p2)" << RESET << std::endl << std::endl;
		std::pair<int, int> p2(43, 40);
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;
		std::cout << "p2.first: " << p2.first << " - p2.second: " << p2.second << std::endl;
		std::cout << "(p1 > p2): " << (p1 > p2) << std::endl;

		std::cout << BOLDGREEN   << std::endl << "----------- p2 -----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Pair.hpp - line 60" << RESET << std::endl;
		std::cout << "p2 = p1;" << RESET << std::endl << std::endl;
		p2 = p1;
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;
		std::cout << "p2.first: " << p2.first << " - p2.second: " << p2.second << std::endl;

		std::cout << BOLDGREEN   << std::endl << "-------- p2 && p1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator<= - Pair.hpp - line 91" << RESET << std::endl;
		std::cout << "(p1 <= p2)" << RESET << std::endl << std::endl;
		std::cout << "(p1 <= p2): " << (p1 <= p2) << std::endl;
    
	}

    std::cout << BOLDBLUE    << std::endl << "-------- TESTS FOR INT & STRING PAIRS --------" << RESET << std::endl << std::endl;

	{

		std::cout << BOLDGREEN   << std::endl << "----------- p1 -----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "initialization constructor - Pair.hpp - line 50" << RESET << std::endl;
		std::cout << "std::pair<int, std::string> p1(42, \"Quarante-deux!\");" << RESET << std::endl << std::endl;
		std::pair<int, std::string> p1(42, "Quarante-deux!");
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;

		std::cout << BOLDGREEN   << std::endl << "-------- p2 && p1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator> - Pair.hpp - line 97" << RESET << std::endl;
		std::cout << "std::pair<int, std::string> p2(43, \"Quarante!\");" << RESET << std::endl << std::endl;
		std::cout << "(p1 > p2)" << RESET << std::endl << std::endl;
		std::pair<int, std::string> p2(43, "Quarante!");
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;
		std::cout << "p2.first: " << p2.first << " - p2.second: " << p2.second << std::endl;
		std::cout << "(p1 > p2): " << (p1 > p2) << std::endl;

		std::cout << BOLDGREEN   << std::endl << "----------- p2 -----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Pair.hpp - line 60" << RESET << std::endl;
		std::cout << "p2 = p1;" << RESET << std::endl << std::endl;
		p2 = p1;
		std::cout << "p1.first: " << p1.first << " - p1.second: " << p1.second << std::endl;
		std::cout << "p2.first: " << p2.first << " - p2.second: " << p2.second << std::endl;

		std::cout << BOLDGREEN   << std::endl << "-------- p2 && p1 --------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator<= - Pair.hpp - line 91" << RESET << std::endl;
		std::cout << "(p1 <= p2)" << RESET << std::endl << std::endl;
		std::cout << "(p1 <= p2): " << (p1 <= p2) << std::endl;
    
	}

    std::cout << BOLDBLUE    << std::endl << "-------- TESTS FOR INT && STRING MAPS --------" << RESET << std::endl << std::endl;

	{
		std::cout << BOLDGREEN   << std::endl << "---------- map1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "default constructor - Map.hpp - line 138" << RESET << std::endl;
		std::cout << "std::map<int, std::string> map1;" << RESET << std::endl << std::endl;
		std::map<int, std::string> map1;
		// std::cout << std::endl << "map1.max_size(): " << map1.max_size() << std::endl;
		print_map_int_str_real(map1);

		std::cout << BOLDGREEN   << std::endl << "---------- map1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Map.hpp - line 246" << RESET << std::endl;
		std::cout << "map1.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << map1.empty() << std::endl;
		print_map_int_str_real(map1);

		std::cout << BOLDGREEN   << std::endl << "---------- map1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // single element - Map.hpp - line 298" << RESET << std::endl;
		std::cout << "std::pair<int, std::string> pair_one = std::make_pair(65, \"A\");" << RESET << std::endl;
		std::cout << "std::pair<int, std::string> pair_two = std::make_pair(66, \"B\");" << RESET << std::endl;
		std::cout << "std::pair<int, std::string> pair_three = std::make_pair(67, \"C\");" << RESET << std::endl;
		// std::cout << "std::pair<int, std::string> pair_four = std::make_pair(68, \"D\");" << RESET << std::endl;
		// std::cout << "std::pair<int, std::string> pair_five = std::make_pair(69, \"E\");" << RESET << std::endl;
		// std::cout << "ft::pair<int, std::string> pair_six = ft::make_pair(70, \"F\");" << RESET << std::endl;
		// std::cout << "ft::pair<int, std::string> pair_seven = ft::make_pair(71, \"G\");" << RESET << std::endl;
		// std::cout << "ft::pair<int, std::string> pair_eight = ft::make_pair(72, \"H\");" << RESET << std::endl;
		// std::cout << "ft::pair<int, std::string> pair_nine = ft::make_pair(73, \"I\");" << RESET << std::endl;
		// std::cout << "ft::pair<int, std::string> pair_ten = ft::make_pair(74, \"J\");" << RESET << std::endl;
		std::pair<int, std::string> pair_one = std::make_pair(65, "A");
		std::pair<int, std::string> pair_two = std::make_pair(66, "B");
		std::pair<int, std::string> pair_three = std::make_pair(67, "C");
		// std::pair<int, std::string> pair_four = std::make_pair(68, "D");
		// std::pair<int, std::string> pair_five = std::make_pair(69, "E");
		// ft::pair<int, std::string> pair_six = ft::make_pair(70, "F");
		// ft::pair<int, std::string> pair_seven = ft::make_pair(71, "G");
		// ft::pair<int, std::string> pair_eight = ft::make_pair(72, "H");
		// ft::pair<int, std::string> pair_nine = ft::make_pair(73, "I");
		// ft::pair<int, std::string> pair_ten = ft::make_pair(74, "J");
		std::cout << "map1.insert(pair_one);"	<< RESET << std::endl;
		std::cout << "map1.insert(pair_two);"	<< RESET << std::endl;
		std::cout << "map1.insert(pair_three);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_four);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_five);"	<< RESET << std::endl << std::endl;
		// std::cout << "map1.insert(pair_six);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_seven);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_eight);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_nine);"	<< RESET << std::endl;
		// std::cout << "map1.insert(pair_ten);"	<< RESET << std::endl << std::endl;
		map1.insert(pair_one);
		map1.insert(pair_two);
		map1.insert(pair_three);
		// map1.insert(pair_four);
		// map1.insert(pair_five);
		// map1.insert(pair_six);
		// map1.insert(pair_seven);
		// map1.insert(pair_eight);
		// map1.insert(pair_nine);
		// map1.insert(pair_ten);
		print_map_int_str_real(map1);

		std::cout << BOLDGREEN   << std::endl << "---------- map1 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "empty() - Map.hpp - line 246" << RESET << std::endl;
		std::cout << "map1.empty()" << RESET << std::endl << std::endl;
		std::cout << "empty(): " << map1.empty() << std::endl;
		print_map_int_str_real(map1);

		std::cout << BOLDGREEN   << std::endl << "------ map2 && map1 ------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "constructor range - Map.hpp - line 146" << RESET << std::endl;
		std::cout << "std::map<int, std::string> map2(map1.begin(), map1.end());" << RESET << std::endl << std::endl;
		std::map<int, std::string> map2(map1.begin(), map1.end());
		std::cout << std::endl << "map1: " << std::endl;
		print_map_int_str_real(map1);
		std::cout << "map2: " << std::endl;
		print_map_int_str_real(map2);

		std::cout << BOLDGREEN   << std::endl << "---------- map2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "at() - Map.hpp - line 264" << RESET << std::endl;
		std::cout << "map2.at(65) = \"alpha\"" << RESET << std::endl;
		std::cout << "map2.at(66) = \"beta\"" << RESET << std::endl;
		std::cout << "map2.at(67) = \"gamma\"" << RESET << std::endl<< std::endl;
		map2.at(65) = "alpha";
		map2.at(66) = "beta";
		map2.at(67) = "gamma";
		print_map_int_str_real(map2);
		
		std::cout << BOLDGREEN   << std::endl << "---------- map2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator[] - Map.hpp - line 286" << RESET << std::endl;
		std::cout << "map2[75] = \"ALPHA\";" << RESET << std::endl;
		std::cout << "map2[76] = \"BETA\";" << RESET << std::endl;
		std::cout << "map2[77] = \"GAMMA\";" << RESET << std::endl<< std::endl;
		map2[75] = "ALPHA";
		map2[76] = "BETA";
		map2[77] = "GAMMA";
		print_map_int_str_real(map2);

		std::cout << BOLDGREEN   << std::endl << "---------- map2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() from key - Map.hpp - line 334" << RESET << std::endl;
		std::cout << "map2.erase(66);" << RESET << std::endl;
		map2.erase(66);
		print_map_int_str_real(map2);

		std::cout << BOLDGREEN   << std::endl << "---------- map2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "swap() - Map.hpp - line 354" << RESET << std::endl;
		std::cout << "map2.swap(map1);" << RESET << std::endl;
		std::cout << std::endl << "map1 BEFORE: " << std::endl;
		print_map_int_str_real(map1);
		std::cout << "map2 BEFORE: " << std::endl;
		print_map_int_str_real(map2);
		map2.swap(map1);
		std::cout << "map1 AFTER: " << std::endl;
		print_map_int_str_real(map1);
		std::cout << "map2 AFTER: " << std::endl;
		print_map_int_str_real(map2);

		std::cout << BOLDGREEN   << std::endl << "---------- map3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "insert() // range - Map.hpp - line 319" << RESET << std::endl;
		std::cout << "std::map<int, std::string> map3;" << RESET << std::endl;
		std::cout << "map3.insert(map2.begin(), --map2.end());" << RESET << std::endl;
		std::map<int, std::string> map3;
		map3.insert(map2.begin(), --map2.end());
		std::cout << std::endl << "map2: " << std::endl;
		print_map_int_str_real(map2);
		std::cout << "map3: " << std::endl;
		print_map_int_str_real(map3);

		std::cout << BOLDGREEN   << std::endl << "---------- map3 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "erase() // range - Map.hpp - line 345" << RESET << std::endl;
		std::cout << "map3.erase(map3.begin(), map3.end());" << RESET << std::endl;
		std::cout << std::endl << "map3 BEFORE: " << std::endl;
		print_map_int_str_real(map3);
		map3.erase(map3.begin(), map3.end());
		std::cout << std::endl << "map3 AFTER: " << std::endl;
		print_map_int_str_real(map3);

		std::cout << BOLDGREEN   << std::endl << "---------- map2 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "rbegin() - Map.hpp - line 239" << RESET << std::endl;
		std::cout << "map2.rbegin()->first" << RESET << std::endl << std::endl;
		std::cout << "map2.rbegin()->first: " << map2.rbegin()->first << std::endl << std::endl;
		print_map_int_str_real(map2);

		std::cout << BOLDGREEN   << std::endl << "---------- map4 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "copy constructor - Map.hpp - line 153" << RESET << std::endl;
		std::cout << "std::map<int, std::string> map4(map2);" << RESET << std::endl << std::endl;
		std::map<int, std::string> map4(map2);
		std::cout << std::endl << "map2: " << std::endl;
		print_map_int_str_real(map2);
		std::cout << "map4: " << std::endl;
		print_map_int_str_real(map4);
	
		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "operator= - Map.hpp - line 164" << RESET << std::endl;
		std::cout << "std::map<int, std::string> map5 = map4;" << RESET << std::endl << std::endl;
		std::map<int, std::string> map5 = map4;
		std::cout << std::endl << "map4: " << std::endl;
		print_map_int_str_real(map4);
		std::cout << std::endl << "map5: " << std::endl;
		print_map_int_str_real(map5);
		
		std::cout << BOLDGREEN   << std::endl << "---------- map4 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "clear() - Map.hpp - line 372" << RESET << std::endl;
		std::cout << "map4.clear()" << RESET << std::endl << std::endl;
		map4.clear();
		print_map_int_str_real(map4);

		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "find() - Map.hpp - line 390" << RESET << std::endl;
		std::cout << "map5.find(66)->second" << RESET << std::endl << std::endl;
		std::cout << "map5.find(66)->second: " << map5.find(66)->second << std::endl << std::endl;
		print_map_int_str_real(map5);

		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "find() - Map.hpp - line 390" << RESET << std::endl;
		std::cout << "map5.find(6600)" << RESET << std::endl << std::endl;
		std::map<int, std::string>::iterator it = map5.find(6600);
		if (it != map5.end())
			std::cout << "map5.find(6600)->second: " << map5.find(6600)->second << std::endl << std::endl;
		else
			std::cout << "ptr in iterator null. Value not found." << std::endl;
		print_map_int_str_real(map5);

		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "lower_bound() - Map.hpp - line 417" << RESET << std::endl;
		std::cout << "map5.lower_bound(66)->second" << RESET << std::endl << std::endl;
		std::cout << "map5.lower_bound(66)->second: " << map5.lower_bound(66)->second << std::endl << std::endl;
		print_map_int_str_real(map5);
	
		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "upper_bound() - Map.hpp - line 441" << RESET << std::endl;
		std::cout << "map5.upper_bound(66)->second" << RESET << std::endl << std::endl;
		std::cout << "map5.upper_bound(66)->second: " << map5.upper_bound(66)->second << std::endl << std::endl;
		print_map_int_str_real(map5);

		std::cout << BOLDGREEN   << std::endl << "---------- map5 ----------" << RESET << std::endl << std::endl;
		std::cout << YELLOW << "equal_range() - Map.hpp - line 469" << RESET << std::endl;
		std::cout << "(map5.equal_range(66)).first->second" << RESET << std::endl;
		std::cout << "(map5.equal_range(66)).second->second" << RESET << std::endl << std::endl;
		std::cout << "(map5.equal_range(66)).first->second: " << (map5.equal_range(66)).first->second << std::endl;
		std::cout << "(map5.equal_range(66)).second->second: " << (map5.equal_range(66)).second->second << std::endl << std::endl;
		print_map_int_str_real(map5);

	}

    return (0);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

////////// MAIN GIVEN ON THE PROJECT PAGE //////////

#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	std::vector<std::string> vector_str;
	std::vector<int> vector_int;
	std::stack<int> stack_int;
	std::vector<Buffer> vector_buffer;
	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	std::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(std::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		std::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

//////////////// A FEW MORE SIMPLE AND BASIC VARIOUS VECTOR TESTS ////////////////

# include <iostream>
# include <string>
# include <list>
# include <map>
# include <stack>
# include <vector>

void    print_vector_real(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        std::cout << *begin << std::endl;
        begin++;
    }
}

int main()
{

	{

		std::vector<int>	vec2(4, 6);

		print_vector_real(vec2.begin(), vec2.end());
		vec2.pop_back();
		std::cout << std::endl;
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.clear();
		print_vector_real(vec2.begin(), vec2.end());

		std::cout << "*****************************************" << std::endl << std::endl;

	}

	// TESTS SWAP VECTOR

	{

		std::vector<int> vec3(3, 42);
		std::vector<int> vec4(3, 84);

		print_vector_real(vec3.begin(), vec3.end());
		print_vector_real(vec4.begin(), vec4.end());

		swap(vec3, vec4);

		print_vector_real(vec3.begin(), vec3.end());
		print_vector_real(vec4.begin(), vec4.end());

		std::cout << std::endl << "*****************************************" << std::endl << std::endl;

	}

	// TESTS ERASE VECTOR

	{	

		std::vector<int> vec2(1, 42);

		vec2.push_back(43);
		vec2.push_back(44);
		vec2.push_back(45);
		vec2.push_back(46);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << vec2[0] << std::endl;
		std::cout << vec2[1] << std::endl;
		std::cout << vec2[2] << std::endl;
		std::cout << vec2[3] << std::endl;
		std::cout << vec2[4] << std::endl;
		std::cout << std::endl;

		vec2.erase(vec2.begin() + 1);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << vec2[0] << std::endl;
		std::cout << vec2[1] << std::endl;
		std::cout << vec2[2] << std::endl;
		std::cout << vec2[3] << std::endl;
		std::cout << std::endl;

		std::cout << "*****************************************" << std::endl << std::endl;

	}

	// TESTS AGAIN ERASE VECTOR

	{

		std::vector<int> myvector2;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++)
			myvector2.push_back(i);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector2.size(); ++i)
			std::cout << ' ' << myvector2[i];
		std::cout << '\n';

		// erase the 6th element
		myvector2.erase (myvector2.begin()+5);

		// erase the first 3 elements:
		myvector2.erase (myvector2.begin(),myvector2.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector2.size(); ++i)
			std::cout << ' ' << myvector2[i];
		std::cout << "\n\n";
			
		std::cout << "*****************************************" << std::endl << std::endl;

	}

	// TESTS POP ET PUSH VECTOR

	{

		std::vector<int> vec2(6, 42);

		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.pop_back();
		vec2.pop_back();
		vec2.push_back(456);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;

		std::cout << "*****************************************" << std::endl << std::endl;

	}

	// TESTS ASSIGN VECTOR

	{

		std::vector<int> vec2(2, 42);
		std::vector<int> vec2_to_add(3, 84);
		std::vector<int> vec2_to_add2(1, 8);

		print_vector_real(vec2.begin(), vec2.end());
		vec2.assign(vec2_to_add.begin(), vec2_to_add.end());
		std::cout << std::endl;
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.assign(vec2_to_add2.begin(), vec2_to_add2.end());
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.assign(5, 123);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;

		std::cout << "*****************************************" << std::endl << std::endl;

	}

	// TESTS AT VECTOR
	{

		std::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';

		std::cout << std::endl << "*****************************************" << std::endl << std::endl;

	}

	// TEST RESIZE VECTOR

	{

		std::vector<int> vec2(2, 42);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.resize(5,78);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.resize(3);
		print_vector_real(vec2.begin(), vec2.end());
		std::cout << std::endl;
		vec2.resize(5);
		print_vector_real(vec2.begin(), vec2.end());

		std::cout << std::endl << "*****************************************" << std::endl << std::endl;

	}

	// TESTS BASIQUES VECTOR

	{

		std::vector<int> vec;
		std::vector<int> vec2(10, 33);
		std::vector<int> vec3(vec2);
		std::vector<int> vec4 = vec3;

		std::cout << vec.size() << std::endl;
		std::cout << vec.capacity() << std::endl;
		std::cout << std::endl;
		std::cout << vec2.size() << std::endl;
		std::cout << vec2.capacity() << std::endl;
		vec2.pop_back();
		std::cout << vec2.size() << std::endl;
		std::cout << vec2.capacity() << std::endl;
		std::cout << std::endl;
		std::cout << vec3.size() << std::endl;
		std::cout << vec3.capacity() << std::endl;
		std::cout << std::endl;
		std::cout << vec4.size() << std::endl;
		std::cout << vec4.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << std::endl << "*****************************************" << std::endl << std::endl;

	}

	// TESTS INSERT VECTOR

	{

		// std::vector<int> vec_vrai;
		// std::vector<int> vec_vrai(2);
		std::vector<int> vec_vrai(4, 46);
		
		std::vector<int> vec_to_add2(2, 78);

		std::cout << vec_vrai[0] << std::endl;
		std::cout << vec_vrai[1] << std::endl;
		std::cout << vec_vrai[2] << std::endl;
		std::cout << vec_vrai[3] << std::endl << std::endl;

		// vec_vrai.insert(vec_vrai.begin(), 56);
		vec_vrai.insert(vec_vrai.begin(), 3, 52);
		// vec_vrai.insert(vec_vrai.begin(), vec_to_add2.begin(), vec_to_add2.end());

		std::cout << vec_vrai[0] << std::endl;
		std::cout << vec_vrai[1] << std::endl;
		std::cout << vec_vrai[2] << std::endl;
		std::cout << vec_vrai[3] << std::endl;
		std::cout << vec_vrai[4] << std::endl;
		std::cout << vec_vrai[5] << std::endl;
		std::cout << vec_vrai[6] << std::endl;

		std::cout << std::endl << "*****************************************" << std::endl << std::endl;

	}

	return (0);
}

*/