//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends

int mn;
void push(stack<int>& s, int a){
	// Your code goes here
	if(s.empty()){
	    mn=a;
	    s.push(a);
	}
	else if(mn>a){
	    int val=2*a-mn;
	    s.push(val);
	    mn=a;
	}
	else
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n)return true;
	else
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	return s.empty();
}

int pop(stack<int>& s){
	// Your code goes here
	if(s.empty())return -1;
	else if(s.top()<mn){
	    int val=2*mn-s.top();
	    s.pop();
	    return val;
	}
	else
	s.pop();
}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.empty())return -1;
	else
	return mn;
}