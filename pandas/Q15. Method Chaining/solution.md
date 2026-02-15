# Method Chaining

## Problem

Return the names of animals that weigh **more than 100 kilograms**, sorted by **weight in descending order**.

---

## Key Concepts

### DataFrame Manipulation (pandas)
A **DataFrame** is a tabular data structure in pandas that supports filtering, sorting, and column selection.

### Filtering Data
**Boolean indexing** is used to select rows matching a condition.  
Here, we keep animals with `weight > 100`.

### Sorting Data
`sort_values()` sorts rows based on column values.  
We sort by `weight` in descending order.

### Column Selection
After filtering and sorting, we keep only the `name` column.

### Method Chaining
Method chaining allows multiple DataFrame operations to be combined in one expression, making the code concise and readable once understood.

### Python Function
We define `findHeavyAnimals()` to wrap the logic into a reusable function that takes a DataFrame and returns the result.

---
## Visualization
![Visualization](images/visualization.png)

## Implementation

```
import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight'] > 100].sort_values(by='weight', ascending=False)[['name']]

```

