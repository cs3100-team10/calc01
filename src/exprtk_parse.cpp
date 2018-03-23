//Programmer: David Szatkowski
//Purpose: exprtk_parse() header file
//Filename: "exprtk_parse.cpp"

#include "exprtk_parse.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <exprtk/exprtk.hpp>

using std::string;

double exprtk_parse(string expression_string)
{
   typedef exprtk::symbol_table<double> symbol_table_t;
   typedef exprtk::expression<double>     expression_t;
   typedef exprtk::parser<double>             parser_t;

   symbol_table_t symbol_table;
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser; // the two lines below remove spaces from the string
   expression_string.erase(remove_if(expression_string.begin(), 
     expression_string.end(), isspace), expression_string.end());
   parser.compile(expression_string,expression);

	double y = expression.value();
	return y;
}
