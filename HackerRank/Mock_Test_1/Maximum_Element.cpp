//https://www.hackerrank.com/contests/iitb-2025-26-mock-coding-test-1/challenges/maximum-element
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMax' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY operations as parameter.
 */

vector<int> getMax(vector<string> operations) {
    vector<int> v,m;
    m.push_back(0);
    for(int i=0;i<int(operations.size());i++){
        string s=operations[i];
        int n=operations[i].size()-1;
        if(s[0]=='1'){
            int x=0;
            int mul=1;
            for(int i=n;i>=2;i--){
                x+=((s[i]-'0')*mul);
                mul*=10;
            }
            if(x>=m.back()){m.push_back(x);}
            else{m.push_back(m.back());}
        }
        else if(s[0]=='2'){
            m.pop_back();
        }
        else{
            v.push_back(m.back());
        }
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> ops(n);

    for (int i = 0; i < n; i++) {
        string ops_item;
        getline(cin, ops_item);

        ops[i] = ops_item;
    }

    vector<int> res = getMax(ops);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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