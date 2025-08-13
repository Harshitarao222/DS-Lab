#include<iostream>
using namespace std;
int main(){
    int arr[100],n;
    cout<<"enter array size: ";
    cin>>n;
    cout<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            i++;
           arr[i]=arr[j];
        }
    }
    n=i+1;
    cout<<"after removal";
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}