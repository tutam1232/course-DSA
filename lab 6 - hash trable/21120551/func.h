#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#define SIZE 2000
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Company
{
	string name;
	string tax_code;
	string address;
};