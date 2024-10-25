#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

double findConstantTerm(const vector<pair<int, int>>& points) {
    int k = points.size();
    MatrixXd A(k, k);
    VectorXd B(k);

    for (int i = 0; i < k; i++) {
        int x = points[i].first;
        int y = points[i].second;
        B(i) = y;
        for (int j = 0; j < k; j++) {
            A(i, j) = pow(x, j);
        }
    }

    VectorXd coeffs = A.colPivHouseholderQr().solve(B);
    return coeffs(0);
}

int main() {
    vector<pair<int, int>> points = {{1, 3}, {2, 5}, {3, 7}, {4, 9}};
    double constantTerm = findConstantTerm(points);
    cout << "The constant term of the polynomial is: " << constantTerm << endl;
    return 0;
}