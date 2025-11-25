/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:21:30 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/21 16:04:48 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
class Fixed
{
	private:
		int			fpvalue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const int floatingPointInt);
		Fixed(const float floatinfPointFloat);
		Fixed(const Fixed& other);
		Fixed	operator=(const Fixed& other);
		bool	operator>(const Fixed  &other);
		bool	operator<(const Fixed  &other);
		bool	operator>=(const Fixed  &other);
		bool	operator<=(const Fixed  &other);
		bool	operator==(const Fixed  &other);
		bool	operator!=(const Fixed  &other);
		int	operator+(const Fixed  &other);
		int	operator-(const Fixed  &other);
		int	operator*(const Fixed  &other);
		int	operator/(const Fixed  &other);
		Fixed	operator++(const Fixed  &other);
		Fixed	operator--(const Fixed  &other);
		Fixed	operator++(const Fixed  &other);
		Fixed	operator--(const Fixed  &other);
		static void min(int &fpvalue,int &fpvalue2);
		static void min(const int &fpvalue4);
};
	std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
