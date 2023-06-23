#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <regex.h>

struct Operator {
	char* name; // name of the operator
	int id; // id is the role number based on sequential occurance
};

typedef struct Operator Operator;

struct Operand {
	char* name; // name of the operand
	int id; // id is the role number based on sequential occurance
};

typedef struct Operand Operand;

char* get_operator(char* codeline); // for each line of code seraches operators

Operator* get_operator_list(char* filename);
Operand* get_operand_list(char* filename);



