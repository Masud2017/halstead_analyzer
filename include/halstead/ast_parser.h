#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <regex.h>
#include <iostream>

struct Operator {
	std::string name; // name of the operator
	int id; // id is the role number based on sequential occurance
};

typedef struct Operator Operator;

struct Operand {
	std::string name; // name of the operand
	int id; // id is the role number based on sequential occurance
};

typedef struct Operand Operand;

std::string get_operator(std::string codeline); // for each line of code seraches operators

Operator* get_operator_list(std::string filename);
Operand* get_operand_list(std::string filename);



