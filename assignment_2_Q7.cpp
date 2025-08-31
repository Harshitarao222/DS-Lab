#include <iostream>
using namespace std;


class LowerTriangular {
   int A[100];
   int n;    


public:
   void setSize(int size) {
       n = size;
       for (int i = 0; i < (n*(n+1))/2; i++) A[i] = 0;
   }


   void set(int i, int j, int val) {
       if (i >= j) {
           int index = (i*(i-1))/2 + (j-1); 
           A[index] = val;
       }


   }


   int get(int i, int j) {
       if (i >= j) {
           int index = (i*(i-1))/2 + (j-1);
           return A[index];
       }
       else
           return 0;
   }


   void display() {
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= n; j++) {
               cout << get(i, j) << " ";
           }
           cout << endl;
       }
   }
};


int main() {
   int n;
   cout << "Enter dimension of lower triangular matrix: ";
   cin >> n;


   LowerTriangular lt;
   lt.setSize(n);


   cout << "Enter elements row-wise:\n";
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           int val;
           cin >> val;
           lt.set(i, j, val);
       }
   }


   cout << "\nMatrix is:\n";
   lt.display();


   return 0;
}