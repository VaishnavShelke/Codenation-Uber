#include<bits/stdc++.h>
using namespace std;


#define ff first
#define ss second


int dis_x[4] = {0,1,-1,0};
int dis_y[4] = {1,0,0,-1};

class comparer{
public:
    bool operator()(pair<int,pair<int,int>>& p1,pair<int,pair<int,int>>& p2){
        return p1.ff>p2.ff;
    }
};


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> arr = heightMap;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,comparer> minHp;

        int wd = heightMap[0].size();
        int ht = heightMap.size();

        for(int i = 1; i<wd-1 ; i++){
            minHp.push({arr[0][i],{0,i}});
            minHp.push({arr[ht-1][i],{ht-1,i}});
            arr[0][i] = -1; arr[ht-1][i] = -1;
        }

        for(int j = 0; j<ht ; j++){
            minHp.push({arr[j][0],{j,0}});
            minHp.push({arr[j][wd-1],{j,wd-1}});
            arr[j][0] = -1; arr[j][wd-1] = -1;
        }

        int i,j,htt,ii,jj;
        int ans = 0;
        int threshold = 0;
        while(!minHp.empty()){
            j = minHp.top().ss.ff;
            i = minHp.top().ss.ss;
            htt = minHp.top().ff;
            minHp.pop();
            threshold = max(threshold,htt);

            for(int k = 0; k<4 ; k++){
                ii = i + dis_x[k]; jj = j + dis_y[k];
                if(ii<wd && ii>=0 && jj<ht && jj>=0 && arr[jj][ii] != -1){
                    if(arr[jj][ii]<threshold) { cout << threshold-arr[jj][ii] << endl; ans += threshold-arr[jj][ii];}
                    minHp.push({arr[jj][ii],{jj,ii}});
                    arr[jj][ii] = -1;
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};

    Solution sol;
    cout << sol.trapRainWater(heightMap);
}
