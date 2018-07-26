//
//  Gate.cpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/7.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "Gate.hpp"
Gate::Gate()
{
    name='\0';
    graph='\0';
    in[0]=-1;
    in[1]=-1;
    out=-1;
    output=false;
    infull=false;
}
Gate::Gate(string _name)
{
    name=_name;
    in[0]=-1;
    in[1]=-1;
    out=-1;
    output=false;
    infull=false;
}
Gate::~Gate()
{
    
}
string Gate::theGraph()
{
    return graph;
}
void Gate::setGraph(string s)
{
    graph=s;
}
void Gate::connect(Gate* p, int where)
{
    if(where==1)
        connection["after"][0]=p;
    else
        if(infull==true)
            throw infull;
        else
        {
            connection["before"].push_back(p);
            if(connection["before"].size()==2)
                infull=true;
        }
}
void Gate::allSetIn()
{
   if(connection["before"][0]->out==-1)
       connection["before"][0]->allSetIn();
    
    in[0]=connection["before"][0]->out;
   if(connection["before"][1]->out==-1)
       connection["before"][1]->allSetIn();

    in[1]=connection["before"][1]->out;
    if(in[0]!=-1&&in[1]!=-1)
        compute();
}
void Gate::operator= (Gate& another)
{
    this->name=another.name;
    this->graph=another.graph;
    this->output=another.output;
    this->connection=another.connection;
    this->in[0]=another.in[0];
    this->in[1]=another.in[1];
    this->output=another.output;
    this->out=another.out;
}
ostream& operator<< (ostream& out, Gate* p)
{
    out<<p->theGraph();
    return out;
}
