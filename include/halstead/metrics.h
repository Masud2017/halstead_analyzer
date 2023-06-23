#pragma once

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




int get_operator_count(char* filename);
int get_distinct_operator_count(char* filename);
int get_operand_count(char* filename);
int get_distinct_operand_count(char* filename);
