using namespace std;
#include<stack>
#include<string>
#include<iostream>
int bracketMatcher(string s,int i)
{
    int j=i+1;
    while(s[j]!=')')
    {
        if(s[j]=='(')
        {
            j=bracketMatcher(s,j);
        }
        j++;
    }
    return j;
}
bool isOperator(char i)
{
    int j=false;

    switch(i)
    {
    case 'V':
    case '^':
    case '>':
    case '~':
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

    return (x_weight>=y_weight)?1:0 ;
}
string infixToPostfix(string s)
{
    stack<char> st;
    stack<char> neg;
    string pf="";
    stack<unsigned> j;
    for (unsigned i=0;i<s.length();i++)
    {
        if(!isOperator(s[i]))
     {
         pf+=s[i];
     }
     if(!j.empty() && i==j.top()+1)
     {
         pf+='~';
         j.pop();
     }
        if(!neg.empty())
        {
            pf+=neg.top();
            neg.pop();
        }
        if(s[i]=='~' && s[i+1]!='(')
        {
            neg.push(s[i]);
        }
        if(s[i]=='~' && s[i+1]=='(')
        {
            int k=i+1;
            j.push(bracketMatcher(s,k));

        }

     if(isOperator(s[i]) && s[i]!='~')
     {
         if(!st.empty())
         {
             while(st.top()!='('&& higherPrecedence(st.top(),s[i]) && s[i]!='(' )
             {
                 pf+=st.top();
                 st.pop();
             }
             if(!higherPrecedence(st.top(),s[i]))
             {
                 st.push(s[i]);

             }
             if(s[i]=='(')
             {
                 st.push(s[i]);
             }
             if(s[i]==')'&& st.top()!='(')
             {
                 pf+=st.top();
                 st.pop();
                 st.pop();
             }
             if(s[i]==')'&& st.top()=='(')
             {
                 st.pop();
             }
         }
         else
         {
             st.push(s[i]);
         }
     }
    }
    st = stack<char>();

    return pf;
}

string main2()
{
    string s;
    cout <<"enter infix formula"<<endl;
    getline(cin,s);
    string pf;
    pf=infixToPostfix(s);
    cout<<pf;
    return pf;
}
