/*Given a string str and an array of strings arr[] of size N, the task is to print a string from arr[],
 which has maximum count of matching characters with str.*/

 // this programme will not show the output becoz its run time is 7.62;
#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string str)
{
    set<char> st;

    for(int i=0; i<str.length(); i++)
        st.insert(str[i]);

    string output;

    for (char s : st) {

            output.push_back(s);
        }
return output;
}
void mostSimilarString(string str, string arr[], int n)
{
    int res;
    str = removeDuplicate(str);
    int maxx=INT_MIN;
    string output;

   for(int i=0; i<n; i++)
   {
       string s = removeDuplicate(arr[i]);
       string new_str = arr[i];
       res=0;
      for(int j=0; j<str.length(); j++)
      {
          int n = s.find(str[j]);
            if(n<s.length())
                res++;
      }
      if(maxx<res)
      {
          maxx=res;
          output=new_str;
      }
   }
   cout<<output<<" "<<maxx;
}

int main()
{
   string str = "vikas";
   string arr[] = {"preeeeeeeti", "khusbu", "katherina"};
   int n = sizeof(arr)/sizeof(arr[0]);

   mostSimilarString(str, arr, n);
   return 0;
}
