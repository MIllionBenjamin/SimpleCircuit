//
//  NotGate.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "NotGate.hpp"
NotGate::NotGate(): Gate()
{
    
}
NotGate::NotGate(string _name): Gate(_name)
{
    setGraph("N");
}
NotGate::~NotGate()
{
    
}
void NotGate::compute()
{
    if(in[0]==1)
        out=0;
    else
        out=1;
}
