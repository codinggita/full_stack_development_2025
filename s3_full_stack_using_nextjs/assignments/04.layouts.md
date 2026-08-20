# Layouts — Assignments

## Assignment — Layouts and Route Groups

**Title:** Build a Multi-Section App With Root Layout, Nested Layouts, and Route Groups

**Implementation:**

- Create a new Next.js project with App Router and `src/` directory enabled
- Create a `Navbar` component in `components/` with links to: Home, About, Products, and Contact
- Create a `Footer` component in `components/` with a copyright line
- Import both into `app/layout.tsx` and place them above and below `{children}`
- Add global CSS in `globals.css` with a basic body font and background color
- Create the following pages: `/`, `/about`, `/products`, and `/contact` — each returning a heading with the page name
- Navigate between all pages and confirm the `Navbar` and `Footer` remain visible without being written in each page file
- Create a `dashboard/` route with its own `layout.tsx` containing a sidebar with links to: Dashboard, Settings, and Profile
- Create the following pages inside `dashboard/`: `page.tsx`, `settings/page.tsx`, and `profile/page.tsx` — each returning a heading with the page name
- Navigate between the three dashboard pages and confirm the sidebar stays visible while only the page content changes
- Create two route groups inside `app/`: `(marketing)` and `(admin)`
- Inside `(marketing)`, create a `layout.tsx` with a marketing-specific header containing the site name, then create `pricing/page.tsx` and `blog/page.tsx` pages inside it
- Inside `(admin)`, create a `layout.tsx` with an admin-specific header, then create `users/page.tsx` and `reports/page.tsx` pages inside it
- Confirm that neither `(marketing)` nor `(admin)` appears in any URL and that each section shows its own layout
- Inside `app/dashboard/`, create a Client Component containing a `useState` counter and import it into the dashboard layout — navigate between the dashboard pages and confirm the counter value is preserved
- Add a `template.tsx` file inside `app/dashboard/` alongside the existing `layout.tsx`, containing the same counter component — navigate between the dashboard pages and observe the difference in counter behavior between the two files
- Write a comment at the top of `template.tsx` explaining the difference between `layout.tsx` and `template.tsx` based on what you observed
- Draw the complete layout hierarchy of the final project as a comment at the top of `app/layout.tsx`
