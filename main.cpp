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
                    return 1;
                }

                // Check if the number already exists
                if (rowUsed[rowNumber]) {
                    cout<<"Duplicate number in row "<<i+1<<endl;
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
                    cout<<"Invalid number in column "<<j+1<<endl;
                    return 1;
                }

                // Check if the number already exists
                if (columnUsed[columnNumber]) {
                    cout<<"Duplicate number in column "<<j+1<<endl;
                    return 1;
                }

                // Mark the number as used
                columnUsed[columnNumber] = true;
            }
        }
    }
    else {
        cout<<"File could not be opened."<<endl;
    }

    return 0;
}