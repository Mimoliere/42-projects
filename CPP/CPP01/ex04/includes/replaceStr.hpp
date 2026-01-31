/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStr.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:37 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:40 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACESTR_HPP
#define REPLACESTR_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

int			replaceStr(char *argv[]);
void		modifiedFile(std::ifstream& file, std::ofstream& outfile, std::string s1, std::string s2);
std::string	getNewName(std::string filename);

#endif
