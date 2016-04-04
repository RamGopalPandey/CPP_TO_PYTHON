/*
jai shree ram _/\_
A hacker from NITP
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int,char> msi;
typedef pair<int,int> pa;
typedef long long int ll;

void print(string str)
{
    //cout<<"yo";
    int i;
    if(str.substr(0,4)=="cout")                  // handling cout
    {
        cout<<"print(";
        i=4;
        while(str[i]=='<')
        {
            i+=2;
            while(str[i]!='<' && str[i]!=';')
            {
                cout<<str[i];
                i++;
            }
            if(str[i]==';')
            {
                cout<<")\n";
                return;
            }
            else
                cout<<",";
        }
    }
    else if(str.substr(0,3)=="cin")                             //handling cin
    {
        i=3;
        while(str[i]=='>')
        {
            i+=2;
            while(str[i]!='>' && str[i]!=';')
            {
                cout<<str[i];
                i++;
            }
            if(str[i]==';')
            {
                cout<<"=map(int,raw_input().split())\n";
                return;
            }
            else
                cout<<",";
        }
    }
    else if(str.substr(0,3)=="int" || str.substr(0,5)=="float" || str.substr(0,4)=="void" || str.substr(0,6)=="double" || str.substr(0,4)=="long" || str.substr(0,6)=="string")
        return;                                                      //HANDLING VARIABLE DECLARATION
    else
        cout<<str<<"\n";                                             //print ordinary statements
}

string format(string str)                                             //removing leading and trailing spaces
{
    int i=0,j,s=str.length();
    while(i<s && str[i]==' ')
        i++;
    j=s-1;
    while(j>i && str[j]==' ')
        j--;
    return str.substr(i,j-i+1);
}

void rec(int indent,string str)                                      //recursive code to handle "for,if,else if,else,while,function declaration" with indentation
{
    int i,j;
    string pass="";
    char str1[55];
    while(str!="{" && str!="}" && str.substr(0,4)!="else" &&  str.substr(0,5)!="while" && str.substr(0,3)!="for" && str.substr(0,2)!="if" && str.substr(0,3)!="int" && str.substr(0,5)!="float" && str.substr(0,4)!="void" && str.substr(0,6)!="double" && str.substr(0,4)!="long" && str.substr(0,6)!="string")
    {
        for(i=0;i<indent;i++)
        cout<<"\t";
        //cout<<str<<"\n";
        print(str);
        gets(str1);//gets(str);
        str=str1;
        str=format(str);
    }
    if(str.substr(0,3)=="int" || str.substr(0,5)=="float" || str.substr(0,4)=="void" || str.substr(0,6)=="double" || str.substr(0,4)=="long" || str.substr(0,6)=="string")
    {
            i=0;
            while(i<str.length() && str[i]!=' ')
                i++;
            i++;
            int p=i;
            while(i<str.length() && str[i]!='(')
                i++;
            if(i<str.length() && str[i]=='(')
            {
                cout<<"def ";
                cout<<str.substr(p,i-p)<<"(";
                i++;
                while(i<str.length() && str[i]!=')')
                {

                    while(i<str.length() && str[i]!=' ')
                        i++;
                    if(i<str.length() && str[i]==' ')
                    {
                        i++;
                        while(i<str.length() && str[i]!=','  && str[i]!=')')
                        cout<<str[i],i++;
                        if(str[i]==',')
                            cout<<str[i++];
                        else if(str[i]==')')
                        {
                            cout<<"):\n";
                            gets(str1);
                            str=str1;
                            str=format(str);
                            rec(indent,str);
                            return;
                        }
                    }
                }
                gets(str1);
                str=str1;
                str=format(str);
                rec(indent,str);
            }
            return;
        }
    else if(str=="{")
    {
        indent++;
        gets(str1);
        str=str1;
        str=format(str);
        rec(indent,str);
        if(indent!=1){
        gets(str1);
        str=str1;
        str=format(str);
        rec(indent-1,str);
        }
        return;
    }
    else if(str=="}")
    {
        indent--;
        //gets(str);
        return;
    }
    else if(str.substr(0,3)=="for"){
    for(i=0;i<indent;i++)
        cout<<"\t";
    i=4;
    while(str[i]!=';')
        cout<<str[i],i++;
    cout<<"\n";
    for(j=0;j<indent;j++)
        cout<<"\t";
    cout<<"while ";
    i++;
    while(str[i]!=';')
        cout<<str[i],i++;
    cout<<":\n";
    pass=str.substr(i+1);
    gets(str1);
    str=str1;
    str=format(str);
    rec(indent,str);
    for(i=0;i<indent+1;i++)
        cout<<"\t";
    for(i=0;i+1<(pass.length())-2;i++)
        cout<<pass[i];
    if(pass[i]=='-' && pass[i+1]=='-')
        cout<<"-=1";
    else if(pass[i]=='+' && pass[i+1]=='+')
        cout<<"+=1";
    else
        cout<<pass[i]<<pass[i+1];
    cout<<"\n";
    }
    else if(str.substr(0,2)=="if"){
    for(i=0;i<indent;i++)
        cout<<"\t";
    i=3;
    cout<<"if ";
    while(str[i]!=')')
        cout<<str[i],i++;
    cout<<":\n";
    gets(str1);
    str=str1;
    str=format(str);
    rec(indent,str);
    }
    else if(str.substr(0,7)=="else if"){
    for(i=0;i<indent;i++)
        cout<<"\t";
    i=8;
    cout<<"elif ";
    while(str[i]!=')')
        cout<<str[i],i++;
    cout<<":\n";
    gets(str1);
    str=str1;
    str=format(str);
    rec(indent,str);
    }
    else if(str.substr(0,4)=="else"){
    for(i=0;i<indent;i++)
        cout<<"\t";
    cout<<"else";
    cout<<":\n";
    gets(str1);
    str=str1;
    str=format(str);
    rec(indent,str);
    }
    else if(str.substr(0,5)=="while"){
    for(i=0;i<indent;i++)
        cout<<"\t";
    i=6;
    cout<<"while ";
    while(str[i]!=')')
        cout<<str[i],i++;
    cout<<":\n";
    gets(str1);
    str=str1;
    str=format(str);
    rec(indent,str);
    }
}

char str1[55];
string str;
int main()
{
	freopen("cpp1.cpp", "r", stdin);                      //read cpp file
  	freopen("python1.py", "w", stdout);                    //write to python file
	ios_base::sync_with_stdio(false);                     //fast i/o
	cin.tie(0);
  	while(1)
    {
        gets(str1);                                        //read line by line
        str=str1;
        str=format(str);                                   // removing leading spaces
        if(str[0]=='#' || str.substr(0,5)=="using" || str[0]=='/' || str=="return 0;")            //ignore these
            continue;
        if(str.substr(0,3)=="int" || str.substr(0,4)=="void")                 // main body
        {
            if(str.substr(0,3)=="int")
            {
                if(str.substr(4,min((int)(str.length()) -4,4))=="main")
                    continue;
            }
            else
            {
                if(str.substr(5,min((int)(str.length()) -5,4))=="main")
                    continue;
            }
        }
        if(str.substr(0,3)=="for" || str.substr(0,5)=="while" || str.substr(0,2)=="if" || str.substr(0,4)=="else" || str.substr(0,3)=="int" || str.substr(0,5)=="float" || str.substr(0,4)=="void" || str.substr(0,6)=="double" || str.substr(0,4)=="long" || str.substr(0,6)=="string")
            rec(0,str);                                                  //recursive code for control,coditional statements and function definition
        else if(str=="return 0;" || str=="}")                                        // break from main function
            break;
        else if(str!="{" && str!="}")                                    //print ordinary statements
            print(str);
    }
    if(str=="return 0;")
    	gets(str1);                                                          // handling closing brace
	return 0;
}
