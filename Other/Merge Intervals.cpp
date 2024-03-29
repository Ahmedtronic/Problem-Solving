#include<cmath>
#include <iostream>
#include<algorithm>
#include <vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_map>
#include <map>
using namespace std;
#define ll long long
#define endl '\n'
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define clear1(x) memset(x,-1,sizeof(x))
#define clear0(x) memset(x,0,sizeof(x))

/// وَاصْبِرْ لِحُكْمِ رَبِّكَ فَإِنَّكَ بِأَعْيُنِنَا ❤  ////



int n, m;

int main()
{
    
    fast;
    cin >> n >> m;
    vector<pair<ll,ll>> intervals(n);
    for (int i = 0 ; i< n ; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    // next we will merge them ( merge Intervals )
    sort(intervals.begin(), intervals.end());
    
    vector<pair<ll,ll>> mergedintervals;
    mergedintervals.push_back(intervals[0]);
    
    for (int i = 1 ; i < n ; i++)
    {
        if (mergedintervals.back().second >= intervals[i].first && (mergedintervals.back().second <= intervals[i].second || mergedintervals.back().second >= intervals[i].second) )
        {
            mergedintervals.back().second = max(mergedintervals.back().second, intervals[i].second);
        }
        else
        {
            mergedintervals.push_back(intervals[i]);
        }
    }
  
   // printing new Intervals:
    for ( auto interval : mergedintervals)
        cout << interval.first << " " << interval.second << endl;
}
