//Programmer: David Szatkowski
//Purpose: exprtk_parse() header file
//Filename: "exprtk_parse.h"


#ifndef EXPRTK_PARSE_H_INCLUDED
#define EXPRTK_PARSE_H_INCLUDED

#include <cstdio>
#include <string>
#include <iostream>
#include "exprtk.hpp"

double exprtk_parse(std::string expression_string)
{
   typedef exprtk::symbol_table<double> symbol_table_t;
   typedef exprtk::expression<double>     expression_t;
   typedef exprtk::parser<double>             parser_t;

   symbol_table_t symbol_table;
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

	double y = expression.value();
	return y;
}

float exprtk_parse_float(std::string expression_string)
{
   typedef exprtk::symbol_table<float> symbol_table_t;
   typedef exprtk::expression<float>     expression_t;
   typedef exprtk::parser<float>             parser_t;

   symbol_table_t symbol_table;
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

	float y = expression.value();
	return y;
}

long double exprtk_parse_long(std::string expression_string)
{
   typedef exprtk::symbol_table<long double> symbol_table_t;
   typedef exprtk::expression<long double>     expression_t;
   typedef exprtk::parser<long double>             parser_t;

   symbol_table_t symbol_table;
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

	long double y = expression.value();
	return y;
}

#endif // EXPRTK_PARSE_H_INCLUDED
