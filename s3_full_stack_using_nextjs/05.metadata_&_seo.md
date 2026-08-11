# 5. SEO & Metadata in Next.js

## Why SEO and Metadata Matter

Imagine you built the best **Swiggy clone** — beautiful UI, fast, all restaurant menus updated daily.
But when people search _"best biryani in Mumbai"_ on Google, your site **does not appear anywhere**.

This is where **SEO (Search Engine Optimization)** and **metadata** come in.

Metadata tells **search engines, social platforms, AI assistants, and browsers**:

- What your page is about
- Who it is for
- How to display it in search results and link previews

If you share a **Zomato restaurant link** on WhatsApp and see a preview with the name, photo, and ratings — that is **Open Graph metadata** in action.

In modern **Next.js (App Router)**, SEO is managed mainly through:

- **Metadata API** — `metadata` and `generateMetadata`
- `robots.ts` — Crawler instructions
- `sitemap.ts` — URL discovery for search engines
- **Canonical URLs** — Preferred URL for duplicate variants
- **Structured data (JSON-LD)** — Rich results and clearer machine-readable content

> For new projects, prefer the **App Router Metadata API**. The Pages Router `next/head` approach is still valid for older projects.

---

## Types of SEO

SEO is not one single task. Different channels need different optimization.

| Type                | Goal                                               | Examples                                                                                         |
| ------------------- | -------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| **Traditional SEO** | Rank in search engines like Google and Bing        | Titles, descriptions, headings, internal links, backlinks                                        |
| **Technical SEO**   | Make the site crawlable, fast, and well-structured | Sitemap, robots.txt, canonical URLs, Core Web Vitals, mobile-friendly layout                     |
| **On-page SEO**     | Optimize individual page content                   | Useful headings, semantic HTML, alt text, clear URLs                                             |
| **Local SEO**       | Appear in location-based searches                  | Business name, address, maps, local keywords                                                     |
| **E-commerce SEO**  | Rank product and category pages                    | Product titles, prices, availability, reviews, structured data                                   |
| **Social SEO**      | Control link previews on social/messaging apps     | Open Graph, Twitter/X cards                                                                      |
| **AI Search / GEO** | Help AI systems understand and cite your content   | Clear content structure, FAQ sections, structured data, authoritative pages, llms.txt (optional) |

### What is AI Search / GEO?

**GEO (Generative Engine Optimization)** is optimization for **AI-powered search and assistants** such as ChatGPT search, Perplexity, Google AI Overviews, and Copilot.

These systems still rely on crawlable, trustworthy content, but they also favor:

- **Clear, factual, well-structured content** — short summaries, headings, bullet points
- **Authoritative pages** — about pages, docs, product pages with complete information
- **Structured data** — Schema.org JSON-LD for products, articles, FAQs, organizations
- **Canonical, stable URLs** — so AI systems can reference the correct source
- **Fast, accessible HTML** — important content available without heavy client-only rendering

Optional: some teams add an `llms.txt` file (similar in idea to `robots.txt`) to describe which pages are most useful for AI systems to read. This is emerging practice, not a guaranteed ranking factor.

> **Important:** Good traditional SEO still helps AI search. If Google cannot crawl and understand your page, AI systems usually struggle too.

---

## How Search Engines Work

A simplified model:

```text
Crawling → Indexing → Ranking
```

1. **Crawling** — Bots discover URLs and fetch page content
2. **Indexing** — The search engine stores and analyzes page information
3. **Ranking** — Relevant pages are ordered for a search query

Next.js helps by delivering **server-rendered or static HTML**, but:

> **Next.js does not automatically guarantee good SEO.** Content, metadata, links, performance, and accessibility still matter.

---

## Metadata API (App Router)

In the App Router, metadata is defined in `layout.tsx` or `page.tsx` using the **Metadata API**.

### Static metadata

Use when page metadata is fixed.

