// Program 1

#include <iostream>
#include "boost/interprocess/managed_shared_memory.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "boost/interprocess/shared_memory_object.hpp"


using namespace::std;



int main(){

	using namespace boost::interprocess;

	// use try-catch to handle exceptions
	try{
		// try remove old shared memory first
		shared_memory_object::remove("MySharedInteger"); // "MySharedInteger" is the name that will be used later for shared memory

		//create a shared integer
		shared_memory_object sharedInteger (create_only, "MySharedInteger", read_write);

		// set size
		sharedInteger.truncate(sizeof(int));

		//map the shared memory in this process
		mapped_region region(sharedInteger, read_write);

		// create an object of Int initialized to 19
		//int *instance = segment.construct<int>("Integer Instance")(19); // name, initial value

		// get a pointer to the mapped_region
		int *ptr = static_cast<int*>(region.get_address());

		// set initial value
		cout << "Setting initial value by program 1: " << endl;
		*ptr = 19; // set to 19
		cout << *ptr << endl;
		

	}
	// catch all exceptions
	catch(...) {
		cout << "something happens...\n";
	}


	// remove shared memory
	//shared_memory_object::remove("MySharedInteger");

	return 0;
}