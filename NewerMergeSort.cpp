// Online C++ compiler to run C++ program online
#include <iostream>
#include <random>

int main() {
    // Write C++ code here
    std::cout << "Start small. Ship something.";

    return 0;
}

// my merge sort
void sort(int *arr,int n){
	int *A[2] = {arr, int[n]}; // in stack, will point to the 2 arrays used for back to back merge sort, one of which was the original array
	int NEW = 0;
	
	// init: for each power i s.t. pre-sorted portions are size 2^1
	// bool: stop when size of pre-sorted portions 2^i>=n i.e. i>=log2(n)
	// incr: flips new and newer array
	for(int i=0, NWR=1 ; i<log2(n) ; i++, NEW^=1, NWR^=1){
	    int sect = pow(2,i+1); // size of section
	    // for each section starting from index s (pre-sorted sect size is sectsize/2)
		for(int s=0; s<n; s+=sect){
		    int subsect = sect/2; // typical size of presorted subsections
			int n1 = min(n-s,subsect); // actual size of 1st pre-sorted subsect
			int n2 = min(n-s-n1,subsect); // actual size of 2nd . . .
			if(n1>0&&n2>0) for(int j=s;k=s+n1; j<s+n1||k<s+n1+n2; )
				A[NWR][j+k-s] = (A[NEW][j]<A[NEW][k]||k=s+n1+n2)? A[NEW][j++] : A[NEW][k++];
			else for(int jk=s; jk<s+n1+n2; jk++)
				A[NWR][jk] = A[NEW][jk];
		}
	}
	
	if(NEW==1) for(int i=0; i<n; i++){
		arr[i] = A[1][i];
	}
}
