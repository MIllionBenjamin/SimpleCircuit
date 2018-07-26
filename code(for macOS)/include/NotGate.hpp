//
//  NotGate.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef NotGate_hpp
#define NotGate_hpp

#include "Gate.hpp"

class NotGate: public Gate
{
public:
    NotGate();
    NotGate(string _name);
    ~NotGate();
    virtual void compute();
};

#endif /* NotGate_hpp */