```tsx
// app/layout.tsx
import type { Metadata } from "next";

export const metadata: Metadata = {
	metadataBase: new URL("https://codinggita.com"),
	title: {
		default: "CodingGita",
		template: "%s | CodingGita",
	},
	description: "Learn full stack development with practical projects.",
	openGraph: {
		title: "CodingGita",
		description: "Learn full stack development with practical projects.",
		url: "https://codinggita.com",
		siteName: "CodingGita",
		images: ["/og-default.jpg"],
		type: "website",
	},
	twitter: {
		card: "summary_large_image",
		title: "CodingGita",
		description: "Learn full stack development with practical projects.",
		images: ["/og-default.jpg"],
	},
};

export default function RootLayout({
	children,
}: {
	children: React.ReactNode;
}) {
	return (
		<html lang='en'>
			<body>{children}</body>
		</html>
	);
}
```

Set `metadataBase` in the root layout so relative image and canonical URLs resolve correctly.

### Dynamic metadata with `generateMetadata`

Use when metadata depends on route params or fetched data (product pages, blog posts, restaurant pages).

```tsx
// app/restaurants/[slug]/page.tsx
import type { Metadata } from "next";

type Props = {
	params: Promise<{ slug: string }>;
};

async function getRestaurant(slug: string) {
	const response = await fetch(
		`https://api.example.com/restaurants/${slug}`,
		{
			next: { revalidate: 3600 },
		},
	);

	return response.json();
}

export async function generateMetadata({ params }: Props): Promise<Metadata> {
	const { slug } = await params;
	const restaurant = await getRestaurant(slug);

	return {
		title: `${restaurant.name} - ${restaurant.city}`,
		description: restaurant.description,
		alternates: {
			canonical: `/restaurants/${slug}`,
		},
		openGraph: {
			title: `${restaurant.name} - Order Online`,
			description: restaurant.description,
			images: [restaurant.image],
			url: `/restaurants/${slug}`,
			type: "website",
		},
		twitter: {
			card: "summary_large_image",
			title: restaurant.name,
			description: restaurant.description,
			images: [restaurant.image],
		},
	};
}

export default async function RestaurantPage({ params }: Props) {
	const { slug } = await params;
	const restaurant = await getRestaurant(slug);

	return <h1>{restaurant.name}</h1>;
}
```

### Important Metadata API rules (Next.js 15+)

- `metadata` and `generateMetadata` work only in **Server Components**
- Do **not** export both `metadata` and `generateMetadata` from the same route segment
- In **Next.js 15+**, `params` and `searchParams` are **Promises** — always `await` them
- Use `alternates.canonical` on dynamic routes to avoid duplicate URL issues
- `fetch` **inside** `generateMetadata` **is memoized** — the same request can be reused in the page component
- **File-based metadata** (`opengraph-image.tsx`, `icon.tsx`, `robots.ts`, `sitemap.ts`) can override config-based metadata

---

## Pages Router (Legacy)

Older Next.js projects use `next/head` in the Pages Router.

```jsx
// pages/restaurants/paradise-biryani.js
import Head from "next/head";

