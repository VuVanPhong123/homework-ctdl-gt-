#include<bits/stdc++.h>
using namespace std;
vector<int> Merge(vector<int>a,vector<int>b,vector<int>c){
    vector<int>d;
    for (int i=0;i<a.size();i++)
        d.push_back(a[i]);
    for (int i=0;i<b.size();i++)
        d.push_back(b[i]);
    for (int i=0;i<c.size();i++)
        d.push_back(c[i]);
    return d;
}
vector<int> Quick_sort(vector<int>a){
    int n=a.size();
    if (n==1||n==0)
        return a;
    int pivot=a[0];
    vector<int>left;
    vector<int>right;
    vector<int>equa;
    for (int i=0;i<n;i++){
        if (a[i]<pivot)
            left.push_back(a[i]);
        else if (a[i]==pivot)
            equa.push_back(a[i]);
        else right.push_back(a[i]);
    }
    left=Quick_sort(left);
    right=Quick_sort(right);
    return Merge(left,equa,right);
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    for (int x : Quick_sort(a))
        cout<<x<<" ";
}
