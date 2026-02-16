# 🧾 LeetCode 183 – Customers Who Never Order

## 📌 Problem Statement

Table: `Customers`

| Column Name | Type    |
|------------|----------|
| id         | int      |
| name       | varchar  |

Table: `Orders`

| Column Name | Type |
|------------|------|
| id         | int  |
| customerId | int  |

Write an SQL query to report all customers who never order anything.

Return the result table in any order.

---

## 💡 Approach

To find customers who **never placed any orders**, we use a **LEFT OUTER JOIN**:

1. Perform a `LEFT JOIN` between `Customers` and `Orders` on `customerId`.
2. A `LEFT JOIN` keeps all records from the `Customers` table.
3. If a customer has not placed any order, the joined `Orders` columns will contain `NULL`.
4. Filter rows where `Orders.customerId IS NULL`.

This ensures we only get customers without matching orders.

---

## 🛠️ SQL Solution

```sql
SELECT c.name AS Customers
FROM Customers c
LEFT OUTER JOIN Orders o
ON c.id = o.customerId
WHERE o.customerId IS NULL;
