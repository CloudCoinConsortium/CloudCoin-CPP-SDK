#include "CinReader.h"

CinReader::CinReader ()
{
	intErrors = true;
	charRangeErrors = true;

	boolMsg = "Please enter \"true\" or \"false\": ";
	charMsg = "Please enter a single character: ";
	charRangeMsg = "is not valid. Re-enter: ";
	intMsg = "Re-enter number: ";
	doubleMsg = "Input is not a double. Re-enter: ";
	floatMsg = "Input is not a float. Re-enter: ";
	stringMsg = "Input cannot be blank--enter text: ";
}

CinReader::~CinReader ()
{
}

int CinReader::readInt (int lower, int upper)
{
	string input = "";
	string msg = "";
	getline (cin, input);
	input = stripCommas(input);
	if (lower > upper)
	{
		int temp = upper;
		lower = upper;
		upper = temp;
	}

	while (!testIntInput(input, msg, lower, upper))
	{
		if (intErrors)
			cout << "[ ERROR: " << msg << " ]\n";
		cout << intMsg;
		getline (cin, input);
	}

	return (atoi(input.c_str()));
}

int CinReader::readInt (bool userLimit, int lower, int upper)
{
	if (userLimit)
		return (readInt(lower, upper));
	else
		return (readInt());
}

double CinReader::readDouble ()
{
	string input = "";
	getline(cin, input);
	input = stripCommas(input);
	while (!testDoubleInput(input))
	{
		cout << doubleMsg;
		getline(cin, input);
	}

	return (atof(input.c_str()));
}

float CinReader::readFloat ()
{
	string input = "";
	getline(cin, input);
	input = stripCommas(input);
	while (!testDoubleInput(input))
	{
		cout << floatMsg;
		getline(cin, input);
	}

	return (atof(input.c_str()));
}

char CinReader::readChar (string range)
{
	bool valid = false;
	string input = "";
	getline(cin, input);

	if (range.length() > 0)
	{
		do
		{
			while (input.length() != 1)
			{
				cout << charMsg;
				getline(cin, input);
			}
			if (!testCharInput(input[0], range))
			{
				if (charRangeErrors)
					cout << "[" << input[0] << "] " << charRangeMsg;
				input = "";
			}
			else
				valid = true;
		} while (!valid);
	}
	else
	{
		while (input.length() != 1)
		{
			cout << charMsg;
			getline(cin, input);
		}
	}

	return (input[0]);
}

bool CinReader::readBool ()
{
	string input = "";
	getline(cin, input);
	while (!testBoolInput(input))
	{
		cout << boolMsg;
		getline(cin, input);
	}

	return (getBoolValue(input));
}

string CinReader::readString (bool allowEmpty, unsigned int limitTo)
{
	string input = "";
	getline(cin, input);
	if (!allowEmpty)
	{
		while (input.length() == 0)
		{
			cout << stringMsg;
			getline(cin, input);
		}
	}
	if (limitTo > 0)
	{
		if (input.length() > limitTo)
			input = input.substr(0, limitTo);
	}
	return input;
}

void CinReader::showIntErrors (bool show)
{
    intErrors = show;
}

void CinReader::showCharRangeErrors (bool show)
{
    charRangeErrors = show;
}

void CinReader::setBoolMessage (string newMessage)
{
	boolMsg = newMessage;
	if (boolMsg.length() > 0 && boolMsg[boolMsg.length()-1] != ' ')
		boolMsg += ' ';
}

void CinReader::setCharMessage (string newMessage)
{
	charMsg = newMessage;
	if (charMsg.length() > 0 && charMsg[charMsg.length()-1] != ' ')
		charMsg += ' ';
}

void CinReader::setCharRangeMessage (string newMessage)
{
	charRangeMsg = newMessage;
	if (charRangeMsg.length() > 0 && charRangeMsg[charRangeMsg.length()-1] != ' ')
		charRangeMsg += ' ';
}

void CinReader::setIntMessage (string newMessage)
{
	intMsg = newMessage;
	if (intMsg.length() > 0 && intMsg[intMsg.length()-1] != ' ')
		intMsg += ' ';
}

void CinReader::setDoubleMessage (string newMessage)
{
	doubleMsg = newMessage;
	if (doubleMsg.length() > 0 && doubleMsg[doubleMsg.length()-1] != ' ')
		doubleMsg += ' ';
}

