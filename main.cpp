//Afham Bashir
//09.7.2020
#include <iostream>
#include <string>            //allows use of string
using namespace std; 

void permute (const string& str);        //function prototypes
void permute (const string& str, size_t pos);
int count = 0;                           //global variable to track number of recursive function calls

int main() {                  
	string str; 
	cout << "Enter string: ";         
	cin >>str;
  cout << "\nThe possible permutations are: \n" << endl; 
	permute(str);                   //calls driver function
  cout << "\nTimes the permute function was called : " << count <<endl; 
	return 0;
}

void permute (const string& str){
  permute(str, 0);      //calls function that finds the possible permutations of the string AND also prints them
}

void permute( const string& str, size_t pos){  // takes a string and index of the string as the two parameters. 
  count++;                                     //increaments for each time he the recursive function is called
  string pStr= str;                            // creates a copy of the string passed as a parameter
  if (str.size() == (pos+1)) {                 // if the fuction reaches the last index of the string, then it has created one permutation and will print its result. 
    cout << str << endl; }                                     
  else { 
     for (int i = pos; i <= (str.size()-1); i++){   //creates a for loop that works through permutaions by selecting intially the first index od swapping with other character, the index increaments each time the loop is executed, untill it reaches the last index, which is equal to the size of the string minus 1.  
          swap(pStr[pos], pStr[i]);   //this swaps the specified position in the string with the index the of i, this will intially only switch the first character in the string with itself. 
          permute(pStr, pos+1);      // recursivly calls the permute function with the next position in the string
          swap(pStr[pos], pStr[i]);  // switch back the indexes, so that when the function is recursivly called and the for loop is done again, it can pass the string to create other permutations back starting at the intial index, with out refering back to the orginal string passed by the driver function. 
             }  
    }  
}