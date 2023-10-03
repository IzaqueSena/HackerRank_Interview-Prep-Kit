#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */
 
bool isSpecial(string s) {
    cout << s << " ";
    char prev;
    if (s.size() > 0) {
        prev = s[0];
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != prev) {
            if (s.size() % 2 != 0 && i == s.size()/2) {
                continue;
            } else {
                cout << "false" << endl;
                return false;
            }
        }
    }
    cout << "true" << endl;
    return true;
}

// 13min
// n + n-1 + n-2 +... + 1 + [n-1+n-2+..+1] + [n-2+..+1] = (n + 1)*n/2 + (n-1+1)*(n-1)/2 entre n² e n³
// O(n²)<O<O(n³) time
long substrCount(int n, string s) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isSpecial(s.substr(i, j - i + 1))) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
