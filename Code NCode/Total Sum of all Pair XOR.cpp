
#include <bits/stdc++.h>
using namespace std;

// L06 : Total Sum of all Pair XOR | Bit Manipulation Course

int main()
{
    vector<int> arr = {5 , 3 , 9};
    int ans = 0;
    for(int i = 0; i<32 ; i++){
        int zero = 0;
        int one = 0;

        for(int j = 0; j<arr.size() ; j++){
            if(arr[j]&(1<<i)) one++;
            else zero++;
        }

        ans += (zero*one)*(1<<i);
    }
    cout << ans;
}







