# Markdown Cheat Sheet — Quick Reference ✅

A compact reference for writing clear, consistent documentation in this repo.

## Basic syntax
- Headings: `# H1`, `## H2`, `### H3` — use a clear hierarchy and add a blank line after headings.
- Emphasis: `**bold**`, `*italic*`, `~~strikethrough~~`.
- Inline code / code block: Inline: `` `code` ``. Fenced block:

  ```markdown
  ```language
  // code here
  ```
  ```

  (Always add the language for syntax highlighting.)

- Lists: Unordered `- item` or `* item`; Ordered `1. item` (indent 2 spaces for nested lists).
- Links & images: Link: `[text](url)`; Image: `![alt text](path.png)` — **always provide alt text**.
- Blockquote: `> Quote text`
- Horizontal rule: `---`
- Table:

  ```markdown
  | Column | Column |
  | ------ | ------ |
  | value  | value  |
  ```

- Task lists: `- [ ] todo` and `- [x] done`
- Diagrams: Use fenced blocks: ```` ```mermaid ... ``` ```` or PlantUML blocks if supported.

## Quick mapping (cheat)
- `##` → Subheading
- `**bold**` → Bold
- `` `code` `` → Inline code
- ```` ```lang ... ``` ```` → Code block with highlighting

## Best practices
- Keep paragraphs short (1–3 sentences) and focused.
- Use descriptive headings and logical structure; readers scan headings first.
- Show small examples for algorithms: input → code → output.
- Prefer relative links (e.g., `../README.md`) for repo docs.
- Add `alt` text for all images and short textual descriptions for diagrams (accessibility).
- Add a one-line summary at the top of long pages (what, why, how).
- Close fenced code/diagram blocks with the same fence used to open (``` or ~~~) and add a blank line after to prevent rendering issues.
- Maintain consistent style (naming, tense, formatting); consider a repo style guide (e.g., keep `code` in `backticks`).

## Checklist before committing docs
- [ ] Headings follow hierarchy and are concise
- [ ] Code blocks include language for syntax highlighting
- [ ] Images include alt text
- [ ] Links use relative paths where appropriate
- [ ] File previewed and linted (markdownlint)

## Tools & tips
- Use a Markdown linter (e.g., `markdownlint`) and a previewer in your editor.
- Keep diagrams simple and add a short caption or description below them.
- For big docs, add a Table of Contents and an index for discoverability.

---

If you'd like, I can add a link to this cheat sheet in the repository `README.md` or reference it from the `docs/` index.
