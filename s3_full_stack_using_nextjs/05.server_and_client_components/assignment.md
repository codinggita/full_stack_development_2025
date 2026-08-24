# Server & Client Components — Assignments

## Assignment — Server and Client Components

**Title:** Build a Page Using Server and Client Components Together

**Implementation:**
- Create a new Next.js project with App Router and `src/` directory enabled
- Create a `products/page.tsx` as a Server Component that defines a hardcoded array of five products (id, name, price) and renders them as a list — do not add `"use client"` to this file
- Create a `components/AddToCartButton.tsx` as a Client Component that accepts a `productId` prop and displays a button — clicking the button should show an alert with the product id
- Import `AddToCartButton` into the products page and render it alongside each product — confirm the page works without making the entire page a Client Component
- Create a `components/Counter.tsx` as a Client Component with a `useState` counter and increment button
- Create an `about/page.tsx` as a Server Component that renders a heading and description, and includes the `Counter` component inside it — confirm the page renders without adding `"use client"` to the page file
- Create a `components/InteractivePanel.tsx` as a Client Component that accepts `children` and renders them inside a wrapper with a toggle button
- Create a `dashboard/page.tsx` as a Server Component that passes a hardcoded `<p>` element as `children` to `InteractivePanel` — confirm server-rendered content renders inside a Client Component
- Create a `components/SearchBar.tsx` as a Client Component that uses `useState` to track an input value and displays the current value below the input
- Create a `components/ProductCard.tsx` as a Server Component that accepts a product name and price as props and renders them — import it inside the products page alongside `AddToCartButton`
- Attempt to add `useState` directly inside a Server Component and observe the error — then fix it by extracting that piece into a separate Client Component
- Write a comment at the top of each component file stating whether it is a Server Component or Client Component and one sentence explaining why
