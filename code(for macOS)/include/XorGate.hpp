//
//  XorGate.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef XorGate_hpp
#define XorGate_hpp

#include "Gate.hpp"

class XorGate: public Gate
{
public:
    XorGate();
    XorGate(string _name);
    ~XorGate();
    virtual void compute();
};

#endif /* XorGate_hpp */
