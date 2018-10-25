using namespace std;
#include<stack>
#include<string>
#include<iostream>
/**
*\brief a function for checking if number of open braces equal to closing braces
*\param a string and int are given as inputs
*\return returns a value j which is the index of the corresponding closing bracket
*/
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
/**
*\brief a function to check if the given character is a operator
*\param a character is given as input
*\return returns true if the character is an operator('^','V','^','(',')','~')
*/
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
/**
*\brief assigns a weight to character
*\param takes a character(o) as input
*\return returns a variable(weight) in which corresponding priority of the character is stored
*/
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
/**
*\brief checks which operator has higher priority
*\param takes two characters x&y as input
*\return returns 1 if x has higher or equal priority and 0 if y has higher priority
*/
int higherPrecedence(char x,char y)
{
    int x_weight = weight(x);
    int y_weight = weight(y);

    return (x_weight>=y_weight)?1:0 ;
}
/**
*\brief a function to convert infix to postfix
*\param takes the infix string as input(s)
*\return returns the post fix string
*the operators are separated from operands and saved temporarily in the stack while the just succeeding and preceding operands are moved into a new array for printing postfix.
*while the operators enter the stack priority order is strictly followed and simultaneously corresponding operands are moved into the array. operands of same priority are not allowed to be present simultaneously hence the preceding operator jumps from stack to postfix array.
*lower priority operators are allowed after higher ones but not the reverse way round so lower priority operator is sent into postfix array. following these steps till the last of characters will give the required postfix order.
*/
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
/**
*\brief this is the function which converts the infix expression to postfix and passes it to the next file
*\param no in put parameters
*\return it returns the postfix expression which is in turn used in the next file
*/
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
