#ifndef __DOMAIN__
#define __DOMAIN__

#include "empty_domain_exception.h"
#include <set>

class Domain
{
private:
    std::set<int> values;

public:
    Domain()
    {
    }

    void set_values(const std::set<int> values_in)
    {
        std::copy(values_in.begin(), values_in.end(), std::inserter(values, values.begin()));
    }

    Domain &operator=(const Domain &other)
    {
        if (this != &other)
        {
            for (std::set<int>::const_iterator it = other.values.begin(); it != other.values.end(); ++it)
            {
                values.insert(*it);
            }
        }
        return *this;
    }

    ~Domain()
    {
    }

    bool is_empty()
    {
        return values.empty();
    }

    std::set<int> get_domain()
    {
        return values;
    }
};

#endif