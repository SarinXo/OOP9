#include "SymmetricMatrix.h"

#define Ttype int

int main(){

	cout << "This program is designed to work with a symmetric matrix\n";
	cout << "Enter the size of the matrix: ";
	ui size; cin >> size;
	cout << "\n";
	SymmetricMatrix<Ttype> mat(size);

	cout << "Enter the number of options: ";
	ui num; cin >> num;
	cout << "\n";

	while (num--) {
		cout << "Enter the operation you want to perform\n";
		cout << "1 - Enter the value in the cell\n";
		cout << "2 - Add the original matrix with the new one\n";
		cout << "3 - Output a value from a specific cell\n";
		cout << "4 - Output the matrix completely\n";
		cout << "5 - Exit\n\n";

		ui operation;  cin >> operation;
		switch (operation) {

		case(1): {

			cout << "Enter the position of matrix\n";
			ui row, col;
			cin >> row >> col;
			cout << "Enter value\n";
			Ttype value;
			cin >> value;
			try {
				mat.RemoveElement(row, col, value);
			}catch (exception& e){
				cout << e.what();
			}
			break;
		}case(2): {

			cout << "Enter the size of the new matrix: ";
			ui NEWsize; cin >> NEWsize;
			cout << "\n";
			SymmetricMatrix<Ttype> NEWmat(NEWsize);
			try {
				mat + NEWmat;
			}
			catch (exception& e) {
				cout << e.what();
			}
			break;
		}case(3): {

			cout << "Enter the position of matrix\n";
			ui row, col;
			cin >> row >> col;
			try {
				cout << mat.GetElement(row, col);
			}catch (exception& e){
				cout << e.what();
			}
			break;
		}case(4): {

			mat.PrintMatrix();
			cout << "\n\n";
			break;
		}case(5): {

			num = 0;
			break;
		}default:
			cout << "Uncorrect operation \n Please try again...\n";
		}
	}
	return 0;
}