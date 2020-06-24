
Socket.o: Socket.cc Socket.h
	g++ -g -c Socket.cc

udp-server.o: udp-server.cc Socket.h
	g++ -g -c udp-server.cc

udp-client.o: udp-client.cc Socket.h
	g++ -g -c udp-client.cc

udp-server.out: udp-server.o Socket.o
	g++ -g udp-server.o Socket.o -o udp-server.out


udp-client.out: udp-client.o Socket.o
	g++ -g udp-client.o Socket.o -o udp-client.out

