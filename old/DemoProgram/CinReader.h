/*
Copyright (c) 2008, J Boyd Trolinger

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are  permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list 
of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list 
of conditions and the following disclaimer in the documentation and/or other materials 
provided with the distribution.

Neither the name of the Butte College Department of Computer Science nor the names of its 
contributors may be used to endorse or promote products derived from this software without 
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <sstream>

using namespace std;

/**
 *   A class for handling keyboard input.  CinReader provides
 *   functions for reading all of the C++ primitive data types
 *   and C++ strings, and performs error checking on the input.
 *   @author J Boyd Trolinger
 *   @version 1.1
 */
 class CinReader
{
	public:
	
		/**
		 *  Constructor.
		 *  Initializes data members to the following values:
		 *  <ul>
		 *  <li>intErrors = true;</li>
		 *  <li>charRangeErrors = true;</li>
		 *  <li>boolMsg = "Please enter \"true\" or \"false\": "</li>
		 *  <li>charMsg = "Please enter a single character: "</li>
		 *  <li>charRangeMsg = "is not valid. Re-enter: "</li>
		 *  <li>intMsg = "Re-enter number: "</li>
		 *  <li>doubleMsg = "Input is not a double. Re-enter: "</li>
		 *  <li>floatMsg = "Input is not a float. Re-enter: "</li>
		 *  <li>stringMsg = "Input cannot be blank--enter text: "</li>
		 *  </ul>
		 */
		CinReader ();
		
		/**
		 *  Destructor.
		 *  CinReader performs no dynamic memory allocation.  Destructor
		 *  is provided for thoroughness and to reinforce good OO/C++ 
		 *  programming practices.
		 */
		~CinReader ();
		
		/**
		 *  Read integer input from the keyboard.
		 *  Used with no arguments, the function will return an integer between
		 *  INT_MIN and INT_MAX.  Optionally the function can be called
		 *  with caller-specified upper and lower limits. If lower>upper, valid return
		 *  value is not guaranteed. Uses intMsg for error prompt.
		 * @param lower caller-specified lower limit of the input, defaults to INT_MIN
		 * @param upper caller-specified upper limit of the input, defaults to INT_MAX
		 * @return an integer between INT_MIN and INT_MAX if called with
		 *               no arguments, or between lower and upper  (inclusive)
		 */
		int readInt (int lower=INT_MIN, int upper=INT_MAX);
		
		/**
		 *  Read integer input from the keyboard.
		 *  Provided for backward compatibility with the version 1.0 CinReader API. Calls
		 *  readInt(lower,upper) if userLimit==true, else calls readInt().
		 *  @param userLimit if true, limit keyboard input to caller-specified range
		 *  @param lower caller-specified lower limit of the input
		 *  @param upper caller-specified upper limit of the input
		 *  @return an integer between lower and upper (inclusive)
		 */
		int readInt (bool userLimit, int lower, int upper);
		
		/**
		 *  Read double input from the keyboard.
		 *  Unlike readInt, this function does not limit the range of the
		 *  input value. Uses doubleMsg for error prompt.
		 *  @return a double
		 */
		double readDouble ();
		
		/**
		 *  Read float input from the keyboard.
		 *  Unlike readInt, this function does not limit the range of the
		 *  input value. Uses floatMsg for error prompt.
		 *  @return a float
		 */
		float readFloat ();
		
		/**
		 *  Read input from the keyboard as a boolean value.
		 *  Will accept "T", "F" or "TRUE", "FALSE" as input and will
		 *  return a corresponding boolean value.  The function is NOT
		 *  case sensitive, it will accept input as any combination of
		 *  uppercase and lowercase characters. Uses boolMsg for error prompt.
		 *  @return a bool
		 */
		bool readBool ();
		
		/**
		 * Read char input from the keyboard.
		 *  Used with no arguments, the function will return the char entered at 
		 *  the keyboard.  Optionally, a range of acceptable inputs can
		 *  be specified.  The range must be written as a list of chars, such as
		 *  "abcdef". Uses charMsg for error prompt. If charRangeErrors==true, and 
		 *  range.length() > 0, also uses charRangeMsg for error prompt.
		 *  @param range the range of acceptable inputs
		 *  @return a char that is a member of range if specified, or
		 *                 any single char if no range is provided
		 */
		char readChar (string range="");
		
		/**
		 *  Read string input from the keyboard.
		 *  Used with no arguments, the function will return the string
		 *  entered at the keyboard, which can include an empty string.
		 *   Uses stringMsg for error prompt.
		 *  @param allowEmpty if true, allow empty string as input, else
		 *                 require at least one character of input
		 *  @param limitTo if 0, do not limit the number of characters of
		 *                 input; if not 0, return only "limitTo" number of
		 *                 characters
		 *  @return a string
		 */
		string readString (bool allowEmpty = true, unsigned int limitTo = 0);
		
		/**
		 * Enable or disable more verbose error messages for invalid integer inputs.
		 * Defaults to true.
		 * @param show 	if true, show additional ERROR output on invalid input; if false,
		 * 					display only intMsg as error prompt.
		 */
		void showIntErrors (bool show);
		
		/**
		 * Enable or disable more verbose error messages for invalid character inputs when 
		 * limiting to a caller-specified range.
		 * Defaults to true.
		 * @param show 	if true, show additional ERROR output on invalid input; if false,
		 * 					display only charMsg as error prompt.
		 */
		void showCharRangeErrors (bool show);
		 
		/**
		 * Set the prompt string for invalid bool inputs.
		 * Default boolMsg is "Please enter \"true\" or \"false\": "
		 * @param newMessage a prompt string for invalid bool inputs
		 */
		void setBoolMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid char inputs.
		 * Default charMsg is "Please enter a single character: "
		 * @param newMessage a prompt string for invalid char inputs
		 */
		void setCharMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid char inputs when limiting to a caller-specified 
		 * range.
		 * Default charRangeMsg is "[CHAR] is not valid. Re-enter: " (CHAR is the user's invalid
		 * input.) "[CHAR]" is always appended to the beginning of the char range error prompt string.
		 * @param newMessage a prompt string for invalid char inputs
		 */
		void setCharRangeMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid int inputs.
		 * Default intMsg is "Re-enter number: "
		 * @param newMessage a prompt string for invalid int inputs
		 */
		void setIntMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid double inputs.
		 * Default doubleMsg is "Input is not a double. Re-enter: "
		 * @param newMessage a prompt string for invalid double inputs
		 */
		void setDoubleMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid float inputs.
		 * Default floatMsg is "Input is not a float. Re-enter: "
		 * @param newMessage a prompt string for invalid float inputs
		 */
		void setFloatMessage (string newMessage);
		
		/**
		 * Set the prompt string for invalid string inputs.
		 * Default stringMsg is "Input cannot be blank--enter text: "
		 * @param newMessage a prompt string for invalid string inputs
		 */
		void setStringMessage (string newMessage);
		
	private:
		
		bool intErrors;
		bool charRangeErrors;
		string boolMsg;
		string charMsg;
		string charRangeMsg;
		string intMsg;
		string doubleMsg;
		string floatMsg;
		string stringMsg;
		
		string stripCommas (string input);
		bool testIntInput (string, string&, int l=-1, int u=-1);
		bool testDoubleInput (string);
		bool testCharInput (char, string);
		bool testBoolInput (string);
		bool getBoolValue (string);
		void toUpperCase (string&);
		bool ignoreCaseCompare (string, string);
};
