
===================================1========================================
                            DYNAMIC PROGRAMMING (DP)


## What is DP?
-----------
Dynamic Programming is an optimization technique used when:

1. The problem has Overlapping Subproblems.
   - Same subproblem gets solved multiple times.

2. The problem has Optimal Substructure.
   - Bigger answer can be built using smaller answers.

Example:
--------
Fib(5)
= Fib(4) + Fib(3)

Fib(4)
= Fib(3) + Fib(2)

Notice:
Fib(3) is calculated multiple times.
Fib(2) is calculated multiple times.

This repeated work is eliminated using DP.

===============================================================================
                            FIBONACCI SERIES


## Series:
-------
0, 1, 1, 2, 3, 5, 8, 13, 21, ...

Index:
------
0, 1, 2, 3, 4, 5, 6,  7,  8, ...

Formula:
--------
Fib(n) = Fib(n-1) + Fib(n-2)

Base Cases:
-----------
Fib(0) = 0
Fib(1) = 1

===============================================================================
                    APPROACH 1 : RECURSION (BRUTE FORCE)


Idea:
-----
Start from the main problem and recursively break it into smaller problems.

Example:
--------
Fib(5)
|
|-- Fib(4)
|   |
|   |-- Fib(3)
|   |-- Fib(2)
|
|-- Fib(3)
    |
    |-- Fib(2)
    |-- Fib(1)

Problem:
--------
Fib(3) solved multiple times.
Fib(2) solved multiple times.

Time Complexity : O(2^n)
Space Complexity: O(n)  (recursion stack)

===============================================================================
                APPROACH 2 : MEMOIZATION (TOP-DOWN DP)


Meaning:
--------
Memo = Memory

Store already calculated answers inside dp[].

If answer already exists:
return it directly.

Direction:
----------
Big Problem -> Small Problem

Fib(5)
↓
Fib(4)
↓
Fib(3)
↓
Fib(2)
↓
Fib(1)

Therefore:

Memoization = Top-Down DP

Key Points:
-----------
✓ Uses Recursion
✓ Uses DP Array
✓ Saves repeated calculations
✓ Easy to derive from recursion

Time Complexity : O(n)
Space Complexity: O(n) dp + O(n) recursion stack

Recognition:
------------
If you see:

function(n)
{
    return function(n-1) + function(n-2);
}

along with dp[] storage

=> Memoization

===============================================================================
                APPROACH 3 : TABULATION (BOTTOM-UP DP)


Idea:
-----
Start from already known answers and build upward.

Known:
------
Fib(0) = 0
Fib(1) = 1

Build:

Fib(2)
Fib(3)
Fib(4)
Fib(5)

Direction:
----------
Small Problem -> Big Problem

0
↑
1
↑
2
↑
3
↑
4
↑
5

Therefore:

Tabulation = Bottom-Up DP

Key Points:
-----------
✓ No Recursion
✓ Uses Iteration
✓ Usually faster than Memoization
✓ No recursion stack overhead

Time Complexity : O(n)
Space Complexity: O(n)

Recognition:
------------
If you see:

for(int i=2; i<=n; i++)
{
    dp[i] = dp[i-1] + dp[i-2];
}

=> Tabulation

===============================================================================
                    APPROACH 4 : SPACE OPTIMIZATION


Observation:
------------
To calculate Fib(i),
we only need previous two values.

Instead of storing entire dp[] array:

prev2 = Fib(i-2)
prev1 = Fib(i-1)

current = prev1 + prev2

Time Complexity : O(n)
Space Complexity: O(1)

This is the most optimized Fibonacci solution.

===============================================================================
                            REVISION NOTES


DP Checklist:
-------------
1. Is there repeated work?
   -> Overlapping Subproblems

2. Can bigger answer be built from smaller answers?
   -> Optimal Substructure

3. Write Recursion First

4. Convert Recursion -> Memoization

5. Convert Memoization -> Tabulation

6. Optimize Space if possible

Golden Formula:
---------------
Recursion
    ↓
Memoization (Top-Down)
    ↓
Tabulation (Bottom-Up)
    ↓
Space Optimization
=======================solution flow======================================================
1. Recursive Solution

2. Memoization
   - Create dp[]
   - Check dp[]
   - Store answer

3. Tabulation
   - Define table
   - Fill base cases
   - Loop

4. Space Optimization
   - If only previous states needed

==============================02=======================================
## DP-02 : Climbing Stairs

## Problem Statement

You are standing at stair `0`.

To reach stair `n`, you can:

* Climb 1 stair
* Climb 2 stairs

Find the total number of distinct ways to reach stair `n`.

Example:

```text
n = 3

Ways:

1 + 1 + 1
1 + 2
2 + 1

Answer = 3
```

---

# Step 1 : Think About The Last Move

Suppose we want to reach stair `n`.

The last move could be:

```text
1 step from stair (n-1)

OR

2 steps from stair (n-2)
```

Therefore:

```text
ways(n) = ways(n-1) + ways(n-2)
```

This is the recurrence relation.

---

# Step 2 : Understanding The Base Cases

