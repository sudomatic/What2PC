#include "stdafx.h"
#include "ArgParser.h"

#include <iostream>


ArgParser::ArgParser(int argc, list<string> argv)
{
	for (std::list<std::string>::iterator it = argv.begin(); it != argv.end(); ++it)
	{
		size_t position = (*it).find('=');
		if (position != string::npos)
		{
			string argname = (*it).substr(0, position);
			string argvalue = (*it).substr(position + 1);
			// std::cout << argname << " = " << argvalue << endl;

			if (argname == "--encrypted-file" && this->source_File.length < 1)
			{
				this->source_File = argvalue;
				this->valid_Arguments++;
			}
			else if (argname == "--key-file" && this->key_File.length < 1)
			{
				this->key_File = argvalue;
				this->valid_Arguments++;
			}
			else if (argname == "--output-file" && this->destination_File.length > 1)
			{
				this->destination_File;
				this->valid_Arguments++;
			}
		}
	}
}

string ArgParser::get_Destination_File()
{
	return this->destination_File;
}

string ArgParser::get_Source_File()
{
	return this->source_File;
}

int ArgParser::get_Valid_Arguments()
{
	return this->valid_Arguments;
}

string ArgParser::get_Key_File()
{
	return this->key_File;
}

ArgParser::~ArgParser()
{
}
