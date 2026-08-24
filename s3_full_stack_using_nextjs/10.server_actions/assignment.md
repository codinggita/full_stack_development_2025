# Server Actions — Assignments

## Assignment — Forms, Validation and Server Actions

**Title:** Build a Product Management System With Forms, Validation, and Server Actions

**Implementation:**

**Basic Form and Server Action**
- Create a new Next.js project with App Router and `src/` directory enabled
- Create a `/contact` page with a form containing name, email, and message fields — each with correct input types and `name` attributes and a proper `<label>` for each field
- Create a Server Action in a separate `actions.ts` file that reads the three fields from `FormData` and logs them to the console
- Wire the form to submit to this Server Action
- Add HTML validation attributes (`required`, `minLength`) to each field

**Server-Side Validation and Error Display**
- Create a `/signup` page with a form containing name, email, password, and confirm password fields
- Define a Zod schema that validates: name is required, email is a valid email, password is at least 8 characters, and confirm password matches password
- Create a Server Action that validates the submitted data using the Zod schema and returns field-level errors when validation fails
- Use `useActionState` in a Client Component to receive the returned errors and display each error message beside its corresponding field
- Display a success message when the action completes without errors
- While the form is submitting, disable the submit button and change its label to "Submitting..."

**React Hook Form + Server Action**
- Create a `/create-product` page with a form containing product name, price, and category fields
- Use React Hook Form with a Zod schema for client-side validation — validate that name is required, price is a positive number, and category is required
- Wire the form to call a Server Action using `handleSubmit` with `startTransition`
- The Server Action should also validate the data with Zod on the server — return field-level errors if validation fails
- Display both client-side React Hook Form errors and server-side errors returned from the action

**Create, Update and Delete With Revalidation**
- Create a hardcoded in-memory product list stored in a module-level array containing at least three products with id, name, and price
- Create a `/products` page that renders the product list with an Edit button and a Delete button next to each product
- Create a Server Action for deleting a product by id — after deletion, call `revalidatePath("/products")`
- Create an `/edit-product` page with a form pre-filled with the product's current name and price
- Create an update Server Action that uses `.bind(null, id)` to receive the product id and updated fields from `FormData` — after update, call `revalidatePath("/products")` and redirect to `/products`
- Create a `/new-product` page with a form and a Server Action that adds a new product to the list, revalidates `/products`, and redirects to `/products`

**Calling a Server Action Outside a Form**
- On the `/products` page, add a "Mark as Featured" button next to each product that calls a Server Action directly using `startTransition` without a form
- The Server Action should log the product id to the console and return a success message
- Display the success message in the UI after the action completes

**Accessibility**
- Review all forms built and confirm every input has a visible `<label>` connected via `htmlFor` and `id`
- Add `aria-invalid="true"` and `aria-describedby` to inputs that have an error state
- Confirm all forms are navigable using only the keyboard
