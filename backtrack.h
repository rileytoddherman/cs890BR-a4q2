#ifndef __BACTRACK__
#define __BACTRACK__

#include "csp.h"

class Backtrack
{
private:
    CSP *csp;

    CSP *search_helper(unsigned int j)
    {
        if (csp->all_assigned() && csp->is_consistent())
        {
            return csp;
        }
        std::set<int> domain = csp->get_domains()[j]->get_domain();
        for (std::set<int>::const_iterator it = domain.begin(); it != domain.end(); ++it)
        {
            if (csp->is_consistent(j, *it))
            {
                csp->set_value(j, *it);
                return search_helper((j + 1) % csp->num_variables());
            }
        }
        csp->reset_value(j);
        return search_helper((j + 1) % csp->num_variables());
    }

public:
    Backtrack(CSP *csp_in)
    {
        csp = csp_in;
    }

    ~Backtrack()
    {
        delete csp;
    }

    CSP *search()
    {
        return search_helper(0);
    }
};

#endif