#include <bits/stdc++.h> 
#include<iostream> 
#include<limits.h>
using namespace std;

//                                     2D Arrays
/*
int main(){

    int arr[3][4];
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,14,16};
    // int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout << "Enter the elements " <<  endl;

    // taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cin >> arr[row][col];
        }
    }

    // taking input -> col wise input
    for(int col=0; col<4; col++) {
        for(int row=0; row<3; row++) {
            cin >> arr[row][col];
        }
    }

    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}
*/

//                              Searching Element in 2d Array
/*
bool isPresent(int arr[][4], int target, int row, int col) {

    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) { 
            if( arr[row][col] == target) {
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int arr[3][4];

    cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cin >> arr[row][col];
        }
    }

    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout <<" Enter the element to search " << endl;
    int target;
    cin >> target;

    if(isPresent(arr, target, 3, 4)) {
        cout <<" Element found " << endl;
    }
    else{
        cout <<" Not Found" << endl;
    }
}
*/

//                      Printing Sum Row Wise and Column Wise
/*
void printColSum(int arr[][3], int row, int col) {

    cout << "Printing Sum -> " << endl;
    for(int col=0; col<3; col++) {
        int sum = 0;
        for(int row=0; row<3; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}
void printRowSum(int arr[][3], int row, int col) {

    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}
int main(){

    int arr[3][3];

    cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }
    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    printRowSum(arr, 3, 3 );
    printColSum(arr, 3, 3 );
}
*/

//                                  Largest Row Sum
/*
int largestRowSum(int arr[][3], int row, int col) {

    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }

        if(sum > maxi ) {
            maxi = sum;
            rowIndex = row;
        }
       
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}
int main(){
    int arr[3][3];
    cout << "Enter the elements " <<  endl;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }
    cout << "Printing the array " << endl;
    //print 
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    int ansIndex = largestRowSum(arr,3,3);
    cout << " Max row is at index " << ansIndex << endl;

    return 0;
}
*/

//                                 Print Like A Wave
/*
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){

    vector<int> ans;
    
    for(int col=0; col<mCols; col++) {
        if( col&1 ) {
            //odd Index -> Bottom to top
            for(int row = nRows-1; row>=0; row--) {
                //cout << arr[row][col] <<" ";
                ans.push_back(arr[row][col]);
            }    
        }
        else{
            // 0 or even iondex -> top to bottom
            for(int row = 0; row<nRows; row++) {
                //cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
        }   
    }
    return ans;
}
int main() {

    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int nRows = 3, mCols = 3;

    vector<int> result = wavePrint(arr, nRows, mCols);

    cout << "Wave Print: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                  Spiral Matrix
/*
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
        
    int count = 0;
    int total = row*col;
        
    //index initialisation
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
        
    while(count < total) {
        //print starting row
        for(int index = startingCol; count < total && index<=endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;
            
        //print ending column
        for(int index = startingRow; count < total && index<=endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
            
        //print ending row
        for(int index = endingCol; count < total && index>=startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;
            
        //print starting column
        for(int index = endingRow; count < total && index>=startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    } 
    return ans;
}
int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> result = spiralOrder(matrix);
    
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
*/

//                                     Rotate Image
/*
void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();      
        
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
void printMatrix(const vector<vector<int>>& matrix) {

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotate(matrix1);

    cout << "Matrix after 90 degree rotation:" << endl;
    printMatrix(matrix1);

    return 0;
}
*/

//                                 Search a 2D Matrix
/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int row = matrix.size();
    int col = matrix[0].size();
        
    int start = 0;
    int end  = row*col-1;
        
    while(start<=end) {
        int mid = start + (end-start)/2;
        int element = matrix[mid/col][mid%col];    
        if(element == target) {
            return 1;
        }    
        if(element < target) {
            start = mid+1;
        }
        else{
            end = mid-1;
        }    
    }
    return 0;
}
int main() {
    
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 11;
    bool found = searchMatrix(matrix, target);
    
    cout << (found ? "Found" : "Not Found") << endl; // Output: Found
    
    return 0;
}
*/

//                              Search a 2D Matrix II
/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int row = matrix.size();
    int col = matrix[0].size();
        
    int rowIndex = 0;
    int colIndex = col-1;
        
    while(rowIndex < row && colIndex>=0 ) {
        int element = matrix[rowIndex][colIndex];    
        if(element == target) {
            return 1;
        }    
        if(element < target){
            rowIndex++;
        }
        else{
            colIndex--;
        }
    }
    return 0;
}
int main() {

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;

    bool found = searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl; // Output: Found
    
    // Test with a target that is not in the matrix
    target = 20;
    found = searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl; // Output: Not Found

    return 0;
}
*/