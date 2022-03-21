#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // this is my approach
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        map<string, bool> m;
        for (int i = 0; i < wordList.size(); i++)
        {
            m[wordList[i]] = true;
        }
        if (m.find(endWord) == m.end())
        {
            return 0;
        }
        map<string, bool> visited;
        int count = INT_MAX;
        while (!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            string str = word;
            // cout<<word<<endl;
            visited[word] = true;
            for (int j = 0; j < str.length(); j++)
            {
                for (char i = 'a'; i <= 'z'; i++)
                {
                    str[j] = i;
                    if (m.find(str) != m.end() && !visited[str])
                    {
                        if (str.compare(endWord) == 0)
                        {
                            count = min(count, len + 1);
                            continue;
                        }
                        else
                        {
                            visited[str] = true;
                            q.push({str, len + 1});
                        }
                    }
                }
                str = word;
            }
        }
        if (count == INT_MAX)
        {
            return 0;
        }
        return count;
    }
};