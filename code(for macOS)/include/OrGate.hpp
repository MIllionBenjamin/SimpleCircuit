//
//  OrGate.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef OrGate_hpp
#define OrGate_hpp

#include "Gate.hpp"

class OrGate: public Gate
{
public:
    OrGate();
    OrGate(string _name);
    ~OrGate();
    virtual void compute();
};

#endif /* OrGate_hpp */
