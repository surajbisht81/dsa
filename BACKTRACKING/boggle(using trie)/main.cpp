#include <bits/stdc++.h>
using namespace std;
#define M 3
#define N 3
struct trie
{
    unordered_map<char, trie*>mp;
    bool isend;
    trie()
    {
        isend=false;
    }
};
struct trie *root;

void insert(string str)
{
    struct trie *curr=root;
    for(char ch:str)
    {
        if(!curr->mp.count(ch))
            curr->mp[ch]=new trie;
        curr=curr->mp[ch];
    }
    curr->isend=true;
}

bool search_character(string str)
{
    struct trie *curr=root;
    for(char ch:str)
    {
        if(!curr->mp.count(ch))
            return false;
        curr=curr->mp[ch];
    }
    return curr->isend;
}
int main()
{
    root=new trie;
    string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};

    for(int i=0;i<4;i++)
      insert(dictionary[i]);

    char boggle[M][N] = {{'G','I','Z'},
        {'U','E','K'},
        {'Q','S','E'}};

    for(int i=0;i<4;i++)
    {
        string str=dictionary[i];
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<N;k++)
            {
               if(str[0]==boggle[j][k])
               {  if(search_character(str))
                    cout<<str<<"is present."<<endl;
                  else
                    cout<<str<<"is not present."<<endl;
               }
            }
        }
    }
    return 0;
}
