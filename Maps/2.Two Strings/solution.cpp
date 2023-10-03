#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
 
map<char, int> frequenciesChars(string s) {
    map<char, int> chars;
    for (int i = 0; i < size(s); i++) {
        if (chars.find(s[i]) != chars.end()) {
            chars[s[i]]++;
        } else {
            chars[s[i]] = 1;
        }
    }
    return chars;
}

// 7min
// n1 + n2*O(find in map) time
string twoStrings(string s1, string s2) {
    auto charsS1 = frequenciesChars(s1);
    for (int i = 0; i < size(s2); i++) {
        if (charsS1.find(s2[i]) != charsS1.end()) {
            return "YES";
        }
    } 
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

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
