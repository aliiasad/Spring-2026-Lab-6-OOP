# include <iostream>
using namespace std;

class Matrix {
    private:
        int size;
        int** matrix;
    public:
        Matrix (); // default constructor
        Matrix (int); // parameterized constructor
        Matrix (const Matrix&); // copy constructor 
        Matrix& operator= (const Matrix&); // overloaded = operator
        ~Matrix (); // destructor


};

Matrix :: Matrix () {
    size = 2; // given is 2x2
    matrix = new int* [size];
    for (int i = 0; i < size; i++)  {
        *(matrix + i) = new int [size];
        for (int j = 0; j < size; j++)  {
            *(*(matrix + i) + j) = 0;
        }  
    }
}

Matrix :: Matrix (int n) {
    size = n;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)  {
        *(matrix + i) = new int [size];
        for (int j = 0; j < size; j++)  {
            *(*(matrix + i) + j) = 0;
        }
    }
}

Matrix :: Matrix (const Matrix& dummy)  {
    size = dummy.size;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)  {
        *(matrix + i) = new int [size];
        for (int j = 0; j < size; j++)  {
            *(*(matrix + i) + j) = *(*(dummy.matrix + i) + j);
        }
    }
}

Matrix& Matrix :: operator= (const Matrix& dummy)  {
    if (this == &dummy) return *this;

    for (int i = 0; i < size; i++)  {
        delete[] *(matrix + i);
    }
    delete[] matrix;

    size = dummy.size;
    matrix = new int* [size];
    for (int i = 0; i < size; i++)  {
        *(matrix + i) = new int [size];
        for (int j = 0; j < size; j++)  {
            *(*(matrix + i) + j) = *(*(dummy.matrix + i) + j);
        }
    }

    return *this;
}

Matrix :: ~Matrix ()    {
    for (int i = 0; i < size; i++)  {
        delete[] *(matrix + i);
    }
    delete[] matrix;
}

int main()  {

    return 0;
}