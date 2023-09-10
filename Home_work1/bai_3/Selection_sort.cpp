#include<bits/stdc++.h>
using namespace std;
void Selection_sort(vector<int>a){
    int n=a.size();
    int Min;
    for (int i=0;i<n-1;i++){
        Min=i;
        for (int j=i+1;j<n;j++){
            if (a[Min]>a[j]){
                Min=j;
            }
        }
        if (Min!=i)
            swap(a[i],a[Min]);
    }
    for (int x:a)
        cout<<x<<" ";
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    Selection_sort(a);
}

