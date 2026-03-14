#include <bits/stdc++.h>
using namespace std;

void resetAndRecalculate(vector<int> &prefix, vector<int> &suffix, vector<int> &arr){
    cout<<endl;
    prefix=arr;
    suffix=arr;
    for(int i=1;i<arr.size();i++){
        prefix[i]=prefix[i]+prefix[i-1];
    }
    for(int i=arr.size()-2;i>=0;i--){
        suffix[i]=suffix[i]+suffix[i+1];
    }
    cout<<"RECALCULATED PREFIX:- ";
    for(auto e: prefix){
        cout<<e<<" ";
    }
    cout<<endl<<"RECALCULATED SUFFIX:- ";
    for(auto e: suffix){
        cout<<e<<" ";
    }
    cout<<endl;
}
 
void Solve(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> prefix=arr;
    vector<int> suffix=arr;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i]+prefix[i-1];
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i]+suffix[i+1];
    }
    vector<int> origDifference(n);
    cout<<"DIFFERENCE WITHOUT REPLACEMENT "<<endl;
    for(int i=0;i<n-1;i++){
        origDifference[i]=prefix[i]-suffix[i+1];
        cout<<origDifference[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        cout<<endl;
        vector<int> temp=arr;
        temp[i]=k;
        cout<<"i= "<<i<<endl;
        cout<<"Difference is d- "<<k-arr[i]<<endl;
        cout<<"ARRAY- ";
        for(auto e: temp){
            cout<<e<<" ";
        }
        resetAndRecalculate(prefix,suffix,temp);
        vector<int> tempDiff(n);
        cout<<"DIFFERENCE- ";
        for(int i=0;i<n-1;i++){
            tempDiff[i]=prefix[i]-suffix[i+1];
            cout<<tempDiff[i]<<" ";
        }
        cout<<endl<<"DIFFERENCE WRT TO origDifference "<<endl;
        for(int i=0;i<n-1;i++){
            cout<<origDifference[i]-tempDiff[i]<<" ";
        }
        cout<<endl;
    }
    
}

int main() {
    vector<int> arr={22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14};
    int k=-33;
    cout<<"ORIGINAL ARRAY: -"<<endl;
    for(auto e: arr){
        cout<<e<<" ";
    }
    cout<<endl<<endl;
    Solve(arr,k);

    return 0;
}