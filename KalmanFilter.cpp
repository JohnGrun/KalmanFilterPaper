#include <KalmanFilter.hpp>

float estimate_variance = 100;
const float SensorVariance = 0.02; //chech data sheet of sensor * the ADC variance  see FSR data sheet
float estimate = 950.0;
float WeightVariance = 0.9;
float GAIN = 0.8;

// float KalmanFilter(float measurement)
// {

// 	// normal variance of the measured phenomenon
// 	std::cout << "Measurement: " << measurement << std::endl;
// 	float WeightVariance = estimate_variance; // estimate from last run; // I really hope the real weight isn't changinging a detectable amount. That would be bad

// 	std::cout << "WeightVariance: " << WeightVariance << std::endl;
// 	//gk=pk−1/(pk−1+r)
// 	float GAIN = WeightVariance / (WeightVariance + SensorVariance);
	
// 	//pk=(1−gk)pk−1
// 	//WeightVariance = (1-GAIN)* WeightVariance;
	

// 	std::cout << "estimate: " << estimate << std::endl;

// 		//x̂k=x̂k−1+gk(zk−x̂ k−1)
// 	// zk=xk+vk zK = measurement
// 	estimate = (1-GAIN)*estimate + GAIN*measurement;

// 	//estimate = estimate + GAIN * (measurement - estimate)

// 	estimate_variance = (WeightVariance*SensorVariance) / (WeightVariance + SensorVariance);
	
//  	std::cout << "Estimate: " << estimate << std::endl;

//  	return estimate;
// }

float KalmanFilter(float measurement)
{

//PREDICT

	// SINCE WE ARE STATIC. time UNCHANGING, NO CONTROL INPUTS, SINGLE VARIABLE 

	//This is where your predict equation would exists
	// in our case we assume that a weight sensor does not vary e.g. a scale should reach equaliliberm 
	//thus the last estimate should equal the next estimate
	//x̂k=ax̂ k−1
	estimate = estimate;
	//pk=apk−1a
	WeightVariance = WeightVariance;

//UPDATE:

	std::cout << "Measurement: " << measurement << std::endl;
	std::cout << "WeightVariance: " << WeightVariance << std::endl;

	//gk=pk−1/(pk−1+r)
	GAIN = WeightVariance / (WeightVariance + SensorVariance);
	std::cout << "GAIN: " << GAIN << std::endl;
	//x̂k=x̂k+gk(zk−x̂k)
	estimate = estimate + (GAIN * (measurement - estimate));

	//pk=(1−gk)pk−1
	WeightVariance = (1-GAIN)* WeightVariance;

	 std::cout << "Estimate: " << estimate << std::endl;

 	return estimate;
}