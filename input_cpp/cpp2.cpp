#include<bits/stdc++.h>
using namespace std;
int i,n,a,b,cur,t[55],p[55],c;
int main()
{
cin>>n>>c;
for(i=0;i<n;i++)
{
cin>>p[i];
}
for(i=0;i<n;i++)
{
cin>>t[i];
}
cur=0; a=0;
for(i=0;i<n;i++)
{
cur+=t[i];
a+=max(0,p[i]-cur*c);
}
cur=0; b=0;
for(i=n-1;i>=0;i--)
{
cur+=t[i];
b+=max(0,(p[i]-cur*c));
}
if(a>b)
{
cout<<"Limak\n";
}
else if(b>a)
{
cout<<"Radewoosh\n";
}
else
{
cout<<"Tie\n";
}
return 0;
}
