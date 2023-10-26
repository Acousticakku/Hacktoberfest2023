import java.util.*;


class stack {
    private
    final int max = 10000;
    int top;
    int[] arr = new int[max];

    public
    stack(){
        top = -1;
    }
    void push(int val){
        arr[++top] = val;
    }

    void pop(){
        top--;
    }

    boolean isEmpty(){
        return top == -1;
    }

    int atTop(){
        return arr[top];
    }
}

public class postfixEvaluation {
    public static void main(String[] args){
        stack st = new stack();
        Scanner scan = new Scanner(System.in);
        String postfix = scan.nextLine();

        for(int i = 0;i<postfix.length();i++){
            if(postfix.charAt(i) == ' '){
                continue;
            }
            if(postfix.charAt(i) >= '0' && postfix.charAt(i) <= '9'){
                st.push(postfix.charAt(i) - '0');
            }
            else{
                char oprtr = postfix.charAt(i);
                int b2 = st.atTop();
                st.pop();
                int b1 = st.atTop();
                st.pop();
                int res = operate(b1,b2,oprtr);
                st.push(res);
            }
        }
        System.out.println(st.atTop());
        st.pop();
    }

    static int operate(int b1,int b2,char op){
        switch(op){
            case '+' : return b1 + b2;
            case '-' : return b1 - b2;
            case '*' : return b1 * b2;
            case '/' : return b1 / b2;
            case '%' : return b1 % b2;
            case '^' : return (int)(Math.pow(b1, b2));
        }
        return 0;
    }
}
