#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct Sta
{
    string s;///< it is the statement in the given line
    string d;///< it is the total string stored in  a line
    string c;///< it is the proof rule used
    int  a;///< a is the 1st number after c
    int b;///< a is the 2nd number after c
}Sta;
/**
*\brief it compares two strings
*\param s1,s2 datatype :string
*\return returns 0 if strings are not equal else returns 1
*
*/
int stcmp(string s1,string s2)
{
    if(s1.length()==s2.length())
    {
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[i])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
*\brief checks whether a given set of rules are valid or not
*\param an array and an integer
*\return returns true if statements hold else false
*this functions checks the validity of each line of the input following some set of rules (^i,^e,Vi,>e and P)and continues till the last line valid but returns false even if one line is false
*/
bool isValid(Sta a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(stcmp(a[i].c,"P"))
        {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
        }
        if(stcmp(a[i].c,"^i"))
        {
            int k1= a[i].a;
            int k2 = a[i].b;
            if(!stcmp(a[i].s,(a[k1-1].s+"^"+a[k2-1].s)))
            {
                cout<<"\n\nerror in "<<i+1<<".^i"<<a[i].c<<" "<<a[i].s<<" "<<a[i].a<<" "<<a[i].b;
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
        if(stcmp(a[i].c,"^e1"))
        {
            int k1 = a[i].a;
            if(!stcmp(a[i].s,a[k1-1].s.substr(0,a[i].s.length())))
            {
                cout<<"\n\n"<<i+1<<".^e1";
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
        if(stcmp(a[i].c,"^e2"))
        {
            int k1 = a[i].a;
            if(!stcmp(a[i].s,a[k1-1].s.substr((a[k1-1].s.length()-a[i].s.length()),a[i].s.length())))
            {
                cout<<"\n\nerror in "<<i+1<<".^e2";
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
        if(stcmp(a[i].c,"Vi1"))
        {
            int k1 = a[i].a;
            if(!stcmp(a[k1-1].s+"V",a[i].s.substr(0,a[k1-1].s.length()+1)))
            {
                cout<<"\n\n"<<i+1<<".Vi1";
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
        if(stcmp(a[i].c,"Vi2"))
        {
            int k1 = a[i].a;
            if(!stcmp("V"+a[k1-1].s,a[i].s.substr((a[i].s.length()-a[k1-1].s.length()-1),a[i].s.length()+1)))
            {
                cout<<"\n\n"<<i+1<<".Vi2";
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
        if(stcmp(a[i].c,">e"))
        {
            int k1 = a[i].a;
            int k2 = a[i].b;
            if(!stcmp(a[k1-1].s+">",a[k2-1].s.substr(0,a[k1-1].s.length()+1)))
            {
                cout<<"\n\n"<<i+1<<".>e1";
                return false;
            }
            if(!stcmp(">"+a[i].s,a[k2-1].s.substr((a[k2-1].s.length()-a[i].s.length()-1),a[i].s.length()+1)))
            {
                cout<<"\n\n"<<i+1<<".>e2";
                return false;
            }
            else
            {
            if(i!=n-1)
            {
                continue;
            }
            else
            {
                return true;
            }
            }
        }
    }
}
/**
*\brief it is the main method.
*it takes each line as input and splits the statement into different parts and stores them in different parts of the structure(s,d,c,a and b).It then passes array of structures to the isValid()function
*/
int main()
{
    int x;///< it is the number of lines that need to be taken in
    cout<<"enter the number of lines: ";
    cin>>x;
    cout<<"\n"<<x<<"\n";
    Sta a[x];///< it an array of structure Sta which has s,d,c,a and b pre-defined
    for(int i=0;i<x;i++)
{
    cout<<i+1<<".";
	cin>>a[i].d;
	for(int j=0;j<a[i].d.length();j++)
	{
		if(a[i].d[j]=='/')
		{
			a[i].c=a[i].d.substr(j+1);
			a[i].s=a[i].d.substr(0,j);
			for(int k=0;k<a[i].c.length();k++)
			{
				if(a[i].c[k]=='/')
                {
				a[i].a =(a[i].c[k+1]) -'0';
				if(a[i].c[k+2]=='/')
				{
					a[i].b=(a[i].c[k+3])-'0';
				}
				a[i].c = a[i].c.substr(0,k);
				break;
				}
			}
			break;
		}
	}
}
    if(isValid(a,x))
    {
        cout<<"\n       Valid   \n";
    }
    else
    {
        cout<<"\n      Not Valid  \n";
    }

    return 0;
}
