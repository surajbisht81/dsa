#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int MaxOccuredElmt(int L[], int R[], int n)
{
    int arr[MAX];
    memset(arr, 0, sizeof(arr));
   int maxi=-1;
	for (int i = 0; i < n; i++) {
		arr[L[i]] += 1;
		arr[R[i] + 1] -= 1;
		if(R[i]>maxi){
			maxi=R[i];
		}
	}


       int msum = arr[0],ind;
    for (int i = 1; i < maxi+1; i++) {
        arr[i] += arr[i - 1];
        if (msum < arr[i]) {
            msum = arr[i];
            ind = i;
        }
    }
    return ind;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int L[n], R[n];
        for(int i=0; i<n; i++)
         cin>>L[i];
        for(int i=0; i<n; i++)
         cin>>R[i];
       cout<<MaxOccuredElmt(L, R, n)<<endl;
    }
    return 0;
}


