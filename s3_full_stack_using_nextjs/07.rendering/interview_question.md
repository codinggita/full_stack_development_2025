# Rendering in Next.js — Interview Questions

1. What is static rendering in Next.js?

2. What is dynamic rendering in Next.js?

3. Why does using a Client Component not automatically mean the page uses Client-Side Rendering?

4. What can force a statically-looking route to become dynamically rendered in the App Router?

5. How do static rendering and server-side rendering differ in when HTML and data are produced?

6. What is Client-Side Rendering, and when is it appropriate in Next.js?

7. What is Static Site Generation, and when should you use it?

8. What does `generateStaticParams` do for a dynamic route like `/products/[slug]`?

9. What is ISR, and how does it differ from pure SSG?

10. A page uses `revalidate: 60`. A user opens it five minutes after the last rebuild. Does that request always wait for fresh data?

11. When would ISR be a better fit than SSR for the same content?

12. What is the difference between time-based and on-demand revalidation?

13. Two pages share the same fetch function, but one reads `cookies()`. Why might one be static and the other dynamic?

14. Why is SSG a poor fit for data that must change on every request?

15. Why should ISR not be treated as real-time data?
