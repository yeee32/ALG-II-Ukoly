#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<double> gauss(vector<vector<double>>& matrix, vector<double>& col_vector) {
    int n = matrix.size();

    for(int i = 0; i < n ; i++){
        matrix[i].push_back(col_vector[i]);
    }

    for(int i = 0; i < n; i++){
        int pivotRow = i;
        for(int j = i + 1; j < n; j++){
            if(abs(matrix[j][i]) > abs(matrix[pivotRow][i])){
                pivotRow = j;
            }
        }

        for(int k = i; k < n + 1; k++){
            swap(matrix[i][k], matrix[pivotRow][k]);
        }
        for(int l = i + 1; l < n; l++){
            double tmp = matrix[l][i] / matrix[i][i];
            for(int h = i; h <= n; h++){
                matrix[l][h] -= matrix[i][h]*tmp;
            }
        }
    }

    // zpetna sub
    vector<double> result(n);
    for(int i = n - 1; i >= 0; i--){
        double sum = matrix[i][n];
        for(int j = i + 1; j < n; j++){
            sum -= matrix[i][j] * result[j];
        }
        result[i] = sum / matrix[i][i];
    }

    return result;
}

vector<vector<double>> readMatrix() {
    vector<vector<double>> matrix;
    string line;

    while (getline(cin, line) && !line.empty()) {
        vector<double> row;
        istringstream iss(line);
        double value;
        while (iss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }

    return matrix;
}

vector<double> readVector() {
    vector<double> vec;
    string line;

    getline(cin, line);
    istringstream iss(line);
    double value;
    while (iss >> value) {
        vec.push_back(value);
    }

    return vec;
}

void printMatrix(const vector<vector<double>>& matrix) {
    cout << "Matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(10) << fixed << setprecision(3) << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const vector<double>& vec) {
    // cout << "Vector:" << endl;
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        // cout << setw(10) << fixed << setprecision(3) << elem << " ";
        cout << fixed << setprecision(3) << vec[i] << " ";
    }
    cout << vec[n-1] << endl;
}

int main() {
    double lim = 1e-9;
    vector<vector<double>> matrix = readMatrix();
    vector<double> vec = readVector();
    vector<double> res = gauss(matrix, vec);
    
    // printMatrix(matrix);
    // printVector(vec);
    
    int n = matrix.size();

    bool allZeros = true;
    for(int j = 0; j < n; j++){
        if(abs(matrix[n-1][j]) > lim){
            allZeros = false;
            break;
        }
    }


    if(allZeros && abs(matrix[n-1][n]) < lim){
        cout << "Nekonecne mnoho rerseni" << endl;
    }
    else if(allZeros && abs(matrix[n-1][n]) > lim){
        cout << "Zadne reseni" << endl;
    }
    else{
        printVector(res);
    }
    
    return 0;
}