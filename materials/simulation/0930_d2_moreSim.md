# CST Day 2: More Simulation
**Goals:**
1. Have made a **[USACO](https://usaco.org), [CF](https://codeforces.com), and [CSES](https://cses.fi) account**
2. Remember what **simulation** is
3. Be able to **reason through simulation problems logically**
4. Be able to **implement solutions for simple simulation problems**
5. Explore more **difficult simulation problems**

# Review: Simulation + How to C++
*Refer to [Day 1 Notes](0923_d1_sim_howToCPP.md) for the comprehensive notes; below are select notes.*

## Template
Here's a template to get you started with every problems:
```cpp
#include <iostream>
// #include more headers as needed
using namespace std;

int main() {
    // code here
}
```

Remember that certain structures or functions require you to `#include` more headers. Here are some common ones you'll keep seeing:
```cpp
#include <iostream>     // cin & cout
#include <vector>       // vectors (resizable arrays)
#include <string>       // strings
#include <cmath>        // math functions like sqrt() or pow()
#include <algorithm>    // advanced functions
```

Always refer to C++'s documentation if you need to figure out what a function does: [Devdoc's C++ Reference](https://devdocs.io/cpp/) or the much scarier [C++ Reference Wiki](https://cppreference.com)

## Common Patterns
1. Comprog problems always tell you the size of the data you will receive; this makes it easy for you to.
2. Some problems will give you multiple 'queries' each test case. E.g., [Majority Opinion (USACO Bronze 2024)](https://usaco.org/index.php?page=viewproblem2&cpid=1371). Each query is one set of inputs.<br/>If this is the case (pun intended), focus on solving the main problem *(note that they usually do this to make sure your code runs fast enough, so be careful!)*.<br/> Then, just loop that code $Q$ times:
```cpp
void solve() {
    // code to solve the problem here
}

int main() {
    int Q; // number of queries
    cin >> Q;

    // Fancy way to run the same code Q times
    while (Q--) {
        solve(); // solve the individual query
    }
}
```

### Simulation-Specific Patterns
**Basic:**
1. **Time-based**: These problems give you something that happens over time, and your job is usually to track the process and output some data.
    1. [Speeding Ticket](../../problems/B15_16_SpeedingTicket.md) (USACO Bronze 2015)
    2. [Weird Algorithm](https://cses.fi/ckvo8q5wh/task/1068) (CSES)
    3. [Bear and Big Brother](https://codeforces.com/problemset/problem/791/A) (CF)
2. **1D and 2D Directional**: These problems make you simulate movement on a 1D line or 2D plane.
    1. [The Lost Cow](../../problems/B16_16_TheLostCow.md) (USACO Bronze 2016)
    2. [Robot Sequence](https://codeforces.com/problemset/problem/626/A) (CF)

**More difficult:**

3. **Event-driven**: When the maximum number of steps that need to be simulated is too large, simulate the number of **meaningful** state changes.
    1. [Restaurant Customers](../../problems/CSES_RestaurantCustomers.md) (CSES)

# Practice Problems
Some problems have editorials written by us and some don't. Try not to look at the solution before thinking about the problem for at least 30 minutes by yourself.

**Really easy:**
- [In Search of an Easy Problem](../../problems/CF1030_InSearchOfAnEasyProblem.md) (CF)
- [Wrong Subtraction](../../problems/CF977A_WrongSubtraction.md) (CF)
- [The Lost Cow](../../problems/B16_16_TheLostCow.md) (USACO Bronze 2016)
- [Weird Algorithm](https://cses.fi/ckvo8q5wh/task/1068) (CSES)
- [Bear and Big Brother](https://codeforces.com/problemset/problem/791/A) (CF)

**Easy:**
- *[Bovine Shuffle](../../problems/B17_18_BovineShuffle.md) (USACO Bronze 2017)
- *[Speeding Ticket](../../problems/B15_16_SpeedingTicket.md) (USACO Bronze 2015)
- *[Circular Barn](../../problems/B15_16_CircularBarn.md) (USACO Bronze 2015)
- [Robot Sequence](https://codeforces.com/problemset/problem/626/A) (CF)

**Challenging:**
- *[Restaurant Customers](../../problems/CSES_RestaurantCustomers.md) (CSES)
- **[Promotion Counting](../../problems/B15_16_PromotionCounting.md) (USACO Bronze 2015)

---

\* = Encouraged to try<br/>\*\* = Challenging