//fileUltils.hpp

// John Grun jan 29 2017

#include <string>
#include <iostream>
#include <fstream>
//#include <sstream>      // std::istringstream
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <stdexcept>

std::vector<std::string> getFilesNamesInDIR(std::string dir);

std::vector<std::string> getFilesNamesInDIR(std::string dir, std::string extension);

std::vector<std::string> getFilesNamesInDIRContainingSubstring(std::string dir, std::string SubstringInFilename);

std::vector<std::string> GetVectorOfLinesInFile(std::ifstream &infile);

std::string getcwd_string( void );



