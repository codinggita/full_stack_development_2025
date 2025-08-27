# Arrays


***

## Introduction to Arrays

An **array** is one of the most fundamental data structures in programming, used for storing a fixed-size sequence of elements, all of the same data type. Arrays allow efficient and direct access to any element through its index, making them essential for many algorithms and other advanced data structures.

Arrays store elements in contiguous memory locations, which makes accessing elements by index very fast.

***

## Linear Arrays and Their Representation

### What is a Linear Array?

A **linear array** is a sequential collection of elements with the following properties:

- Elements arranged in a linear order.
- Each element is identified by a unique index starting from 0 (zero-based indexing).
- Elements are stored in contiguous blocks of memory.


### Characteristics of Linear Arrays

- Fixed length, determined at the time of creation.
- All elements have the same data type.
- Accessing any element by index is \$ O(1) \$ time, thanks to contiguous memory.
- Supports iteration, but modifications such as insertion and deletion can be costly due to shifting elements.


### Memory Representation

Consider an array of 5 integers:


| Index | 0 | 1 | 2 | 3 | 4 |
| :-- | :-- | :-- | :-- | :-- | :-- |
| Value | 10 | 20 | 30 | 40 | 50 |

The address of the element at index \$ i \$ is calculated as:

$$
\text{Address}(i) = \text{Base Address} + i \times \text{Size of Element}
$$

This enables constant-time access to any element.

***

## Array Operations and Methods

Here are fundamental operations typically performed on arrays along with explanations and C++ examples.

### 1. Accessing Elements

**Description:** Retrieve the value at a given index.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int val = arr;  // val is 30
```

- **Time Complexity:** $O(1)$
- **Why:** Direct access via calculated memory address.


#### **Step-by-step Explanation**

- Every array in memory is stored in **contiguous blocks**.
- The first element is at base address `arr`.
- To access `arr[i]`, the computer internally calculates:

$$
\text{Address of arr[i]} = \text{Base Address} + (i \times \text{Size of each element})
$$
- So accessing **any index** is constant time, since the calculation is direct.


#### **Representation**

Array memory layout:


| Index | 0 | 1 | 2 | 3 | 4 |
| :-- | :-- | :-- | :-- | :-- | :-- |
| Value | 10 | 20 | 30 | 40 | 50 |

If we access `arr`, pointer jumps directly to index `2` = value `30`.

***

### 2. Traversing an Array

**Description:** Visit each element, usually to process or print.

```cpp
for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

- **Time Complexity:** $O(n)$
- **Why:** Each element is accessed once sequentially.


#### **Step-by-step Explanation**

1. Start from index `0`.
2. Move sequentially through each element until `n-1`.
3. Perform an operation (e.g., printing, summation, etc.).

#### **Representation**

Traversal order:

`10 → 20 → 30 → 40 → 50`

***

### 3. Inserting Elements

**Description:** Insert a new element at a specific position by shifting subsequent elements.

```cpp
int arr[10] = {10, 20, 30, 40, 50};
int n = 5;  
int pos = 2, val = 25;

// Shift elements to right
for (int i = n; i > pos; i--) {
    arr[i] = arr[i - 1];
}

arr[pos] = val;  // Insert 25 at index 2
n++;  // Update size
```

- **Time Complexity:** $O(n)$
- **Why:** Elements to the right need to be shifted one position to make space.


#### **Step-by-step Explanation**

1. Suppose we insert `25` at index `2`.
2. Current array: ``
3. Starting from the last element, shift everything → right.
    - `arr = arr (50)`
    - `arr = arr (40)`
    - `arr = arr (30)`
4. Now `arr` is free → place `25`.
5. New array size becomes 6.


***

### 4. Deleting Elements

**Description:** Remove element at a specific index and shift remaining elements left.

