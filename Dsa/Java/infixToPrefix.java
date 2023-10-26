import java.util.*;

class stack{
    private
    int top;
    char[] arr = new char[10000];

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

    char atTop(){
        return arr[top];
    }

    boolean isEmpty(){
        return top == -1;
    }
}

public class infixToPrefix {
        public static void main(String[] args){
            Scanner scan = new Scanner(System.in);

            String infix = scan.nextLine();

            StringBuilder inf = new StringBuilder();

            for(int i = infix.length()-1;i>=0;i--){
                if(isBracket(infix.charAt(i))){
                    inf.append(opposite(infix.charAt(i)));
                }else{
                    inf.append(infix.charAt(i));
                }
            }

            StringBuilder ans = toPostfix(inf);

            ans.reverse();
            System.out.println(ans);

        }

        static StringBuilder toPostfix(StringBuilder inf){
            
            stack st = new stack();
    
            char[] str = inf.toString().toCharArray();
    
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
    
            return ans;
        }

        static boolean isBracket(char ch){
            if(ch == '(' ||ch == '{' ||ch == '[' ||ch == ']' ||ch == '}' ||ch == ')'){
                return true;
            }
            return false;
        }

        static char opposite(char ch){
            if(ch == '('){
                return ')';
            }
            if(ch == '{'){
                return '}';
            }
            if(ch == '['){
                return ']';
            }
            if(ch == ')'){
                return '(';
            }
            if(ch == '}'){
                return '{';
            }
            if(ch == ']'){
                return '[';
            }
            return 0;
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
