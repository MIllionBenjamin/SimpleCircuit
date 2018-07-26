//
//  Run.hpp
//  [Project] Simple Circuit
//
//  Created by MillionBenjamin on 2018/7/7.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Run_hpp
#define Run_hpp

#include "Input.hpp"
#include "AndGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "NotGate.hpp"

void Run()
{
    Input input[100];
    int iptNum = 0;
    map<string, Input> inputMap;
    AndGate andgate[100];
    int adgNum = 0;
    map<string, AndGate> andgateMap;
    map<string, OrGate> orgateMap;
    map<string, XorGate> xorgateMap;
    map<string, NotGate> notgateMap;

    //Input
    cout << "Please Enter the Input:" << endl;
    cout << "(Format:'name' 'value'; Example:A 1; Input \"END\" to finish)" << endl;
    string InputName;
    int value;
    while (true)
    {
        cin >> InputName;
        if (InputName != "END")
        {
            try
            {
                cin >> value;
                Input ipt(InputName, value);
                input[iptNum] = ipt;
                iptNum++;
                inputMap[InputName] = ipt;
            }
            catch (int)
            {
                cout << "Error: The Value of an Input must be 0 or 1." << endl;
                exit(-1);
            }
        }
        else
        {
            cout << "Finish Entering the Input." << endl;
            break;
        }
    }

    //Gate
    cout << "Please Enter the Gate:" << endl;
    cout << "(Format:'type' 'name'; Example:AndGate 1; Input \"END\" to finish)" << endl;
    string GateType;
    string GateName;
    string wholename;
    while (true)
    {
        cin >> GateType;
        if (GateType != "END")
        {
            try
            {
                if (GateType == "AndGate")
                {
                    cin >> GateName;
                    wholename = GateType + GateName;
                    AndGate adgt(wholename);
                    andgate[adgNum] = adgt;
                    adgNum++;
                    andgateMap[wholename] = adgt;
                }
                else if (GateType == "OrGate")
                {
                    cin >> GateName;
                    wholename = GateType + GateName;
                    OrGate orgt(wholename);
                    orgateMap[wholename] = orgt;
                }
                else if (GateType == "XorGate")
                {
                    cin >> GateName;
                    wholename = GateType + GateName;
                    XorGate xorgt(wholename);
                    xorgateMap[wholename] = xorgt;
                }
                else if (GateType == "NotGate")
                {
                    cin >> GateName;
                    wholename = GateType + GateName;
                    NotGate notgt(wholename);
                    notgateMap[wholename] = notgt;
                }
                else
                    throw GateType;
            }
            catch (string)
            {
                cout << "Error: This type of Gate does not exsit. " << endl;
                exit(-1);
            }
        }
        else
        {
            cout << "Finish Entering the Gate." << endl;
            break;
        }
    }

    //Curcuit
    cout << "Please describe the Circuit:" << endl;
    cout << "(Format:'type' 'name' to 'type' 'name'; Eaxmple: Input A to AndGate 1; Input \"END\" to finish)" << endl;
    string befType, befName, befwholeName;
    string aftType, aftName, aftwholeName;
    string to;
    while (true)
    {
        cin >> befType;
        if (befType != "END")
        {
            try
            {
                cin >> befName;
                cin >> to;
                cin >> aftType;
                cin >> aftName;
                befwholeName = befType + befName;
                aftwholeName = aftType + aftName;
                if (aftType == "AndGate")
                {
                    if (befType == "Input")
                        andgateMap[aftwholeName].connect(&inputMap[befName], 0);
                    else if (befType == "AndGate")
                        andgateMap[aftwholeName].connect(&andgateMap[befwholeName], 0);
                    else if (aftType == "OrGate")
                        andgateMap[aftwholeName].connect(&orgateMap[befwholeName], 0);
                    else if (aftType == "XorGate")
                        andgateMap[aftwholeName].connect(&xorgateMap[befwholeName], 0);
                    else if (aftType == "NotGate")
                        andgateMap[aftwholeName].connect(&notgateMap[befwholeName], 0);
                }
                else if (aftType == "OrGate")
                {
                    if (befType == "Input")
                        orgateMap[aftwholeName].connect(&inputMap[befName], 0);
                    else if (befType == "AndGate")
                        orgateMap[aftwholeName].connect(&andgateMap[befwholeName], 0);
                    else if (aftType == "OrGate")
                        orgateMap[aftwholeName].connect(&orgateMap[befwholeName], 0);
                    else if (aftType == "XorGate")
                        orgateMap[aftwholeName].connect(&xorgateMap[befwholeName], 0);
                    else if (aftType == "NotGate")
                        orgateMap[aftwholeName].connect(&notgateMap[befwholeName], 0);
                }
                else if (aftType == "XorGate")
                {
                    if (befType == "Input")
                        xorgateMap[aftwholeName].connect(&inputMap[befName], 0);
                    else if (befType == "AndGate")
                        xorgateMap[aftwholeName].connect(&andgateMap[befwholeName], 0);
                    else if (aftType == "OrGate")
                        xorgateMap[aftwholeName].connect(&orgateMap[befwholeName], 0);
                    else if (aftType == "XorGate")
                        xorgateMap[aftwholeName].connect(&xorgateMap[befwholeName], 0);
                    else if (aftType == "NotGate")
                        xorgateMap[aftwholeName].connect(&notgateMap[befwholeName], 0);
                }
                else if (aftType == "NotGate")
                {
                    if (befType == "Input")
                    {
                        notgateMap[aftwholeName].connect(&inputMap[befName], 0);
                        notgateMap[aftwholeName].connect(&inputMap[befName], 0);
                    }
                    else if (befType == "AndGate")
                    {
                        notgateMap[aftwholeName].connect(&andgateMap[befwholeName], 0);
                        notgateMap[aftwholeName].connect(&andgateMap[befwholeName], 0);
                    }
                    else if (aftType == "OrGate")
                    {
                        notgateMap[aftwholeName].connect(&orgateMap[befwholeName], 0);
                        notgateMap[aftwholeName].connect(&orgateMap[befwholeName], 0);
                    }
                    else if (aftType == "XorGate")
                    {
                        notgateMap[aftwholeName].connect(&xorgateMap[befwholeName], 0);
                        notgateMap[aftwholeName].connect(&xorgateMap[befwholeName], 0);
                    }
                    else if (aftType == "NotGate")
                    {
                        notgateMap[aftwholeName].connect(&notgateMap[befwholeName], 0);
                        notgateMap[aftwholeName].connect(&notgateMap[befwholeName], 0);
                    }
                }
            }
            catch (bool)
            {
                cout << "Connect Error. " << endl;
                exit(-1);
            }
        }
        else
        {
            cout << "Finish Describe the Circuit." << endl;
            break;
        }
    }

    //Output
    cout << "Confirm the Output:";
    cout << "(Enter the name of the Output Gate; Eaxmple: AndGate 1; Input \"END\" to finish)" << endl;
    int otpt[100];
    int otNum = 0;
    string outputgt;
    string outputname;
    string outputwhole;
    while (true)
    {
        cin >> outputgt;
        if (outputgt != "END")
        {
            cin >> outputname;
            outputwhole = outputgt + outputname;
            if (outputgt == "AndGate")
            {
                andgateMap[outputwhole].allSetIn();
                otpt[otNum] = andgateMap[outputwhole].out;
                otNum++;
            }
            else if (outputgt == "OrGate")
            {
                orgateMap[outputwhole].allSetIn();
                otpt[otNum] = orgateMap[outputwhole].out;
                otNum++;
            }
            else if (outputgt == "XorGate")
            {
                xorgateMap[outputwhole].allSetIn();
                otpt[otNum] = xorgateMap[outputwhole].out;
                otNum++;
            }
            else if (outputgt == "NotGate")
            {
                notgateMap[outputwhole].allSetIn();
                otpt[otNum] = notgateMap[outputwhole].out;
                otNum++;
            }
        }
        else
        {
            cout << "Output is/are";
            for (int i = 0; i < otNum; i++)
                cout << " " << otpt[i];
            cout << endl;
            break;
        }
    }
}

#endif /* Run_hpp */
