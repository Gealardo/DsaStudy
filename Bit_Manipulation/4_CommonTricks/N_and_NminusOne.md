### Why does `n & (n - 1)` work for checking a power of 2?

A power of 2 has **exactly one set bit** in its binary representation.

For example:

```text
1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000
```

When we subtract 1 from such a number:

* The **only set bit becomes 0**.
* All the bits to its **right become 1**.
* All the bits to its **left remain unchanged**.

Example:

```text
8 = 1000

8 - 1 = 0111
```

Now perform AND:

```text
1000
0111
----
0000
```

The only set bit is cleared, so the result becomes **0**.

Now consider a number that is **not** a power of 2.

Example:

```text
12 = 1100

12 - 1 = 1011
```

Now AND:

```text
1100
1011
----
1000
```

The result is **not zero** because another set bit still remains.

Therefore:

* If `n` has **exactly one set bit**, then `n & (n - 1)` becomes `0`.
* If `n` has **more than one set bit**, at least one set bit survives after the AND operation, so the result is **non-zero**.

Finally, we must also check:

```cpp
n > 0
```

because `0` and negative numbers are **not** powers of 2, even though `0 & (0 - 1)` also evaluates to `0`.
