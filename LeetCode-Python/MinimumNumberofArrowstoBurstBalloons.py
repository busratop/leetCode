class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points:
            return 0

        # Sort the balloons based on their end points
        points.sort(key=lambda x: x[1])

        arrows = 1
        end = points[0][1]

        # Iterate through the balloons
        for i in range(1, len(points)):
            # If the current balloon's start point is greater than the end point of the previous balloon,
            # it means a new arrow is needed
            if points[i][0] > end:
                arrows += 1
                end = points[i][1]  # Update the end point
        return arrows
