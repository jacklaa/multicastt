#include "SocketMulticast.h"
#include "PaqueteDatagrama.h"
#include <stdlib.h>

using namespace std;

int main(int args, char *argv[]) {
	if (atoi(argv[0]) != 4) {
		printf("Introduzca IP, puerto, mensaje y TTL\n");
		exit(-1);
	}

	char *ip   = argv[1];
	int puerto = atoi(argv[2]);
	char *cad  = argv[3];

	printf("Vamos a mandar el msj: %s\n", cad);

	int ttl    = atoi(argv[4]);

	SocketMulticast sock(puerto);
	PaqueteDatagrama data(cad, strlen(cad), ip, puerto);
	sock.envia(data, ttl);
	return 0;
}
