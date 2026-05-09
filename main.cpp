#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int sudoku[9][9];

    // File object for reading sudoku data
    ifstream file;
    file.open("sudoku.txt");

    // Check if the file opened successfully
    if (file.is_open()) {

        // Read sudoku values from the file
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                file >> sudoku[i][j];
            }
        }

        // Validate each row...
        for (int i = 0; i < 9; i++) {
            bool rowUsed[10] = {false};

            for (int j = 0; j < 9; j++) {

                int rowNumber = sudoku[i][j];

                // Check if the number is between 1 and 9
                if (rowNumber < 1 || rowNumber > 9) {
                    cout<<"Invalid number in row "<<i+1<<endl;
                    cout << "Invalid Sudoku" << endl;
                    return 1;
                }

                // Check if the number already exists
                if (rowUsed[rowNumber]) {
                    cout<<"Duplicate number in row "<<i+1<<endl;
                    cout << "Invalid Sudoku" << endl;
                    return 1;
                }

                // Mark the number as used
                rowUsed[rowNumber] = true;
            }
        }

        // Validate each column...
        for (int i = 0; i < 9; i++) {
            bool columnUsed[10] = {false};

            for (int j = 0; j < 9; j++) {

                int columnNumber = sudoku[j][i];

                // Check if the number is between 1 and 9
                if (columnNumber < 1 || columnNumber > 9) {
                    cout<<"Invalid number in column "<<i+1<<endl;
                    cout << "Invalid Sudoku" << endl;
                    return 1;
                }

                // Check if the number already exists
                if (columnUsed[columnNumber]) {
                    cout<<"Duplicate number in column "<<i+1<<endl;
                    cout << "Invalid Sudoku" << endl;
                    return 1;
                }

                // Mark the number as used
                columnUsed[columnNumber] = true;
            }
        }

        // Validate each 3x3 subgrid
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                bool subgridUsed[10] = {false};

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        int subgridNumber = sudoku[row + i][col + j];

                        // Check if the number is between 1 and 9 in 3x3 subgrid
                        if (subgridNumber < 1 || subgridNumber > 9) {
                            cout<<"Invalid number in 3x3 subgrid "<<endl;
                            cout << "Invalid Sudoku" << endl;
                            return 1;
                        }

                        // Check if the number already exists in 3x3 subgrid
                        if (subgridUsed[subgridNumber]) {
                            cout<<"Duplicate number in 3x3 subgrid "<<endl;
                            cout << "Invalid Sudoku" << endl;
                            return 1;
                        }

                        // Mark the number as used in subgrid
                        subgridUsed[subgridNumber] = true;
                    }
                }
            }
        }

        cout<<"Valid Sudoku"<<endl;
    }
    else {
        cout<<"File could not be opened."<<endl;
        return 1;
    }

    return 0;
}