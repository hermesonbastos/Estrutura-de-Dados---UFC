#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  float l1, l2, l3, p, a;
  cin >> l1 >> l2 >> l3;
  
  p = (l1 + l2 + l3)/2;
  a = sqrt(p * (p - l1) * (p - l2) * (p - l3));
  
  cout << fixed << setprecision(2);
  cout << a;
}