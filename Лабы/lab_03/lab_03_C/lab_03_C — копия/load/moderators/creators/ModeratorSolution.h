#ifndef CREATE_MODERATOR_SOLUTION_H
#define CREATE_MODERATOR_SOLUTION_H

#include <memory>

template<typename Tcreator>
class ModeratorSolution
{
public:
    decltype(auto) create();
};

#include "ModeratorSolution.hpp"

#endif // CREATE_MODERATOR_SOLUTION_H
