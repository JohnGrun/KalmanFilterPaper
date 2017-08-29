#include <fstream>		// fstream ofstream
#include <iostream>		//std::cout 
#include <string>		//std::String 
#include <chrono>		//time functions 
#include <fstream>      // std::ifstream
#include <sstream> 		// string stream
#include <algorithm> 	// std::sort std::binary_search
#include <tuple>

#include <functionTimer.hpp>
#include <fileUltils.hpp>
#include <KalmanFilter.hpp>


int main()
{
	
	// variables to collect data 
	std::vector<std::tuple<unsigned int,int,float>> CSVOUTPUT; // used to generate graphs from CSV data 
	std::vector<std::pair<unsigned int, unsigned long long int >> RUNNNGTIMEOUTPUT;
	functionTimer Runtimer; 
	unsigned int index = 0;


	//get file
	std::ifstream infile("./Data.txt");
	std::vector<std::string> filelines = GetVectorOfLinesInFile(infile);

	//std::cout << "About to enter for loop. E = "<< E <<  std::endl;
	for (std::string line : filelines) // add each line into the vector 
		{ // Add an edge.

			//std::cout << "i = " << i << std::endl;

			std::string buffer;
			//std::cout << "filelines.size() " <<  filelines.size() << std::endl;
			std::stringstream tokenizerStream(line);
			tokenizerStream >> buffer;
			int input = std::stoi(buffer);

			Runtimer.startTimer();
			float FilterEsatimate = KalmanFilter((float)input);
			Runtimer.stopTimer();

			//store data to compare raw vs kalman filted data 
			CSVOUTPUT.push_back(std::make_tuple(index, input, FilterEsatimate));
			// get the running time for the filter for each pass. 
			RUNNNGTIMEOUTPUT.push_back(std::make_pair(index, Runtimer.getRunTimeInNanoSeconds()));
			index = index + 1;
		}


		//create output file for Raw Vs Kalman filtered data
		std::ofstream outfile("KALMAN_INPUT_VS_OUTPUT.csv"); // this is a comma seperated value format for N vs time 
		outfile << "Sample Number,Raw Measurement, Kalman Filtered" << std::endl;

		for( std::tuple<unsigned int,int,float> Temp  : CSVOUTPUT )
		{
			std::stringstream lineOne;
			lineOne << std::get<0>(Temp);
			lineOne << " ,"; 
			lineOne << std::get<1>(Temp);
			lineOne << " ,";
			lineOne << std::get<2>(Temp);
			std::string temp2(lineOne.str());
			outfile << temp2;
			outfile << std::endl;
		}
		
		//create output file for input size vs running time
		std::ofstream outfileRunTime("KALMAN_FILTER_RUNNING_TIME_VS_INPUT_SIZE.csv"); // this is a comma seperated value format for N vs time 
		outfileRunTime << "Sample Number, Running Time per function call" << std::endl;

		for( std::pair<unsigned int, unsigned int> Temp  : RUNNNGTIMEOUTPUT )
		{
			std::stringstream lineOne;
			lineOne << std::get<0>(Temp);
			lineOne << " ,"; 
			lineOne << std::get<1>(Temp);
			std::string temp2(lineOne.str());
			outfileRunTime << temp2;
			outfileRunTime << std::endl;
		}

}// end of files for loop
