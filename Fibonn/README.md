# Nth Fibonacci Number – DAA Lab

## Objective

To compute the Nth Fibonacci number using a recursive algorithm and compare it with an optimized algorithm. The performance of both algorithms is analyzed.

---

## Algorithm Description

### Recursive Fibonacci

The Fibonacci sequence is defined as:

F(n) = F(n-1) + F(n-2)

with base cases:

F(0) = 0  
F(1) = 1

This direct recursive implementation repeatedly recomputes subproblems.

---

### Optimized Fibonacci

An improved approach uses Dynamic Programming. Instead of recomputing values, previous results are stored and reused.

Algorithm idea:

1. Initialize two variables for F(0) and F(1)
2. Iteratively compute next Fibonacci numbers
3. Continue until n is reached

---

## Formula / Recurrence Relation

Recursive relation:

T(n) = T(n-1) + T(n-2) + O(1)

Solution:

T(n) ≈ O(2ⁿ)

Optimized approach:

T(n) = O(n)

---

## Time Complexity

| Algorithm | Complexity |
|----------|------------|
| Recursive Fibonacci | O(2ⁿ) |
| Dynamic Programming Fibonacci | O(n) |

---

## Program Output

Recursive and optimized Fibonacci results with execution time.
