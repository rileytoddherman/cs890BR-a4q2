#ifndef __CSP__
#define __CSP__

#include <vector>
#include "domain.h"

class CSP
{
private:
    std::vector<Domain *> domains;
    std::vector<int> values;

    int count_all_for_index(unsigned int index)
    {
        int count = 0;
        for (unsigned int i = 0; i < values.size(); i++)
        {
            if (values[i] == index)
            {
                count++;
            }
        }
        return count;
    }

public:
    CSP(std::vector<Domain *> domains_in)
    {
        domains = domains_in;
        values = *(new std::vector<int>(domains_in.size()));
        for (unsigned int i = 0; i < values.size(); i++)
        {
            values[i] = INT16_MIN;
        }
    }

    CSP &operator=(const CSP &other)
    {
        if (this != &other)
        {
            this->domains = other.domains;
            this->values = other.values;
        }
        return *this;
    }

    ~CSP()
    {
        for (std::vector<Domain *>::const_iterator it = domains.begin(); it != domains.end();)
        {
            Domain *tmp = (*it);
            ++it;
            delete tmp;
        }
    }

    bool is_consistent(unsigned int index, int value)
    {
        return value == count_all_for_index(index);
    }

    bool is_consistent()
    {
        for (unsigned int i = 0; i < values.size(); i++)
        {
            if (!is_consistent(i, values[i]))
            {
                return false;
            }
        }
        return true;
    }

    void set_value(unsigned int index, int value)
    {
        values[index] = value;
    }

    void reset_value(unsigned int index) {
        values[index] = INT16_MIN;
    }

    int num_variables()
    {
        return values.size();
    }

    std::vector<int> get_values()
    {
        return values;
    }

    std::vector<Domain *> get_domains()
    {
        return domains;
    }

    bool all_assigned() {
        for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it) {
            if (*it == INT16_MIN) {
                return false;
            }
        }
        return true;
    }
};

#endif