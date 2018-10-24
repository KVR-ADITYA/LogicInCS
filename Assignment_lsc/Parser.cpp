#include<iostream>
#include<stack>
#include<string>
#include "main.cpp"
using namespace std;
class Node
{
    char p;
    Node left;
    Node right;
    Node (char p)
    {
        this.p=p;
    }
};
int main()
{
    string pf=main2();
    stack<Node> sta;
    for(int i=0;i<pf.length();i++)
    {
        Node node(pf[i]);
        if(!isOperator(pf[i]))
        {
            sta.push(node);
        }
        else if(isOperator(pf[i]) &&pf[i]!='~')
        {
            node.right = sta.pop();
            node.left  = sta.pop();
            sta.push(node);
        }
        else if(pf[i]!='~')
        {
            node.right = sta.pop();
            sta.push(node);
        }
    }
    return 0;
}
