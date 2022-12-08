#pragma once
#include <map>
#include <iostream>
#include <stdexcept>

#define ui unsigned int 

using namespace std;

template <class T>
class SymmetricMatrix
{
	ui Size;
	map <pair<ui, ui>, T> matrix;
	pair<ui, ui> Position(ui row, ui col);
	bool checkExistCell(pair<ui, ui> position);

public:
	void RemoveElement(ui row, ui col, T value);
	SymmetricMatrix(ui& Size);
	void SetElement(ui row, ui col, T value);
	T GetElement(ui row, ui col);
	void PrintMatrix();
	void operator+(SymmetricMatrix<T>& anotherMatrix);
};

template <class T>
void SymmetricMatrix<T>::RemoveElement(ui row, ui column, T value) {

	pair<ui, ui> position = Position(row, column);
	if (checkExistCell(position)) {
		matrix.erase(position);
		matrix.insert(make_pair(position, value));
	}
	else
		throw out_of_range("OUCH! This cell doesn't exist");
	return;
}

template <class T>
SymmetricMatrix<T>::SymmetricMatrix(ui& Size) {

	this->Size = Size;
	cout << "Specify the fields of the symmetric matrix:\n";
	for (ui row = 0; row < Size; row++)
		for (ui column = row; column < Size; column++) {
			cout << "Initialize the field " << row << " " << column << "\n";
			T value;
			cin >> value;
			this->SetElement(row, column, value);
		}
}

//Check range of matrix
template <class T>
bool SymmetricMatrix<T>::checkExistCell(pair<ui, ui> position) {

	return position.first < Size && position.second < Size;
}

/**
 *  Set value in upper triangular matrix or the main diagonal
 */
template <class T>
void SymmetricMatrix<T>::SetElement(ui row, ui column, T value) {

	pair<ui, ui> position = Position(row, column);
	if (checkExistCell(position)) {
		matrix.insert(make_pair(position, value));
	}
	else
		throw out_of_range("OUCH! This cell doesn't exist");
	return;
}

/*
*  checks that the position points to the upper triangular matrix or to the main diagonal
*  and change positionon right if this not true
*  @return correct position
*/
template <class T>
pair<ui, ui> SymmetricMatrix<T>::Position(ui row, ui column) {

	if (row > column)
		swap(row, column);
	pair<ui, ui> position(row, column);
	return position;
}

template <class T>
T SymmetricMatrix<T>::GetElement(ui row, ui column){

	if (checkExistCell(Position(row, column))) {
		auto it = matrix.find(Position(row, column));
		return it->second;
	}
	else
		throw out_of_range("OUCH! This cell doesn't exist\n\n");
}

/**
 *  make new matrix 
 *	@return new matrix with sum identical cells
 */
template <class T>
void SymmetricMatrix<T>::operator+( SymmetricMatrix<T>& anotherMatrix){

	if (Size == anotherMatrix.Size)
		for (ui row = 0; row < Size; row++)
			for (ui column = row; column < Size; column++) {
				T value = this->GetElement(row, column) + anotherMatrix.GetElement(row, column);
				matrix.erase(make_pair(row, column));
				this->SetElement(row, column, value);
			}
	else
		throw logic_error("OUCH! We can't sum matrixs with difference size\n\n");
}

template <class T>
void SymmetricMatrix<T>::PrintMatrix() {

	cout << "\n";
	for (ui row = 0; row < Size; row++) {
		for (ui column = 0; column < Size; column++)
			cout << this->GetElement(row, column) << "\t";
		cout<<"\n";
	}
	return;
}