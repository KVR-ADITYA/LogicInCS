#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include "main.cpp"
#include<malloc.h>
using namespace std;
typedef struct Tree
{
    char p;
    string s;
    Tree *l;
    Tree *r;
}Tree;
 void subTree(string s,Tree *t)
    {

        t->p = s[s.length()-1];
        t->r = (Tree*)(malloc(sizeof(s)+2));
        t->l = (Tree*)(malloc(sizeof(s)+2));
        if(!isOperator(t->p))
        {
            t->l=NULL;
            t->r=NULL;
        }
        if(isOperator(t->p)&&t->p!='~')
        {
            if(isOperator(s[s.length()-2]))
            {
                subTree(s=s.substr(0,s.length()-2),t->r);

                    subTree(s=s.substr(0,s.length()),t->l);

            }
            else
            {
                subTree(s.substr(0,s.length()-2),t->l);
            }
        }
        if(t->p=='~')
        {
            t->l=NULL;
            subTree(s.substr(0,s.length()-1),t->r);
        }
        return;
    }



int main()
{
    string pf=main2();
    Tree *t = (Tree*)(malloc(sizeof(pf)+3));
    t->s=pf;
    subTree(pf,t);
    cout<<"\n gfhfhdh"<<t->p;
    return 0;
}
