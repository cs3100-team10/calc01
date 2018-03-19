
#ifndef EXPRTK_PARSE_H_INCLUDED
#define EXPRTK_PARSE_H_INCLUDED

#include <string>

using std::string;

double exprtk_parse(string expression_string);
float exprtk_parse_float(string expression_string);
long double exprtk_parse_long(string expression_string);

#endif // EXPRTK_PARSE_H_INCLUDED
