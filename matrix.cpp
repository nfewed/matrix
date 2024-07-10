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
    
    int flag = 1;
    for ( int k = 0; k < N-1; k++ ) {
        for ( int i = k; i < N-1; i++ ) {
            for ( int j = N-1; j >= k; j-- ) {
                if ( matrix[k][k] == 0 ) {
                    int u = k+1;
                    for ( ; matrix[u][k] == 0; u++ ) {
                        if ( u == N-1 && matrix[u][k] == 0) {
                            flag = 0;
                            break;
                        }
                    }
                    
                    for ( int v = k; v < N; v++ ) {
                        matrix[k][v] = matrix[u][v];
                        matrix[u][v] = 0;
                    }
                }
                
                if ( flag ) {
                    matrix[i+1][j] = matrix[i+1][j] - matrix[k][j] * (matrix[i+1][k]/matrix[k][k]);
                }
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
