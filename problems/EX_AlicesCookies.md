# Alice's Cookies

Alice has a jar containing $N$ cookies. Every day, she performs a strict routine:
1. In the morning, she eats exactly $E$ cookies from the jar.
2. In the evening, her brother refills the jar by adding exactly $R$ cookies.

If at any point in the morning there are fewer than $E$ cookies remaining in the jar, Alice will eat all the remaining cookies, and the simulation **immediately ends** (her brother will not add any cookies that evening).

Given the initial number of cookies $N$, the daily consumption $E$, and the daily refill $R$, determine **how many days** the simulation will run until the jar runs completely empty, and output the **total number of cookies** Alice managed to eat.

### Input Format
The input consists of a single line containing three space-separated integers:
```text
N E R
```
* $N$: The initial number of cookies in the jar.
* $E$: The number of cookies Alice eats each morning.
* $R$: The number of cookies added each evening.

### Output Format
Print two space-separated integers:
1. The **total number of days** the simulation lasted.
2. The **total number of cookies** Alice ate.

### Constraints
* $1 ≤ N ≤ 1000$
* $1 ≤ E ≤ 100$
* $0 ≤ R < E$ *(Note: R < E guarantees the simulation will eventually terminate)*

### Sample Test Case
**Sample Input**
```text
10 3 1
```

**Sample Output**
```text
5 10
```

**Explanation**
* **Day 1:** Morning: 10 cookies $\rightarrow$ Eats 3 (Remaining: 7). Evening: Adds 1 (Total: 8).
* **Day 2:** Morning: 8 cookies $\rightarrow$ Eats 3 (Remaining: 5). Evening: Adds 1 (Total: 6).
* **Day 3:** Morning: 6 cookies $\rightarrow$ Eats 3 (Remaining: 3). Evening: Adds 1 (Total: 4).
* **Day 4:** Morning: 4 cookies $\rightarrow$ Eats 3 (Remaining: 1). Evening: Adds 1 (Total: 2).
* **Day 5:** Morning: 2 cookies. Since $2 < 3$, she eats the remaining 2 cookies. The jar is now empty, and the simulation ends. 
* Total days = 5. Total cookies eaten = $3 + 3 + 3 + 3 + 2 = 10$.
Use code with caution.Would you like to see:A Python, C++, or Java solution implementing this simulation?A change in constraints to turn this into an O(1) math formula challenge instead?Another simulation problem involving grids or string manipulations?AI responses may include mistakes. Learn more