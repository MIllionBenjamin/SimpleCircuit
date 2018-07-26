1.	向程序输入目标电路的输入

2.	向程序输入目标电路所需的逻辑门

3.	向程序输入对目标电路的描述

4.	示例输入
        实现全加器：（现默认输入0，0，1，可修改）
A 0
B 0
C 1
END
AndGate 1
AndGate 2
AndGate 3
XorGate 1
XorGate 2
OrGate 1
OrGate 2
END
Input A to XorGate 1
Input B to XorGate 1
XorGate 1 to XorGate 2
Input C to XorGate 2
Input A to AndGate 1
Input B to AndGate 1
Input A to AndGate 2
Input C to AndGate 2
Input B to AndGate 3
Input C to AndGate 3
AndGate 1 to OrGate 1
AndGate 2 to OrGate 1
OrGate 1 to OrGate 2
AndGate 3 to OrGate 2
END
XorGate 2
OrGate 2
END

