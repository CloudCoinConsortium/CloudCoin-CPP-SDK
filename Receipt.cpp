
#include "Receipt.h"
#include "ReceiptDetail.h"

//using namespace Newtonsoft::Json;

//namespace Founders
//{

	wstring Receipt::getreceipt_id() const
	{
		return privatereceipt_id;
	}

	void Receipt::setreceipt_id(const std::wstring &value)
	{
		privatereceipt_id = value;
	}

	std::wstring Receipt::gettime() const
	{
		return privatetime;
	}

	void Receipt::settime(const std::wstring &value)
	{
		privatetime = value;
	}

	std::wstring Receipt::gettimezone() const
	{
		return privatetimezone;
	}

	void Receipt::settimezone(const std::wstring &value)
	{
		privatetimezone = value;
	}

	std::wstring Receipt::getbank_server() const
	{
		return privatebank_server;
	}

	void Receipt::setbank_server(const std::wstring &value)
	{
		privatebank_server = value;
	}

	int Receipt::gettotal_authentic() const
	{
		return privatetotal_authentic;
	}

	void Receipt::settotal_authentic(const int &value)
	{
		privatetotal_authentic = value;
	}

	int Receipt::gettotal_fracked() const
	{
		return privatetotal_fracked;
	}

	void Receipt::settotal_fracked(const int &value)
	{
		privatetotal_fracked = value;
	}

	int Receipt::gettotal_counterfeit() const
	{
		return privatetotal_counterfeit;
	}

	void Receipt::settotal_counterfeit(const int &value)
	{
		privatetotal_counterfeit = value;
	}

	int Receipt::gettotal_lost() const
	{
		return privatetotal_lost;
	}

	void Receipt::settotal_lost(const int &value)
	{
		privatetotal_lost = value;
	}


	ReceiptDetail* Receipt::getrd()
	{
		return privaterd;
	}

	void Receipt::setrd(ReceiptDetail* value)
	{
		privaterd = value;
	}
//}
