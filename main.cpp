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

        bool isValid = true;

        // Read sudoku values from the file
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Check for missing numbers in the file
                if (!(file >> sudoku[i][j])) {
                    cout << "Missing numbers in sudoku file." << endl << endl;

                    cout << "Invalid Sudoku" << endl;
                    return 1;
                }
            }
        }

        // Check for extra numbers in the file
        int extraNumber;
        if (file >> extraNumber) {
            cout << "Too many numbers in sudoku file." << endl << endl;

            cout << "Invalid Sudoku" << endl;
            return 1;
        }

        // Validate each row
        for (int i = 0; i < 9; i++) {
            bool rowUsed[10] = {false};

            for (int j = 0; j < 9; j++) {

                int rowNumber = sudoku[i][j];

                // Check number range in rows
                if (rowNumber < 1 || rowNumber > 9) {
                    cout<<"Row "<< i + 1 <<" is invalid."<<endl;

                    isValid = false;
                    break;
                }

                // Check duplicate numbers in rows
                if (rowUsed[rowNumber]) {
                    cout<<"Row "<< i + 1 <<" is invalid."<<endl;

                    isValid = false;
                    break;
                }

                // Mark the number as used
                rowUsed[rowNumber] = true;
            }
        }

        // Validate each column
        for (int i = 0; i < 9; i++) {
            bool columnUsed[10] = {false};

            for (int j = 0; j < 9; j++) {

                int columnNumber = sudoku[j][i];

                // Check number range in columns
                if (columnNumber < 1 || columnNumber > 9) {
                    cout<<"Column "<< i + 1 <<" is invalid."<<endl;

                    isValid = false;
                    break;
                }

                // Check duplicate numbers in columns
                if (columnUsed[columnNumber]) {
                    cout<<"Column "<< i + 1 <<" is invalid."<<endl;

                    isValid = false;
                    break;
                }

                // Mark the number as used
                columnUsed[columnNumber] = true;
            }
        }

        // Validate each 3x3 subgrid
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                bool subgridUsed[10] = {false};
                bool subgridInvalid = false;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        int subgridNumber = sudoku[row + i][col + j];

                        // Check number range in subgrid
                        if (subgridNumber < 1 || subgridNumber > 9) {
                            cout<<"Invalid 3x3 subgrid starting at row "<< row + 1 <<", column "<< col + 1 <<endl;

                            isValid = false;
                            subgridInvalid = true;
                            break;
                        }

                        // Check duplicate numbers in subgrid
                        if (subgridUsed[subgridNumber]) {
                            cout<<"Invalid 3x3 subgrid starting at row "<< row + 1 <<", column "<< col + 1 <<endl;

                            isValid = false;
                            subgridInvalid = true;
                            break;
                        }

                        // Mark the number as used in subgrid
                        subgridUsed[subgridNumber] = true;
                    }

                    if (subgridInvalid) break;
                }
            }
        }

        if (isValid) {
            cout << "Valid Sudoku" << endl;
        }
        else {
            cout << endl;
            cout << "Invalid Sudoku" << endl;
        }
        file.close();
    }
    else {
        cout<<"File could not be opened."<<endl;
        return 1;
    }

    return 0;
}