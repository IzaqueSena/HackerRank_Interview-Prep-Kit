#include <bits/stdc++.h>
#include <unordered_map>
#include<map>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// 1hr+
// O(nlogn)
string isValid(string s) {
    unordered_map<char, int> freq;
    for (int i = 0; i < size(s); i++) {
        freq[s[i]]++;
    }
    map<int, int> freqOfFreq;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        freqOfFreq[it->second]++;
    }
    if (freqOfFreq.size() == 1) {
        return "YES";
    }
    if (freqOfFreq.size() == 2) {
        if (freqOfFreq.begin()->first == 1 && freqOfFreq.begin()->second == 1) {
            return "YES";
        }
        auto it = next(freqOfFreq.begin());
        if (it->first - freqOfFreq.begin()->first == 1 && it->second == 1) {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
