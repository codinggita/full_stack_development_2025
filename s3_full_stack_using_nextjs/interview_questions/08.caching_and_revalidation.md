# Caching & Revalidation — Interview Questions

1. Why does Next.js use multiple caching layers instead of one global cache?

2. What is the difference between the Data Cache and the Full Route Cache?

3. How is request memoization different from the Data Cache?

4. What is the Client Router Cache, and how can it show stale UI after server data was updated?

5. Two Server Components in one request call the same `fetch()` with identical options. How many upstream requests happen?

6. What do `cache: "force-cache"`, `cache: "no-store"`, and `next: { revalidate: N }` mean for fetch?

7. How does caching interact with static versus dynamic rendering?

8. When should you use `revalidatePath()` instead of `revalidateTag()`?

9. What is the difference between time-based and on-demand revalidation?

10. Why are cache tags useful when one dataset appears on many pages?

11. When would you choose `updateTag()` over `revalidateTag(tag, "max")` after a mutation?

12. A Server Action calls `revalidatePath()`, but a TanStack Query list on the client stays stale. Why can both be wrong at once?

13. A fetch uses `cache: "no-store"`, but client navigation still shows old HTML. What other cache layer could be involved?

14. Why is choosing a very long revalidation time risky for semi-fresh content?

15. You updated a product but the wrong page still looks cached. What revalidation mistakes should you check?
