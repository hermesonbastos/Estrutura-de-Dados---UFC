#include <iostream>
#include <string>

using namespace std;

int countChar(string str, int n, char c, int count) {
    if (n == 0) {
        return 0;
    }
    
    count = countChar(str, n-1, c, count);
    
    if (str[n-1] == c) {
        count++;
    }
    
    return count;
}

int main() {
    int count = 0;
    string str;
    char c;
    getline(cin, str);
    cin >> c;
    cout << countChar(str, str.length(), c, count) << endl;
    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int countChar(string str, int n, char c) {
//     if (n == 0) {
//         return 0;
//     }
//     int count = countChar(str, n-1, c);
//     if (str[n-1] == c) {
//         count++;
//     }
//     return count;
// }

// int main() {
//     string str;
//     char c;
//     getline(cin, str);
//     cin >> c;
//     cout << countChar(str, str.length(), c) << endl;
//     return 0;
// }