#include <bits/stdc++.h>
using namespace std;

class Matrix {
    public:
        Matrix(int N) : N(N) {
            a = new float*[N];
            for (int i = 0; i < N; ++i) {
                a[i] = new float[N];
            }
        }
        ~Matrix() {
            for (int i = 0; i < N; ++i) {
                delete a[i];
            }
            delete[] a;
        }
        void init() {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    cin >> a[i][j];
                }
            }
        }
        void show() {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }
        int size() {
            return N;
        }
        float* operator[](int i) {

                return a[i];

            }
    private:
        int N;
        float **a;
};
bool condition(Matrix &matrix) {
    return true;
}
void transpose(Matrix &matrix, Matrix &matrixT) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrixT[j][i] = matrix[i][j];
        }
    }
}
Matrix MatrixDes(Matrix& matrix) {
    if (!condition(matrix)) throw string("NOT!");
    int n = matrix.size();
    Matrix dest(n), destT(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += dest[i][k] * destT[j][k];
            }
            if (i == j) {
                dest[i][i] = sqrt(matrix[i][i] - sum);
                destT[i][i] = dest[i][i];
            } else {
                dest[i][j] = (matrix[i][j] - sum) / dest[i][i];
                destT[j][i] = dest[i][j];
            }
        }
    }
    return dest;
}
int main() {
    const int N = 3;
    Matrix matrix(N);
    Matrix failureMatrix(N);
    matrix.init();
    failureMatrix.init();

    Matrix finalL(N);
    try {
        finalL = MatrixDes(matrix);
    } catch (string e) {
        cout << "catching\n";
        cout << e << endl;
        return 0;
    } 
    finalL.show();
}