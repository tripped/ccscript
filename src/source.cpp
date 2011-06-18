// source.cpp
//
#include "source.h"

#include <fstream>

namespace ccscript
{

/**
 * Class: stringsource
 *
 * Provides CCScript source code from std::string objects.
 */
class stringsource : public source
{
public:
    stringsource(std::string const& str)
        : str_(str), pos_(0), line_(0), column_(0)
    {
    }

    char next()
    {
        char n = str_.at(pos_++);

        ++column_;

        // TODO: proper newline handling
        if (n == '\n') {
            ++line_;
            column_ = 0;
        }
         
        return n;
    }

    size_t line() const { return line_; }
    size_t column() const { return column_; }
    bool eof() const { return pos_ >= str_.length(); }

private:
    std::string str_;
    size_t      pos_;
    size_t      line_;
    size_t      column_;
};

/**
 * Class: filesource
 *
 * Provides CCScript source code from a file on disk.
 */
class filesource : public source
{
public:
    explicit filesource(std::string const&);
    char next();

private:
    std::ifstream infile_;
};


/*std::unique_ptr<source> file(std::string const& filename)
{
    return std::unique_ptr<source>(new filesource(filename));
}*/


std::unique_ptr<source> str(std::string const& string)
{
    return std::unique_ptr<source>(new stringsource(string));
}


}

