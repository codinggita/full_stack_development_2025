

### **Practice Assignment:**

**1. Additional Questions on CRUD Operations:**

- Insert new students into the `"students"` collection with random data.
```js
db.students.insertMany([
  {
    name: "Dev Patel",
    roll_number: "CSE1010",
    department: "Computer Science",
    year: 1,
    courses_enrolled: ["CS101", "CS102", "Math101"]
  },
  {
    name: "Dharti Raval",
    roll_number: "ECE3005",
    department: "Electronics",
    year: 3,
    courses_enrolled: ["EC201", "CS101"]
  }
]);
```
- Update the department of a student based on their roll number.
```js
db.students.updateOne(
  { roll_number: "CSE1010" },
  { $set: { department: "Information Technology" } }
);
```
- Remove all students who have enrolled in less than 3 courses.
```js
db.students.deleteMany({ "coursesEnrolled.2": { $exists: false } });
```

**2. Aggregation Exercise:**

- Use aggregation to find the department with the most number of students.
```js
db.students.aggregate([
  {
    $group: {
      _id: "$department",
      student_count: { $sum: 1 }
    }
  },
  {
    $sort: { student_count: -1 }
  },
  {
    $limit: 1
  }
]);
```
**3. Advanced Querying Exercise:**

- Query students who have enrolled in a specific set of courses (e.g., `CS101` and `MATH101`).

```js
db.students.find({
  courses_enrolled: { $all: ["CS101", "Math101"] }
});
```

**4. Indexing and Performance:**

- Experiment with creating indexes on various fields like `department`, `year`, etc., and measure the query performance using `explain()`.
```js
db.students.createIndex({ department: 1 });

db.students.createIndex({ year: 1 });

db.students.find({ department: "Computer Science" }).explain("executionStats");
```
---