export default function RestaurantPage() {
	return (
		<>
			<Head>
				{/* Basic SEO */}
				<title>
					Paradise Biryani - Hyderabad | Order Online on CodingGita
				</title>
				<meta
					name='description'
					content='Order authentic Paradise Biryani from Hyderabad on CodingGita. Fast delivery, fresh ingredients, and unbeatable taste.'
				/>
				<meta
					name='keywords'
					content='biryani, Paradise Biryani, Hyderabad food, order online'
				/>

				{/* OpenGraph for social media */}
				<meta
					property='og:title'
					content='Paradise Biryani - Hyderabad | Order Online'
				/>
				<meta
					property='og:description'
					content="Taste Hyderabad's legendary Paradise Biryani, now on CodingGita. Order online and get it delivered hot."
				/>
				<meta
					property='og:image'
					content='https://codinggita.com/images/paradise-biryani.jpg'
				/>
				<meta property='og:type' content='website' />
				<meta
					property='og:url'
					content='https://codinggita.com/restaurants/paradise-biryani'
				/>

				{/* Twitter Card */}
				<meta name='twitter:card' content='summary_large_image' />
				<meta
					name='twitter:title'
					content='Paradise Biryani - Hyderabad'
				/>
				<meta
					name='twitter:description'
					content='Order authentic Paradise Biryani from Hyderabad on CodingGita.'
				/>
				<meta
					name='twitter:image'
					content='https://codinggita.com/images/paradise-biryani.jpg'
				/>

				{/* Canonical URL */}
				<link
					rel='canonical'
					href='https://codinggita.com/restaurants/paradise-biryani'
				/>
			</Head>

			<h1>Paradise Biryani - Hyderabad</h1>
		</>
	);
}
```

For new App Router projects, prefer `metadata` / `generateMetadata` instead of `next/head`.

---

## `robots.txt` & Its Limitations

- The `robots.txt` file lives at the **root** (e.g. `https://swiggy-clone.com/robots.txt`) and guides crawlers like Googlebot on _which parts of your site they may or may not crawl_ ([Google for Developers][1], [Yoast][2]).
- It’s **advisory only**—respecting crawlers obey it; malicious bots often ignore it ([Wikipedia][3]).
- Blocking via `robots.txt` doesn’t guarantee de-indexing; URLs may still appear in search results without descriptions if linked elsewhere ([Google for Developers][1]).

---

## Example — What Should Be in `robots.txt`

Let’s imagine a Swiggy-like food delivery app. Here’s how you might structure your `robots.txt`, by features and rationale.

```
User-agent: *
Allow: /
```

- **`User-agent: *`** → applies to all crawlers.
- **`Allow: /`** → indicates general access is fine.

### 1. Block Non-Public / Functional Paths

These include APIs, admin, login, and order flows—none are meaningful for public indexing and may leak private data.

```
Disallow: /api/
Disallow: /admin/
Disallow: /auth/
Disallow: /login
Disallow: /logout
```

### 2. Prevent Duplication from Filters or Parameters

A food delivery app often has filter queries (e.g., `?cuisine=italian`) and category views. These create tons of similar URLs.

```
Disallow: /*?filter=
Disallow: /*?sort=
```

- Use wildcards (`*`) to block parameter-caused URL variants ([Prerender][4]).

### 3. Exclude Sensitive or Transactional Pages

Pages like the shopping cart, checkout, order tracking, and payment gateway aren’t useful for SEO and could expose sensitive flows.

```
Disallow: /cart
Disallow: /checkout
Disallow: /order-track
Disallow: /payment
```

### 4. E-commerce Best Practice Reminder

Do **not** use broad or “blanket” disallows that accidentally block important content — target only pages that should remain private or are low-value for search ([Prerender][4]).

### 5. Respect Crawlers’ Budget & Sitemap Tracking

Be explicit, add your sitemap(s) so crawlers can discover pages efficiently:

```
Sitemap: https://swiggy-clone.com/sitemap.xml
Sitemap: https://swiggy-clone.com/instamart/sitemap.xml.gz
```

Swiggy itself references multiple sitemaps; useful for segmented site areas (e.g., Instamart) ([Swiggy.com][5]).

---

## Swiggy’s Real `robots.txt` Example

Swiggy's actual `robots.txt` (as of now) looks like:

```
User-agent: *
Allow: /
Disallow: /product
Disallow: /product-category
Disallow: /api
Disallow: /dapi
Disallow: /mapi
Disallow: /?attachment_id=*
Disallow: /wp-admin
Disallow: /wp-includes
Disallow: /wp-content/plugins/
Disallow: /category/*
Disallow: /track-order/*
Disallow: /order-track/*
Disallow: /auth*
Disallow: /web-payments
Disallow: /invoice/*
Disallow: /home
Disallow: /cart
Disallow: /payment
Disallow: /checkout
Disallow: /my-account
Disallow: /rate
Sitemap: https://www.swiggy.com/sitemap.xml.gz
Sitemap: https://www.swiggy.com/instamart/sitemap/sitemap.xml.gz
```

