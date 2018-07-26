//
//  Input.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "Gate.hpp"

class Input: public Gate
{
public:
    Input();
    Input(string _name, int value=1);
    ~Input();
    virtual void compute();
};

#endif /* Input_hpp */
