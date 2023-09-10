#include<bits/stdc++.h>
using namespace std;
vector<int> ghep(vector<int>a,vector<int>b){
    vector<int>Merge;
    int m=a.size();
    int n=b.size();
    int i=0,j=0;
    while(i<m&&j<n){
        if (a[i]>b[j]){
            Merge.push_back(b[j]);
            j++;
        }
        else {
            Merge.push_back(a[i]);
            i++;
        }
    }
    if (i==m)
        for (int k=j;k<n;k++)
            Merge.push_back(b[k]);
    else if (j==n)
        for (int k=i;k<m;k++)
            Merge.push_back(a[k]);
    return Merge;
}
vector<int>merge_sort(vector<int>a){
    int n=a.size();
    if (n==1)
        return a;
    vector<int>left;
    vector<int>right;
    for (int i=0;i<n/2;i++){
        left.push_back(a[i]);
    }
    for (int i=n/2;i<n;i++)
        right.push_back(a[i]);

    left=merge_sort(left);
    right=merge_sort(right);

    return ghep(left,right);

}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    for (int x : merge_sort(a))
        cout<<x<<" ";
}

