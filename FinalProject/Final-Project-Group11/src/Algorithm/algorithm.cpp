#include "algorithm.h"

fp::Algorithm::Algorithm(){
}

fp::Algorithm::~Algorithm(){
}

void fp::Algorithm::Solve(std::shared_ptr<fp::LandBasedRobot> robot){
    std::cout << robot->GetDirection() <<std::endl;
}


