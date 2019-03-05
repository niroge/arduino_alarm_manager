#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

namespace niroge {
	int bluetooth_connect(const char *mac_address)
	{
		sockaddr_rc socket_rfcomm;
		int bluetooth_socket_id, status;

		std::cout << "Connecting to " << mac_address << std::endl;
		std::cout << "----------------------------" << std::endl;
		std::cout << "Socket system: unix" << std::endl;
		std::cout << "Connecting to " << mac_address << "..." << std::endl;

		bluetooth_socket_id = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
		socket_rfcomm.rc_family = AF_BLUETOOTH;
		socket_rfcomm.rc_channel = (unsigned short int) 1;

		str2ba(mac_address, &socket_rfcomm.rc_bdaddr);

		status = connect(bluetooth_socket_id, (struct sockaddr *) &socket_rfcomm, sizeof socket_rfcomm);

		if (status < 0) {
			std::cerr << "Could not connect to the device, please try again" << std::endl;
			return -1;
		}

		else {
			std::cout << "Device connected successfully" << std::endl;
			return bluetooth_socket_id;
		}

		std::cout << "Closing connection..." << std::endl;
	}

	int bluetooth_send(int socket_id, const char *message, int bytes)  {
		std::cout << "sending data to socket " << socket_id << "..." << std::endl;
		std::cout << "content: ";

		for (int i = 0; i < bytes; i++) {
			std::cout << (int) message[i] << "d ";
		}

		std::cout << std::endl;

		int exit_code = write(socket_id, message, bytes);

		std::cout << "Bytes sent: " << exit_code << "/" << bytes << std::endl;
		return exit_code;
	}
}
