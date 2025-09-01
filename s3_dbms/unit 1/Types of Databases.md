# Types of Databases

## 1. Introduction

Not all databases are the same. The type of database depends on **how data is organized, stored, and accessed**.

For example:

* CodingGita’s **Student Information System** → best suited for a **Relational Database**.
* Instagram storing **posts, likes, comments** → better suited for a **NoSQL Database**.
* Telephone directory in old systems → worked well in a **Hierarchical Database**.

Thus, understanding types of databases helps us **choose the right database for the right problem**.

---

## 2. Relational Databases (RDBMS)

### Definition

* Data is stored in **tables (relations)** consisting of rows (tuples) and columns (attributes).
* Introduced by **E. F. Codd** in 1970.
* Each table represents one entity, and relationships are created using **keys**.

### Example – CodingGita Student DB

* **Student**(RollNo, Name, CourseID, FeeStatus)
* **Course**(CourseID, Title, FacultyID)
* **Faculty**(FacultyID, Name, Dept)

Here, relations connect tables:

* Student.CourseID → Course.CourseID
* Course.FacultyID → Faculty.FacultyID

### Features

* Structured, organized data.
* Supports **SQL** for queries.
* Ensures **ACID properties** (Atomicity, Consistency, Isolation, Durability).

### Popular RDBMS

* MySQL, PostgreSQL, Oracle, SQL Server.

---

## 3. Hierarchical Databases

### Definition

* Data stored in a **tree-like structure (parent-child relationships)**.
* Each child can have **only one parent**, but a parent can have multiple children.

### Example – CodingGita Course Catalog

```
University (Root)
   ├── Faculty of Engineering
   │     ├── Department of Computer Science
   │     │     ├── Course: DBMS
   │     │     └── Course: DSA
   │     └── Department of Electrical
   │           └── Course: Circuits
   └── Faculty of Management
         └── Course: MBA
```

### Features

* Fast access if hierarchy is natural.
* Rigid structure (cannot easily model many-to-many relationships).

### Real Use

* Old mainframe systems, **banking software** in the 1970s.
* IBM’s **Information Management System (IMS)** is a classic hierarchical DB.

---

## 4. Network Databases

### Definition

* Extension of hierarchical DB, but **a child can have multiple parents**.
* Data represented as a **graph with nodes and edges**.

### Example – CodingGita Students & Courses

* A **Student** can enroll in multiple courses.
* A **Course** can have multiple students.

In Network DB, this is stored as:

```
Student  <---enrolled_in--->  Course
```

### Features

* Better than hierarchical for many-to-many relationships.
* Complex to design and maintain.

### Real Use

* Still used in **telecom and supply chain management**.
* CODASYL (Conference on Data Systems Languages) introduced this model.

---

## 5. Object-Oriented Databases (OODBMS)

### Definition

* Combines **database capabilities** with **object-oriented programming concepts**.
* Data is stored as **objects**, similar to Java/C++ classes.
* Supports inheritance, polymorphism, and encapsulation.

### Example – CodingGita Student Object

```
Object: Student
{
   RollNo: 101
   Name: "Mahir"
   Courses: [DBMS, DSA, OS]
   Result: { DBMS: 85, DSA: 72, OS: 90 }
}
```

### Features

* Ideal for multimedia, CAD/CAM, and real-time systems.
* Stores images, videos, audio directly as objects.

### Popular OODBMS

* ObjectDB, Versant, db4o.

---

## 6. NoSQL Databases (Not Only SQL)

### Definition

* Designed for **large-scale, unstructured, or semi-structured data**.
* No fixed schema like RDBMS.
* Scales horizontally across multiple servers.

### Types of NoSQL DBs

1. **Document-oriented** → MongoDB (stores JSON-like documents).
2. **Key-Value stores** → Redis, DynamoDB.
3. **Column-based** → Cassandra, HBase.
4. **Graph-based** → Neo4j (used in social networks).

### Example – CodingGita Student in MongoDB (Document DB)

```json
{
   "RollNo": 101,
   "Name": "Jenil",
   "Courses": [
      {"CourseID": "CS101", "Title": "DBMS", "Marks": 85},
      {"CourseID": "CS102", "Title": "DSA", "Marks": 90}
   ],
   "FeeStatus": "Paid"
}
```

### Features

* Handles **big data**.
* Flexible schema (easy to add/remove fields).
* High speed and scalability.

### Real Use

* Instagram, YouTube, Flipkart, Paytm use NoSQL for scalability.

---

## 7. Comparison of Database Types

| Feature            | Relational DB | Hierarchical DB | Network DB   | Object-Oriented DB | NoSQL DB               |
| ------------------ | ------------- | --------------- | ------------ | ------------------ | ---------------------- |
| **Structure**      | Tables        | Tree            | Graph        | Objects            | JSON / Key-Value       |
| **Flexibility**    | Medium        | Low             | Medium       | High               | Very High              |
| **Relationships**  | Foreign Keys  | Parent-Child    | Many-to-Many | Inheritance, Links | Embedded Docs          |
| **Best Use**       | Business apps | Old banking     | Telecom, SCM | Multimedia, CAD    | Big Data, Social Media |
| **Query Language** | SQL           | Navigational    | Navigational | OQL                | Varies (MongoQL, CQL)  |

---

## 8. Summary

* **Relational Databases** (RDBMS) → Most common, table-based, supports SQL.
* **Hierarchical Databases** → Tree-like, outdated but fast for simple hierarchies.
* **Network Databases** → Graph-based, supports many-to-many relationships.
* **Object-Oriented Databases** → Stores objects directly, good for multimedia.
* **NoSQL Databases** → Schema-less, scalable, handles unstructured data.

👉 In real-world applications:

* CodingGita uses **Relational DB** for student info, exams, and fees.
* Instagram uses **NoSQL (MongoDB, Cassandra)** for posts and likes.
* Telecom systems still use **Network DB**.
* CAD/CAM uses **Object-Oriented DB**.

---
