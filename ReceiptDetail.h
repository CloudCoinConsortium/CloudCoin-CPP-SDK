#pragma once


#include <string>

using namespace std;

	class ReceiptDetail
	{
	private:
		int privatenn = 0;
		int privatesn = 0;
		wstring privatestatus;
		wstring privatepown;
		wstring privatenote;

		//Fields
	public:
		int getnn() const;
		void setnn(const int &value);

		int getsn() const;
		void setsn(const int &value);

		wstring getstatus() const;
		void setstatus(const wstring &value);

		wstring getpown() const;
		void setpown(const wstring &value);

		wstring getnote() const;
		void setnote(const wstring &value);


		//Constructors
		ReceiptDetail();

		ReceiptDetail(int nn, int sn, const wstring &status, const wstring &pown, const wstring &note);

	}; //End Class
