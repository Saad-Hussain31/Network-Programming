#include <boost/asio.hpp>
#include <iostream>
using namespace std;
using namespace boost;
int main(){
	string raw_ip_address = "127.0.0.1";
	unsigned short port = 3333;
	boost::system::error_code ec; //to store the parsing errors.
	asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);
	if (ec.value() != 0){
		cout << "Failed parsing the IP. Error code = " << ec.value() << ". Message = " << ec.message();
		return ec.value(); 
	}
	asio::ip::tcp::endpoint ep(ip_address, port);
	return 0;
}