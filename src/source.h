/*
 * Objects representing source code character streams.
 */

#pragma once

#include <memory>
#include <string>

namespace ccscript
{

/**
 * Interface: source
 *
 * Specifices the minimal interface for an object acting as a provider
 * of CCScript source code.
 */
class source
{
public:
    /// Return curent character and advance
    virtual char next() = 0;

    /// Return current line number
    virtual size_t line() const = 0;

    /// Return current column number
    virtual size_t column() const = 0;

    /// Return true if another call to next() is erroneous
    virtual bool eof() const = 0;

    virtual ~source() { }
};

/**
 * Creates a CCScript source from a file.
 */
std::unique_ptr<source> file(std::string const&);

/**
 * Creates a CCScript source from a string.
 */
std::unique_ptr<source> str(std::string const&);



}
