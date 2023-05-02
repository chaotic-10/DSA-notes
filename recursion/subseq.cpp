#include <bits/stdc++.h>
using namespace std;
void printF (int ind, int vector<int> &v, int arr[],int n)
{
    //base 
    if(ind == n )
    {
         for(auto it : v)
            {
                cout<<it<<" ";
            }
            if(v.size()==0){
                cout<<"{}";
            }
 cout<<endl;
 return;
    }
    //take or pick the particular index into the subsequence
    v.push_back(arr[ind]);
    printF(ind+1,v,arr,n);
    v.pop_back; 

    //not pick, or not take condition, this element is not added to your subsequence
    printF(ind+1,v,arr,n);
}
int main()
{
 int arr[] = {3,1,2}; 
 int n = 3;
 vector<int>v;

 printF(0,arr,n);
return 0;
}