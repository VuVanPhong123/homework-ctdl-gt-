#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> arr;
    for (int i=0;i<n;i++){
        string a;
        int b;
        cin>>a;
        if (a!="dequeue"){
            cin>>b;
        }
        if (a=="enqueue"){
            arr.push(b);
        }
        else {
            arr.pop();
        }
    }
    while (!arr.empty()){
        cout<<arr.front()<<" ";
        arr.pop();
    }
}
