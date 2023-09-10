#include<bits/stdc++.h>
using namespace std;
void Insertion_sort(vector<int>a){
    int n=a.size();
    int j;
    int temp;
    for (int i=1;i<n;i++){
        j=i-1;
        temp=a[i];
        while (j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    for (int x:a)
        cout<<x<<" ";
}
int main(){
    srand(time(nullptr));
    vector<int>a;
    for (int i=0;i<1000;i++)
        a.push_back(rand()%1000);
    Insertion_sort(a);
}
