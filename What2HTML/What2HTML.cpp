// What2HTML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "defines.h"
#include <iostream>
#include <string>
#include <list>

#include "ArgParser.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/**
	 * Get all the arguments
	 * First is the filename of the executable
	 * Second should be the encrypted message file
	 * Third is the keyfile
	 * Fourth is the destination.
	 * ArgParser will do the job
	 */
	ArgParser* argparser = NULL;

	list<string> arg_list;

	for (int i = 1; i < argc; ++i)
	{
		arg_list.push_back(string(argv[i]));
	}

	argparser = new ArgParser(argc, arg_list);

	if (argparser->get_Valid_Arguments() < 3)
	{
		cout << "What2HTML" << " by <gaurav.joseph@linuxmail.org>" << endl
			<< "Converts WhatsApp messages to HTML text" << endl << endl
			<< "Usage:" << endl
			<< argv[0] << " --encrypted-file=<sourcefile> --key-file=<keyfile> --output-file=<outfile>";
		return EXIT_ARGUMENT_ERROR;
	}
	return EXIT_SUCCESS;
}

