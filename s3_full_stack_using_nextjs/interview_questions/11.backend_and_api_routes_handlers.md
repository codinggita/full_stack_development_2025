# Backend & API Route Handlers — Interview Questions

1. What is the App Router file convention for an API endpoint at `/api/products`?

2. How do Route Handlers map HTTP methods like GET and POST to exported functions?

3. How does a Route Handler differ from a Server Action for the same create-product flow?

4. Why should Route Handlers stay thin instead of containing all business logic?

5. In the App Router, why is `context.params` a Promise in Route Handlers?

6. What is the difference between Web `Request`/`Response` and Express `req`/`res`?

7. A webhook from Stripe hits your app. Why is a Route Handler usually the right entry point?

8. A mobile app needs the same backend as your Next.js site. Which backend pattern fits best?

9. Where should shared validation and database logic live if both Route Handlers and Server Actions exist?

10. What HTTP status codes should a create endpoint return for success, validation failure, and auth failure?

11. How can Route Handler caching affect GET APIs in the App Router?

12. What is the Pages Router equivalent of `app/api/products/route.ts`?

13. When should you choose Server Actions over Route Handlers for an internal admin form?

14. A Route Handler parses JSON manually and trusts the client shape. What risks appear?

15. What is a good folder structure for backend code in a growing Next.js app?
