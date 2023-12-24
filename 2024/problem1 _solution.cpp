(Analysis by Nick Wu)
Subtask 1: N,M≤103
.

For this subtask, it suffices to simulate the process, as that would take (NM)
 time.

Python code is as follows:

n, m = (int(x) for x in input().split())
h = [int(x) for x in input().split()]
for curr in [int(x) for x in input().split()]:
  idx = 0
  taken = 0
  while idx < n:
    if h[idx] > taken:
      inc = min(curr, h[idx]) - taken
      h[idx] += inc
      taken += inc
    idx += 1
for x in h:
  print(x)
Full credit:

Only a small change is needed from the subtask solution to get full credit - specifically, if the candy cane is fully eaten, don't simulate the remaining cows trying to eat the candy cane, just break out of that loop and start the next iteration.

We can show that this process takes (M+Nlog109)
 time. Note that if any cow besides the first cow gets to eat any part of a given candy cane, this implies that the first cow was able to eat their height's worth of candy cane and doubles in height. Under the bounds of the given problem, the cow cannot double in height more than 30
 times.

Agastya Goel's C++ solution:

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 2e5+5;
ll heights[MAXN];
int n, m;
 
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> heights[i];
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		int l = 0;
		for (int j = 0; j < n && l < x; j++) {
			int diff = max(0, (int)min(heights[j], (ll)x)-l);
			heights[j] += diff;
			l += diff;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << heights[i] << '\n';
	}
}
My Java solution:

import java.io.*;
import java.util.*;
public class Solution {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int q = Integer.parseInt(st.nextToken());
    long[] h = new long[n];
    st = new StringTokenizer(br.readLine());
    for(int i = 0; i < n; i++) {
      h[i] = Long.parseLong(st.nextToken());
    }
    st = new StringTokenizer(br.readLine());
    while(q-- > 0) {
      long curr = Long.parseLong(st.nextToken());
      long taken = 0;
      for(int i = 0; i < n && taken < curr; i++) {
        long inc = Math.min(curr, h[i]) - taken;
        if(inc > 0) {
          h[i] += inc;
          taken += inc;
        }
      }
    }
    for(int i = 0; i < n; i++) pw.println(h[i]);
    pw.close();  
  }
}
Benjamin Qi's Python solution:

N, M = map(int, input().split())
 
cows = list(map(int, input().split()))
haybales = map(int, input().split())
 
for h in haybales:
	if h <= cows[0]:
		cows[0] += h
	else:
		h_so_far = 0
		for i in range(N):
			if cows[i] > h_so_far:
				next_h = min(cows[i], h)
				cows[i] += next_h - h_so_far
				h_so_far = next_h
 
 
for c in cows:
	print(c)
