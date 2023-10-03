#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

// 10min
// n + n + 2n = 4n => O(n) time
// O(2n) = O(n) space
int makeAnagram(string a, string b) {
    unordered_map<char, int[2]> frequencies;
    int count = 0;
    for (int i = 0; i < size(a); i++) {
        frequencies[a[i]][0]++;
    }
    for (int i = 0; i < size(b); i++) {
        frequencies[b[i]][1]++;
    }
    for (auto it = frequencies.begin(); it != frequencies.end(); it++) {
        count += abs(it->second[0] - it->second[1]);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