Notice how they've blocked legacy WordPress paths (`/wp-admin` etc.), their APIs (`/api`, `/dapi`, `/mapi`), filters (`?attachment_id=*`), and private user flows like cart, checkout, order tracking, etc. They also provide multiple sitemaps ([Swiggy.com][5]).

---

## Advanced Features & Tips

| Directive                 | Purpose & Example                                                                                          |
| ------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `Crawl-delay`             | Throttle crawlers (supported by some like Bing/Yandex, ignored by Google) ([Wikipedia][6], [Wikipedia][3]) |
| `$` at end                | Match end-of-URL, e.g. `Disallow: /*.php$` blocks `.php` files only ([Wikipedia][6])                       |
| `Allow:` override         | Allow sub-paths inside disallowed paths (useful selectively) ([Conductor][7])                              |
| Comments (`#`)            | Annotate why rules exist—for future clarity ([seerinteractive.com][8])                                     |
| Multiple Sitemaps         | Helps structure large sites (e.g. separate Instamart section) ([SEOTesting.com][9])                        |
| Specific User-Agent rules | e.g. restrict just `Googlebot-Image`, allow `*` ([Google for Developers][10])                              |

---

## Recap

For a site like Swiggy:

1. **Allow general crawling** but **block private or sensitive pages**—they don't add SEO value and risk exposing user data.
2. **Avoid duplicate-content trap** by blocking parameter-heavy or filter-generated URLs.
3. **Provide sitemaps** for easier indexation and efficient crawling.
4. **Add notes/comments** in your `robots.txt` for clarity as your team evolves.
5. **Test your setup** via tools like Google Search Console's Robots Tester and validate syntax (one rule per line, proper order: User-agent → Disallow → Allow → Sitemap) ([Ignite Visibility][11]).

---

[1]: https://developers.google.com/search/docs/crawling-indexing/robots/intro?utm_source=codinggita.com "Robots.txt Introduction and Guide | Google Search Central"
[2]: https://yoast.com/ultimate-guide-robots-txt/?utm_source=codinggita.com "The ultimate guide to robots.txt - Yoast"
[3]: https://en.wikipedia.org/wiki/Robots.txt?utm_source=codinggita.com "Robots.txt"
[4]: https://prerender.io/blog/robots-txt-for-ecommerce-seo/?utm_source=codinggita.com "Robots.txt Best Practices for Ecommerce SEO - Prerender"
[5]: https://www.swiggy.com/robots.txt?utm_source=codinggita.com "robots.txt - Swiggy"
[6]: https://de.wikipedia.org/wiki/Robots_Exclusion_Standard?utm_source=codinggita.com "Robots Exclusion Standard"
[7]: https://www.conductor.com/academy/robotstxt/?utm_source=codinggita.com "Robots.txt for SEO: The Ultimate Guide - Conductor"
[8]: https://www.seerinteractive.com/insights/how-to-read-robots-txt?utm_source=codinggita.com "What is Robots.txt? A Guide for SEOs - Seer Interactive"
[9]: https://seotesting.com/google-search-console/robots-txt/?utm_source=codinggita.com "Robots.txt and SEO - The Ultimate Guide from the Experts"
[10]: https://developers.google.com/search/docs/crawling-indexing/robots/create-robots-txt?utm_source=codinggita.com "Create and Submit a robots.txt File | Google Search Central"
[11]: https://ignitevisibility.com/the-newbies-guide-to-blocking-content-with-robots-txt/?utm_source=codinggita.com "Robots.txt Disallow: A Complete Guide - Ignite Visibility"

# **Sitemaps**

## 1. **What is a Sitemap?**

A **sitemap** is a **structured list or diagram** that outlines all the pages, content sections, and navigation flows of a website or application.

- For **users**, it acts as a **guide** to understand where they can go.
- For **search engines**, it helps **index content efficiently** so it appears in search results.
- For **designers and developers**, it is a **blueprint** of the site’s architecture.

Think of a sitemap like the **floor plan of a mall** — it shows you all the stores (pages) and how to get from one to another.

