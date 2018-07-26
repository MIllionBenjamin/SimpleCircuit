//
//  Gate.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/7.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Gate_hpp
#define Gate_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Gate
{
private:
    string name;
    string graph;
    bool output;
    bool infull;
    map<string, vector<Gate*> > connection;
public:
    int in[2];
    int out;
    Gate();
    Gate(string _name);
    ~Gate();
    string theGraph();
    void setGraph(string g);
    void allSetIn();
    virtual void connect(Gate* p, int where);
    virtual void compute()=0;
    void operator= (Gate& another);
    friend ostream& operator<< (ostream& out, Gate* p);
};


#endif /* Gate_hpp */
