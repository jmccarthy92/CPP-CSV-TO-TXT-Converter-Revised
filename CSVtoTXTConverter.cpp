#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// input stream object passed by reference will be the file to be read
// output will be the vector container that holds string vectors
void readCSV(istream &input, vector< vector<string> > &output) {
	string line;

	while (getline(input, line)) {
		istringstream csvStream(line);
		vector<string> csvColumn;
		string csvField;
		while (getline(csvStream, csvField, ',')) {
			csvColumn.push_back(csvField);
		}
		output.push_back(csvColumn);
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		cout << "Did not provide enough arguements to execute the program\nPlease provide an input file, and an output file";
		return 1;
	}
	ofstream outputFile;
	string results;
	//fstream file("F:/Common/Purefix/pure.csv", ios::in);
	//outputFile.open("F:/Common/Purefix/pure.txt");
	//fstream file("C:/CSV_To_Txt_In_Dir/csvToConvert.csv", ios::in);
	//outputFile.open("C:/CSV_To_Txt_In_Dir/csvToConvert.txt");
	
	fstream file(argv[1], ios::in);
	outputFile.open(argv[2]);
	if (!file.is_open()) {
		cout << argv[1] << "FILE NOT FOUND! \n" << endl;
		return 1;
	}

	typedef vector< vector<string> > csvVector;
	csvVector csvData;

	readCSV(file, csvData);

	for (csvVector::iterator i = csvData.begin(); i != csvData.end(); ++i)
	{
		for (vector<string>::iterator j = i->begin(); j != i->end(); ++j) {
			results = *j;
			cout << results << "      ";
			outputFile << results << '\t';
		}
		outputFile << "\n";
		cout << "\n";
	}
	outputFile.close();
}