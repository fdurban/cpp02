/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdurban- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:57:24 by fdurban-          #+#    #+#             */
/*   Updated: 2025/11/17 18:06:36 by fdurban-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};
