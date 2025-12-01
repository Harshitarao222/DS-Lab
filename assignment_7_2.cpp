#include <iostream>
using namespace std;
int main() {
    int n; 
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int left = 0, right = n - 1;

    while(left < right) {
        int minIndex = left, maxIndex = right;
        for(int i = left; i <= right; i++) {
            if(a[i] < a[minIndex]) minIndex = i;
            if(a[i] > a[maxIndex]) maxIndex = i;
        }
        swap(a[left], a[minIndex]);  
        if(maxIndex == left) maxIndex = minIndex;
        swap(a[right], a[maxIndex]); 
        left++;
        right--;
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
return 0;
}