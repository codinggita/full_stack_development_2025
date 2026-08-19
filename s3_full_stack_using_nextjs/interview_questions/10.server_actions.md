# Server Actions — Interview Questions

1. What is a Server Action, and how does it differ from calling a Route Handler with `fetch()`?

2. Why use Server Actions for form mutations instead of client-side API calls?

3. Where does `"use server"` go — top of a file or inside a function?

4. How do Server Actions read submitted form data?

5. Why must mutations like create, update, and delete run on the server?

6. How do you return validation errors from a Server Action without throwing?

7. What is `useActionState()` used for with Server Actions?

8. Can Server Actions be called outside a `<form>`? When is that useful?

9. What is the difference between expected errors and unexpected errors inside Server Actions?

10. After a Server Action updates data, why call `revalidatePath()` or `revalidateTag()`?

11. When should a Server Action redirect with `redirect()` instead of returning JSON?

12. When is a Route Handler a better choice than a Server Action?

13. A Server Action is exported from a shared module. What security checks must still run inside the action?

14. Why should Server Actions not return sensitive internal error details?

15. A team updates the database in a Server Action but the UI stays stale until hard refresh. What did they forget?
