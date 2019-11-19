#pragma once
#include "landbasedtracked.h"
#include "landbasedwheeled.h"
#include <memory>

namespace fp{

class Algorithm{
public:
    Algorithm();
    virtual ~Algorithm();
    void Solve(std::shared_ptr<fp::LandBasedRobot> robot);

};

}

