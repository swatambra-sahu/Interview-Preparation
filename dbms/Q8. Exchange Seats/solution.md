# 626. Exchange Seats

## Intuition

We are given a table where:

- `id` represents the seat number
- `student` represents the student sitting in that seat

The goal is to **swap the seat IDs for every pair of consecutive students**.

This means:

| Original IDs | After Swap |
|--------------|------------|
| 1, 2         | 2, 1       |
| 3, 4         | 4, 3       |
| 5            | 5 (unchanged if odd count) |

So:

- Odd ID → swap with next ID (`id + 1`)
- Even ID → swap with previous ID (`id - 1`)
- BUT if the total number of students is **odd**, the last student should **not** be swapped.

---

## Approach

We use a `CASE` statement:

1. If `id` is odd AND it's **not the last id** → swap with `id + 1`
2. If `id` is even → swap with `id - 1`
3. If it's the last odd id → keep it unchanged

To detect the last row, we compare with:

```sql
SELECT
    CASE
        WHEN id % 2 = 1 AND id < (SELECT COUNT(*) FROM Seat) THEN id + 1
        WHEN id % 2 = 0 THEN id - 1
        ELSE id
    END AS id,
    student
FROM Seat
ORDER BY id;
```
---

### Complexity Analysis

- Time Complexity: O(N) as Each row is processed once, COUNT(*) is computed once.

- Space Complexity: O(1) as No extra storage used, Only transformation of output.
