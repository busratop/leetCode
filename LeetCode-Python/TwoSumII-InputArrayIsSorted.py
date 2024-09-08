class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        resIn = []
        for i in range(len(numbers)):
            sum = target - numbers[i]

            if sum in numbers:
                index1 = sum
                index2 = i
                break
        for j in range(index2+1,len(numbers),1):
            
            if numbers[j]==index1:
                index1 = j
                break

        resIn = [index2+1,index1+1]
        return resIn
