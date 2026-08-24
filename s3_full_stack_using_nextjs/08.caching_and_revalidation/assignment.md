# Caching & Revalidation — Assignments

## Assignment — Rendering Strategies

**Title:** Build a Store Application Covering All Four Rendering Strategies

**Implementation:**

**Static Rendering**
- Create a new Next.js project with App Router and `src/` directory enabled
- Create an `/about` page that fetches categories from `https://fakestoreapi.com/products/categories` and renders them as a list
- Create a `/pricing` page that returns hardcoded pricing tiers
- Create a `/products` page that fetches all products from `https://fakestoreapi.com/products` and renders each product's title and price
- Create a `/products/[id]` page that pre-renders the first five product IDs at build time and renders each product's title, description, and price
- Write a comment at the top of each page file stating it uses static rendering and one sentence explaining why

**ISR**
- Create a `/news` page that fetches products from `https://fakestoreapi.com/products` and revalidates every 30 seconds
- Create a `/blog` page that fetches categories from `https://fakestoreapi.com/products/categories` and revalidates every 120 seconds using a route-level revalidation export instead of on the fetch call
- Write a comment at the top of each page file stating the revalidation period chosen and why

**Dynamic Rendering**
- Create an `/account` page that reads a cookie named `username` and renders a welcome message
- Create an `/orders` page that reads a `?status=` search parameter and renders the current status
- Create a `/profile` page that fetches user data from `https://fakestoreapi.com/users/1` and renders the user's name and email
- Create a `/dashboard` page that renders a heading and a timestamp that changes on every request
- Create a `/feed` page that reads the `user-agent` from request headers and renders it
- Write a comment at the top of each page file identifying which trigger caused dynamic rendering

**CSR**
- Create a `/cart` page that manages a list of items with an "Add Item" button that appends a new item on each click
- Create a `/search` page that tracks a search input and fetches products from `https://fakestoreapi.com/products` after the component loads — display only products whose title contains the current input value
- Create a `/tracker` page that displays and updates the current window width when the browser is resized
- Create a `/products` page that renders a product list alongside an "Add to Cart" button — keep the page itself server-side and only the button as a Client Component
- Write a comment at the top of each Client Component file stating it uses CSR and one sentence explaining why
