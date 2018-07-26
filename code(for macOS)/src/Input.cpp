//
//  Input.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Input.hpp"

Input::Input(): Gate()
{
    
}
Input::Input(string _name, int value): Gate(_name)
{
    if(value!=1&&value!=0)
        throw value;
    out=value;
    in[1]=value;
    in[0]=value;
    setGraph(_name);
}
Input::~Input()
{
    
}
void Input::compute()
{
    
}
