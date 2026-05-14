// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <random>

template<typename T>
void print(const T arr[],int n,std::string heading = "");
template<typename T>
void print(const T var,std::string heading = "");
template<typename T>
void sort(T *arr,int n);

int main() {
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.
    std::uniform_int_distribution<> dist(1,100);
    int n = 10;
    int arr[n];
    for(int i=0; i<n; i++) arr[i] = dist(gen);
    sort(arr,n);
    return 0;
}

// .....................................................................

// my merge sort
template<typename T>
void sort(T *arr,int n){
    print(arr,n,"BEFORE");
    int temp[n];
	int *A[2] = {arr, temp}; // in stack, will point to the 2 arrays used for back to back merge sort, one of which was the original array
	int NEW = 0, NWR = 1;
	// init: for each power i s.t. pre-sorted portions are size 2^1
	// bool: stop when size of pre-sorted portions 2^i>=n i.e. i>=log2(n)
	// incr: flips new and newer array
	for(int i=0; i<floor(log2(n)) ; i++, NEW^=1, NWR^=1){
	    int sect = pow(2,i+1); // size of section
	    print(sect, "SORTING sections of size ");
	    print(A[NWR],n,"Blank slate");
	    // for each section starting from index s (pre-sorted sect size is sectsize/2)
		for(int s=0; s<n; s+=sect){
		    int subsect = sect/2; // typical size of presorted subsections
			int n1 = std::min(n-s,subsect); // actual size of 1st pre-sorted subsect
			int n2 = std::min(n-s-n1,subsect); // actual size of 2nd . . .
			std::cout<<"sect index "<<s<<", subsect lens "<<n1<<"+"<<n2<<std::endl;
			if(n1>0&&n2>0) for(int j=s, k=s+n1; j<s+n1||k<s+n1+n2; ){
			    print(j+k-s, " fixing index");
				// A[NWR][j+k-s] = (A[NEW][j]<A[NEW][k]||k==s+n1+n2)? A[NEW][j++] : A[NEW][k++];
				if(A[NEW][j]<A[NEW][k]||k==s+n1+n2){
				    A[NWR][j+k-s] = A[NEW][j];
				    j++;
				}
				else{
				    A[NWR][j+k-s] = A[NEW][k];
				    k++;
				}
			}
			else for(int jk=s; jk<s+n1+n2; jk++) A[NWR][jk] = A[NEW][jk];
			std::cout << "section " << s/sect+1 << "/" << ceil(double(n)/sect) << " sorted: ";
			print(A[NWR],n);
		}
		print(A[NWR],n,"After sort");
	}
	
	print(A[NEW],n,"NEW");
	print(A[NWR],n,"NWR");
	
	if(NEW==1) for(int i=0; i<n; i++){
		arr[i] = A[1][i];
	}
	print(arr,n,"SORTED");
}

// .....................................................................

template<typename T>
void print(const T arr[],int n,std::string heading){
    if(heading!="") std::cout << heading << ": ";
    for(int i=0; i<n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<typename T>
void print(const T var,std::string heading){
    if(heading!="") std::cout << heading << ": ";
    std::cout << var << std::endl;
}
