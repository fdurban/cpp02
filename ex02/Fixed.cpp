/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:24:42 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/21 16:40:25 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fpvalue = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int floatingPointInt)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->fpvalue = floatingPointInt << this->fractionalBits;
}

Fixed::Fixed(const float floatingPointFloat)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->fpvalue = floatingPointFloat * (1<<this->fractionalBits);
}


Fixed::Fixed(const Fixed& other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

int	Fixed::getRawBits(void) const
{
	return (this->fpvalue)
}

Fixed	Fixed::operator=(const Fixed& other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if(this == &other)
		return *this;
	this->fpvalue = other.getRawBits();
	return *this;
}

std::ostream operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

bool	Fixed::operator>(const Fixed  &other)
{
	return(this.getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed  &other)
{
	return(this.getRawBits() < other.getRawBits());
}


bool	Fixed::operator>=(const Fixed  &other)
{
	return(this.getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed  &other)
{
	return(this.getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed  &other)
{
	return(this.getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed  &other)
{
	return(this.getRawBits() != other.getRawBits());
}

//OVERLOAD ARITHMETIC OPERATIONS

int Fixed::operator+(const Fixed &other)
{
	return(this.getRawBits() + other.getRawBits());
}
int	Fixed::operator-(const Fixed &other)
{
	return(this.getRawBits() - other.getRawBits());
}
int	Fixed::operator*(const Fixed &other)
{
	return(this.getRawBits() * other.getRawBits());
}
int	Fixed::operator/(const Fixed &other)
{
	return(this.getRawBits() / other.getRawBits());
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

Fixed	Fixed::operator--()
{
	int	temp;
	temp = this->fpvalue;
	this->fpvalue++;
	return (temp);
}

