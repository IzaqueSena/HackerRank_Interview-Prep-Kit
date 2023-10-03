#include <bits/stdc++.h>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

map<long, long> frequencies(vector<long> arr) {
    map<long, long> freq;
    for (int i = 0; i < arr.size(); i++ ){
        freq[arr[i]]++;
    }
    return freq;
}

// Complete the countTriplets function below.
//O(n³)
long countTriplets(vector<long> arr, long r) {
    sort(arr.begin(), arr.end());
    long triplets = 0;
    for (long i = 0; i < arr.size() - 2; i++) {
        cout << "i:" << i << " " << "a[i]: " << arr[i] << " ";
        for (long j = i + 1; j < arr.size() - 1; j++) {
            cout << "j:" << j << " " << "a[j]" << arr[j] << " ";
            if (arr[i] * r != arr[j]) {
                if (arr[i] * r > arr[j]) {
                    continue;
                } else {
                    break;
                }
            }
            for (long k = j + 1; k < arr.size(); k++) {
                cout << "k:" << k << " " << "a[k]: " << arr[k] << " ";
                if (arr[j] * r != arr[k]) {
                    if (arr[j] * r > arr[k]) {
                        continue;
                    } else {
                        break;
                    }
                }
                cout << " +1+ ";
                triplets++;
            }
        }
    }
    return triplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
