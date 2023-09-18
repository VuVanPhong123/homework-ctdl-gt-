

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> arr;
    queue<int> arr2;
    for (int i=0;i<n;i++){
        string a;
        int b;
        cin>>a;
        if (a=="push"){
            cin>>b;
            arr.push(b);
        }
        else if (a=="pop") {
            while (arr.size()>1){
                arr2.push(arr.front());
                arr.pop();
            }
            arr.pop();
            while(!arr2.empty()){
                arr.push(arr2.front());
                arr2.pop();
            }
        }
    }

    while (!arr.empty()){
        cout<<arr.front()<<" ";
        arr.pop();
    }

}
