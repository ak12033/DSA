#include <iostream>
using namespace std;

/*
int main() {

    int row;
    cin >> row;

    int col;
    cin >> col;

    // Creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    // Taking input
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    // Output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }


    // Releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete []arr;

    // How to create a 2D array dynamically
    // Input/Output
    // Memory free kaise karani hai 

    return 0;
}
*/

//                                      Jagged Array
/*
int main() {

    int row; // Number of rows in the jagged array
    cout << "Enter number of rows: ";
    cin >> row;

    // Dynamically allocate the jagged array
    int** jagged = new int*[row];

    // Array to store the number of columns for each row
    int* sizes = new int[row];

    // Taking input for each row
    for (int i = 0; i < row; i++) {
        cout << "Enter number of columns for row " << i + 1 << ": ";
        cin >> sizes[i];

        // Dynamically allocate memory for the current row
        jagged[i] = new int[sizes[i]];

        cout << "Enter " << sizes[i] << " elements for row " << i + 1 << ": ";
        for (int j = 0; j < sizes[i]; j++) {
            cin >> jagged[i][j]; // Taking input for each element in the row
        }
    }

    // Output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<sizes[i]; j++) {
            cout << jagged[i][j] << " ";
        } cout << endl;
    }


    // Releasing memory
    for(int i=0; i<row; i++) {
        delete [] jagged[i];
    }   

    delete []jagged;

    // How to create a 2D array dynamically
    // Input/Output
    // Memory free kaise karani hai 

    return 0;
}
*/
