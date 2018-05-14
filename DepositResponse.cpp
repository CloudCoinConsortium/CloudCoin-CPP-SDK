#include "DepositResponse.h"

wstring DepositResponse::getbank_server() const
{
	return bank_server;
}

void DepositResponse::setbank_server(const wstring &value)
{
	bank_server = value;
}

wstring DepositResponse::gettime() const
{
	return time;
}

void DepositResponse::settime(const wstring &value)
{
	time = value;
}

wstring DepositResponse::getstatus() const
{
	return status;
}

void DepositResponse::setstatus(const wstring &value)
{
	status = value;
}

wstring DepositResponse::getmessage() const
{
	return message;
}
void DepositResponse::setmessage(const wstring &value)
{
	message = value;
}

wstring DepositResponse::getreceipt() const
{
	return receipt;
}
void DepositResponse::setreceipt(const wstring &value)
{
	receipt = value;
}


