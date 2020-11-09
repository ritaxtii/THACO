#include <bits/stdc++.h>

using namespace std;

int main()
{long long int n,m;
   cin>>n>>m;
double yak[100000],xak[100000],x,y,h,k,r;
   for(long long int i=0;i<n;i++)
   {
       cin>>x>>y;
       yak[i]=y;
       xak[i]=x;
   }

   int sum=0,c;
   for(long long int i=0;i<m;i++)
   {c=0;
       cin>>h>>k>>r;
       for(long long int j=0;j<n;j++)
       {
           float distance=sqrt((xak[j]-h)*(xak[j]-h)+(yak[j]-k)*(yak[j]-k));
           //cout<<distance<<"\n";
           if(distance<r) {c++;sum++;j=n;}
       }
       if(c==n) {cout<<"0";}

   }
   if(c!=n)
    cout<<sum;
    return 0;
}
