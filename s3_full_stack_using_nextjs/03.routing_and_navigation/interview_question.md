# Routing and Navigation — Interview Questions

1. What is file-based routing in the App Router?

2. How does a nested folder structure like `app/products/[id]/page.tsx` map to URLs?

3. When should you use a dynamic segment like `[id]` instead of a search param like `?page=2`?

4. How do you read route params versus search params in a Server Component page?

5. How are route groups like `(marketing)` different from normal folders in the URL?

6. What is the difference between catch-all `[...slug]` and optional catch-all `[[...slug]]` routes?

7. What is the purpose of a private folder prefixed with `_` in the App Router?

8. Why does Next.js prefer `<Link>` over a plain `<a>` tag for internal navigation?

9. What does `<Link prefetch>` do, and when might you turn prefetch off?

10. A developer calls `router.push()` inside a Server Component. Why does it fail?

11. When should you use `redirect()` on the server instead of client-side navigation?

12. After a form submit, why might you use `router.replace()` instead of `router.push()`?

13. What does `router.refresh()` re-run on the server, and what does it not clear?

14. What is the difference between `router.back()` and `router.replace()`?

15. A page needs normal in-app links, a post-login redirect, and a hard server guard. Which navigation tool fits each case?
