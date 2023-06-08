#include <iostream>    // stream I/O
#include <fstream>
#include <string>      // string
#include <cassert>     // assert()
using namespace std;

char CaesarEncode(char ch, int key);


// Question 1. Write a function returns the position of the key, if the key does not exist, returns -1
int LinearSearch(int* a, int n, int key)
{
	int i = 0;
	while (i < n && a[i] != key)
		i++;
	if (i == n)
		return -1;
	return i;

}

// Question 2. Write a function prints the binary form of the positive integer n
void PrintBinary(int n)
{
	if (n == 0)
	{
		return;
	}

	PrintBinary(n / 2);
	cout << n % 2;

}


//  Question 3. 
bool encode_message()
{

	// 0. Display introductory message 
	cout << "\nThis program uses the Caesar cipher to encode the contents of a"
		<< "\nfile and writes the encoded characters to another file.\n";

	// 1. (0.25 point) Open inFile for reading 
	string inFile = "message.txt";
	ifstream f(inFile);


	// 2. (0.25 point) If file is failed to open, display an error message and return False; otherwise, display success message

	if (!f)
	{
		cout << "Cannot open file message.txt" << endl;
		return false;
	}
	cout << "File message.txt opened!" << endl;

	// 3. (0.25 point) Open outFile for output.
	string outFile = "encoded_message.txt";
	ofstream f1(outFile);


	// 4. (0.25 point) If file is failed to open, display an error message and return False; otherwise, display success message

	if (!f1)
	{
		cout << "Cannot open file encoded_message.txt" << endl;
		return false;
	}
	cout << "File encoded_message.txt opened!" << endl;


	// 5. (3.0 point) Read the content of inFile and encode the message then write the encoded message to outFile 
	char c = NULL;
	while (!f.eof())
	{
		f.get(c);
		f1 << CaesarEncode(c, 5);
	}


	// 6. (0.5 point) close the connection to the input and output file

	f.close();
	f1.close();

	// 7. display a 'successful completion' message
	cout << "\nProcessing complete.\n Encoded message is in " << outFile << endl;
	return true;
}

int main()
{
	int n = 6;
	int *a = new int[n] {1, 2, 3, 4, 5, 0};
	int key = 0;

	int pos = LinearSearch(a, 6, 0);
	cout << "\nVi tri cua " << key << " trong mang la: " << pos << endl;


	cout << "Dang nhi phan cua " << n << " la: ";
	PrintBinary(n);
	cout << "\n";


	encode_message();

	return 1;
}

/*============================================================
 * CaesarEncode implements the Caesar cipher encoding scheme.
 *
 * Receive: ch, a character.
 *          key, the amount by which to rotate ch.
 * Return:  The character that is key positions after ch,
*/

#include <cctype>      // isupper(), islower()

char CaesarEncode(char ch, int key)
{
	const int FIRST_UPPER = 65,
		FIRST_LOWER = 97,
		NUM_CHARS = 26;

	if (key <= 0 || key >= NUM_CHARS)
	{
		cerr << "\n*** CaesarEncode: key must be between 1 and 25\n" << endl;
		exit(1);
	}

	if (isupper(ch))
		return (ch - FIRST_UPPER + key) % NUM_CHARS + FIRST_UPPER;
	else if (islower(ch))
		return (ch - FIRST_LOWER + key) % NUM_CHARS + FIRST_LOWER;
	else
		return ch;
}


