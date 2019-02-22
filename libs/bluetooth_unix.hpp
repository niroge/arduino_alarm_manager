#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

void bluetooth_connect(const char *mac_address)
{
	std::cout << "Connecting to " << mac_address << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Socket system: unix" << std::endl;
}
