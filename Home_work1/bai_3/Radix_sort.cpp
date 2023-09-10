#include<bits/stdc++.h>
using namespace std;
void counting_sort(vector<int>&a,int key){
    vector<int>amo(10,0);
    for (int i=0;i<a.size();i++){
        amo[(a[i]/key)%10]++;
    }
    for (int i=1;i<10;i++){
        amo[i]+=amo[i-1];
    }
    vector<int>b(a.size());
    for (int i=a.size()-1;i>=0;i--){
        b[amo[(a[i]/key)%10]]=a[i];
        amo[(a[i]/key)%10]--;
    }
    for (int i=0;i<a.size();i++){
        a[i]=b[i];
    }
}
vector<int> Radix_sort(vector<int>a){
    int largest=a[0];
    for (int i=0;i<largest;i++){
        if (largest<a[i]){
            largest=a[i];
        }
    }
    int times=1;
    while (times<largest){
        counting_sort(a,times);
        times*=10;
    }
    return a;
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    vector<int>b=Radix_sort(a);
    for (int i=0;i<a.size();i++)
        cout<<b[i]<<" ";
}
