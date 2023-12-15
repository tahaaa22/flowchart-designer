
#include "HelperFn.h"
#include <iostream>
using namespace std;
bool IsAlpha(char c) {
	return((c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'));
}

bool IsValue(string input)
{
	int size = input.size();
	int count = 0;
	int dot = 0;
	bool digit = false;
	if (input[count] == '-')
		count++;
	while (isdigit(input[count]) && count < size) {
		count++;
		digit = true;
	}
	if (input[count] == '.') {
		count++;
		dot++;
	}
	while (isdigit(input[count]) && count < size) {
		count++;
		digit = true;
	}
	return (digit && count == size && dot == 1);

	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function
}

bool IsVariable(string input)
{
	int sl = 0;
	int size = input.size();

	
	if (IsAlpha(input[sl]) || input[sl] == '_')
	{
		sl++;
	}
	else
		return false;
	bool variable = false;
	for (sl; sl<size; sl++) {
		if (IsAlpha(input[sl]) || input[sl] == '_' || isdigit(input[sl])) {
			variable = true;
		}
		else
		{
			return false;
		}
	}
	return variable;
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function
}

OpType ValueOrVariable(string input)
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
