(Analysis by Suhas Nagar)
The number of days D
 is uncertain, but if we knew the number of days that have passed from the initial configuration, solving the problem would be easier, since we can think of each initially infected cow as a window of 2D+1
 ones (since the infection spreads D units to the left and right of the originally infected cow) and we want to cover the infected cows in the input with the minimal amount of these windows.

We first notice that our windows can overlap. Suppose we wanted to cover 8 cows with windows of size 5. It is fine to use two windows and have a two cow overlap, because an already infected cow cannot get reinfected.

This leads us to see that if there are multiple values of D
 that allow for an end state to be feasible, the maximal value of D
 will always correspond to the minimum number of initial cows, since we want to prioritize each window covering the most amount of cows.

Seemingly, the maximum window that we can use would be the minimum contiguous region of 1
s in the input, as if the window we pick was any larger, that region would be impossible to cover. However, there are two special cases.

Case 1 (End Pieces): If there is a group of I
 infected cows on either end of our list, it is possible for the initial infected cow to have been the one on the very edge, in which case our maximum window could be up to 2∗I−1
 instead of just I

Case 2 (Even Pieces): If there is a group of I
 infected cows where I
 is even, it is impossible for this to have been covered by a single cow. Instead, we must have had at least two cows, so the maximum window in this case is I−1
 instead of I
.

Now, we can calculate the maximum value of D
 possible by taking the minimum windows across the end, even, and odd cases and then summing the ceiling of ID
 for every contiguous group of I
 infected cows.

import java.io.*;
import java.util.*;

public class CowntactTracing2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String s = in.readLine();
        ArrayList<Integer> segments = new ArrayList<>();
        int region = 0;
        for (int i = 0; i < n; i++){
            if (s.charAt(i) == '1'){
                region++;
            }else{
                if (region > 0) segments.add(region);
                region = 0;
            }
        }
        if (region > 0) segments.add(region);
        int[] minBlock = {Integer.MAX_VALUE, Integer.MAX_VALUE};
        int minEnd = Integer.MAX_VALUE;
        int sind = 0; int eind = segments.size()-1;
        if (s.charAt(0) == '1') {
            minEnd = Math.min(minEnd, segments.get(0));
            sind++;
        }
        if (s.charAt(n-1) == '1') {
            minEnd = Math.min(minEnd, segments.get(eind));
            eind--;
        }
        for (int i = sind; i <= eind; i++){
            minBlock[segments.get(i)%2] = Math.min(minBlock[segments.get(i)%2], segments.get(i));
        }
        int daySpread = Math.min(minEnd*2-1, Math.min(minBlock[0]-1, minBlock[1]));
        int numInfected = 0;
        for (int block : segments){
            numInfected += (block+daySpread-1)/daySpread;
        }
        System.out.println(numInfected);
    }
}
Alternatively, we could have simulated all possible values of "windows" from 1
 to N
, breaking when we find the first invalid window, and take the minimum across all possible values. We can break early since if we are unable to cover our input with some window, we cannot use a larger window to cover it. The time complexity here is O(N)
. Let the number of regions of contiguous 1
s be R
. We iterate R
 times for every window, and the maximum window we check is bounded by NR
 so we have O(R∗NR)=O(N)

import java.io.*;
import java.util.*;

public class CowntactTracing2 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String s = in.readLine();
        ArrayList<Integer> segments = new ArrayList<>();
        int region = 0;
        for (int i = 0; i < n; i++){
            if (s.charAt(i) == '1'){
                region++;
            }else{
                if (region > 0) segments.add(region);
                region = 0;
            }
        }
        if (region > 0) segments.add(region);
        int numInfected = n;
        outer: for (int window = 1; window <= n; window += 2){
            int tempInfected = 0;
            for (int i = 0; i <  segments.size(); i++){
                int block = segments.get(i);
                //if block is an end piece
                if ((i == 0 && s.charAt(0) == '1') || (i == segments.size()-1 && s.charAt(n-1) == '1')){
                    if (window > block*2-1) break outer;
                }else {
                    if (window > block) break outer;
                }
                tempInfected += (block+window-1)/window;
            }
            numInfected = Math.min(numInfected,tempInfected);
        }
        System.out.println(numInfected);
    }
}
