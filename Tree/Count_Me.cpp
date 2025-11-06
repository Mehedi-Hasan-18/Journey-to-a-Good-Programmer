#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        map<string, int> mp;

        while (ss >> word)
        {
            mp[word]++;
        }
        int maxCount = 0;
        string mostFrequentWord;
        for (auto it : mp)
        {
            if (it.second > maxCount)
            {
                maxCount = it.second;
            }
        }

        map<string, int>mp2;
        stringstream ss2(s);
        while (ss2 >> word)
        {
            mp2[word]++;
            if(mp2[word]==maxCount)
            {
                mostFrequentWord=word;
                break;
            }
        }

        cout << mostFrequentWord << " " << maxCount << "\n";
    }

    return 0;
}
