// C++ KNN
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 거리 계산
double distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += pow(a[i] - b[i], 2);
    return sqrt(sum);
}

class KNN {
private:
    int K;
    vector<vector<double>> X;
    vector<int> y;

public:
    KNN(int K) : K(K) {}

    void fit(const vector<vector<double>>& data, const vector<int>& labels) {
        X = data;
        y = labels;
    }

    int predict(const vector<double>& x) {
        vector<pair<double, int>> dist_list;

        for (int i = 0; i < X.size(); i++)
            dist_list.push_back({ distance(x, X[i]), y[i] });

        sort(dist_list.begin(), dist_list.end());

        int count0 = 0, count1 = 0;
        for (int i = 0; i < K; i++) {
            if (dist_list[i].second == 0) count0++;
            else count1++;
        }
        return (count1 > count0) ? 1 : 0;
    }
};

int main() {
    vector<vector<double>> data = {
        {1,2}, {2,3}, {3,3},
        {8,7}, {9,6}, {8,8}
    };
    vector<int> labels = {0,0,0, 1,1,1}; // 두 클래스

    KNN knn(3);
    knn.fit(data, labels);

    cout << knn.predict({2,2}) << endl; // 0 예상
    cout << knn.predict({9,7}) << endl; // 1 예상
}
