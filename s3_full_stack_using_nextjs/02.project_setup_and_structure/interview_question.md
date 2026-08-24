# Next.js Project Setup & Structure — Interview Questions

1. What are the main differences between the Pages Router and the App Router?

2. Can the Pages Router and App Router exist in the same project? What should you watch out for if both are used?

3. When would you start a new project on the App Router instead of the Pages Router? When might you keep the Pages Router?

4. What is the difference between `pages/index.tsx` in the Pages Router and `app/page.tsx` in the App Router?

5. In the App Router, does creating a folder always create a public URL route? Explain.

6. Why must `error.tsx` be a Client Component in the App Router?

7. What is the difference between a normal environment variable and one prefixed with `NEXT_PUBLIC_`?

8. Why should secrets never use the `NEXT_PUBLIC_` prefix? What happens if a server-only secret is imported into a Client Component?

9. What is the purpose of the `src/` directory, and is it required?

10. Are `components/`, `lib/`, and `hooks/` special Next.js folders with built-in behavior?

11. Given this App Router structure, what URL does each `page.tsx` map to?

```text
src/
└── app/
    ├── page.tsx
    ├── about/
    │   └── page.tsx
    └── products/
        ├── page.tsx
        └── [id]/
            └── page.tsx
```

12. In a Pages Router project, what API endpoint does `pages/api/products.ts` expose?

13. An old codebase uses the Pages Router and the team wants Server Components and nested layouts. What constraints should they understand before adding an `app/` folder?

14. `DATABASE_URL` works in `.env.local` on the server but breaks when used in a Client Component. Why?

15. What is the role of special files like `layout.tsx`, `loading.tsx`, and `not-found.tsx` in an App Router folder?
