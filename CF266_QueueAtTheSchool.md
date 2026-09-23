# Queue at the School
Link: https://codeforces.com/problemset/problem/266/B

Type: Simulation

Difficulty: Easy

# Solution
Iterate $t$ times, each time going through the entire string. If you find a 'B' before a 'G', swap their positions.

Notice the edge case: `BGGG`. If you forget to **skip over the B-G pair when you find it**, your code will repeatedly swap the boy and girl **in the same time iteration**. This is because after swapping the boy and girl, it will move on to the next position, which is now the **same boy** since you just moved him into the next position
1. BGGG ($j=0$, swap B-G)
2. GBGG ($j=1$, swap B-G again)
3. GGBG ($j=2$, swap B-G again)
4. GGGB

So, remember to skip over the B-G pair when you find it. The correct sequence should be:
1. BGGG ($j=0$, swap B-G, skip over pair)
2. GBGG ($j=2$, no B, so do nothing)
3. GBGG
## Code
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, t;
    string line;
    cin >> N >> t >> line;

    // iterate t times
    for (int i=0; i<t; i++) {
        // go through the string (except last char)
        for (int j=0; j<N-1; j++) {
            if (line[j] == 'B' && line[j+1] == 'G') {
                // there is a boy before a girl
                line[j+1] = 'B';
                line[j] = 'G';
                j++; // skip over the B-G pair
            }
        }
    }

    cout << line;
}
```