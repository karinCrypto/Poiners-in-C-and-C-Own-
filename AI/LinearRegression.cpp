//C++ 선형 회귀 (경사 하강법)

#include <iostream>
#include <vector>
using namespace std;

class LinearRegression {
private:
    double w;  
    double b;  
    double lr; 

public:
    LinearRegression(double lr=0.01) : w(0), b(0), lr(lr) {}

    double predict(double x) {
        return w * x + b;
    }

    void train(const vector<double>& X, const vector<double>& y, int epochs) {
        int n = X.size();

        for (int e = 0; e < epochs; e++) {
            double dw = 0, db = 0;

            for (int i = 0; i < n; i++) {
                double pred = predict(X[i]);
                dw += (pred - y[i]) * X[i];
                db += (pred - y[i]);
            }

            dw /= n;
            db /= n;

            w -= lr * dw;
            b -= lr * db;
        }
    }
};

int main() {
    vector<double> X = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4, 6, 8, 10};

    LinearRegression model;
    model.train(X, y, 500);

    cout << model.predict(6) << endl; // 12와 비슷하게 나옴
}
