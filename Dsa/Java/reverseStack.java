import java.util.*;

public class reverseStack {
    public static void main(String[] args){
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
        reverse(s);
        while(!s.empty()){
            System.out.print(s.peek() + " ");
            s.pop();
        }
    }
    static void reverse(Stack<Integer> s){
        if(s.empty()){
            return;
        }
        int top = s.pop();
        reverse(s);
        pushAtBottomOfStack(s,top);
    }
    static void pushAtBottomOfStack(Stack<Integer> s,int n){
        if(s.empty()){
            s.push(n);
            return;
        }
        int top = s.pop();
        pushAtBottomOfStack(s, n);
        s.push(top);
    }
}
