# Circular Barn (USACO Bronze 2015)
Link: https://usaco.org/index.php?page=viewproblem2&cpid=616

Type: Simulation

Difficulty: Easy

# Solution
First of all notice that starting from different sections of the barn will yield different total distances that the cows have to travel.

With this observation, we notice that the numbers are small enough such that to solve this problem, we can just go through every starting section and check the distance. We'll just keep track of the smallest distance travelled.

Notice that each time the cows enter a room $i$, $r_i$ cows will stay. So, the number of cows entering the next room will be $r_i$ less. Thus, if we start from room 1, then the total cost of filling up the barn is:

$$\text{cost} = N + (N-r_1) + (N-r_1-r_2) + \cdots + 0$$

However, if we start from room 2, then we need to account for room 1 at the end (2 -> 3 -> ... -> N -> 1). To do this, we can use the modulo operator. Notice that:
- $1\mod 5 = 1$
- $2\mod 5 = 2$
- $3\mod 5 = 3$
- $4\mod 5 = 4$
- $5\mod 5 = 0$
- $6\mod 5 = 1$

Notice it wraps around! This is exactly what we need, since if we start from room $S$, we want to go through all rooms in the order:

$$ S, (S+1)\mod N, (S+2)\mod N, \ldots, (S+N-1)\mod N$$

Check out the code (cuz im too lazy to finish writing this, and gemini writes confusing editorials, and i dont have claude credits):
[full C++ solution](B15_16_CircularBarn.cpp)