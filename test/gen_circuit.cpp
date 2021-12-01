#include "emp-tool/emp-tool.h"
#include <stdlib.h> 
#include <cstdlib>
#include <cmath>
using namespace emp;


void ham(int n) {
	Integer a(n, 0, ALICE);
	Integer b(n, 0, BOB);
	Integer c = a^b;
	Integer d = c.hamming_weight();
	d.reveal<string>();
}

void mult(int n) {
	Integer a(n, 0, ALICE);
	Integer b(n, 0, BOB);
	Integer c = a*b;
	c.reveal<string>();
}
void modexp(int n1, int n2) {
	Integer a(n1, 0,  ALICE);
	Integer b(n2, 0,  BOB);
	Integer c(n1, 5, ALICE);
	Integer d = a.modExp(b, c);
}
void sort(int n) {
	Integer *A = new Integer[n];
	Integer *B = new Integer[n];
	for(int i = 0; i < n; ++i) {
		A[i] = Integer(32, n - i, ALICE);
  	}
	for(int i = 0; i < n; ++i) {
		B[i] = Integer(32, i, BOB);
  	}
	for(int i = 0; i < n; ++i)
		A[i] = A[i] ^ B[i];
	sort(A, n);
	for(int i = 0; i < n; ++i)
		A[i].reveal<string>();
}

void minus(int n){
	Integer a(n, 0, ALICE);
	Integer b(n, 0, BOB);
	Integer c = a+b;
	c.reveal<string>();

}
void subtract_vector(int n){
	Integer *A = new Integer[n];
	Integer *B = new Integer[n];
	Integer *C = new Integer[n];

	for(int i = 0; i < n; ++i) {
		A[i] = Integer(32, i, ALICE);
  	}
	for(int i = 0; i < n; ++i) {
		B[i] = Integer(32, i, BOB);
  	}
	for(int i = 0; i < n; ++i)
		C[i] = (A[i] - B[i]).abs();
	for(int i = 0; i < n; ++i)
		C[i].reveal<string>();

}
int main(int argc, char** argv) {

	setup_plain_prot(true, "sort.txt");
	// subtract_vector(5);
	minus(8);
	// sort(128);
	// mult(100);
	// ham(1<<10);

	finalize_plain_prot ();
	BristolFormat bf("sort.txt");
	//BristolFormat bf(sort_num_gate, sort_num_wire, sort_n1, sort_n2, sort_n3, sort_gate_arr);
	bf.to_file("sort_file.h", "sort");
}
