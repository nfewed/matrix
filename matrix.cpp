#include <iostream>

// Бібліотеки, які потрібні для того, щоб випадково заповнити матрицю
// #include <ctime>
// #include <cstdlib>

int main() {
    int N;
    
    std::cout << "Enter a size of matrix: ";
    std::cin >> N;
    
    double** matrix = new double*[N];
    for ( int i = 0; i < N; i++ ) {
        matrix[i] = new double[N];
    }
    
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            std::cout << "matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
    
    // srand(time(0));
    // for ( int i = 0; i < N; i++ ) {
    //     for ( int j = 0; j < N; j++ ) {
    //         matrix[i][j] = rand() % 10;
    //     }
    // }
    
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
    
    for ( int q = 0, p = 0; q < N-1; q++ ) {
        if ( matrix[q][q+p] == 0 ) {
            int s = q+1;
            for ( ; matrix[s][q+p] == 0; s++ ) {
                if ( s == N-1 && matrix[s][q+p] == 0 ) {
                    p++;
                    s = q;
                }
            }
            
            for ( int w = 0, temp; w < N; w++ ) {
                temp = matrix[q][w];
                matrix[q][w] = matrix[s][w];
                matrix[s][w] = -1 * temp;
            }
        }
        for ( int i = q; i < N-1; i++ ) {
            for ( int j = N-1; j >= q+p; j-- ) {
                matrix[i+1][j] = matrix[i+1][j] - matrix[q][j] * (matrix[i+1][q+p]/matrix[q][q+p]);
            }
        }
    }
        
    std::cout << '\n';
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << '\n';
    }
    
    double det = 1;
    for ( int i = 0; i < N; i++ ) {
        det *= matrix[i][i];
    }
    std::cout << "Determinant:" << det << '\n';
    
    int zeroCount = 0;
    int defect = 0;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( matrix[i][j] == 0 ) {
                zeroCount++;
            }
        }
        if ( zeroCount == N ) {
            defect++;
        }
        zeroCount = 0;
    }
    std::cout << "Rank: " << N-defect << '\n';
    defect = 0;
    
    for ( int i = 0; i < N; i++ ) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}
