/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:42:17 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/18 17:00:47 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	this->fpvalue = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int floatingPoInt)
{
	this->fpvalue = floatingPointInt;
}

Fixed::Fixed(const float floatingPointFloat)
{

	this->fpvalue = floatingPointFloat;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fpvalue/(float)(1<<this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return(this->fpvalue>>this->fractionBits);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if(this == &other)
		return *this;
	this->fpnvalue = other.getRawBits();
	return *this;
}

std::ostream&	Fixed::operator<<(std::ostream &o, Fixed const &fixed)
{
	o<<fixed.toFloat();
	return (o);
}
Fixed::~Fixed()
{
	std::endl<<"Destructor called"<<std::endl;
}
