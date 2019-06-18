#include<stdio.h>
#include<string>
#include<stack>
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

stack<string>frwd;
stack<string>bck;



int main()
{
    int t,cs=1;
    string command,current;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",cs++);
        current="http://www.lightoj.com/";
        while(1)
        {
            cin>>command;
            //cout<<command;
            if(command=="QUIT")
                break;
            if(command=="VISIT")
            {
                bck.push(current);
                while(!frwd.empty())
                    frwd.pop();
                cin>>current;
                cout<<current<<endl;
            }
            else if(command=="BACK")
            {
                if(bck.empty())
                    printf("Ignored\n");
                else
                {
                    frwd.push(current);
                    current=bck.top();
                    bck.pop();
                    cout<<current<<endl;
                }
            }
            else
            {
                if(frwd.empty())
                    printf("Ignored\n");
                else
                {
                    bck.push(current);
                    current=frwd.top();
                    frwd.pop();
                    cout<<current<<endl;
                }
            }

        }
        while(!frwd.empty())
            frwd.pop();
        while(!bck.empty())
            bck.pop();
    }
return 0;
}
