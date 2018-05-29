#include "FailResponse.h"

wstring FailResponse::getbank_server() const
{
	return bank_server;
}

void FailResponse::setbank_server(const wstring &value)
{
	bank_server = value;
}

wstring FailResponse::gettime() const
{
	return time;
}

void FailResponse::settime(const wstring &value)
{
	time = value;
}

wstring FailResponse::getstatus() const
{
	return status;
}

void FailResponse::setstatus(const wstring &value)
{
	status = value;
}

wstring FailResponse::getmessage() const
{
	return message;
}
void FailResponse::setmessage(const wstring &value)
{
	message = value;
}