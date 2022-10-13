all:
	g++ with_seep.cpp -o with_seep.out
	g++ without_seep.cpp -o without_seep.out
	g++ without_vendorization.cpp -o without_vendorization.out
