# Restaurant Customers
Link: https://cses.fi/problemset/task/1619

Type: Simulation

Difficulty: Medium

# Solution
It is crucial to notice that simulating all possible time segments naively will require a up to $10^9 \times 10^5 = 10^{14}$ operations, which is too long. Furthermore, an array ith $10^9$ elements will likely go over the memory limit.

So, we must think of a solution that only processes important data.

If we instead recorded the points in time when a customer enters and leaves, we can then keep a running total of the current number of customers and all-time maximum, we can solve this problem much faster.

To do this, we first store the data in an array containing tuples $\{T, n\}$ where $T$ is the time and $n$ is the change in the number of customers. For each customer, we add $\{T_{arrival}, +1\}$ as well as $\{T_{departure}, -1\}$ to the array. 

This means that at time $T_{arrival}$, the number of customers increases by 1, and at $T_{departure}$, the number of customers decreases by 1.

We then sort this array by $T$ so we get the data in chronological order. Then, we traverse through this array, which will have at most $2\times N = 4\times 10^5$ elements. Each time we encounter the $i$-th event, we add $n_i$ to a running total and update the all-time maximum accordingly.

At the end, the maintained all-time maximum is the answer.