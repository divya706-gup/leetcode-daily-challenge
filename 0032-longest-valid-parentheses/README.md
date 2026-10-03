# 32. Longest Valid Parentheses

**Difficulty:** Hard  
**Topics:** String, Dynamic Programming, Stack, Bracket Sequences  
**Link:** https://leetcode.com/problems/longest-valid-parentheses/

**Runtime:** 0 ms | **Memory:** 11.6 MB

---

Given a string containing just the characters `'('` and `')'`, return _the length of the longest valid (well-formed) parentheses __substring_.

 

Example 1:**

```

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

Example 2:**

```

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

Example 3:**

```

Input: s = ""
Output: 0

```

 

**Constraints:**

	
- `0 <= s.length <= 3 * 104`
	
- `s[i]` is `'('`, or `')'`.
