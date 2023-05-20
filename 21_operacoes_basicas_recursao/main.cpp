#include <iostream>
#include <vector>

using namespace std;

void print_reverse_vector(vector<int>& v, int i) {
    if (i >= 0) {
        cout << v[i] << " ";
        print_reverse_vector(v, i-1);
    }
}

void sum(vector<int>& v, int i, int& result) {
    if (i >= 0) {
        result += v[i];
        sum(v, i-1, result);
    }
}

void mult(vector<int>& v, int i, int& result) {
    if (i >= 0) {
        result *= v[i];
        mult(v, i-1, result);
    }
}

void min(vector<int>& v, int i, int& result) {
    if (i == 0) {
        result = v[i];
    } else {
        min(v, i-1, result);
        result = (v[i] < result) ? v[i] : result;
    }
}

void invert(vector<int>& v, int i, int j) {
    if (i < j) {
        swap(v[i], v[j]);
        invert(v, i+1, j-1);
    }
}

int main() {
    vector<int> v;

    int x;
    while (cin >> x) {
        v.push_back(x);
    }

    cout << "vet : [ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;

    cout << "rvet: [ ";
    print_reverse_vector(v, v.size()-1);
    cout << "]" << endl;

    int sum_result = 0;
    sum(v, v.size()-1, sum_result);
    cout << "sum : " << sum_result << endl;

    int mult_result = 1;
    mult(v, v.size()-1, mult_result);
    cout << "mult: " << mult_result << endl;

    int min_result;
    min(v, v.size()-1, min_result);
    cout << "min : " << min_result << endl;

    invert(v, 0, v.size()-1);

    cout << "inv : [ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
