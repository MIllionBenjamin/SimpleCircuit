//
//  XorGate.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "XorGate.hpp"
XorGate::XorGate(): Gate()
{
    
}
XorGate::XorGate(string _name): Gate(_name)
{
    setGraph("X");
}
XorGate::~XorGate()
{
    
}
void XorGate::compute()
{
    if(in[0]!=in[1])
        out=1;
    else
        out=0;
}
