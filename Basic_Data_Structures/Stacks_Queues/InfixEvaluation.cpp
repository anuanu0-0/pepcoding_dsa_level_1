#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

// Return precedence of the operator
int precedence(char op) {
	if(op=='+') return 1;
	else if(op=='-') return 1;
	else if(op=='*') return 2;
	else return 2;
}

// Compute values given operator and operands
int operation(int num1, int num2, char op) {
	if(op=='+') return num1+num2;
	else if(op=='-') return num1-num2;
	else if(op=='*') return num1*num2;
	else return num1/num2;
}

// Perform infix evaluation of a given string
int infixEvaluation(string str) {

	stack<int> operands;
	stack<char> operators;

	for(int i=0; i<str.size(); i++) {
		char ch = str[i];
		if(ch=='(') {
			operators.push('(');
		} else if(isdigit(ch)) {
			operands.push(ch-'0');
		} else if(ch==')') {
			while(operators.top()!='(') {
				char op = operators.top(); operators.pop();
				int num2 = operands.top(); operands.pop();
				int num1 = operands.top(); operands.pop();

				operands.push(operation(num1, num2, op));
			}
			operators.pop();
		} else if(ch=='+' || ch=='-' || ch=='*' || ch=='/') {
			while(!operators.empty() && operators.top()!='(' && precedence(ch) <= precedence(operators.top())) {
				char op = operators.top(); operators.pop();
				int num2 = operands.top(); operands.pop();
				int num1 = operands.top(); operands.pop();

				operands.push(operation(num1, num2, op));
			}

			operators.push(ch);
		}
	}

	// Perform computations if operators stack is not empty
	while(!operators.empty()) {
		char op = operators.top(); operators.pop();
		int num2 = operands.top(); operands.pop();
		int num1 = operands.top(); operands.pop();

		operands.push(operation(num1, num2, op));
	}	

	return operands.top();
}

int main(){
	string str;
	getline(cin, str);
	
	cout << infixEvaluation(str);
	return 0;
}