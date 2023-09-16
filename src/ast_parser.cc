#include <halstead/ast_parser.h>

#define OPERATOR_ARR_SIZE 10

char operatorlist[10][3];

void push_to_list(std::string item, std::string operator_list) {

}


std::string[] get_operators(std::string codeline) {
	char operators[][10] = {
	        "\\+",
	        "\\-",
	        "\\*",
	        "\\/",
	        "%",
	        "\\+\\+",
	        "\\-\\-",
	        "==",
	        "!=",
	        ">",
	        "<",
	        ">=",
	        "<=",
	        "\\&\\&",
	        "\\|\\|",
	        "!",
	        "=",
	        "\\+=",
	        "\\-=",
	        "\\*=",
	        "\\/=",
	        "%=",
	        "\\&",
	        "\\|",
	        "\\^",
	        "\\~",
        	"<<",
	        ">>",
	        "\\?:",
	        "\\&",
        	"\\*"
    	};


	// printf("Visualizing the code line : %s\n",codeline);
	int arr_size = (sizeof(operators) / sizeof (operators[0]));


	for (int i = 0 ; i < arr_size; i++) {
		printf("Printing the arr item : :%s\n",operators[i]);


		char *pattern = (char*)malloc(sizeof(char)* 400);
		sprintf(pattern,".*\\(%s\\).*",operators[i]);
		regex_t reegex;	
		int res = regcomp(&reegex,pattern,REG_ICASE);		

		if (res == 0) {
			regmatch_t regmatch[2];
			size_t nm = 2;
			int res2 = regexec(&reegex,codeline,nm,regmatch,0);
			if (res2 == 0) {
				char buffer [10];
				sprintf(buffer, "%.*s", regmatch[1].rm_eo - regmatch[1].rm_so, &codeline[regmatch[1].rm_so]);

				printf("printing the detected expression : %.*s for line : %s\n",regmatch[1].rm_eo - regmatch[1].rm_so, &codeline[regmatch[1].rm_so],codeline);
			}
			
		} 
		free(pattern);
	}

}

Operator* get_operator_list(std::string filename) {
	FILE* file = fopen(filename,"r");
//	char* buffer = (char*)malloc(sizeof(char)*1024);
//	char* content = (char*) malloc(sizeof(char)*5003);
	Operator* operator_arr = (Operator*)malloc(sizeof(Operator)*10); // defing the array of size 10
	while (fgets(buffer,1023,file) > 0) {
		get_operators(buffer);
		strcat(content,buffer);
	}


	fclose(file);
	free(buffer);
	free(content);




	return NULL;
}

Operand* get_operand_list(std::string filename) {
	FILE* file = fopen(filename,"r");
//	char* buffer = (char*)malloc(sizeof(char)*1024);
	free(buffer); // garbadge collection



	return NULL;
}
