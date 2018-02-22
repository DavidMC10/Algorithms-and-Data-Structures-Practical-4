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

	Sorter<int> sS(size);
	sS.fillRandom(300);
	Sorter<int> iS(sS);
	Sorter<int> mS(sS);
	Sorter<int> qS(sS);


	// For each Sorter start clock, call relevant sort algorithm, 
	// call clock again, print results
	// Note:Sorting very large data sets may cause quicksort to run out
	// of stack space and crash program as recursive overhead is too great.

	clock_t start, finish, start1, finish1;

	//Selection Sort

	//Unsorted
	start = clock();
	sS.selectionSort();
	finish = clock();

	//Sorted
	start1 = clock();
	sS.selectionSort();
	finish1 = clock();

	// Print Result
	cout << "Selection Sort   " << size << " = " << (finish - start) << "/" << (finish1 - start1) << endl;



	// Insertion Sort

	// Unsorted
	start = clock();
	iS.insertionSort();
	finish = clock();

	// Sorted
	start1 = clock();
	iS.insertionSort();
	finish1 = clock();

	// Print resu;t
	cout << "Insertion Sort   " << size << " = " << (finish - start) << "/" << (finish1 - start1) << endl;


	// Merge Sort

	// Unsorted
	start = clock();
	mS.mergeSort();
	finish = clock();

	// Sorted
	start1 = clock();
	mS.mergeSort();
	finish1 = clock();

	// Print result
	cout << "Merge Sort   " << size << " = " << (finish - start) << "/" << (finish1 - start1) << endl;




	// Quick Sort

	// Unsorted
	start = clock();
	qS.quickSort();
	finish = clock();

	//Sorted
	/*start1 = clock();
	qS.quickSort();
	finish1 = clock();*/

	// Print result
	cout << "Quick Sort   " << size << " = " << (finish - start) << "/" << (finish1 - start1) << endl;


}

// Determine the most frequent word in the supplied text file 'words.txt'
// print the word and its frequency
void wordFrequency() {

	// Create a sorter of length 400
	Sorter<std::string> words(400);

	// Load the text file into the array.
	words.loadFile("words.txt");

	// Sort the words
	words.quickSort();

	// Write the sorted words into the sorted text file
	words.writeFile("sorted.txt");

	// Create an array and assign it a copy of the words sorter
	Array<std::string> data = words.getElements();

	// Variable declaration
	int frequency{ 1 };
	int maxFrequency{ 0 };
	int maxPos{ 0 };

	// Loop to check which word occurs the most
	for (int i{ 0 }; i < data.length() - 1; i++) {

		if (data[i] == data[i + 1]) {
			frequency++;
		} else {
			// If frequency is greater than the max frequence. Max frequency is assigned the frequency.
			// Max position is assigned i.
			if (frequency > maxFrequency) {
				maxFrequency = frequency;
				maxPos = i;
			}
			// Frequency is reset to one.
			frequency = 1;
		}
	}

	// Print results
	cout << "The most frequent word is '" << data[maxPos] << "' it occurs " << maxFrequency << " times" << endl;
}



// Main method.
int main() {

	//testPerformance(5000);
	wordFrequency();
	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}