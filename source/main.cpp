/*
TestLongerExample
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*	This tutorial illustrates how pointer and reference work independently 
*	or simultaneously; 
*	It covers the concepts of L-value, R-value, inverse feature and null pointer.
*/

#include <iostream>
using namespace std;

int main() {
    int* p;		// int* is pointer-to-int type
    int i = 10;
    p = &i;		// p gets address of i
    *p = 20;	// L-value
				// dereference p and store 20
				// goto the "pointee" of p and store 20
				// L-val: put 20 where p points

	cout << "i:  " << i << endl;	// i:  20
    cout << "p:  " << p << endl;	// p:  0091FB64
    cout << "*p: " << *p << endl;	// *p: 20
    cout << "&i: " << &i << endl;	// &i: 0091FB64

    int j = 30;
    int* q = &j;	// q is a pointer-to-int type
					// q can store an address
					// q now stores address of j

    *p = *q;		// get the value of pointer q, put it to what p points to
    cout << "i:  " << i << endl; // i:  30
    // RHS: *q means: get the value stored at the address
    //                contained in q (get j's address and
    //                return the value stored at j)
    // LHS: *p means: take the value from the RHS (30 was
    //				  the result of *q) and store in i

    p = q;			// p gets q's value (p points to j)
    *q = 40; 
    *p = 50;
    cout << "i:  " << i << endl; // i:  30 (no change)
    cout << "j:  " << j << endl; // j:  50 

    int k = 100;
    //int* r = &k;			// could also use
    cout << *&k << endl;	// 100 inverse operators

    // NOTE: the expressions in the output statements above
    // are R-values!!!

    // null pointer:
    int* a = nullptr;
    int* b = 0;
	cout << "a:  " << a << endl;		// a:  00000000
	// cout << "*a:  " << *a << endl;	// allowed?
	cout << "b:  " << b << endl;		// b:  00000000
	//cout << "*b:  " << *b << endl;	// allowed?

}