## ways(0) = 1

This is the most important base case.

Question:

How many ways are there to reach stair 0?

Answer:

```text
1 way
```

You are already standing there.

```text
Start
 ↓
[0]
```

You don't need to move.

This "do nothing" path is counted as one valid way.

Therefore:

```text
ways(0) = 1
```

---

## ways(1) = 1

For stair 1:

```text
0 → 1
```

Only one possible path.

Therefore:

```text
ways(1) = 1
```

---

# Step 3 : Build Small Values

Using:

```text
ways(n) = ways(n-1) + ways(n-2)
```

Calculate:

```text
ways(0) = 1
ways(1) = 1

ways(2)
= ways(1) + ways(0)
= 1 + 1
= 2

ways(3)
= ways(2) + ways(1)
= 2 + 1
= 3

ways(4)
= ways(3) + ways(2)
= 3 + 2
= 5

ways(5)
= ways(4) + ways(3)
= 5 + 3
= 8
```

Pattern:

```text
1, 1, 2, 3, 5, 8, 13...
```

Looks familiar?

This is Fibonacci.

---

# Relation With Fibonacci

Fibonacci:

```text
fib(n) = fib(n-1) + fib(n-2)

fib(0) = 0
fib(1) = 1
```

Climbing Stairs:

```text
ways(n) = ways(n-1) + ways(n-2)

ways(0) = 1
ways(1) = 1
```

Same recurrence.

Only base cases are different.

This means:

```text
Climbing Stairs is Fibonacci in disguise.
```

---

# DP Approaches

## 1. Recursion

Idea:

Solve the problem directly using the recurrence relation.

```text
ways(n)
=
ways(n-1)
+
ways(n-2)
```

Complexity:

```text
Time  : O(2^n)
Space : O(n)
```

Problem:

Repeated calculations occur.

---

## 2. Memoization (Top-Down DP)

Store already calculated answers inside a dp array.

Before solving:

```text
Check dp[n]

If answer exists:
    Return it

Else:
    Calculate and store
```

Complexity:

```text
Time  : O(n)
Space : O(n) + recursion stack
```

---

## 3. Tabulation (Bottom-Up DP)

Start from base cases.

```text
ways(0) = 1
ways(1) = 1
```

Build answers iteratively.

```text
ways(2)
ways(3)
ways(4)
...
ways(n)
```

Complexity:

```text
Time  : O(n)
Space : O(n)
```

---

## 4. Space Optimization

Observation:

To calculate:

```text
ways(i)
```

we only need:

```text
ways(i-1)
ways(i-2)
```

Therefore an entire DP array is unnecessary.

Store only:

```text
prev1
prev2
```

Complexity:

```text
Time  : O(n)
Space : O(1)
```

---

# Key DP Learning From This Problem

1. Learn to derive recurrence relations.

2. Learn why base cases exist.

3. Learn the flow:


Recursion
    ↓
Memoization
    ↓
Tabulation
    ↓
Space Optimization


4. Learn to identify Fibonacci patterns hidden inside problems.

---

# Revision

Whenever you see:


Current answer depends on previous two answers.


Think:


Can this be a Fibonacci-style DP problem?


Climbing Stairs is the first classic example of that pattern.

---------------------------------------------------
## DP3
height = [10, 20, 30, 10]
          0    1    2    3

dp[i]  = [ 0,  10,  20,  20]
          ↑    ↑    ↑    ↑
          |    |    |    └─ Min cost to reach index 3
          |    |    └─────── Min cost to reach index 2
          |    └──────────── Min cost to reach index 1
          └───────────────── Min cost to reach index 0 (start)


          
Option 1: Come from i-1
┌────────────────────────────────────────--------─┐
│ Cost = dp[i-1] + abs(height[i] - height[i-1])   │
│        ↑            ↑                           │
│        |            └─ Cost of this jump        │
│        └─ Total cost to reach i-1               │
└─────────────────────────────────────────--------┘

Option 2: Come from i-2
┌────────────────────────────────────────--------─┐
│ Cost = dp[i-2] + abs(height[i] - height[i-2])   │
│        ↑            ↑                           │
│        |            └─ Cost of this jump        │
│        └─ Total cost to reach i-2               │
└─────────────────────────────────────────--------┘


#                    What does the problem ask?
                              │
            ┌─────────────────┼─────────────────┐
            │                 │                 │
        Minimum?          Maximum?         Count Ways?
            │                 │                 │
            ▼                 ▼                 ▼
        Use min()         Use max()         Use + or *


                                 f(3)
                                /    \
  f(1)+height[2]-height[1]<- f(2)     f(1) ← Base case
                            /    \
                         f(1)     f(0) ← Base cases
                          ↑
                   Already calculated!


| Approach   | Time   | Space       | Key Idea          |
|------------|--------|-------------|-------------------|
| Recursion  | O(2^n) | O(n)        | Try all paths     |
| Memoization| O(n)   | O(n) + O(n) | Cache results     |
| Tabulation | O(n)   | O(n)        | Build bottom-up   |
| Space Opt  | O(n)   | O(1)        |Slidingwindow      |

