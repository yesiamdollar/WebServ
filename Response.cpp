#include "Response.hpp"

Response::Response(statusCode statuscode):
	_statuscode(statuscode)
{}

Response::Response(const Response& other)
{
	_statuscode = other._statuscode;
}

Response& Response::operator=(const Response& other)
{
	_statuscode = other.getStatusCode();
	return *this;
}

Response::~Response(){}

statusCode Response::getStatusCode() const
{
	return _statuscode;
}

void Response::setStatusCode(statusCode statuscode)
{
	_statuscode = statuscode;
}

/*
	*To do:
		- Accurate response status codes
		- GET POST DELETE
*/

void Response::unallowedMethod(Request& request)
{
	time_t rawtime;

	time(&rawtime);
	_response = "HTTP/1.1 405 Method Not Allowed\r\n";
	_response += "Date: " + std::string(ctime(&rawtime));
	_response.erase(--_response.end());
	_response += "\r\n";
	_response += "Server: webserver\r\n";
	_response += "Content-Length: 0\r\n";
	_response += "Connection: close\r\n\r\n";
}

void Response::badRequest(Request& request)
{
	time_t rawtime;

	time(&rawtime);
	_response = "HTTP/1.1 400 Bad Request\r\n";
	_response += "Date: " + std::string(ctime(&rawtime));
	_response.erase(--_response.end());
	_response += "\r\n";
	_response += "Server: webserver\r\n";
	_response += "Content-Length: 0\r\n";
	_response += "Connection: close\r\n\r\n";
}

void Response::set_header(size_t status_code, std::string const &message, Request request)
{
	time_t rawtime;
	std::stringstream ss, ss_content;

	ss << status_code;
	time(&rawtime);
	_response += "HTTP/1.1 " + ss.str() + " " + message + "\r\n";
	_response += "Date: " + std::string(ctime(&rawtime));
	_response.erase(--_response.end());
	_response += "\r\n";
	_response += "Server: webserver\r\n";
	ss_content << request.getContentLength();
	_response += "Content-Length: " + ss_content.str() + "\r\n";
	_response += "Content-Type: text/html\r\n";
	_response += "Connection: close\r\n\r\n";
}