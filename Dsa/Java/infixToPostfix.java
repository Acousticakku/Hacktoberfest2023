import java.util.*;

class stack {
    private
    final int max = 10000;
    int top;
    char[] arr = new char[max];

    public
    stack(){
        top = -1;
    }
    void push(char val){
        arr[++top] = val;
    }

    void pop(){
        top--;
    }

    boolean isEmpty(){
        return top == -1;
    }

    char atTop(){
        return arr[top];
    }
}

public class infixToPostfix {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        String expression = scan.nextLine();

        stack st = new stack();

        char[] str = expression.toCharArray();

        StringBuilder ans = new StringBuilder();

        for(int i = 0;i <str.length;i++){
            if(str[i] == ' '){
                continue;
            } else if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            } else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
                while(!match(st.atTop(),str[i])){
                    ans.append(st.atTop());
                    st.pop();
                }
                st.pop();
            } else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){
                ans.append(str[i]);
            } else{
                while(!st.isEmpty() && (precedence(str[i]) <= precedence(st.atTop()))){
                    ans.append(st.atTop());
                    st.pop();
                }
                st.push(str[i]);
            }
        }

        while(!st.isEmpty()){
            ans.append(st.atTop());
            st.pop();
        }

        System.out.println(ans.toString());
    }

    static boolean match(char ch1,char ch2){
        if(ch1 == '(' && ch2 == ')'){
            return true;
        }
        if(ch1 == '{' && ch2 == '}'){
            return true;
        }
        if(ch1 == '[' && ch2 == ']'){
            return true;
        }
        return false;
    }

    static int precedence(char ch){
        switch (ch) {
            case '+':return 1;
            case '-':return 1;
            case '*':return 2;
            case '/':return 2;
            case '%':return 2;
            case '^':return 3;
        }
        return -1;
    }
}
