#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// demo of stringstream
// see http://www.cplusplus.com/forum/beginner/203521/ for more info
void load(std::istream& inStream)
{
	std::string         line;
	std::stringstream   lineStream;
	std::string         cell;

	int row=0;

	//read lines
	while( std::getline(inStream, line) )
	{
		lineStream.clear();
		lineStream.str(line);
		std::cout << "row=" << row++
			<< " lineStream.str() = " << lineStream.str() << std::endl;

		//read cells, you can check the return value of getline, if its 0
		//then the stream is exhausted, 
		while(std::getline(lineStream, cell, ','))
		{
			std::cout << "cell=" << cell << std::endl;
		}
	}
}


int main()
{
    std::ifstream       infile("data.txt");
    load(infile);
}
