/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:44:38 by fdurban-          #+#    #+#             */
/*   Updated: 2025/12/10 14:59:39 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->fixedPointNumberValue = 0;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if(this == &other)
		return *this;
	this->fixedPointNumberValue = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits function called"<<std::endl;
	return (this->fixedPointNumberValue);
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNumberValue = raw;
}
