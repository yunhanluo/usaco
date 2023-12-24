(Analysis by Nick Wu, Chongtian Ma)
Subtask 1: N≤2
.

Consider only two plants. Let i
 and j
 be indices such that ti=0
 and tj=1
. If hi>hj
, then we don't need to spend any time growing the plants. Otherwise, we can break it up into cases.

If ai>aj
, after each day, plant i
 grows ai−aj
 more inches than plant j
. The number of days it takes for plant i
 to be at least one inch taller is ⌈hj−hi+1ai−aj⌉
.

If ai≤aj
, there is no way for plant i
 to be able to surpass plant j
 in height. We output −1
.

Nick Wu's Python code:

def mintime(hi, ai, hj, aj):
    # return the smallest time when plant i, with height h[i] and growth rate a[i]
    # is strictly taller than plant j, with height h[j] and growth rate a[j]
    # returns -1 if this is impossible
    if hi > hj: return 0
    if ai <= aj: return -1
    return (hj-hi) // (ai-aj) + 1

def solve():
    n = int(input())
    assert n <= 2
    h = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    t = [int(x) for x in input().split()]
    if n == 1: return 0
    if t[0] == 0:
        return mintime(h[0], a[0], h[1], a[1])
    else:
        return mintime(h[1], a[1], h[0], a[0])
 
t = int(input())
for _ in range(t):
    print(solve())
Subtask 2: N≤50
 and ai,hi≤103
.

From the first subtask, we can observe that based on the bounds of ai
 and hi
, if there is a value of x
 number of days that satisfies Farmer John's request, then it must be at most 1000
. Therefore, for this subtask, it suffices to just check all times from 0
 to 1000
 and print the earliest one that works, or otherwise, claim it is impossible.

Python code is as follows:

def solve():
    n = int(input())
    h = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    t = [int(x) for x in input().split()]
    assert n <= 50
    assert max(a) <= 1000
    assert max(h) <= 1000
    for ret in range(1002):
        heights = [h[i] + a[i] * ret for i in range(n)]
        tcomp = [sum([heights[i] < heights[j] for j in range(n)]) for i in range(n)]
        if tcomp == t:
            return ret
    return -1
 
t = int(input())
for _ in range(t):
    print(solve())
Subtask 3: N≤103
.

We'll leverage the N=2
 subtask repeatedly here. If plants i
 and j
 have ti<tj
, then we know that plant i
 must eventually be taller than plant j
. From the N=2
 subtask, if ai>aj
 and hi≤hj
, that gives us a lower bound on what x
 can be. We can take all of the lower bounds from all pairs of plants and use the strictest one as our candidate answer. If at any point there is no valid value of x
, then it is impossible to satisfy FJ.

def mintime(hi, ai, hj, aj):
    # return the smallest time when plant i, with height h[i] and growth rate a[i]
    # is strictly taller than plant j, with height h[j] and growth rate a[j]
    # returns -1 if this is impossible
    if hi > hj: return 0
    if ai <= aj: return -1
    return (hj-hi) // (ai-aj) + 1

def solve():
    n = int(input())
    assert n <= 1000
    h = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    t = [int(x) for x in input().split()]
    ret = 0
    for i in range(n):
        for j in range(n):
            if t[i] < t[j]:
                candt = mintime(h[i], a[i], h[j], a[j])
                if candt < 0:
                    return -1
                ret = max(ret, candt)
    heights = [h[i] + a[i] * ret for i in range(n)]
    tcomp = [sum([heights[i] < heights[j] for j in range(n)]) for i in range(n)]
    if tcomp == t:
        return ret
    return -1
 
t = int(input())
for _ in range(t):
    print(solve())
Full credit:

To get full credit on this problem, we claim that it is sufficient to only check pairs of plants i
 and j
 where |ti−tj|=1
. The reason for this is that the relation of being taller or shorter than another plant is transitive - if you have plants i
, j
, and k
, where ti>tj>tk
, and plant i
 is always shorter than plant k
, if plant j
 is also shorter than plant i
, then plant j
 is necessarily shorter than plant k
. Therefore, checking plants where |ti−tj|>1
 is unnecessary.

