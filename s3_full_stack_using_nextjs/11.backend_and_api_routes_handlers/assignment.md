# Backend & API Route Handlers — Assignments

## Assignment — Backend and Route Handlers

**Title:** Build a Product API Using App Router and Pages Router Route Handlers

**Implementation:**

**App Router — Collection Route**
- Create a new Next.js project with App Router and `src/` directory enabled
- Create `app/api/products/route.ts` with a module-level in-memory array of at least three products, each with id, name, price, and category
- Implement a `GET` handler that reads an optional `?category=` query parameter from the URL and returns either all products or filtered products based on the category
- Implement a `POST` handler that reads the request body, validates it with a Zod schema, and adds the new product to the array — return the created product with a `201` status
- Return `401` from both handlers when the `authorization` header is missing
- Return `400` with validation details from the `POST` handler when the body is invalid
- Add `export const dynamic = "force-dynamic"` to the file

**App Router — Individual Product Route**
- Create `app/api/products/[id]/route.ts`
- Implement a `GET` handler that awaits `context.params`, finds the product by id, and returns it with `200` or `404` if not found
- Implement a `PUT` handler that replaces the entire product with the request body and returns the updated product
- Implement a `PATCH` handler that reads an optional `?notify=` query parameter and merges only the provided fields into the product — validate the body with a Zod schema where all fields are optional
- Implement a `DELETE` handler that removes the product from the array and returns `204` with no body
- Return `401` from all handlers when the `authorization` header is missing
- Return `404` from all handlers when the product does not exist

**App Router — Service Layer**
- Create `lib/services/product.service.ts` that exports the product array and functions: `getAllProducts`, `getProductById`, `createProduct`, `updateProduct`, `deleteProduct`
- Refactor both route files to call these service functions instead of managing the array directly

**Pages Router**
- Create a new Next.js project with Pages Router enabled
- Create `pages/api/products.ts` with a default export handler that branches on `req.method` — implement `GET` returning the product list and `POST` creating a new product from `req.body`
- Create `pages/api/products/[id].ts` with a default export handler that reads `req.query.id` and branches on `req.method` — implement `GET`, `PUT`, `PATCH`, and `DELETE` for a single product
- Return `405` from both handlers for any unsupported HTTP method

**Connecting From the Frontend**
- In the App Router project, create a `/products` Client Component page that fetches the product list from `/api/products` using `useEffect` and renders each product's name and price
- Add a form on the same page that submits a new product name, price, and category — on submit, call `POST /api/products` with the form data as JSON and refresh the list on success
- Add a Delete button next to each product that calls `DELETE /api/products/[id]` and removes the product from the list on success
