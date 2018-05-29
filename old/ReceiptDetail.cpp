

#include "ReceiptDetail.h"

	int ReceiptDetail::getnn() const
	{
		return privatenn;
	}

	void ReceiptDetail::setnn(const int &value)
	{
		privatenn = value;
	}

	int ReceiptDetail::getsn() const
	{
		return privatesn;
	}

	void ReceiptDetail::setsn(const int &value)
	{
		privatesn = value;
	}

	std::wstring ReceiptDetail::getstatus() const
	{
		return privatestatus;
	}

	void ReceiptDetail::setstatus(const std::wstring &value)
	{
		privatestatus = value;
	}

	std::wstring ReceiptDetail::getpown() const
	{
		return privatepown;
	}

	void ReceiptDetail::setpown(const std::wstring &value)
	{
		privatepown = value;
	}

	std::wstring ReceiptDetail::getnote() const
	{
		return privatenote;
	}

	void ReceiptDetail::setnote(const std::wstring &value)
	{
		privatenote = value;
	}

	ReceiptDetail::ReceiptDetail()
	{

	} //end of constructor

	ReceiptDetail::ReceiptDetail(int nn, int sn, const std::wstring &status, const std::wstring &pown, const std::wstring &note)
	{
		this->setnn(nn);
		this->setsn(sn);
		this->setstatus(status);
		this->setpown(pown);
		this->setnote(note);

	} //end of constructor
