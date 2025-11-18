/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <fdurban-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:24 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/18 17:29:37 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
class Fixed
{
	private:
		const int	fpvalue;
		int		fractionalBits;
	public:
		Fixed(const int floatingPointInt);
		Fixed(const float floatingPointFloat);
		float	toFloat(void) const;
		int	toInt(void) const;
		std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
};
