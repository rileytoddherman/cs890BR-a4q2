/*
 * Riley Herman 200352833
 * Assignment 4 Question 2
*/

#include <iostream>
#include "backtrack.h"

static const int NUM_VARIABLES = 10;
static const int DOMAIN_SIZE = 10;

int main() {
    std::set<int> _default_domain_set;
    for (int i = 0; i < DOMAIN_SIZE; i++) {
        _default_domain_set.insert(i);
    }
    Domain* _default_domain = new Domain();
    _default_domain->set_values(_default_domain_set);
    std::vector<Domain*> _domains = *(new std::vector<Domain*>(NUM_VARIABLES));
    for (unsigned int i = 0; i < _domains.size(); i++) {
        _domains[i] = new Domain();
        _domains[i]->set_values(_default_domain->get_domain());
    }
    CSP* _csp = new CSP(_domains);
    Backtrack* backtrack = new Backtrack(_csp);
    CSP *solution = backtrack->search();
    if (solution == nullptr) {
        std::cout << "No solution!!" << std::endl;
        return 1;
    }
    std::cout << "Solution: ";
    std::vector<int> result = solution->get_values();
    for (std::vector<int>::const_iterator it = result.begin(); it != result.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    return 0;
}