#include<iostream>
using namespace std;

int main(){
    int rows, cols, n;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    cout << "Enter the number of non-zero elements: ";
    cin >> n;

    int matrix[n+1][3];
    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = n;

    cout << "Enter the row, col, value of non-zero elements:\n";
    for(int i = 1; i <= n; i++){   
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
    }

    cout << "\nOriginal Triplet Representation:\n";
    for(int i = 0; i <= n; i++){
        cout << matrix[i][0] << " "
             << matrix[i][1] << " "
             << matrix[i][2] << endl;
    }

    int transpose[n+1][3];
    transpose[0][0] = matrix[0][1]; 
    transpose[0][1] = matrix[0][0];
    transpose[0][2] = matrix[0][2];

    int k = 1;
    for(int i = 0; i < cols; i++){
        for(int j = 1; j <= n; j++){
            if(matrix[j][1] == i){
                transpose[k][0] = matrix[j][1];
                transpose[k][1] = matrix[j][0];
                transpose[k][2] = matrix[j][2];
                k++;
            }
        }
    }

    cout << "\nTranspose Triplet Representation:\n";
    for(int i = 0; i <= n; i++){
        cout << transpose[i][0] << " "
             << transpose[i][1] << " "
             << transpose[i][2] << endl;
    }

    return 0;
}
