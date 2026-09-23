# Promotion Counting (USACO Bronze 2015)
Link: https://usaco.org/index.php?page=viewproblem2&cpid=591

Type: Simulation

Difficulty: Easy

# Solution
1. Process the data— count how many new students joined and add them to the bronze ‘before’ section
2. Subtract the new list, $a$, from the old list, $b$
    1. Notice that if $a_i-b_i<0$, $|a_i-b_i|$ students got promoted **from** that level
    2. Notice that if $a_i-b_i>0$, $|a_i-b_i|$ students got promoted **to** that level.
3. Traverse the list $a-b$ **backwards**, ignoring the value at bronze, and keep a running sum of the values.
    1. This running sum is the number of promotions for the levels platinum, gold, and silver.

Why traverse backwards? Beacuse someone who went from bronze -> platinum must have also been promoted to silver then gold. So, they must be part of the running sum for silver and gold.

![Cool lil' diagram](<Screenshot 2025-10-04 at 10.52.22.png>)

> I realize this is a terrible editorial!! Please try to understand it.

## Code
```cpp
#include <iostream>
using namespace std;

// think of these are just vectors
// they are arrays but vectors are just cooler arrays
int before[4], after[4];
int ans[3];

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int participants = 0, participantsBefore = 0;;
    for (int i=0; i<4; i++) {
        cin >> before[i] >> after[i];
        participantsBefore += before[i];
        participants += after[i];
    }
    before[0] += participants - participantsBefore;

    for (int i=0; i<3; i++) {
        // go from i -> i+1
        if (before[i] > after[i]) {
            int diff = before[i] - after[i];
            ans[i] += diff;

            before[i] -= diff;
            before[i+1] += diff;
        }
    }

    // "\n" is the newline character.
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}
```