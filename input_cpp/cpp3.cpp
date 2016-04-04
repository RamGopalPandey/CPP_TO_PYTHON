#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
if(n<=1)
{
return 1;
}
return fact(n-1)*n;
}
int n;
int main()
{
n=6;
cout<<fact(n);
return 0;
}
