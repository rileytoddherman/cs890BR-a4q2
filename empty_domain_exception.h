#ifndef __EDEX__
#define __EDEX__

#include<exception>

struct EmptyDomainException : std::exception {
    const char* what() const throw() {
        return "Domain is empty!";
    }
};

#endif