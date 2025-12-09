/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:21:30 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/25 15:41:41 by fdurban-         ###   ########.fr       */
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
		Fixed&	operator=(const Fixed& other);
		bool	operator>(const Fixed  &other);
		bool	operator<(const Fixed  &other);
		bool	operator>=(const Fixed  &other);
		bool	operator<=(const Fixed  &other);
		bool	operator==(const Fixed  &other);
		bool	operator!=(const Fixed  &other);
		float	operator+(const Fixed  &other);
		float	operator-(const Fixed  &other);
		float	operator*(const Fixed  &other);
		float	operator/(const Fixed  &other);
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static void min(int &fpvalue,int &fpvalue2);
		static void min(const int &fpvalue4);
		int	getRawBits(void) const;
		float	toFloat(void) const;
		static const Fixed&     max(Fixed  const &a, Fixed const &b);
		static const Fixed&     min(Fixed  const &a, Fixed const &b);
};
	std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
