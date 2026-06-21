
===============================================================================
                            DYNAMIC PROGRAMMING (DP)
===============================================================================

What is DP?
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
===============================================================================

Series:
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
===============================================================================

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
===============================================================================

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
===============================================================================

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
===============================================================================

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
===============================================================================

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

================================================================================