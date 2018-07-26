//
//  AndGate.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef AndGate_hpp
#define AndGate_hpp

#include "Gate.hpp"

class AndGate: public Gate
{
public:
    AndGate();
    AndGate(string _name);
    ~AndGate();
    virtual void compute();
};

#endif /* AndGate_hpp */
