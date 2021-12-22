#include <bits/stdc++.h>
using namespace std;

void allpermutation(string str,int idx,int l)
{
    //base case
    if(idx==l)
    {
      cout<<str<<endl;
      return;
    }

    for(int i=idx;i<=l;i++)
    {
        swap(str[i],str[idx]);
        allpermutation(str,idx+1,l);
        swap(str[i],str[idx]);
    }
}
int main()
{
    string str="ABC";
    int n=str.length();
    allpermutation(str,0,n-1);
    return 0;
}




/* //iterative method to find permutation


#include<bits/stdc++.h>
using namespace std;

int factorial(int num)
{
    int res=1;
    for(int i=2; i<=num; i++)
     res *= i;
    return res;
}
int main(){
    string str;
    cin>>str;
    
    int n = str.length();              // length of string
    int fact = factorial(n);           // finding the total permutations of n to divide each number by n;
    
    for(int i=0; i<fact; i++)
    {
        string s = str;
        int temp = i;                  // stroring original string to temperory string
        for(int j=n; j>=1; j--)
        {
            int q = temp/j;            // quotient for next temp;
            int r = temp%j;            // remainder is the ans for current permutation
            
            cout<<s[r];
            s.erase(r, 1);            // erasing the rth character because we have printed it on output, so no need to incude it again
            temp = q;
        }
        cout<<endl;
    }
    
    return 0;
}
*/