---

## 2. **Why Sitemaps are Important**

A sitemap is not just a list — it is **central to planning, SEO, and user experience**.
For a platform like **JioHotstar**, which has millions of content pieces, a well-structured sitemap ensures:

- **Better Content Organization**: Movies, series, sports, news — all neatly categorized.
- **Improved User Experience**: Users can find what they want without confusion.
- **Search Engine Optimization (SEO)**: Google, Bing, etc., can quickly discover and index new shows or matches.
- **Reduced Development Confusion**: Teams know exactly which pages to build and how they connect.

---

## 3. **Types of Sitemaps**

JioHotstar (and similar OTT platforms) generally uses **two main types** of sitemaps:

### **A. Visual Sitemap (Planning Stage)**

- Shows **hierarchical structure** of pages (parent–child relationships).
- Used internally during the **design and UX planning phase**.
- Example:

```
Home
│
├── Movies
│   ├── Bollywood
│   ├── Hollywood
│   ├── Regional
│
├── TV Shows
│   ├── Drama
│   ├── Comedy
│   ├── Reality
│
├── Sports
│   ├── Cricket
│   ├── Football
│   ├── Hockey
│
├── My Account
│   ├── Login / Sign Up
│   ├── Subscriptions
│   ├── Watchlist
```

---

### **B. XML Sitemap (For Search Engines)**

- A **machine-readable file** (in XML format) submitted to search engines.
- Lists **URLs**, last modified date, priority, and update frequency.
- Helps **Google** and other crawlers index pages faster.

Example of JioHotstar XML Sitemap (simplified):

```xml
<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
  <url>
    <loc>https://www.jiohotstar.com/</loc>
    <lastmod>2025-08-01</lastmod>
    <priority>1.0</priority>
  </url>
  <url>
    <loc>https://www.jiohotstar.com/movies/bollywood</loc>
    <lastmod>2025-08-05</lastmod>
    <priority>0.9</priority>
  </url>
  <url>
    <loc>https://www.jiohotstar.com/sports/cricket</loc>
    <lastmod>2025-08-07</lastmod>
    <priority>0.8</priority>
  </url>
</urlset>
```

---

## 4. **How JioHotstar is using a Sitemap**

JioHotstar’s sitemap must account for **different user journeys** and **content categories**.

- **Movies Section**
    - Genre Pages (Action, Romance, Comedy, Thriller)
    - Language Pages (Hindi, Tamil, Telugu, Bengali)
    - Individual Movie Pages (e.g., `/movies/brahmastra`)

- **TV Shows Section**
    - Categories (Drama, Comedy, Reality)
    - Language-specific TV shows
    - Show Detail Pages (with season/episode listings)

- **Sports Section**
    - Live Matches
    - Upcoming Matches
    - Highlights
    - Specific Tournaments (e.g., IPL, Pro Kabaddi)

- **Account Management**
    - Login & Sign Up
    - Subscription Management
    - Profile Settings
    - Watchlist

- **Support Pages**
    - FAQ
    - Terms & Conditions
    - Privacy Policy

---

## 5. **Key Sitemap Best Practices for JioHotstar**

To make the sitemap **effective**, JioHotstar would follow:

- **Keep URLs clean**:
  Instead of
  `https://www.jiohotstar.com/?content_id=12345`
  Use
  `https://www.jiohotstar.com/movies/brahmastra`

- **Update regularly**:
  New content like cricket match highlights or latest Bollywood films should be added instantly.

- **Use Priority Levels**:
  Give **Home Page** a higher priority than a single episode page.

- **Include Canonical URLs**:
  Avoid duplicate content indexing.

- **Separate Mobile & Web Sitemaps** (if needed):
  Since OTT apps have mobile-first audiences, mobile-specific sitemaps can help.

---

## 6. **Benefits JioHotstar Gets from an Optimized Sitemap**

- **Fast Discovery of New Content**:
  A new cricket match highlight is indexed within hours, appearing in Google search quickly.
