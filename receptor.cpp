#include "SocketMulticast.h"
#include <stdlib.h>

using namespace std;

int main(int args, char *argv[]) {
	printf("%s\n", argv[0]);
	
	if (args != 3) {
		printf("Introduzca IP y puerto\n");
		exit(-1);
	}

	char *ip   = argv[1];
	int puerto = atoi(argv[2]);

	SocketMulticast sock(puerto);
	PaqueteDatagrama data(100000);
	sock.recibe(data, ip);

	printf("%s\n", data.obtieneDatos());
	return 0;
}
