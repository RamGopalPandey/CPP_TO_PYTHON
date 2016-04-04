#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,x,y,i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cin>>x>>y;
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i+j%2==0)
{
cout<<i+j<<"is even\n";
}
else
{
cout<<i+j<<"is odd\n";
}
}
}
return 0;
}
