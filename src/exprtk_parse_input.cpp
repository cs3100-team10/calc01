//Programmer: David Szatkowski
//Demonstration of how to use exprtk to parse expressions
//

#include <cstdio>
#include <string>
#include <iostream>
#include "exprtk.hpp"


template <typename T>
T parse_expr(std::string expression_string)
{
   typedef exprtk::symbol_table<T> symbol_table_t;
   typedef exprtk::expression<T>     expression_t;
   typedef exprtk::parser<T>             parser_t;

   symbol_table_t symbol_table;
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

	T y = expression.value();
	return y;
}

int main()
{
   std::string expr;
   std::cout << "Input Expression: ";
   std::cin >> expr;
   double x = parse_expr<double>(expr);
   std::cout << "Result: " << x << "\n";
   return 0;
}