# DP4 - Frog Jump K Distance

## Problem

Given an array `height[]`.

A frog starts at index `0`.

Allowed jumps:

* 1 step
* 2 steps
* 3 steps
* ...
* K steps

Jump Cost:

```
abs(height[i] - height[j])
```

Goal:

```
Reach the last index with minimum total energy.
```

---

# Why This Problem?

DP3 (Frog Jump):

```
Can jump:
1 step
2 steps
```

DP4 (Frog Jump K Distance):

```
Can jump:
1 to K steps
```

This is the first DP problem where the number of choices is not fixed.

---

# Key Observation

To reach index `i`, the frog may come from:

```
i-1
i-2
i-3
...
i-K
```

(Only valid indices)

Therefore:

```
Try all possible jumps
and choose the minimum cost.
```

---

# State Definition

dp[i]

Meaning:

```
Minimum energy required
to reach index i.
```

Important:

```
dp[i] ≠ current jump cost

dp[i] = total minimum cost
        to reach i
```

---

# Thinking Process

Question:

```
How can I reach index i?
```

Answer:

```
From any previous index:

i-1
i-2
...
i-K
```

For every valid jump:

```
Previous Cost
+
Current Jump Cost
```

Take minimum among all choices.

---

# Recurrence

For every jump length j:

```
1 ≤ j ≤ K
```

and

```
i-j ≥ 0
```

Cost:

```
dp[i-j]
+
abs(height[i]-height[i-j])
```

Therefore:

```
dp[i]

=

minimum of all valid jumps
```

---

# Visual Example

Height:

```
[10, 20, 40, 30]
```

K = 3

Index:

```
 0   1   2   3
```

To reach index 3:

Possible previous positions:

```
2
1
0
```

Possible Costs:

```
dp[2] + |30-40|

dp[1] + |30-20|

dp[0] + |30-10|
```

Take minimum.

---

# Base Case

dp[0] = 0

Reason:

```
Already standing there.

No energy required.
```

---

# Recursive Solution

Idea:

For current index:

```
Try all jumps

1 to K
```

Return minimum cost.

Pseudo Thinking:

```
solve(i)

Try:

solve(i-1)

solve(i-2)

...

solve(i-K)
```

Choose minimum.

---

# Why Recursion Is Slow?

Many states are solved repeatedly.

Example:

```
solve(10)
```

calls

```
solve(9)
solve(8)
solve(7)
```

and each of them again calls:

```
solve(8)
solve(7)
solve(6)
```

Repeated work.

---

# Memoization (Top-Down)

Idea:

Before solving a state:

```
Check dp[]
```

If already calculated:

```
Return stored answer.
```

Otherwise:

```
Calculate and store.
```

---

# Tabulation (Bottom-Up)

Build answers from:

```
dp[0]
```

to

```
dp[n]
```

For every index:

```
Try all jumps

1 to K
```

Store minimum answer.

---

# Complexity

Recursion:

```
Time  : Exponential

Space : O(n)
```

---

Memoization:

```
Time  : O(n × k)

Space : O(n)
```

---

Tabulation:

```
Time  : O(n × k)

Space : O(n)
```

---

# Can We Space Optimize?

DP3:

```
dp[i]
depends only on

dp[i-1]
dp[i-2]
```

Therefore:

```
O(1) space possible.
```

---

DP4:

```
dp[i]
depends on

dp[i-1]
dp[i-2]
...
dp[i-k]
```

If K becomes large:

```
We may need many previous states.
```

Therefore:

```
General O(1) space optimization
is NOT possible.
```

Need DP array.

---

# DP Pattern Learned

DP1 Fibonacci:

```
Fixed Previous States

(n-1, n-2)
```

---

DP2 Climbing Stairs:

```
Counting DP
```

---

DP3 Frog Jump:

```
Minimum Cost DP
```

---

DP4 Frog Jump K Distance:

```
Variable Choices DP

Loop Inside Recurrence
```

This pattern appears frequently in advanced DP.

---

# Common Mistakes

Mistake 1:

Thinking:

```
Only check i-1 and i-2
```

Wrong.

Need:

```
i-1
i-2
...
i-K
```

---

Mistake 2:

Forgetting boundary check.

Always ensure:

```
i-j >= 0
```

before using:

```
dp[i-j]
```

---

Mistake 3:

Confusing jump cost with total cost.

Correct:

```
Total Cost

= Previous Best Cost
  + Current Jump Cost
```

---

Mistake 4:

Trying to optimize to O(1) space.

Usually not possible because:

```
Current state may depend on
many previous states.
```

---

# Interview Pattern Recognition

Whenever you see:

```
"From current position,
 choose among many previous positions"
```

Think:

```
DP State

+
Loop over all choices
```

This exact idea appears later in:

```
House Robber Variants
Ninja Training
Grid DP
Coin Change
Knapsack Variants
Stock DP
```

DP4 is your first exposure to:

```
"Loop Inside Transition"
```

which is one of the most important DP patterns.
