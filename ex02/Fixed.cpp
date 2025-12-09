/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:24:42 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/26 13:54:34 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;
Fixed::Fixed()
{
	this->fpvalue = 0;
	//std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int floatingPointInt)
{
	//std::cout<<"Int constructor called"<<std::endl;
	this->fpvalue = floatingPointInt << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointFloat)
{
	//std::cout<<"Float constructor called"<<std::endl;
	this->fpvalue = floatingPointFloat * (1<<this->fractionalBits);
}


Fixed::Fixed(const Fixed& other)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

int	Fixed::getRawBits(void) const
{
	return (this->fpvalue);
}

float	Fixed::toFloat(void) const {
	return ((float)this->fpvalue / (float)(1 << this->fractionalBits));
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	//std::cout<<"Copy assignment operator called"<<std::endl;
	if(this == &other)
		return *this;
	this->fpvalue = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed  &other)
{
	return(this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed  &other)
{
	return(this->getRawBits() < other.getRawBits());
}


bool	Fixed::operator>=(const Fixed  &other)
{
	return(this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed  &other)
{
	return(this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed  &other)
{
	return(this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed  &other)
{
	return(this->getRawBits() != other.getRawBits());
}

//OVERLOAD ARITHMETIC OPERATIONS

float	Fixed::operator+(const Fixed &other)
{
	return(this->toFloat() + other.getRawBits());
}
float	Fixed::operator-(const Fixed &other)
{
	return(this->toFloat() - other.getRawBits());
}
float	Fixed::operator*(const Fixed &other)
{
	return(this->toFloat() * other.toFloat());
}
float	Fixed::operator/(const Fixed &other)
{
	return(this->toFloat() / other.getRawBits());
}

Fixed	Fixed::operator++()
{
	this->fpvalue++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->fpvalue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp = *this;
	++this->fpvalue;
	return (temp);
}
Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp = *this;;
	--this->fpvalue;
	return (temp);
}

//Min max operations


const Fixed	&Fixed::max(Fixed const&a, Fixed const &b)
{
	if(a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed) 
{
	str << fixed.toFloat();
	return (str);
}
