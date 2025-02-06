#ifndef MANAGER_SOLUTION_HPP
#define MANAGER_SOLUTION_HPP

#include "ManagerSolution.h"

template <Derivative<BaseManagerCreator> Tcreator>
    requires NotAbstractClass<Tcreator>
auto ManagerSolution<Tcreator>::create() -> decltype(auto)
{
    auto creator = Tcreator();
    auto manager = creator.createManager();

    return manager;
}

#endif // MANAGER_SOLUTION_HPP
