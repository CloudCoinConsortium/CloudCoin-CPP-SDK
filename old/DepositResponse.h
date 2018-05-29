#pragma once
#include <string>
#include <vector>

using namespace std;


class DepositResponse
{
	private:
		wstring bank_server;
		wstring time;
		wstring status;
		wstring message;
		wstring receipt;
	public:
		DepositResponse()
		{

		}

		wstring getbank_server() const;
		void setbank_server(const wstring &value);

		wstring gettime() const;
		void settime(const wstring &value);

		wstring getstatus() const;
		void setstatus(const wstring &value);

		wstring getmessage() const;
		void setmessage(const wstring &value);

		wstring getreceipt() const;
		void setreceipt(const wstring &value);

};