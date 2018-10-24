#include<iostream>
#include<stack>
#include<string>
#include<malloc.h>
#include "main.cpp"
using namespace std;
class Node
{
    public:
    char p;
    Node* left;
    Node* right;
    Node()
    {

    }
    Node (char x)
    {
        p=x;
    }
};
void printInfix(Node *x)
{
    Node *l;
    Node *r;
    l=(Node*)(malloc(sizeof(Node)));
    r=(Node*)(malloc(sizeof(Node)));
    l=x->left;
    r=x->right;
    if(!isOperator(l->p) && !isOperator(r->p))
    {
        cout<<"("<<l->p << x->p << r->p<<")" ;
        return;
    }
    else if(!isOperator(l->p)&& isOperator(r->p))
    {
        cout<<l->p << x->p ;
        printInfix(r);
    }
    else if(isOperator(l->p)&& !isOperator((r->p)))
    {
        printInfix(l);
        cout<<x->p;
        cout<<r->p;
    }
    else if(isOperator(l->p)&& isOperator(r->p))
    {
        printInfix(l);
        cout<<x->p;
        printInfix(r);
    }

}
int main()
{
    string pf=main2();
    stack<Node*> sta;
    for(int i=0;i<pf.length();i++)
    {
        Node *n;
        n=(Node*)(malloc(sizeof(Node)));
        n->p=(pf[i]);
        if(!isOperator(pf[i]))
        {
            n->right=NULL;
            n->left=NULL;
            sta.push(n);
        }
        else if(isOperator(pf[i]) &&pf[i]!='~')
        {
            n->right = (sta.top());
            sta.pop();
            n->left = (sta.top());
            sta.pop();
            sta.push(n);
        }
        else if(pf[i]=='~')
        {
            n->right =(sta.top());
            sta.pop();
            sta.push(n);
            n->left->p=' ';
        }
    }
    cout<<"\n\n";
    Node *x;
    x=sta.top();
    cout<<"(";
    printInfix(x);
    cout<<")";
    return 0;
}
