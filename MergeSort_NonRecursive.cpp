template<typename T>
bool sort(T *arr, int n){
	T temp[n];
	T *A[2] = {arr,temp}; // non-recursive merge sort between 2 arrays
	int NEW=0, NWR=1;
	for(int i=0, subsect=1; i<log2(n); i++, NEW^=1, NWR^=1, subsect*=2)
	for(int s=0,n1,n2; s<n; s+=2*subsect){
		n1 = std::min(n-s, subsect);
		n2 = std::min(n-s-n1, subsect);
		if(n1>0&&n2>0) for(int j=s, k=s+n1; j<s+n1||k<s+n1+n2; ){
			if(j<s+n1&&A[NEW][j]<A[NEW][k]||k==s+n1+n2){
				A[NWR][j+k-s-n1] = A[NEW][j]; j++;
			} else { A[NWR][j+k-s-n1] = A[NEW][k]; k++; }
		} else for(int jk=s; jk<s+n1+n2; jk++) A[NWR][jk] = A[NEW][jk];
	}
	if(NEW==1) for(int i=0; i<n; i++) arr[i] = A[1][i];
	for(int i=0; i<n-1; i++) if(arr[i]>arr[i+1]) return false;
	return true;
}

/////////////////////////// MOCK-UP TESTING ////////////////////////////


// #include <iostream>
// #include <string>
// #include <random>

// template<typename T>
// void print(const T arr[],int n,std::string heading = "");
// template<typename T>
// void print(const T var,std::string heading = "");
// template<typename T>
// void sort(T *arr,int n);

// int main() {
//     std::random_device rd;   // non-deterministic generator
//     std::mt19937 gen(rd());  // to seed mersenne twister.
//     std::uniform_int_distribution<> dist(1,100);
//     for(int n=1; n<100; n++) for(int i=0; i<10; i++){
//         // int n = 7;
//         int arr[n];
//         for(int i=0; i<n; i++) arr[i] = dist(gen);
//         sort(arr,n);
//     }
//     return 0;
// }

// // .....................................................................

// // my merge sort
// template<typename T>
// void sort(T *arr,int n){
//     // print(arr,n,"BEFORE");
//     T temp[n];
// 	T *A[2] = {arr, temp}; // in stack, will point to the 2 arrays used for back to back merge sort, one of which was the original array
// 	int NEW = 0, NWR = 1;
// 	// init: for each power i s.t. pre-sorted portions are size 2^i
// 	// bool: stop when size of pre-sorted portions 2^i>=n i.e. i>=log2(n)
// 	// incr: flips new and newer array
// 	for(int i=0, sect=2; i<log2(n) ; i++, NEW^=1, NWR^=1, sect*=2){
// 	    // sect size of sections to be sorted
// 	   // print(sect, "SORTING sections of size ");
// 	   // print(A[NWR],n,"Blank slate");
// 	    // for each section starting from index s (pre-sorted sect size is sectsize/2)
// 		for(int s=0; s<n; s+=sect){
// 		    int subsect = sect/2; // typical size of presorted subsections
// 			int n1 = std::min(n-s,subsect); // actual size of 1st pre-sorted subsect
// 			int n2 = std::min(n-s-n1,subsect); // actual size of 2nd . . .
// // 			std::cout<<"sect index "<<s<<", subsect lens "<<n1<<"+"<<n2<<std::endl;
// 			if(n1>0&&n2>0) for(int j=s, k=s+n1; j<s+n1||k<s+n1+n2; ){
// 			 //   print(j+k-s-n1, " fixing index");
// 				// A[NWR][j+k-s-n1] = (j<s+n1&&A[NEW][j]<A[NEW][k]||k==s+n1+n2)? A[NEW][j++] : A[NEW][k++];
// 				if(j<s+n1&&A[NEW][j]<A[NEW][k]||k==s+n1+n2){
// 				    // std::cout<<"j\n";
// 				    A[NWR][j+k-s-n1] = A[NEW][j];
// 				    j++;
// 				}
// 				else{
// 				    // std::cout<<"k\n";
// 				    A[NWR][j+k-s-n1] = A[NEW][k];
// 				    k++;
// 				}
// 			}
// 			else for(int jk=s; jk<s+n1+n2; jk++){
// 			 //   std::cout<<"fixed index "<<jk<<" already\n";
// 			    A[NWR][jk] = A[NEW][jk];
// 			}
// // 			std::cout << "section " << s/sect+1 << "/" << ceil(double(n)/sect) << " sorted: ";
// // 			print(A[NWR],n);
// 		}
// // 		print(A[NWR],n,"After sort");
// 	}
	
// 	if(NEW==1) for(int i=0; i<n; i++){ //if A[1] was just NWR (got flipped at end of loop)
// 		arr[i] = A[1][i];
// 	}
// // 	print(arr,n,"SORTED");
	
// // 	bool failed=false;
// 	for(int i=0;i<n-1;i++){
// 	    if(arr[i]>arr[i+1]){
// 	        std::cout <<"failed.\n";
// 	       // failed=true;
// 	        break;
// 	    }
// 	}
// // 	if(!failed) std::cout<<"good sort.\n";
	
// }

// // .....................................................................

// template<typename T>
// void print(const T arr[],int n,std::string heading){
//     if(heading!="") std::cout << heading << ": ";
//     for(int i=0; i<n; i++) std::cout << arr[i] << " ";
//     std::cout << std::endl;
// }

// template<typename T>
// void print(const T var,std::string heading){
//     if(heading!="") std::cout << heading << ": ";
//     std::cout << var << std::endl;
}
