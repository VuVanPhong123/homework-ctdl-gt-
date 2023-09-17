#include<bits/stdc++.h>
using namespace std;
vector<int> heapify(vector<int> a,int i){
    int left=i*2+1;
    int right=i*2+2;
    int largest=i;
    if (left<a.size()){
        if (a[left]>a[largest]){
            largest=left;
        }
    }
    if (right<a.size()){
        if (a[right]>a[largest]){
            largest=right;
        }
    }
    if (largest==i)
        return a;
    swap (a[i],a[largest]);
    return heapify(a,largest);

}
vector<int> Heap_sort(vector<int> a){
    int n=a.size();
    vector<int>b;
    for(int i=n/2;i>=0;i--){
        a=heapify(a,i);
    }
    while(a.size()>0){
        b.push_back(a[0]);
        a[0]=a[a.size()-1];
        a.pop_back();
        a=heapify(a,0);
    }
    return b;
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    vector<int>b=Heap_sort(a);
    for (int i=b.size()-1;i>=0;i--)
        cout<<b[i]<<" ";
}
