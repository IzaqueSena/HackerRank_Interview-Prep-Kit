#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

// n*n + n*n = 2n² = O(n²) time
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> substrs;
    int anagrams = 0;
    for (int i = 0; i < size(s); i++) {
        for (int j = i; j < size(s); j++) {
            auto substr = s.substr(i, j - i + 1);
            sort(substr.begin(), substr.end());
            cout << substr << ".i: " << i << "j: " << j << endl;
            substrs[substr]++;
        }
    }
    for (auto it = substrs.begin(); it != substrs.end(); it++) {
        auto n = it->second;
        cout << "key: " << it->first << " value: " << it->second << endl;
        anagrams += n*(n-1)/2;
    }
    return anagrams;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

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
