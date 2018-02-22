//================================================================================
// Name        : practical4.cpp
// Author      : McElhinney-d1@ulster.ac.uk
// Version     : 1.0
// Description : practical 4 test program to utilise sort algorithms
//================================================================================

#include <string> // used to access string type
#include <cctype>
#include <ctime> // used to access clock_t and clock()

#include "Array.h"
#include "Sorter.h"

using namespace std;

// Test relative sort performances when sorting same random 
// number sequence of specified size. 
void testPerformance(int size) {
  // create a Sorter for each sort algorithm ensuring each
  // contain the same random numbers. Use of Sorter copy
  // constructor is one way to ensure this!!
  
  // For each Sorter start clock, call relevant sort algorithm, 
  // call clock again, print results

  // Note:Sorting very large data sets may cause quicksort to run out
  // of stack space and crash program as recursive overhead is too great.
}

// Determine the most frequent word in the supplied text file 'words.txt'
// print the word and its frequency
void wordFrequency() {

}



// Main method.
int main() {


	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}