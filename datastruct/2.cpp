#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,e;
    cin>>t;
    while(t--)
    {
        int n;
        int a[100000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>e;
            a[i]=e;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
            if(i<n-1) cout<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
