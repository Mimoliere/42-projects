/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:52:46 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/23 15:11:54 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data {
	private:
		int	_data;

	public:
		Data(const int data);
		Data(const Data& other);
		Data&	operator=(const Data& other);
		~Data();

		int		get_data() const;
		void	set_data(const int val);

};

#endif
