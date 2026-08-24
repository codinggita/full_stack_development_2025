# Data Fetching & UI States — Assignments

## Assignment — Data Fetching and UI States

**Title:** Build a Product Store With Server and Client Data Fetching, Loading, Error, and Not-Found States

**Implementation:**

- Create a new Next.js project with App Router and `src/` directory enabled
- Create a `products/page.tsx` as a Server Component that fetches a list of products from `https://fakestoreapi.com/products` and renders each product's title and price
- Add a `products/loading.tsx` that displays a loading message — confirm it appears while the page is loading
- Add a `products/error.tsx` that displays an error message and a "Try again" button using the `reset` function — simulate an error by throwing inside the page and confirm the error UI appears
- Create a `products/[id]/page.tsx` as a Server Component that reads the `id` from `params`, fetches a single product from `https://fakestoreapi.com/products/{id}`, and renders the product title, price, and description
- Add a `products/[id]/not-found.tsx` with a "Product not found" message — call `notFound()` inside the page when the fetched product does not exist and confirm the not-found UI appears
- Add a `products/[id]/error.tsx` that displays an error message and a "Try again" button
- Create a `store/page.tsx` as a Server Component that fetches both products and categories from `https://fakestoreapi.com/products` and `https://fakestoreapi.com/products/categories` in parallel using `Promise.all` — render both lists on the page
- Create a `search/page.tsx` as a Server Component that reads a `?category=` search parameter from the URL and fetches products from `https://fakestoreapi.com/products/category/{category}` when a category is provided, or all products when it is not — render the results on the page
- Create a `components/LiveSearch.tsx` as a Client Component that uses `useState` and `useEffect` to fetch products from `https://fakestoreapi.com/products` after the component loads and renders them as a list — use an explicit TypeScript type for the state
- Create a `dashboard/page.tsx` that uses `redirect("/login")` when a variable `isLoggedIn` is set to `false` — confirm the redirect works and confirm `redirect()` is not inside a `try/catch` block
- Create a `login/page.tsx` with a heading "Login Page" to serve as the redirect destination
- Wrap the slow product list section on the `store/page.tsx` inside a `<Suspense>` boundary with a fallback message — confirm the rest of the page renders before the slow section appears
