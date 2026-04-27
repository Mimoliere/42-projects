/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:26:33 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/27 17:30:06 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array() : size_(0), arr_(NULL) {

}

template <typename T>
Array<T>::Array(unsigned int n) {
	arr_ = new T[n];
	size_ = n;
}

template <typename T>
Array<T>::Array(const Array& other) : size_(0), arr_(NULL) {
	*this = other;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] arr_;
		size_ = other.size_;
		arr_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++) {
			arr_[i] = other.arr_[i];
		}
	}

	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] arr_;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= size_)
		throw OutOfBoundsException();

	return (arr_[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= size_)
		throw OutOfBoundsException();

	return (arr_[index]);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (size_);
}
