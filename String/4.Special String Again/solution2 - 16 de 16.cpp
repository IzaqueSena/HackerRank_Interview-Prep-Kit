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
 
// n + n = 2n =>O(n) time e O(1) space
long substrCount(int n, string s) {
    int result = 0;
    
    // looking for aaaaa
    // if are m repetions (in aaaaa there are 5), so 
    // the number of substrings is m*(m+1)/2
    for (int i = 0; i < n; ) {
        int char_count = 1;
        for (int j = i; j + 1 < n && s[j] == s[j+1] ;) {
            char_count++;
            j++;
        }
        result += char_count * (char_count + 1) / 2;
        i += char_count;
    }
    cout << result << endl;
    
    // looking for aaabaaa
    // if are m repetions (in aaabaaa there are 3), so
    // the number of substrings is m
    for (int i = 1; i < n; i++) {
        int char_count = 1;
        for (; s[i] != s[i-1] &&
            i+char_count<n &&
            s[i+char_count] == s[i-1] &&
            i-char_count >= 0 &&
            s[i-char_count] == s[i+char_count] ;) {
                char_count++;
            }
        result += char_count-1;
    }
    cout << result <<endl;
    return result;
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
