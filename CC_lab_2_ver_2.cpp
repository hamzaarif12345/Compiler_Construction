#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;
class sol(){
    public:
        string result;
        stack<int> st2;
        string result1;
        int prec(char c);
        int op(char c);
        void infixToPostfix(string s);
        void sol::infixToPostfix2(string s);
        string infix_to_prefix(string infix);

};
int sol::prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int sol::op(char c){
    if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-' || c=='#' )
        return -1;
}
void sol::infixToPostfix(string s)
{

	stack <wchar_t> st; // For stack operations, we are using
					// C++ built in stack
	
    stack <wchar_t> st1;
    for (int i = 0; i < s.length(); i++) {
		char c = s[i];
        if(op(c)==-1){
			    result +=" ";
                auto i=(result).c_str();
                int q=atoi(i);
                st2.push(q);
                //st2.push();
			}
        
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			result += c;
		    
			
		}
		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				//result += " ";
				st.pop();
			}
			
			st.pop();
		}
        else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top();
				result +=" ";
				st.pop();
			}
			st.push(c);
		}
	}
    while (!st.empty()) {
		result += st.top();
		st.pop();
	}
    cout << result << endl;
}
void sol::infixToPostfix2(string s)
{

	stack <wchar_t> st; // For stack operations, we are using
					// C++ built in stack
	
    stack <wchar_t> st1;
    for (int i = 0; i < s.length(); i++) {
		char c = s[i];
        if(op(c)==-1){
			    result1 +=" ";
                auto i=(result).c_str();
                int q=atoi(i);
                st2.push(q);
                //st2.push();
			}
        
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			result1 += c;
		    
			
		}
		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result1 += st.top();
				//result += " ";
				st.pop();
			}
			
			st.pop();
		}
        else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result1 += st.top();
				result +=" ";
				st.pop();
			}
			st.push(c);
		}
	}
    while (!st.empty()) {
		result1 += st.top();
		st.pop();
	}
    //cout << result << endl;
}
string infix_to_prefix(string infix){
    int l=infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++) { 
  
        if (infix[i] == '(') { 
            infix[i] = ')'; 
            i++; 
        } 
        else if (infix[i] == ')') { 
            infix[i] = '('; 
            i++; 
        } 
    }
    infixToPostfix2(infix);
    reverse(result1.begin(),result1.end());
    return result1;
}
int main()
{
    string ex;
	cout<<"\nenter the string:";
	cin>>ex;
    cout<<"postfix: ";
    infixToPostfix(ex);
    int j=0;
    while (!st2.empty()) {
        int w=st2.top();
        st2.pop();
		result1[j] += w;
        j++;
    }
    cout<<"prefix: ";
    cout<<infix_to_prefix(ex)<< endl;
	return 0;
}






