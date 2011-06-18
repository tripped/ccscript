/*
    Lexy lexy!
*/

#include <string>
#include <memory>

namespace ccscript {

class source;

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

    // Lexical value of the token
    std::string value;
};

class lexer
{
public:
    explicit lexer(std::unique_ptr<source>);

    token next();

private:
    std::unique_ptr<source> source_;
};

} // namespace ccscript

