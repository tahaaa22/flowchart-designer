
#include "HelperFn.h"
#include <iostream>
using namespace std;

bool IsValue (string input)
{
	int l = 0;
	if (input[l]) {
		l++;
	}
	bool value = false;
	int j = 0;
	if (j < l && (input[j] == '-' || input[j] >= 49 || input[j] <= 57)) {
		j++;
	}
	while (true) {
		if (j < l && (input[j] >= 49 || input[j] <= 57 || input[j] == '.')) {
			j++;
			if (j < l && (input[j] >= 49 || input[j] <= 57 || input[j] == '.')) {
				j++;
				value = true;
			}
		}
		else if (input[j] <= 49 || input[j] >= 57 || input[j] != '.') {
			value = false;
			break;
		}
	}
	if (value)
		return true;

	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function

	return false;
}

bool IsVariable (string input)
{
	int sl = 0;
	if (input[sl] >= 'a' && input[sl] <= 'z' || input[sl] >= 'A' && input[sl] <= 'Z' || input[sl] == '_')
	{
		sl++;
	}
	bool variable = false;
	while (1) {
		if (input[sl] >= 'a' && input[sl] <= 'z' || input[sl] >= 'A' && input[sl] <= 'Z' || input[sl] == '_') {
			sl++;
			variable = true;
		}
		else
		{
			variable = false;
			break;
		}
	}
	if (variable)
		return true;
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function

	return false;
}

OpType ValueOrVariable (string input)
{
	if (IsValue) 
		return VALUE_OP;
	if (IsVariable) 
		return VARIABLE_OP;
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	return INVALID_OP;
}
