/*Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
The amount of petrol that every petrol pump has.
Distance from that petrol pump to the next petrol pump.
Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). 
Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.*/

#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int start=0;
   int end=1;

   int curr_petrol = p[start].petrol - p[start].distance;

   while(end!=start or curr_petrol<0)
   {
       while(end!=start and curr_petrol<0)
       {
           curr_petrol -= p[start].petrol-p[start].distance;
           start=(start+1)%n;

           if(start==0)
           return -1;
       }

       curr_petrol += p[end].petrol - p[end].distance;
       end=(end+1)%n;
   }
   return start;
}
int main()
{
   petrolPump p[]= {{6, 4}, {3, 6}, {7, 3}};
   int n=sizeof(p)/sizeof(p[0]);

   cout<<"starting petrol pump is :"<<tour(p,n);
   return 0;
}
