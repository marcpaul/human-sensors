#ifndef Printable_h
#define Printable_h

#include "Printx.h"

class Printx;

class Printable
{
  public:
    virtual size_t printTo(Printx &p) const = 0;
};

#endif

