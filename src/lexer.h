/*
    Lexy lexy!
*/

#include <string>

namespace ccscript {

struct token
{
    enum type
    {
        NUMBER,
        STRING,
        IDENTIFIER,
        OPERATOR
    } type;

    // Location of token
    int line, col;

    std::string value;
};

class lexer
{
public:

    token next();
};


} // namespace ccscript

