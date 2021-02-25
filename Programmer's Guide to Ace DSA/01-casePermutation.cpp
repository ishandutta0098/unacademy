/*Program to print all possible permutations of an alplanumeric string using Recursion.

Sample: s = '1aB3'

Outputs: '1aB3', '1ab3', '1AB3', '1Ab3'
*/

/*Approach:
Use recursion to print the element as lowercase and then uppercase.
Perform this on all substrings, and keep attaching the element to output.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void casePermutation(string inp, string out, vector<string> &v) {
    
    //Base Case 
    if(inp.size() == 0) {           //If string is empty put the output in vector
        v.push_back(out);
        return;
    }
    
    string ros = inp.substr(1);                 //ros - rest of string
    
    //Check for the first element of string
    
    //Lowercase Letter
    if(inp[0] >= 'a' and inp[0] <= 'z'){     
        casePermutation(ros, out + inp[0], v);                 //Element as it is
        casePermutation(ros, out + (char)(inp[0] - 32), v);    //Element converted to uppercase
        }
    
    //Uppercase Letter
    else if (inp[0] >= 'A' and inp[0] <= 'Z') {             
        casePermutation(ros, out + inp[0], v);                 //Element as it is
        casePermutation(ros, out + (char)(inp[0] + 32), v);    //Element converted to lowercase 
    }
    
    //Numeric
    else {                                      
        casePermutation(ros, out + inp[0], v);                 //Element as it is
    }
}

int main() {
	
	vector<string> v;
	string str = "1aB3";
	string output = "";         //Initially output is empty
	casePermutation(str, output, v);
	
	for(string s : v) {
	    cout << s << " ";   //prints 1aB3 1ab3 1AB3 1Ab3
	}
	
	return 0;
}