- **Improved SEO Rankings**:
  Search engines can categorize content better.
- **Better Internal Linking**:
  Helps users and crawlers navigate deeper into the site.
- **Scalability**:
  Even with millions of shows, the sitemap can handle growth.

---

## 7. **Challenges in Maintaining JioHotstar’s Sitemap**

Since OTT platforms like JioHotstar are **dynamic**, challenges include:

- Thousands of **new videos** each month.
- Live sports with **short shelf-life**.
- Regional content with **language variations**.
- Avoiding **broken links** for removed shows.
- Managing **multiple subdomains** (e.g., for sports, kids, movies).

---

## 8. **How This Would Look Visually**

If we map JioHotstar’s sitemap into a **flow diagram**, it might start with:

```
Home
│
├── Movies
│   ├── Bollywood
│   │   ├── Brahmastra
│   │   ├── Pathaan
│   ├── Hollywood
│   │   ├── Avengers: Endgame
│   │   ├── Avatar
│
├── Sports
│   ├── Cricket
│   │   ├── IPL 2025
│   │   │   ├── Match 1 Highlights
│   │   │   ├── Match 2 Highlights
```

---

## 9. **Conclusion**

A **sitemap** for a massive content hub like JioHotstar is **not optional — it’s critical**.
It ensures:

- Viewers can find content quickly.
- Search engines can index content efficiently.
- The platform remains organized even as it scales.

If JioHotstar didn’t maintain a proper sitemap, the result would be **chaos** — users might not find their favorite show, and Google might miss indexing new releases.

---

## 1. What is a Canonical URL?

A **canonical URL** is the _preferred_ version of a webpage that search engines should index and rank when multiple versions of the same content exist.

Think of it as telling Google:

> "Hey, if you find similar or duplicate pages, THIS is the one I want you to show in search results."

---

## 2. Why Canonical URLs Matter

Without canonical tags, search engines might:

- **Index duplicates** of the same page
- **Split ranking power** between versions
- Cause **SEO dilution** (traffic spread across multiple URLs)

For big platforms like **Groww**, where many URLs can display the _same or very similar content_, canonical tags are crucial.

---

## 3. How This Applies to Groww

### Example Scenario

Imagine **Groww** has a mutual fund details page for **"Axis Bluechip Fund"**.

Because of tracking parameters, filters, or sorting, this _same page content_ might be accessible from multiple URLs:

