#ifndef REPLACESTR_HPP
#define REPLACESTR_HPP

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

int			replaceStr(char *argv[]);
void		modifiedFile(std::ifstream& file, std::ofstream& outfile, std::string s1, std::string s2);
std::string	getNewName(std::string filename);

#endif
