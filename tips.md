### INT_MAX/MIN

```
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cout << INT_MAX << endl;  // 2147483647
    cout << INT_MIN << endl;  // -2147483648
}
```

### Tuple

```
#include <tuple>
    
    tuple<int, int, int> t = {8, 9, 10};
    cout << get<0>(t); // 8, first element
    get<2>(t) = 100;   // update the third element to 100
    cout << get<2>(t); // 100, third element 
```

### Find complexity

* vector: linear search, O(N)
* map, set: O(log N)
* unordered_map, unordered_set: O(1)
* bool array[]: O(1)


### Data Structure

* array intilization: global variable intialized with ZEROES. Not local variables.  Do array<int, 5> gadooky = {};
