// Program 2

#include <iostream>
#include "boost/interprocess/managed_shared_memory.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "boost/interprocess/shared_memory_object.hpp"


using namespace::std;



int main(){

	using namespace boost::interprocess;

	// use try-catch to handle exceptions
	try{
		// open the shared_memory by program 1
		shared_memory_object sharedInteger (open_only, "MySharedInteger", read_write);

		//map the shared memory in this process
		mapped_region region(sharedInteger, read_write);

		// create an object of Int initialized to 19
		//int *instance = segment.construct<int>("Integer Instance")(19); // name, initial value

		// get a pointer to the mapped_region
		int *ptr = static_cast<int*>(region.get_address());

		// output the integer value
		cout << "Outputting value from program 2: " << endl;
		cout << *ptr << endl; // should be the value set in program 1 and we can see that the in is shared between two programs



	}
	// catch all exceptions
	catch(...) {
		cout << "something happens...\n";
	}


	// remove shared memory
	shared_memory_object::remove("MySharedInteger");

	return 0;
}