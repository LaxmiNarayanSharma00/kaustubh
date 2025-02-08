#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char **argv)
{
    int t;
    cin >>t;

    while (t--)
    {   
        int n,k;
        cin>>n>>k;

       int min=(k-1)+(k*(k+1)/2);
       if(n>=min){
        cout<<"YES"<<endl;

       }
       else
       {
        cout<<"NO"<<endl;
       }
       
    }

    return 0;
}