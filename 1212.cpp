
#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    int n,m,t,cs=1,x,size;
    string command;
    deque<int>dq;

    cin>>t;
    while(t--)
    {
        cout<<"Case "<<cs++<<":"<<endl;
        cin>>n>>m;
        size=0;
        while(m--)
        {
            cin>>command;
            if(command=="pushLeft")
            {
                cin>>x;
                if(size==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    cout<<"Pushed in left: "<<x<<endl;
                    dq.push_front(x);
                    size++;
                }
            }
            else if(command=="pushRight")
            {
                cin>>x;
                if(size==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    cout<<"Pushed in right: "<<x<<endl;
                    dq.push_back(x);
                    size++;
                }
            }
            else if(command=="popLeft")
            {
                if(size==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    x=dq.front();
                    dq.pop_front();
                    size--;
                    cout<<"Popped from left: "<<x<<endl;
                }
            }
            else
            {
                if(size==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    x=dq.back();
                    dq.pop_back();
                    size--;
                    cout<<"Popped from right: "<<x<<endl;
                }
            }
        }
        dq.clear();

    }
    return 0;
}

