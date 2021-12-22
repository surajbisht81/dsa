/*Write a function to generate all possible n pairs of balanced parentheses.
Examples:

Input: n=1
Output: {}
Explantaion: This the only sequence of balanced 
parenthesis formed using 1 pair of balanced parenthesis. 

Input : n=2
Output: 
{}{}
{{}}
Explantaion: This the only two sequences of balanced 
parenthesis formed using 2 pair of balanced parenthesis. 

time complexity = O(2^n) because we have 2 options for each index;
space complexity = O(n)*/


#include <iostream>

using namespace std;

void generatepar(int open,int close,int idx,char op[])
{
    //base case
    if(close==0 && open==0)
    {
        op[idx]='\0';
        cout<<op<<endl;
        return;
    }

    if(open>0)
    {
        op[idx]='(';
        generatepar(open-1,close,idx+1,op);
    }
    if(open<close)
    {
        op[idx]=')';
        generatepar(open,close-1,idx+1,op);
    }
}
int main()
{
    int n;
    cin>>n;
    char output[100];
    generatepar(n,n,0,output);
    return 0;
}
