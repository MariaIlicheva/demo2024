#include <iostream>

int** create2dArr(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];
    return arr;
}

void delete2dArr(int** arr, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;
}

void print2dArr(int** arr, int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c)
            std::cout << arr[r][c] << '\t';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void fillCons(int** arr, int rows, int cols) {
    for (int i=0; i<rows; ++i) { 
        for (int j=0; j<cols; ++j) {
            arr[i][j] = i*cols+j+1;
        }
    }
}


void fillSnakeArr(int** arr, int rows, int cols) {
    int val = 1;
    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; ++j) {
                *(arr[i] + j) = val++;
            }
        } 
        else {
            for (int j = cols - 1; j >= 0; --j) {
                *(arr[i] + j) = val++;
            }
        }
    }
}

void fillSpiral(int** arr, int rows, int cols) {
    int sti = 0, stj = 0, endi = 0, endj = 0;
    int val = 1, i =0, j = 0;
    while (val <= rows*cols) {
        *(arr[i] + j) = val;

        if (i ==  sti and j < cols - endj - 1) ++j;

        else if (i == rows - endi - 1 and j > stj) --j;

        else if (i < rows - endi - 1 and j == cols - endj - 1) ++i;

        else --i;

        if ((i == sti + 1) and (j == stj) and (j != cols - endj - 1)){
            sti += 1;
            stj += 1;
            endi += 1;
            endj += 1;
        }

        val += 1;
    }
}

void fillZigZag(int** arr, int rows, int cols) {
    int val = 1;
    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; ++j) {
                *(arr[i] + j) = val++;
            }
        } 
        else {
            
            for (int j = cols - 1; j >= 0; --j) {
                *(arr[i] + j) = val++;
            }
        }
    }
}


int main(){
    int a, b;
    std::cout<<"input rows: " ;
    std::cin >> a;
    std::cout<<"input cols: " ;
    std::cin >> b;

    int** arr = create2dArr(a, b);

    fillCons(arr, a, b);
    //fillSnakeArr(arr, a, b);
    fillSpiral(arr, a, b);
    //fillZigZag(arr, a, b);
    print2dArr(arr, a, b);
    delete2dArr(arr, a);

	return 0;
}








