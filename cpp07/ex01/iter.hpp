/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:12:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/27 16:22:02 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <class T, class Func>
void    iter(T* array, int arrayLength, Func func);\

template <class T, class Func>
void    iter(const T* array, int arrayLength, Func func);\

#endif