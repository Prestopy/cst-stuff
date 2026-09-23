# Speeding Ticket (USACO Bronze 2015)
Link: https://usaco.org/index.php?page=viewproblem2&cpid=568

Type: Simulation

Difficulty: Easy

# Solution
Notice that the road is only 100 segments long. Instead of doing weird math comparing segments of different lengths together, we can just split the road up into 100 segments, each with a speed limit and a speed at which Bessie drove at. Then, compare the segments one by one to find the answer.