// Taimur Azhar z5116684 Programming Challenges 18s1
// Week 4
// Problem A Expressions

# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <stack>
# include <queue>
# include <map>

# define SIZE 100
# define GRID 1001 
using namespace std;



struct expression
{
	char name;
	expression* first;
	expression* second;
	
};

void freemem(expression* curr) {
	if (curr == NULL) {
		return;
	}
	if (curr->first != NULL) {
		freemem(curr->first);
	}
	if (curr->second != NULL) {
		freemem(curr->second);
	}
	delete curr;
	return;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		// Take in the sequence
		string sequence;
		cin >> sequence;
		//cout << sequence << endl;
		// The stack to work of initially
		stack <expression> init_stack;
		// a map cos i cant use pointers apparently
		map<char, pair<char, char> > assigner;
		for (int j = 0; j < sequence.length(); ++j) {
			//cout << sequence[j] << endl;
			if (isupper(sequence[j])) {
				// operatorr

				expression operatorr;
				operatorr.name = sequence[j];

				operatorr.first = new expression(init_stack.top());
				
				init_stack.pop();

				//cout << operatorr.first->name << " is the name " << endl;
				//expression second = init_stack.top();
				operatorr.second = new expression(init_stack.top());
				//cout << "broke here " << endl;
				init_stack.pop();

				//cout << "pushed " << sequence[j] << " with value " << operatorr.name << endl;
				//cout << "operatorr "<< operatorr.name << " acting on " << operatorr.first->name << " and " << operatorr.second->name << endl ;
				//cout <<"for " << operatorr.name <<" waht " << operatorr.second->name << " second " << operatorr.first->name << " first " << endl;
				init_stack.push(operatorr);
				//cout <<"for " << operatorr.name <<" waht " << operatorr.second->name << " second " << operatorr.first->name << " first " << endl;
				//assigner.insert(make_pair(operatorr.name, make_pair(operatorr.first->name, operatorr.second->name)));
			} else {
				// number
				expression number;
				number.name = sequence[j];
				number.first = NULL;
				number.second = NULL;
				init_stack.push(number);
				//cout << "pushed num " << sequence[j] << " with value " << number.name << endl;
			}
		}
		// Now to unroll it
		// There is only one thing in the stack, and thats our solution
		expression *ans = new expression(init_stack.top());
		init_stack.pop();
		//cout <<"before loop " << ans.name <<" what " << ans.second->name << " second " << ans.first->name << " first "<< endl;
		stack<char> final_stack;
		queue<expression*> final_queue;
		final_queue.push(ans);
		//int count = 10;
		//cout <<"before loop " << ans.name <<" what " << ans.second->name << " second " << ans.first->name << " first "<< endl;

		while ((!final_queue.empty())) {
			//count --;
			expression* curr = final_queue.front();
			final_stack.push(curr->name);
			//char first = assigner[curr].first;
			//char second = assigner[curr].second;
			final_queue.pop();
			
			if (isupper(curr->name)) {
				final_queue.push(curr->second);
				final_queue.push(curr->first);
			}
		
			//cout << "pushed to final stack " << curr << " pushed into queue " << first << second << endl;
 		}
 		while (!final_stack.empty()) {
 			cout << final_stack.top();
 			final_stack.pop();
 		}
 		cout << endl;

 		freemem(ans->first);
 		freemem(ans->second);
	}
}

