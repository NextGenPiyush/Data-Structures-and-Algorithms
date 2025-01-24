#include<bits/stdc++.h>
using namespace std;

int prio(char c){  
    if(c == '+' || c == '-') return 1;
    else return 2;
}

int solve(int val1, int val2, char c){  // for evaluating infix, prefix and postfix
    if(c == '+') return val1 + val2;
    else if(c == '-') return val1 - val2;
    else if(c == '*') return val1 * val2;
    else return val1 / val2;
}

string solve_2(char ch, string val1, string val2){   // for conversion to prefix expression
    string s = "";
    s.push_back(ch);  // to enter character we use push_back
    s += val1;
    s += val2;
    return s;
}

string solve_3(string val1, string val2, char ch){  // for conversion to postfix expression
    string s = "";
    s += val1;
    s += val2;
    s.push_back(ch);  // to enter character we use push_back
    return s;
}

string solve_4(string val1, char ch, string val2){  // for conversion to infix expression
    string s = "";
    s += val1;
    s.push_back(ch);  // to enter character we use push_back
    s += val2;
    return s;
}

int infix_evaluation(string s);
int postfix_evaluation(string s);
int prefix_evaluation(string s);

void infix_to_prefix(string s);
void infix_to_postfix(string s);

void postfix_to_infix(string s);
void postfix_to_prefix(string s);

void prefix_to_infix(string s);
void prefix_to_postfix(string s);

int main(){

//******************************************************************************************************************//

    // string s1 = "2+6*4/8-3";
    // string s2 = "(7+9)*4/8-3";  
    // cout<<"2+6*4/8-3: "<<2+6*4/8-3<<endl;
    // cout<<"Value calculated by function: "<<infix_evaluation(s1)<<endl;
    // cout<<"(7+9)*4/8-3: "<<(7+9)*4/8-3<<endl;
    // cout<<"Value calculated by function: "<<infix_evaluation(s2)<<endl;

//******************************************************************************************************************//

    string s = "(7+9)*4/8-3";  
    cout<<s<<endl;
    cout<<"Prefix: "; infix_to_prefix(s);
    cout<<"Postfix: "; infix_to_postfix(s);

//******************************************************************************************************************//



//******************************************************************************************************************//



//******************************************************************************************************************//



//******************************************************************************************************************//


    return 0;
}

