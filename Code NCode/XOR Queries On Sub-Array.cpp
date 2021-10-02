
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {

        vector<int> sumUpto[arr.size()];

        for (int i = 0; i < 32; i++)
            sumUpto[0].push_back((bool)(arr[0] & (1 << i)));
        // for (int a : sumUpto[0])
        //     cout << a << " ";
        // cout << endl;
        // for (int j = 1; j < arr.size(); j++)
        {
            for (int i = 0; i < 32; i++)
            {
                sumUpto[j].push_back(sumUpto[j - 1][i] + (bool)(arr[j] & (1 << i)));
            }
            // for (int a : sumUpto[j])
            //     cout << a << " ";
            // cout << endl;
            // ;
        }

        vector<int> ans;
        int temp;
        for (int j = 0; j < queries.size(); j++)
        {
            temp = 0;
            for (int i = 0; i < 32; i++)
            {
                int bits = sumUpto[queries[j][1]][i] - sumUpto[queries[j][0]][i] + (int)((bool)(arr[queries[j][0]]&(1<<i))) ;
                if (bits % 2 == 1)
                    temp += (1 << i);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {4, 8, 2, 10};
    vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
    Solution sol;
    vector<int> ans = sol.xorQueries(arr, queries);
    cout << endl
         << endl;
    for (int a : ans)
        cout << a << " ";
}
