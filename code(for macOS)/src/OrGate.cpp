//
//  OrGate.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "OrGate.hpp"

OrGate::OrGate(): Gate()
{
    
}
OrGate::OrGate(string _name): Gate(_name)
{
    setGraph("O");
}
OrGate::~OrGate()
{
    
}
void OrGate::compute()
{
    out=in[0]+in[1];
    if(out>1)
        out=1;
}
