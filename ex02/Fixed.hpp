/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:21:30 by fdurban-          #+#    #+#             */
/*   Updated: 2025/12/10 17:17:17 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
class Fixed
{
	private:
		int			fixedPointNumberValue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const int floatingPointInt);
		Fixed(const float floatinfPointFloat);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		bool	operator>(const Fixed  &other) const;
		bool	operator<(const Fixed  &other) const;
		bool	operator>=(const Fixed  &other) const;
		bool	operator<=(const Fixed  &other) const;
		bool	operator==(const Fixed  &other) const;
		bool	operator!=(const Fixed  &other) const;
		Fixed	operator+(const Fixed  &other);
		Fixed	operator-(const Fixed  &other);
		Fixed	operator*(const Fixed  &other);
		Fixed	operator/(const Fixed  &other);
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static void min(int &fpvalue,int &fpvalue2);
		static void min(const int &fpvalue4);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		static const Fixed&     max(Fixed  const &a, Fixed const &b);
		static Fixed&     max(Fixed &a, Fixed &b);
		static const Fixed&     min(Fixed  const &a, Fixed const &b);
		static Fixed&     min(Fixed &a, Fixed &b);
};
	std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
