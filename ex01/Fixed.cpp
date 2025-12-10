/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:42:17 by fdurban-          #+#    #+#             */
/*   Updated: 2025/12/10 15:20:25 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	this->fixedPointNumberValue = 0;
	std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const int floatingPointInt)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->fixedPointNumberValue = floatingPointInt << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointFloat)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->fixedPointNumberValue = roundf(floatingPointFloat * (1<<this->fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNumberValue/(float)(1<<this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return(this->fixedPointNumberValue>>this->fractionalBits);
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
	this->fixedPointNumberValue = other.getRawBits();
	return *this;
}
std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
int	Fixed::getRawBits(void) const
{
	return (this->fixedPointNumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNumberValue = raw;
}
Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}
