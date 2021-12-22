/*An expression will be given which can contain open and close parentheses and optionally some characters, No other operator will be there in string.
 We need to remove minimum number of parentheses to make the input string valid. If more than one valid output are possible removing same number of
 parentheses then print all such output.
Examples:

Input  : str = “()())()” -
Output : ()()() (())()
There are two possible solutions
"()()()" and "(())()" */

#include <bits/stdc++.h>
using namespace std;

int isvalidstring(string str)
{
    int cnt=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
            cnt++;
        else if(str[i]==')')
            cnt--;
        if(cnt<0)
            return false;
    }
    return cnt==0;
}
bool validParentheses(char c)
{
    return (c=='(' or c==')');
}
void removeInvalidParenthesis(string str)
{
    if(str.empty())
        return ;
    queue<string>q;
    set<string>visit;
    bool level;
    string temp;

    q.push(str);
    visit.insert(str);
    while(!q.empty())
    {
        str=q.front();
        q.pop();
        if(isvalidstring(str))
        {
            cout<<str<<endl;
            level=1;
        }
        if(level)
            continue;
        for(int i=0;i<str.length();i++)
        {
            if(validParentheses(str[i]))
            temp=str.substr(0,i)+str.substr(i+1);
            if(visit.find(temp)==visit.end())
            {
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
}
int main()
{
    string expression = "()())()";
    removeInvalidParenthesis(expression);
    cout<<"\n\n";
    expression = "()v)";
    removeInvalidParenthesis(expression);

    return 0;
}