void CinReader::setFloatMessage (string newMessage)
{
	floatMsg = newMessage;
	if (floatMsg.length() > 0 && floatMsg[floatMsg.length()-1] != ' ')
		floatMsg += ' ';
}

void CinReader::setStringMessage (string newMessage)
{
	stringMsg = newMessage;
	if (stringMsg.length() > 0 && stringMsg[stringMsg.length()-1] != ' ')
		stringMsg += ' ';
}

string CinReader::stripCommas (string input)
{
	string outs = "";
	for (unsigned int i=0; i<input.length(); i++)
	{
		if (input[i] != ',')
			outs += input[i];
	}
	return outs;
}

bool CinReader::testIntInput (string input, string& msg, int lowerLimit, int upperLimit)
{
	int upperMarker = -1;
	int lowerMarker = -1;
	if (upperLimit == INT_MAX)
		upperMarker = 47;
	if (lowerLimit == INT_MIN)
		lowerMarker = 48;

	long linput = strtol(input.c_str(), NULL, 10);
	stringstream ssinput;
	ssinput << linput;
	if (ssinput.str() != input)
	{
	   msg = "integer input out-of-range";
	   return false;
	}

	else
	{
		if (input.length() > 0)
		{
			if (input[0] != '-' && (!isdigit(input[0])))
			{
				msg = "not an integer";
				return false;
			}
			for (unsigned int i=1; i<input.length(); i++)
			{
				if (!isdigit(input[i]))
				{
					msg = "not an integer";
					return false;
				}
			}

			int tmp = strtol(input.c_str(), NULL, 10);
			if (tmp >= upperLimit)
			{
				if (upperMarker != -1)
				{
					string ts = "";
					ts += input[input.length()-2];
					ts += input[input.length()-1];
					int ti = atoi(ts.c_str());
					if (ti > upperMarker)
					{
						msg = "larger than 32-bit integer";
						return false;
					}
					else
						return true;
				}
				else
				{
					if (tmp == upperLimit)
						return true;
					else
					{
						msg = "larger than upper limit";
						return false;
					}
				}
			}
			else if (tmp <= lowerLimit)
			{
				if (lowerMarker != -1)
				{
					string ts = "";
					ts += input[input.length()-2];
					ts += input[input.length()-1];
					int ti = atoi(ts.c_str());
					if (ti > lowerMarker)
					{
						msg = "smaller than 32-bit integer";
						return false;
					}
					else
						return true;
				}
				else
				{
					if (tmp == lowerLimit)
						return true;
					else
					{
						msg = "smaller than lower limit";
						return false;
					}
				}
			}
			else
				return true;
		}
		msg = "no input";
		return false;
	}
}

bool CinReader::testDoubleInput (string input)
{
	int dotCount = 0;
	if (input.length() > 0)
	{
		if (input[0] != '-' && (!isdigit(input[0])) && input[0] != '.')
			return false;
		if (input[0] == '.')
			dotCount = 1;
		for (unsigned int i=1; i<input.length(); i++)
		{
			if (input[i] == '.')
			{
				if (dotCount != 0)
					return false;
				else
					++dotCount;
			}
			else if (!isdigit(input[i]))
				return false;
		}

		return true;
	}

	return false;
}

bool CinReader::testCharInput (char c, string range)
{
	bool valid = false;
	for (unsigned int i=0; i<range.length(); i++)
	{
		if (range[i] == c)
		{
			valid = true;
			break;
		}
	}
	return valid;
}

bool CinReader::testBoolInput (string input)
{
	if (input.length() > 0)
	{
		if (input.length() == 1)
		{
			if (toupper(input[0]) == 'T' || toupper(input[0]) == 'F')
				return true;
			else
				return false;
		}
		else
		{
			if (ignoreCaseCompare(input, "TRUE") ||
			    ignoreCaseCompare(input, "FALSE"))
				return true;
			else
				return false;
		}
	}
	else
		return false;
}

bool CinReader::getBoolValue (string input)
{
	if (toupper(input[0]) == 'T')
		return true;
	else
		return false;
}

bool CinReader::ignoreCaseCompare (string input, string comp)
{
	toUpperCase(input);
	if (input == comp)
		return true;
	else
		return false;
}

void CinReader::toUpperCase (string& s)
{
  transform(s.begin(), s.end(),  s.begin(), ::toupper);
}
