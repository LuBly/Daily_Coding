public class Solution {
    public int LargestRectangleArea(int[] heights) {
        // 1 <= heights.length <= 10^5
        // 0 <= heights[i] <= 10^4
        // 스택을 활용한 문제 풀이
        Stack<int> stack = new Stack<int>();
        stack.Push(-1); // 초기 값 // 왼쪽 기준이 될 값들을 stack 에 저장
        int maxArea = 0; 
        for(int i = 0; i < heights.Length; i++){//좌표를 하나씩 옮기면서 체크
            while(stack.Peek() != -1 && heights[stack.Peek()] >= heights[i])//최초실행이 아니면서 stack 맨 위에 있는 값이 현재 heights값보다 크다면 현재 값으로 계산
                maxArea = Math.Max(maxArea, heights[stack.Pop()] * (i - stack.Peek() - 1)); // 가능한 사각형 계산
            stack.Push(i);
        }
        
        while(stack.Peek() != -1)
            maxArea = Math.Max(maxArea, heights[stack.Pop()] * (heights.Length - stack.Peek() -1));
        
        return maxArea;
    }
}