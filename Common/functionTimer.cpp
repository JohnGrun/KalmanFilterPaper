/// timing.hpp
#include <functionTimer.hpp>

 	functionTimer::functionTimer()
 	{ // default constructor 

 	}


 	functionTimer::~functionTimer()
 	{ // default constructor 

 	}

	void functionTimer::startTimer()
	{
		start = Clock::now();
	}

	void functionTimer::stopTimer()
	{
		end = Clock::now();
	}

	unsigned long long int functionTimer::getRunTimeInNanoSeconds()
	{

	 	nanoseconds diff = duration_cast<nanoseconds>(end - start);
		//std::cout << diff.count() << "ns" << std::endl;
		return (unsigned long long int) diff.count();; // cast to an unsigned int

	}




