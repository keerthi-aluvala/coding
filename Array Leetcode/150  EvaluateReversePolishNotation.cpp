/* 150. Evaluate Reverse Polish Notation 

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, 
and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/


class Solution {
public:
    int precedence(string ch)
    {
        if(ch=="+" || ch=="-")
            return 1;
        else if(ch=="*" || ch=="/")
            return 2;
        return 0;
    }
    bool isoper(string s1)
    {
        if(s1=="+" || s1=="-" || s1=="*" || s1=="/")
            return true;
        else 
            return false;
    }
    int evalRPN(vector<string>& s1) 
    {
        stack<int>s;
        int res;
        for(int i=0; i<s1.size(); i++)
        {
            if(isoper(s1[i]))
            {
                
                    int k1=s.top();
                    s.pop();
                    int k2=s.top();
                    s.pop();
                    if(s1[i]=="+")
                        res=k1+k2;
                    else if(s1[i]=="-")
                        res=k2-k1;
                    else if(s1[i]=="*")
                        res=k1*k2;
                    else
                        res=k2/k1;
                    s.push(res);
                
            }
            else
                s.push(std::stoi(s1[i]));
        }
        res = s.top();
        return res;
    }
};


