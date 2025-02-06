#ifndef CREATE_MODERATOR_SOLUTION_HPP
#define CREATE_MODERATOR_SOLUTION_HPP

#include "ModeratorSolution.h"

template<typename Tcreator>
decltype(auto) ModeratorSolution<Tcreator>::create()
{
    auto creator = Tcreator();
    auto moderator = creator.createModerator();

    return moderator;
}

#endif // CREATE_MODERATOR_SOLUTION_HPP
