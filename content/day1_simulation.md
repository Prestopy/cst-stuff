# CST Day 1: Simulation + How to C++
**Goal:**
1. Understand what **simulation** is
2. Be able to **reason through simulation problems logically**
3. Be able to **write basic C++ code**
4. Be able to **implement solutions for simple simulation problems**
5. *(Be more confident now that you've tried real comprog questions)*

# The idea behind simulation
Simulation problems are often described as "Do What The Problem Says". Unlike difficult problems that require advanced algorithmic knowledge, simulation problems simply test your ability to translate written rules and step-by-step processes into *bug-free* code.

Omg bug-free code is so rare.

# Edge cases
To make simulation problems harder, they usually have **edge cases**, or extreme input values that fall outside typical usage and can break your code if you only design it for normal inputs.

Common edge cases are negative numbers, empty lists, or massive numbers.

# Implementation
## Identifying simulation problems *in the wild* :0
1. Look for **explicit step sequences**, like "first do A, then do B, etc."
2. Look for **small constraints**; a problem could be solvable with simulation but take too long. Remember, competetive programming solutions must run fast enough! Simulation may be the easiest but is typically the slowest.

Remember that code that runs for more than $10^9$ iterations is usually too slow to be a valid solution.

## Mental framework
1. **Define state/data ($S$)** you need to keep track of
2. Define the **transition function** (how would state $S_i$ become $S_{i+1}$)
3. **Identify edge cases** or bounds

## Example comprog problem
Let's familiarize ourselves with a super simple sample comprog problem: [Alice's Cookies (brilliant name ik)](../EX_AlicesCookies.md).

## How to C++
### Important data types *(for now)*
**Primitive data types:**
- `int`
- `long long`
- `double`
- `bool`

**Non-primitive:**
- `vector` (from `<vector>` STL header)
- `string` (from `<string>` STL header)

### Reading input/output
This is **super important**!! Comprog competitions run your program multiple times, each time giving it different inputs, or test cases. Your program must **read the input** it is given, **solve the problem**, then **output the answer**.

```cpp
#include <iostream>
using namespace std;

int main() {
    int coolNum; // variable containing an integer called "coolNum"
    cin >> coolNum; // read input and put it into coolNum

    cout << "yay! Your number was: " << coolNum; // output
}
```

Remember that `cin` always has the arrows pointing **into the variables (right)**, and `cout` always has the arrows pointing **towards it (left)**.

Also notice you can chain the `<<` and `>>`. So, doing `cout << "hi1" << "hi2";` is completely valid.

#### Reading from files
Only old competitive programming problems require you to read your input and write your output to a file. If this is the case, you need to make `cin` read from a file, and `cout` write to a file, instead of from the terminal:

```cpp
// bind input to file "shuffle.in"
freopen("shuffle.in", "r", stdin);

// bind output to file "shuffle.out"
freopen("shuffle.out", "w", stdout);

int N;
cin >> N; // read input from file "shuffle.in"
cout << "lol"; // write output to file "shuffle.out"
```

### Doing simple math
- `+`, `-`, `*`, `/` are plus, minus, multiply, divide.
- `%` is modulo, or the remainder of a division.
- `sqrt()` from `<cmath>` is square root.
- `floor()` and `ceil()` from `<cmath>` round down and up.


**Ok, now let's solve a sample problem:**
> Imagine a magical tree that spawns ducks. The tree spawns 1 duck on day 1, 2 ducks on day 2, and so on. On day 0, there are 0 ducks. There are $N$ people who each want $D$ ducks. Determine how many days it will take after day 0 for everyone to satisfy everyone.
> You will be given the numbers $N$ and $D$.

This is a pure math problem. Notice that after $T$ days, the number of ducks that have been spawned is:

$$\frac{T(1+T)}{2}$$

Since we need a total of $N\cdot D$ ducks to satisfy everyone, we want to find a value of $T$ such that:

$$\frac{T(1+T)}{2} \leq N\cdot D$$

Solving for this gives us:

$$ T\leq \sqrt{2ND+1/4} - 1/2 $$

Since $T$ must be a whole number, we have:

$$ T = \lceil \underbrace{\sqrt{2ND+1/4}}_{\text{coolRoot}} - 1/2 \rceil $$

Now let's translate this into code:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    int D;
    cin >> N >> D; // read input for N and D

    double coolRoot = sqrt(2 * N * D + 0.25); // computers follow PEMDAS too
    double answer = ceil(coolRoot - 0.5); // round up

    cout << answer;
}
```

### Boolean expressions
A boolean expression is **anything** that evaluates to a boolean.

### If/else-if/else
Conditional statements let you conditionally run code based on whether or not a boolean expression is true.
```cpp
int age = 45;

if (age < 50) {
    cout << "young";
} else if (age < 100) {
    cout << "old";
} else {
    cout << "super old";
}
```
This code would print `young`, since `45 < 50`.

If `age = 75`, then the output would be `old`.

If `age = 2000`, then the output would be `super old`.

### For/while loops
Loops are super cool! They let you run code repeatedly for a specified number of times.

#### While loops
While loops run code until a condition becomes false.

```cpp
int n = 10;
while (n > 0) {
    cout << n;
    n = n-1;
}
```

#### For loops
For loops run code a specified number of times (basically similar to while loops).

```cpp
for (int i=10; i>0; i=i-1) {
    cout << i;
}
```

> Btw, the examples for the while and for loop above both output the same thing!

### Arrays/vectors (data type)
Arrays are a super useful data type that store lists of values. We will generally use `vector` from the `<vector>` STL header.

```cpp
vector<int> listOfInts = {1, 2, 3};
vector<bool> listOfBools = {true, false, false, true};

// push_back appends a value to the end
listOfInts.push_back(10); // now listOfInts is {1, 2, 3, 10}

// listOfInts[0] corresponds to the FIRST element of the array "istOfInts" (arrays are 0-indexed: they start from 0)
cout << listOfInts[0]; // 1
cout << listOfInts[1]; // 2
cout << listOfInts[2]; // 3
cout << listOfInts[3]; // 10

listOfInts[2] = listOfInts[2] - 10;

cout << listOfInts[2]; // -7
```

## Strings (data type)
Strings are from the `<string>` STL header. They represent text! You **must** wrap text in quotation marks "", otherwise it will be evaluated as a variable name.

```cpp
string myText = "hello"; // CORRECT; saves text "hello" into variable myText
string myText2 = hello;   // INCORRECT; program will try to find variable called hello
```

You can check the character at position $i$ of a string by using square brackets, just like an array:
```cpp
string world = "hello";
cout << world[0]; // 'h' (1st char)
cout << world[4]; // '0' (5th char)
```

To find the length of a string, use `.size()`:
```cpp
string lightbulb = "buzz";
cout << lightbulb.size(); // 4
```

# Example problems!
- [In Search of an Easy Problem](../CF1030_InSearchOfAnEasyProblem.md) (CF)
- [Wrong Subtraction](../CF977A_WrongSubtraction.md) (CF)
- *[Bovine Shuffle](../B17_18_BovineShuffle.md) (USACO Bronze 2017)
- *[Speeding Ticket](../B15_16_SpeedingTicket.md) (USACO Bronze 2015)
- *[Circular Barn](../B15_16_CircularBarn.md) (USACO Bronze 2015)
- **[Promotion Counting](../B15_16_PromotionCounting.md) (USACO Bronze 2015)

\* = Encouraged to try; \*\* = Challenging
