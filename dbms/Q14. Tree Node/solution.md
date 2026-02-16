# 🌳 LeetCode 608 – Tree Node

## 📌 Problem Statement

Table: `Tree`

| Column Name | Type |
|------------|------|
| id         | int  |
| p_id       | int  |

- `id` is the primary key.
- Each row represents a node in a tree.
- `p_id` is the parent node id.
- If `p_id` is `NULL`, the node is the **root**.

Write an SQL query to report the type of each node in the tree.

Return the result table in any order.

### 🏷️ Node Types

- **Root** → If `p_id IS NULL`
- **Inner** → If the node has at least one child
- **Leaf** → If the node has no children and is not root

---

## 💡 Approach

We classify each node using a `CASE` statement:

1. If `p_id IS NULL` → It is a **Root** node.
2. If `id` appears as a `p_id` in the table → It has children → **Inner** node.
3. Otherwise → It has no children and is not root → **Leaf** node.

To determine whether a node has children, we check if its `id` exists in the `p_id` column of the same table.

---

## 🛠️ SQL Solution

```sql
SELECT id,
       CASE
           WHEN p_id IS NULL THEN 'Root'
           WHEN id IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
           ELSE 'Leaf'
       END AS type
FROM Tree;
