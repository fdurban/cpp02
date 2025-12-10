/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:24:42 by fdurban-          #+#    #+#             */
/*   Updated: 2025/12/10 17:18:25 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	this->fixedPointNumberValue = 0;
}

Fixed::Fixed(const int floatingPointInt)
{
	this->fixedPointNumberValue = floatingPointInt << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointFloat)
{
	this->fixedPointNumberValue = roundf(floatingPointFloat * (1<<this->fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixedPointNumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNumberValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNumberValue / (float)(1 << this->fractionalBits));
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if(this == &other)
		return *this;
	this->fixedPointNumberValue = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed  &other) const
{
	return(this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed  &other) const
{
	return(this->getRawBits() < other.getRawBits());
}


bool	Fixed::operator>=(const Fixed  &other) const
{
	return(this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed  &other) const
{
	return(this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed  &other) const
{
	return(this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed  &other) const
{
	return(this->getRawBits() != other.getRawBits());
}

//OVERLOAD ARITHMETIC OPERATIONS

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	result;
	result.setRawBits(this->fixedPointNumberValue + other.fixedPointNumberValue);
	return(result);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	result;
	result.setRawBits(this->fixedPointNumberValue - other.fixedPointNumberValue);
	return(result);
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	result;
	result.setRawBits((this->fixedPointNumberValue * other.fixedPointNumberValue) >> fractionalBits);
	return(result);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	result;
	result.setRawBits((this->fixedPointNumberValue << fractionalBits) / other.fixedPointNumberValue);
	return(result);
}

Fixed	Fixed::operator++()
{
	this->fixedPointNumberValue++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fixedPointNumberValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp = *this;
	++this->fixedPointNumberValue;
	return (temp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp = *this;;
	--this->fixedPointNumberValue;
	return (temp);
}

//Min max operations

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed) 
{
	str << fixed.toFloat();
	return (str);
}
