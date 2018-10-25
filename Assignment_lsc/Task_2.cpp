#include<iostream>
#include<stack>
#include<string>
#include<malloc.h>
#include "main.cpp"

using namespace std;
/**
*\brief it is a class to define node of a parse tree
*it has a character(p) and two pointers(left and right) stored in it
*/
class Node
{
    public:
    char p;///< it is the main character that exists in the node
    Node* left;///< it is the pointer to the left Node
    Node* right;///< it is the pointer to the right Node
    /**
    *\brief it is a default constructor
    *\param no parameters
    */
    Node()
    {

    }
    /**
    *\brief it is a parameterized constructor
    *\param it takes in a parameter and initializes the main character in the Node
    */
    Node (char x)
    {
        p=x;
    }
};
/**
*\brief it is the function that actually prints the infix by in-order traversal
*\param a pointer to the root Node (the apex of any parse tree)
*This function prints the infix notation of the given parse tree by recurssion i.e it prints left tree then the character in the node it is present in the it prints the right tree reccursively.Thus, the lefmost element gets printed first and then the lefmost operator and so on.
*/
void printInfix(Node *x)
{
    Node *l;
    Node *r;
    l=(Node*)(malloc(sizeof(Node)));
    r=(Node*)(malloc(sizeof(Node)));
    l=x->left;
    r=x->right;
    if(l==NULL && !isOperator(r->p))
    {
        cout<<"("<<x->p<<r->p<<")";
        return;
    }
    if(l==NULL && isOperator(r->p))
    {
        cout<<x->p;
        printInfix(r);
        return;
    }

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
/**
*\brief It is the main method and it also generates the parse tree and prints it
*in this method we get the input from the previous file ,which is the postfix of an expression,then we declare a stack of pointers to Node objects and then the for  loop generates the parse tree
*it then sends the pointer to the first Node to printInfix function
*/
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
            n->left=NULL;
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
