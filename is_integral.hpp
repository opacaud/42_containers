/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:43:55 by opacaud           #+#    #+#             */
/*   Updated: 2022/02/24 14:11:59 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

//////////////////////////////////////////////////////////////////////////////////////
// https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral		//
// Checks whether T is an integral type.											//
// Provides the member constant value which is equal to true, if T is the type :	//
// - bool																			//
// - char																			//
// - wchar_t																		//
// - signed char																	//
// - short int																		//
// - int																			//
// - long int																		//
// - long long int																	//
// - unsigned char																	//
// - unsigned short int																//
// - unsigned int																	//
// - unsigned long int																//
// - unsigned long long int															//
// Otherwise, value is equal to false.												//
//////////////////////////////////////////////////////////////////////////////////////

namespace ft
{
	template <bool is_integral, typename T>
	struct is_integral_res
	{
		typedef T	type;

		static const bool value = is_integral;
	};

	template <typename>
	struct is_integral : public is_integral_res<false, bool>
	{

	};

	template <>
	struct is_integral<bool> : public is_integral_res<true, bool>
	{

	};

	template <>
	struct is_integral<char> : public is_integral_res<true, char>
	{

	};

	template <>
	struct is_integral<signed char> : public is_integral_res<true, signed char>
	{

	};

	template <>
	struct is_integral<wchar_t> : public is_integral_res<true, wchar_t>
	{

	};

	template <>
	struct is_integral<short int> : public is_integral_res<true, short int>
	{

	};

	template <>
	struct is_integral<int> : public is_integral_res<true, int>
	{

	};

	template <>
	struct is_integral<long int> : public is_integral_res<true, long int>
	{

	};

	template <>
	struct is_integral<long long int> : public is_integral_res<true, long long int>
	{

	};

	template <>
	struct is_integral<unsigned char> : public is_integral_res<true, unsigned char>
	{

	};

	template <>
	struct is_integral<unsigned short int> : public is_integral_res<true, unsigned short int>
	{

	};

	template <>
	struct is_integral<unsigned int> : public is_integral_res<true, unsigned int>
	{

	};

	template <>
	struct is_integral<unsigned long int> : public is_integral_res<true, unsigned long int>
	{

	};

	template <>
	struct is_integral<unsigned long long int> : public is_integral_res<true, unsigned long long int>
	{
		
	};
}

#endif
