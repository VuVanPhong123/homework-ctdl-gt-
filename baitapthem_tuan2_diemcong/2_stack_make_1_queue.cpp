#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> arr;
    stack<int> arr2;
    for (int i=0;i<n;i++){
        string a;
        int b;
        cin>>a;
        if (a=="enqueue"){
            cin>>b;
            arr.push(b);
        }
        else if (a=="dequeue") {
            while (!arr.empty()){
                arr2.push(arr.top());
                arr.pop();
            }
            arr2.pop();
            while (!arr2.empty()){
                arr.push(arr2.top());
                arr2.pop();
            }
        }
    }
    while (!arr.empty()){
        arr2.push(arr.top());
        arr.pop();
    }
    while (!arr2.empty()){
        cout<<arr2.top()<<" ";
        arr2.pop();
    }
}
