
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> arr;
    for (int i=0;i<n;i++){
        string a;
        int b;
        cin>>a;
        if (a!="pop"){
            cin>>b;
        }
        if (a=="push"){
            arr.push(b);
        }
        else {
            arr.pop();
        }
    }
    int arr1[arr.size()];
    int i=0;
    while (!arr.empty()){
        arr1[i]=arr.top();
        arr.pop();
        i++;
    }
    for (int j=i-1;j>=0;j--)
        cout<<arr1[j]<<" ";

}
