#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // this is my approach
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        queue<tuple<string, int, vector<string>>> q;
        vector<string> v;
        v.push_back(beginWord);
        q.push({beginWord, 1, v});
        map<string, bool> m;
        for (int i = 0; i < wordList.size(); i++)
        {
            m[wordList[i]] = true;
        }
        if (m.find(endWord) == m.end())
        {
            return ans;
        }
        map<string, bool> visited;
        int count = INT_MAX;

        while (!q.empty())
        {

            string word = get<0>(q.front());
            int len = get<1>(q.front());
            vector<string> temp = get<2>(q.front());
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
                            if (count == len + 1)
                            {
                                temp.push_back(str);
                                ans.push_back(temp);

                                continue;
                            }
                            else if (count > (len + 1))
                            {
                                ans.clear();
                                temp.push_back(str);
                                ans.push_back(temp);
                            }
                        }
                        else
                        {
                            temp.push_back(str);
                            q.push({str, len + 1, temp});
                            temp.pop_back();
                        }
                    }
                }
                str = word;
            }
        }

        return ans;
    }
};