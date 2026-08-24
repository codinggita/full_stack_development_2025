# Routing and Navigation — Assignments

## Assignment 1 — File-Based Routing and Navigation

**Title:** Build a Multi-Page App Using App Router Routing Conventions

**Implementation:**
- Create a new Next.js project with App Router and `src/` directory enabled
- Create the following static routes: `/about`, `/contact`, `/pricing`, and `/terms` — each returning a heading with the page name
- Create a nested route structure for a blog: `/blog` as the listing page and `/blog/latest` as a nested page
- Create a dynamic route `/products/[id]` — read the `id` from the URL and display it on the page
- Create a catch-all route `/docs/[...slug]` that reads the slug segments and displays them as a list
- Create a `/shop` route and add a `_components/` private folder inside it containing a `FilterPanel.tsx` component
- Create two route groups: `(marketing)` containing the home and pricing pages, and `(dashboard)` containing a dashboard page
- In the root `layout.tsx`, add a `Navbar` using `<Link>` for navigation to: Home, Products, Blog, and Docs
- In the `Navbar`, highlight the currently active link based on the current URL path
- On the `/products` page, read and display `?search=` and `?page=` search parameters from the URL
- Add a button on the `/products/[id]` page that navigates back to the previous page
- Add a button on the `/contact` page that navigates to the home page after a simulated action
- In the `/dashboard` page, redirect to `/login` when a variable `isLoggedIn` is set to `false`

---

## Assignment 2 — Pages Router Routing Conventions

**Title:** Build a Multi-Page App Using Pages Router Routing Conventions

**Implementation:**
- Create a new Next.js project with Pages Router enabled — without the `src/` directory
- Create the following static routes inside `pages/`: `about.tsx`, `contact.tsx`, `pricing.tsx`, and `terms.tsx` — each returning a heading with the page name
- Create a nested route structure: `pages/blog/index.tsx` as the listing page and `pages/blog/latest.tsx` as a nested page
- Create a dynamic route `pages/products/[id].tsx` that reads and displays the `id` from the URL
- Create a catch-all route `pages/docs/[...slug].tsx` that reads and displays the matched segments as a list
- In `_app.tsx`, add a `Navbar` using `<Link>` for navigation to: Home, Products, Blog, and Docs
- In the `Navbar`, highlight the currently active link based on the current URL path
- On `pages/products/index.tsx`, read and display `?search=` and `?page=` from the URL
- On `pages/products/[id].tsx`, add a button that navigates back to the previous page
- On `pages/dashboard.tsx`, navigate to `/login` when a variable `isLoggedIn` is set to `false` — ensure the dashboard page is not added to the browser history
- Create a custom `pages/404.tsx` with a not-found message and navigate to a non-existent URL to confirm it appears