Therefore, after sorting the plants in order of ti
, it takes (N)
 time to check that adjacent plants respect the height constraint. Sorting takes (NlogN)
, so the final solution is (NlogN)
.

Note that because the ti
 values are 0,1,2,…,N−1
 in some order, it is possible to order the plants directly without needing to sort them. If we initialize another array p
 where pi
 stores the index j
 where tj=i
, we may use pi
 in place of i
. This solution is (N)
, though this optimization was not necessary to get full credit.

Chongtian Ma's C++ solution (which shows how to do it in linear time):

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ceil_div(ll a, ll b){
	return (a + b - 1) / b;
}
 
int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<ll> height(N), add(N), t(N);
        for(ll& i: height) cin >> i;
        for(ll& i: add) cin >> i;
        for(ll& i: t) cin >> i;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            p[t[i]] = i;
        }
        ll days = 0;
        for(int i = N - 2; i >= 0; i--){
            int small_idx = p[i + 1], big_idx = p[i];
            ll h_diff = (height[small_idx] + add[small_idx] * days) - (height[big_idx] + add[big_idx] * days);
            if(h_diff >= 0){
                ll a_diff = add[big_idx] - add[small_idx];
                if(a_diff <= 0){
                    days = -1;
                    break;
                }
                days += ceil_div(h_diff + 1, a_diff);
            }
        }
        for(int i = N - 2; i >= 0; i--){
            ll big_days = height[p[i]] + add[p[i]] * days;
            ll small_days = height[p[i+1]] + add[p[i+1]] * days;
            if(small_days >= big_days){
                days = -1;
                break;
            }
        }
        cout << days << "\n";
    }
}
Nick Wu's Java solution (with sorting):

import java.io.*;
import java.util.*;
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int t = Integer.parseInt(br.readLine());
        while(t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] h = readArray(br, n);
            int[] a = readArray(br, n);
            int[] p = readArray(br, n);
            long ret = 0;
            int[] ordByGoalHeight = new int[n];
            for(int i = 0; i < n; i++) ordByGoalHeight[i] = i;
            ordByGoalHeight = Arrays.stream(ordByGoalHeight).boxed().sorted((i, j) -> p[j] - p[i]).mapToInt(i -> i).toArray();
            for(int i = 0; i + 1 < n; i++) {
                int smaller = ordByGoalHeight[i];
                int larger = ordByGoalHeight[i + 1];
                if(h[smaller] >= h[larger] && a[larger] > a[smaller]) {
                    ret = Math.max(ret, ceilingDiv(h[smaller] - h[larger] + 1, a[larger] - a[smaller]));
                }
            }
            long[] trueHeights = new long[n];
            for(int i = 0; i < n; i++) {
                trueHeights[i] = h[i] + a[i] * ret;
            }
            for(int i = 0; i + 1 < n && ret >= 0; i++) {
                int smaller = ordByGoalHeight[i];
                int larger = ordByGoalHeight[i + 1];
                if(trueHeights[smaller] >= trueHeights[larger]) ret = -1;
            }
            pw.println(ret);
        }
        pw.close();
    }
    private static long ceilingDiv(long a, long b) {
        // a and b are both positive
        return (a + b - 1) / b;
    }
    private static int[] readArray(BufferedReader br, int n) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] ret = new int[n];
        for(int i = 0; i < n; i++) {
            ret[i] = Integer.parseInt(st.nextToken());
        }
        return ret;
    }
}
Nick Wu's Python solution (also with sorting):

def ceilingDiv(a, b):
    return (a + b - 1) // b
 
def solve():
    n = int(input())
    h = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    t = [int(x) for x in input().split()]
    ord = [i for i in range(n)]
    ord.sort(key=lambda x: t[x])
    ret = 0
    for ordi in range(n-1):
        i = ord[ordi]
        j = ord[ordi+1]
        if h[i] < h[j] and a[i] > a[j]:
            ret = max(ret, ceilingDiv(h[j] - h[i] + 1, a[i] - a[j]))
    for i in range(n):
        h[i] += a[i] * ret
    for ordi in range(n-1):
        i = ord[ordi]
        j = ord[ordi+1]
        if h[i] <= h[j]: return -1
    return ret
 
t = int(input())
for _ in range(t):
    print(solve())
