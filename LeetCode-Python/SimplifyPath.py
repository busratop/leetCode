class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
    
        # Split the path by '/'
        components = path.split('/')
        
        # Process each component
        for component in components:
            # Ignore empty strings and '.'
            if component == '' or component == '.':
                continue
            # Handle '..' by popping the last directory if stack is not empty
            elif component == '..':
                if stack:
                    stack.pop()
            # Otherwise, push valid directory names to the stack
            else:
                stack.append(component)
        
        # Construct the simplified canonical path
        canonical_path = '/' + '/'.join(stack)
        
        return canonical_path
