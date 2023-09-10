#include<bits/stdc++.h>
using namespace std;
void Bubble_sort(vector<int>a){
    int n=a.size();
    for (int i=0;i<n;i++)
        for (int j=0;j<n-1-i;j++){
            if (a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    for (int x:a)
        cout<<x<<" ";
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    Bubble_sort(a);
}