1. [https://groww.in/mutual-funds/axis-bluechip-fund](https://groww.in/mutual-funds/axis-bluechip-fund)
2. [https://groww.in/mutual-funds/axis-bluechip-fund?ref=home](https://groww.in/mutual-funds/axis-bluechip-fund?ref=home)
3. [https://groww.in/mutual-funds/axis-bluechip-fund?utm_source=google](https://groww.in/mutual-funds/axis-bluechip-fund?utm_source=google)
4. [https://groww.in/mutual-funds/axis-bluechip-fund?sort=nav](https://groww.in/mutual-funds/axis-bluechip-fund?sort=nav)

All these URLs lead to **the same main content** — but Google sees them as _different pages_ unless we tell it otherwise.

---

## 4. The Canonical Tag Solution

On all duplicate/variant URLs, Groww can add a canonical tag in the `<head>` section:

```html
<link rel="canonical" href="https://groww.in/mutual-funds/axis-bluechip-fund" />
```

**This says to search engines:**

> “Even if the user came via tracking links, always consider `https://groww.in/mutual-funds/axis-bluechip-fund` as the main page.”

---

## 5. Benefits for Groww

- **Avoids duplicate content issues** → Google only indexes the preferred URL.
- **Consolidates ranking signals** → All backlinks and authority point to the canonical page.
- **Better analytics tracking** → Traffic isn’t split between different URL versions.
- **Cleaner search results** → Users see only one URL in Google.

---

## 6. Practical Groww Examples

### Stocks Page

A stock like **Tata Consultancy Services (TCS)** might have:

- `/stocks/tcs`
- `/stocks/tcs?ref=watchlist`
- `/stocks/tcs?from=portfolio`

**Canonical URL should be:**

```html
<link rel="canonical" href="https://groww.in/stocks/tcs" />
```

### Learning Section

A blog article like **"What is SIP?"** might be accessible as:

- `/p/what-is-sip`
- `/p/what-is-sip?utm_campaign=summer-offer`

Canonical points to:

```html
<link rel="canonical" href="https://groww.in/p/what-is-sip" />
```

---

## 7. Common Mistakes to Avoid

- **Pointing all pages to homepage** (wrong practice — each page should point to its own main version unless it’s truly a duplicate).
- **Forgetting self-canonical** → Even the main page should have a canonical tag pointing to itself.
- **Using relative URLs** in canonical tags — Always use absolute URLs (`https://groww.in/...`).
- **Not updating when URL changes** — If Groww updates its fund page structure, canonical URLs must be updated too.

---

## Structured Data (JSON-LD)

Structured data helps search engines and AI systems understand page content more clearly. It can enable **rich results** (ratings, FAQs, product details) when eligible.

Use **Schema.org** vocabulary with **JSON-LD** in Next.js:

```tsx
// app/products/[id]/page.tsx
export default async function ProductPage() {
	const product = {
		name: "Wireless Headphones",
		price: 2999,
		currency: "INR",
		availability: "InStock",
		rating: 4.5,
		reviewCount: 128,
	};

	const jsonLd = {
		"@context": "https://schema.org",
		"@type": "Product",
		name: product.name,
		offers: {
			"@type": "Offer",
			price: product.price,
			priceCurrency: product.currency,
			availability: `https://schema.org/${product.availability}`,
		},
		aggregateRating: {
			"@type": "AggregateRating",
			ratingValue: product.rating,
			reviewCount: product.reviewCount,
		},
	};

	return (
		<>
			<script
				type='application/ld+json'
				dangerouslySetInnerHTML={{ __html: JSON.stringify(jsonLd) }}
			/>
			<h1>{product.name}</h1>
		</>
	);
}
```

Common schema types:

- `Organization` — company/brand pages
- `Article` / `BlogPosting` — blog content
- `Product` — e-commerce
- `FAQPage` — FAQ sections (useful for SEO and AI answers)
- `BreadcrumbList` — navigation context

Only add structured data that **accurately matches visible page content**.

---

## SEO Checklist for a Public Next.js Page

```text
✓ Useful, original content
✓ Correct page title
✓ Useful meta description
✓ Heading structure (h1, h2, ...)
✓ Semantic HTML
✓ Internal links
✓ Canonical URL when needed
✓ Open Graph + Twitter metadata
✓ sitemap.xml
✓ robots.txt
✓ Structured data where appropriate
✓ Fast page (Core Web Vitals)
✓ Accessible layout and text
✓ Important content available in initial HTML (SSR/SSG where needed)
```

---

## Rendering vs SEO

Rendering is only one part of SEO.

```text
SEO
├── Content
├── Metadata
├── Technical configuration (robots, sitemap, canonical)
├── Links
├── Performance
├── Accessibility
└── Rendering (CSR / SSR / SSG / ISR)
```

```text
Using SSR or SSG ≠ automatically good SEO
```

They make it easier to deliver crawlable HTML, but metadata and content quality still decide results.

---

## Quick Reference

| Task                     | App Router (recommended)        | Pages Router (legacy)                            |
| ------------------------ | ------------------------------- | ------------------------------------------------ |
| Page title & description | `metadata` / `generateMetadata` | `next/head`                                      |
| Dynamic product/blog SEO | `generateMetadata`              | `getStaticProps` / `getServerSideProps` + `Head` |
| robots.txt               | `app/robots.ts`                 | `public/robots.txt`                              |
| sitemap.xml              | `app/sitemap.ts`                | Manual file or custom script                     |
| Canonical URL            | `alternates.canonical`          | `<link rel="canonical">` in `Head`               |
| Structured data          | JSON-LD in Server Component     | JSON-LD in page or `_document`                   |