```cpp
int arr = {10, 20, 30, 40, 50};
int pos = 2;  
int n = 5;

for (int i = pos; i < n - 1; i++) {
    arr[i] = arr[i + 1];
}

n--;  // Update size
```

- **Time Complexity:** $O(n)$
- **Why:** Elements after deleted position must be shifted left.


#### **Step-by-step Explanation**

1. To delete element at index `2` (value = 30).
2. Start from `pos`.
    - Move `arr → arr` → replaces `30` with `40`.
    - Move `arr → arr` → replaces `40` with `50`.
3. Reduce array size by 1.

#### **Representation**

Before deletion:
``

After deleting index `2`:
``

***

### 5. Searching Elements (Linear Search)

**Description:** Find index of an element by checking each position sequentially.

```cpp
int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  
    }
    return -1;
}
```

- **Time Complexity:** $O(n)$
- **Why:** May need to check all elements in worst case.


#### **Step-by-step Explanation**

1. Start loop from index `0`.
2. Compare each `arr[i]` with the target key.
3. If found → return index.
4. If not found till last element → return `-1`.

#### **Representation**

Search `40` in ``.

Check:

- `10 ≠ 40`
- `20 ≠ 40`
- `30 ≠ 40`
- `40 == 40 ✅ Found at index 3`

***

### 6. Updating Elements

**Description:** Change the value at a specific index.

```cpp
arr[3] = 100;  // Set element at index 3 to 100
```

- **Time Complexity:** $O(1)$
- **Why:** Direct access and assignment.


#### **Step-by-step Explanation**

1. Directly go to index `3`.
2. Replace its old value (`40`) with new value (`100`).

#### **Representation**

Before update:{10, 20, 30, 40, 50}
``

After update:{10, 20, 30, 100, 50}
``

***

### 7. Copying Arrays

**Description:** Create a duplicate array.

```cpp
int arr1 = {1, 2, 3, 4, 5};
int arr2;
for (int i = 0; i < 5; i++) {
    arr2[i] = arr1[i];
}
```

- **Time Complexity:** $O(n)$


#### **Step-by-step Explanation**

1. Create new array `arr2`.
2. Copy element by element:
    - `arr2 = arr1`
    - `arr2 = arr1`
… and so on.

#### **Representation**

Original: ``Copied :``

***

### 8. Resizing Arrays (Dynamic Arrays Concept)

**Description:** When array size limit reached, allocate larger array and copy elements.

- In languages like C++, dynamic arrays like `std::vector` handle this internally.
- Copying on resize has $O(n)$ complexity but amortized over time.


#### **Step-by-step Explanation**

1. Suppose array has capacity `5` but already full.
2. Need to insert another element.
3. Allocate a **new array of bigger size** (usually double the capacity).
4. Copy all elements from old array → new array.
5. Insert the new element into new array.
6. Delete/ignore old array.

#### **Representation**

Before resize (capacity 5): ``

Resize to capacity 10 → `[1,2,3,4,5,_,_,_,_,_]` (empty slots reserved).

***

## Advantages of Arrays

- Constant-time access to any element.
- Simple and efficient for fixed-size data.
- Supports bulk operations like sorting.


## Disadvantages of Arrays

- Fixed size limits flexibility.
- Costly insertions/deletions in middle due to shifts.
- Inefficient with dynamic, growing data.

***

## Summary Table

| Operation | Time Complexity | Description |
| :-- | :-- | :-- |
| Access | \$ O(1) \$ | Direct indexing to element by position |
| Traverse | \$ O(n) \$ | Visiting each element sequentially |
| Insert (middle) | \$ O(n) \$ | Shift and insert new element |
| Delete (middle) | \$ O(n) \$ | Shift elements to remove an element |
| Search (linear) | \$ O(n) \$ | Sequential search for value |
| Update | \$ O(1) \$ | Direct overwrite at index |


***

Arrays form the base for fundamental data storage and are crucial in building efficient software systems, making them one of the first and most important data structures to master.
