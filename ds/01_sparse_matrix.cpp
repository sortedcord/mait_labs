#include <iostream>
using namespace std;

struct element {
  int row;
  int col;
  int value;
};

int main() {
  int row, col;

  cout << "Enter the number of rows and columns: ";
  cin >> row >> col;

  int matrix[100][100];

  cout << "Enter each element row-wise" << endl;

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      cin >> matrix[i][j];
    }
  }

  cout << "In sparse matrix representation: " << endl;

  element sparse[10000]; // to store non-zero elements
  int count = 0;

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (matrix[i][j] != 0) { // only store non-zero
        sparse[count].row = i;
        sparse[count].col = j;
        sparse[count].value = matrix[i][j];
        count++;
      }
    }
  }

  for (int i = 0; i < count; ++i) {
    cout << sparse[i].row << " " << sparse[i].col << " " << sparse[i].value
         << endl;
  }
  cout << "Aditya Gupta CST789";

  return 0;
}
