#ifndef MANAGER_SOLUTION_H
#define MANAGER_SOLUTION_H

#include "ClassConcept.h"
#include "BaseManagerCreator.h"

template <Derivative<BaseManagerCreator> Tcreator>
    requires NotAbstractClass<Tcreator>
class ManagerSolution
{
public:
    auto create() -> decltype(auto);
};

#include "ManagerSolution.hpp"

#endif // MANAGER_SOLUTION_H
