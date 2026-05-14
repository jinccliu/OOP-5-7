#include <iostream>
#include <vector>

using namespace std;

class matrix {
public:
    int N; 
    vector<vector<long long>> data; 

    matrix(int n) {
        N = n;
        data.assign(N, vector<long long>(N, 0));
    }

    static matrix* add(matrix* a, matrix* b) {
        matrix* result = new matrix(a->N);
        for (int i = 0; i < a->N; ++i) {
            for (int j = 0; j < a->N; ++j) {
                result->data[i][j] = a->data[i][j] + b->data[i][j];
            }
        }
        return result;
    }

    static matrix* sub(matrix* a, matrix* b) {
        matrix* result = new matrix(a->N);
        for (int i = 0; i < a->N; ++i) {
            for (int j = 0; j < a->N; ++j) {
                result->data[i][j] = a->data[i][j] - b->data[i][j];
            }
        }
        return result;
    }

    static matrix* multiple(matrix* a, matrix* b) {
        matrix* result = new matrix(a->N);
        for (int i = 0; i < a->N; ++i) {
            for (int j = 0; j < a->N; ++j) {
                result->data[i][j] = 0;
                for (int k = 0; k < a->N; ++k) {
                    result->data[i][j] += a->data[i][k] * b->data[k][j];
                }
            }
        }
        return result;
    }

    void print() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << data[i][j] << (j == N - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
};

int main() {
    int n;

    if (!(cin >> n) || n < 2 || n > 3) {
        return 0; 
    }

    matrix* A = new matrix(n);
    matrix* B = new matrix(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A->data[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B->data[i][j];
        }
    }

    int choice;

    while (true) {
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. multiplication" << endl;
        cout << "4. Exit" << endl;
        
        cin >> choice;

        if (choice == 1) {
            matrix* C = matrix::add(A, B);
            C->print();
            delete C; 
        } 
        else if (choice == 2) {
            matrix* C = matrix::sub(A, B);
            C->print();
            delete C;
        } 
        else if (choice == 3) {
            matrix* C = matrix::multiple(A, B);
            C->print();
            delete C;
        } 
        else if (choice == 4) {
            break; 
        }
    }

    delete A;
    delete B;

    return 0;
}

