/// timing.hpp
#ifndef FUNCTIONTIMER_HPP_
#define FUNCTIONTIMER_HPP_

#include <chrono>		//time functions 
/// timing 

using Clock = std::chrono::steady_clock;
using std::chrono::time_point;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using namespace std::literals::chrono_literals;

class functionTimer
{

	public:
		/** @brief Default constructor. basically does nothing*/
	 	functionTimer();

	 	/** @brief It would be nice if JAVA had this*/
	 	~functionTimer();

	 	/** @brief Start the clock. cCall right prior to function execution*/
		void startTimer();

		/** @brief Stop the clock call right after function execution*/
		void stopTimer();

		/** @brief Get the time difference(excution time) in nanoseconds*/
		unsigned long long int getRunTimeInNanoSeconds();
	
	private:
		/** @brief Start time */
		time_point<Clock> start;

		/** @brief End time */
 		time_point<Clock> end;

};

#endif