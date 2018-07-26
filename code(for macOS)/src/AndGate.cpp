//
//  AndGate.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "AndGate.hpp"

AndGate::AndGate(): Gate()
{
    
}
AndGate::AndGate(string _name): Gate(_name)
{
    setGraph("&");
}
AndGate::~AndGate()
{
    
}
void AndGate::compute()
{
    out=in[0]*in[1];
}
