

#include <string>
#include <vector>
#include "ReceiptDetail.h"

//Forward class declarations:
//namespace Founders { class ReceiptDetail; }


using namespace std;

	class Receipt
	{
	private:
		wstring privatereceipt_id;
		wstring privatetime;
		wstring privatetimezone;
		wstring privatebank_server;
		int privatetotal_authentic = 0;
		int privatetotal_fracked = 0;
		int privatetotal_counterfeit = 0;
		int privatetotal_lost = 0;
		ReceiptDetail* privaterd;

	public:

		int NumDetails;

		wstring getreceipt_id() const;
		void setreceipt_id(const wstring &value);

		wstring gettime() const;
		void settime(const wstring &value);

		wstring gettimezone() const;
		void settimezone(const wstring &value);

		wstring getbank_server() const;
		void setbank_server(const wstring &value);

		int gettotal_authentic() const;
		void settotal_authentic(const int &value);

		int gettotal_fracked() const;
		void settotal_fracked(const int &value);

		int gettotal_counterfeit() const;
		void settotal_counterfeit(const int &value);

		int gettotal_lost() const;
		void settotal_lost(const int &value);

		ReceiptDetail* getrd(); //const;
		void setrd (ReceiptDetail* value);

		

		

	};
