#include "main.cpp"
#include<vector>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Tree
{
    Tree *l;
    Tree *r;
    char p;
    string s;
    subTree(string s,Tree t)
    {
        int i = s.length();
        t.p = s[i-1]
        if(!isOperator(t.p))
        {
            t.*l=nullptr;
            t.*r=nullptr;
        }
        if(isOperator(t.p)&&t.p!='~')
        {
            if(isOperator(s[i-2]))
            {
                subTree(s.pop_back(),r);
            }
            else
            {
                subTree(s.pop_back(),l);
            }
        }
        if(t.p=='~')
        {
            t.*l=nullptr;
            subTree(s.pop_back(),r);
        }
    }

};

int main()
{
    cout<<higherPrecedence('(','^');
    return 0;
}
