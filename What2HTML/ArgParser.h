#pragma once

#include <string>
#include <list>

using namespace std;

class ArgParser
{
protected:
	string source_File, destination_File, key_File;
	int valid_Arguments = 0;
public:
	ArgParser(int argc, list<string> argv);
	string get_Source_File();
	string get_Destination_File();
	string get_Key_File();
	int get_Valid_Arguments();
	~ArgParser();
};

