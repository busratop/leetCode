class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""

        # Initialize the character count dictionaries for t and the current window in s
        t_count = Counter(t)
        window_count = Counter()

        # Variables to keep track of the start and end of the minimum window substring
        left = 0
        right = 0

        # Variables to keep track of the minimum window substring
        min_len = float('inf')
        min_window = ""

        # Variable to track the number of characters in t that are missing in the current window
        required_chars = len(t)

        while right < len(s):
            # Expand the window to the right
            if s[right] in t_count:
                window_count[s[right]] += 1
                if window_count[s[right]] <= t_count[s[right]]:
                    required_chars -= 1

            # Contract the window from the left
            while required_chars == 0:
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    min_window = s[left:right + 1]

                if s[left] in t_count:
                    window_count[s[left]] -= 1
                    if window_count[s[left]] < t_count[s[left]]:
                        required_chars += 1

                left += 1

            # Move the right pointer to expand the window further
            right += 1

        return min_window
