/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <fdurban-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:24 by fdurban-          #+#    #+#             */
/*   Updated: 2025/12/10 15:21:19 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedPointNumberValue;
		static const int	fractionalBits;
	public:
		Fixed();
		Fixed(const int floatingPointInt);
		Fixed(const float floatingPointFloat);
		Fixed(const Fixed& other);
		float	toFloat(void) const;
		int	toInt(void) const;
		Fixed& operator=(const Fixed& other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		~Fixed();
};
		std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