int infix_evaluation(string s){
    int n = s.length();
    stack<int> val;
    stack<char> op;
    for(int i=0; i<n; i++){  // traversing into string 
        if(s[i]>=48 && s[i]<=57) val.push(s[i]-48);
        else{    // it means it is a operator  
            if(op.size()==0) op.push(s[i]);    
            else if(s[i]=='(' || op.top()=='(') op.push(s[i]);   
            else if(s[i]==')'){
                while(op.top()!='('){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    val.push(solve(val1,val2,ch));
                }
                op.pop();  // remove the '(' from the operator stack
            }
            else if(prio(s[i])>prio(op.top())) op.push(s[i]);
            else{        // means prio(s[i]) <= prio(op.top())
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    char ch = op.top();
                    op.pop();
                    val.push(solve(val1,val2,ch));
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){   // after traversing the string evaluate tha answer
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        val.push(solve(val1,val2,ch));
    }
    return val.top();
}

int postfix_evaluation(string s){  // we don't need to check priority of the operator 
    int n = s.length();
    stack<int> ans;
    for(int i=0; i<n; i++){  // Traversing in the string 
        if(s[i]>=48 && s[i]<=57) ans.push(s[i]-48);
        else{
            int val2 = ans.top(); ans.pop();        
            int val1 = ans.top(); ans.pop();        
            char ch = s[i];
            ans.push(solve(val1,val2,ch));
        }
    }
    return ans.top();
}

int prefix_evaluation(string s){  // we don't need to check priority of the operator 
    int n = s.length();
    stack<int> ans;
    for(int i=n-1; i>=0; i--){  // Traversing in the string from end  
        if(s[i]>=48 && s[i]<=57) ans.push(s[i]-48);
        else{
            int val1 = ans.top(); ans.pop();  // as we are traversing from the end make sure that first poped element    
            int val2 = ans.top(); ans.pop();  // will be the value 1 and onother poped element will be value 2       
            char ch = s[i];
            ans.push(solve(val1,val2,ch));
        }
    }
    return ans.top();
}

void infix_to_prefix(string s){
    int n = s.length();
    stack<string> str;
    stack<char> op; 
    for(int i=0; i<n; i++){  // Traversing into string  
        if(s[i]>=48 && s[i]<=57) str.push(to_string(s[i]-48));  // convert number into string before inserting 
        else{
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(' || op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    string val2 = str.top();
                    str.pop();
                    string val1 = str.top();
                    str.pop();
                    char ch = op.top();
                    op.pop();
                    str.push(solve_2(ch,val1,val2));
                }
                op.pop();
            }
            else if(prio(s[i])>prio(op.top())) op.push(s[i]);
            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    string val2 = str.top();
                    str.pop();
                    string val1 = str.top();
                    str.pop();
                    char ch = op.top();
                    op.pop();
                    str.push(solve_2(ch,val1,val2));
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        string val2 = str.top();
        str.pop();
        string val1 = str.top();
        str.pop();
        char ch = op.top();
        op.pop();
        str.push(solve_2(ch,val1,val2));
    }
    cout<<str.top()<<endl;
}

void infix_to_postfix(string s){
    int n = s.length();
    stack<string> str;
    stack<char> op; 
    for(int i=0; i<n; i++){  // Traversing the string 
        if(s[i]>=48 && s[i]<=57) str.push(to_string(s[i]-48));  // convert number into string before inserting 
        else{
            if(op.size()==0) op.push(s[i]);
            else if(s[i]=='(' || op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    string val2 = str.top();
                    str.pop();
                    string val1 = str.top();
                    str.pop();
                    char ch = op.top();
                    op.pop();
                    str.push(solve_3(val1,val2,ch));
                }
                op.pop();
            }
            else if(prio(s[i])>prio(op.top())) op.push(s[i]);
            else{
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    string val2 = str.top();
                    str.pop();
                    string val1 = str.top();
                    str.pop();
                    char ch = op.top();
                    op.pop();
                    str.push(solve_3(val1,val2,ch));
                }
                op.push(s[i]);
            }
        }
    }
    while(op.size()>0){
        string val2 = str.top();
        str.pop();
        string val1 = str.top();
        str.pop();
        char ch = op.top();
        op.pop();
        str.push(solve_3(val1,val2,ch));
    }
    cout<<str.top()<<endl;
}

void postfix_to_infix(string s){
    int n = s.length();
    stack<string> ans;
    for(int i=0; i<n; i++){  // Traversing the string 
        if(s[i]>=48 && s[i]<=57) ans.push(to_string(s[i]-48));
        else{
            string val2 = ans.top(); ans.pop();        
            string val1 = ans.top(); ans.pop();        
            char ch = s[i];
            ans.push(solve_4(val1,ch,val2));
        }
    }
    cout<<ans.top()<<endl;   // Remember we have not shown the bracket here 
}

void postfix_to_prefix(string s){
    int n = s.length();
    stack<string> ans;
    for(int i=0; i<n; i++){  // Traversing the string 
        if(s[i]>=48 && s[i]<=57) ans.push(to_string(s[i]-48));
        else{
            string val2 = ans.top(); ans.pop();        
            string val1 = ans.top(); ans.pop();        
            char ch = s[i];
            ans.push(solve_2(ch,val1,val2));
        }
    }
    cout<<ans.top()<<endl;   
}

void prefix_to_infix(string s){
    int n = s.length();
    stack<string> ans;
    for(int i=n-1; i>=0; i--){  // Traversing the string from the end 
        if(s[i]>=48 && s[i]<=57) ans.push(to_string(s[i]-48));
        else{
            string val1 = ans.top(); ans.pop();  // as we are traversing from the end make sure that first poped element   
            string val2 = ans.top(); ans.pop();  // will be the value 1 and onother poped element will be value 2        
            char ch = s[i];
            ans.push(solve_4(val1,ch,val2));
        }
    }
    cout<<ans.top()<<endl;
}

void prefix_to_postfix(string s){
    int n = s.length();
    stack<string> ans;
    for(int i=n-1; i>=0; i--){  // Traversing the string from the end 
        if(s[i]>=48 && s[i]<=57) ans.push(to_string(s[i]-48));
        else{
            string val1 = ans.top(); ans.pop();  // as we are traversing from the end make sure that first poped element        
            string val2 = ans.top(); ans.pop();  // will be the value 1 and onother poped element will be value 2       
            char ch = s[i];
            ans.push(solve_3(val1,val2,ch));
        }
    }
    cout<<ans.top()<<endl;
}

