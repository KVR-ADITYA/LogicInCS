#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperator(char i)
{
    int j=false;

    switch(i)
    {
    case 'V':
    case '^':
    case '>':
    case '(':
    case ')':
        j=true;

    }
    return j;
}
int weight(char o)
{
    int weight = -1;
    switch(o)
    {
    case '>':
        weight=0;
    case '^':
    case 'V':
        weight=1;


    }
    return weight;
}
int higherPrecedence(char x,char y)
{
    int x_weight = weight(x);
    int y_weight = weight(y);
    return (x_weight>y_weight)?1:0 ;
}
string infixToPostfix(string s)
{
    stack<char> st;
    string pf="";
    for (unsigned i=0;i<s.length();i++)
    {
     if(isOperator(s[i]))
     {
         if(!st.empty() && (s[i]!= '(' || higherPrecedence(st.top(),s[i])))
         {
          pf+=st.top();
          st.pop();
          st.push(s[i]);

         }
        else if(!st.empty() && s[i]==')')
        {
            pf.push_back(st.top());
            st.pop();
            st.pop();
        }
        else if(st.empty() || s[i]=='(')
        {
            st.push(s[i]);

        }
     }
     if(!isOperator(s[i]))
     {
         pf.push_back(s[i]);
     }

    }
    st = stack<char>();
    return pf;
}

int main()
{
    string s;
    cout <<"enter infix formula"<<endl;
    getline(cin,s);
    string pf;
    pf=infixToPostfix(s);
    cout<<pf;
    return 0;
}
