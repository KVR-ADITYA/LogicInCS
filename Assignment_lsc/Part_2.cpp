#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct Sta
{
    string s;
    string d;
    string c;
    int  a;
    int b;
}Sta;
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
int main()
{
    int x;
    cout<<"enter the number of lines: ";
    cin>>x;
    cout<<"\n"<<x<<"\n";
    Sta a[x];
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
