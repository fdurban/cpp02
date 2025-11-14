/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:29:41 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/14 17:14:55 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int			fpnvalue;
		static const int	FractionalBits;
	public:
		Fixed();
		Fixed(int fpnvalue, static const int FractionalBits);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};
