#include <bits/stdc++.h>
using namespace std;


#define N 2
int arr[N][N],I[N][N];
void printmatrix(int A[][N],int dim)
{
    for(int i=0;i<dim;i++)
     {   for(int j=0;j<dim;j++)
         cout<<A[i][j]<<" ";
         cout<<endl;
     }
}
void multiply(int A[][N],int B[][N],int dim)
{
    int res[dim+1][dim+1];
     for(int i=0;i<dim;i++)
     {
         for(int j=0;j<dim;j++)
         {
             res[i][j]=0;
             for(int k=0;k<dim;k++)
             {
                 res[i][j]+= A[i][k]*B[k][i];
             }
         }
     }
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
         A[i][j]=res[i][j];
}
void power(int arr[][N],int n,int dim)
{
    for(int i=0;i<dim;i++)
     for(int j=0;j<dim;j++)
     {
         if(i==j)
            I[i][j]=1;
         else
            I[i][j]=0;
     }

     while(n--)
     {
         if(n%2)
         {
             n--;
             multiply(I,arr,dim);
         }
         else
         {
             multiply(arr,arr,dim);
             n/=2;
         }
     }

   for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
     arr[i][j]=I[i][j];
}

int main()
{
    int n,dim;
    cout<<"\nenter power(n) and dimention:";
    cin>>n>>dim;
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            cin>>arr[i][j];

    power(arr,n,dim);
    printmatrix(arr,dim);
    return 0;
}
