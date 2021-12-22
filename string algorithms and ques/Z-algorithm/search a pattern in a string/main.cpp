#include <iostream>

using namespace std;

void createZarray(int Z[],string concate,int l)
{
    Z[0]=0;
    for(int i=0;i<l;i++)
    {
        for(int j=1;j<l;j++)
        {
            if(concate[i]==concate[j])
            {
                m=j;
                i++;
            }
            else
             break;
        }

    }
}
void search(string text,string pattern)
{
    string concate= pattern + "$" + text;
    int l=concate.length();
    int Z[l];
    createZarray(Z,concate,l);
}
int main()
{
    string text="GEEKS FOR GEEKS";
    string pattern = "GEEK";
    search(text,pattern);
    return 0;
}
