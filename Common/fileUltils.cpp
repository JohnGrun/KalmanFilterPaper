//fileUltils.hpp

// John Grun jan 29 2017

#include <fileUltils.hpp>

/*function... might want it in some class?*/
 std::vector<std::string> getFilesNamesInDIR(std::string dir)
{
    std::vector<std::string> files;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL)
    {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        throw std::runtime_error("Error opening directory ");
        //return errno;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        files.push_back(std::string(dirp->d_name));
    }
    closedir(dp);
    return files;
}

 std::vector<std::string> getFilesNamesInDIR(std::string dir, std::string extension)
{
    std::vector<std::string> files;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL)
    {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        throw std::runtime_error("Error opening directory ");
        //return errno;
    }

    extension = "." + extension;

    std::cout << extension << std::endl;

    while ((dirp = readdir(dp)) != NULL)
    {

        std::string Filename = std::string(dirp->d_name);

        if(Filename.find(extension) != std::string::npos)
        { // returns a vector of files with the given extension..
            files.push_back(Filename);
        }
    }
    closedir(dp);
    return files;
}

std::vector<std::string> getFilesNamesInDIRContainingSubstring(std::string dir, std::string SubstringInFilename)
{
    std::vector<std::string> files;
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL)
    {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        throw std::runtime_error("Error opening directory ");
        //return errno;
    }

    //extension = "." + extension;

    std::cout << SubstringInFilename << std::endl;

    while ((dirp = readdir(dp)) != NULL)
    {

        std::string Filename = std::string(dirp->d_name);

        if(Filename.find(SubstringInFilename) != std::string::npos)
        { // returns a vector of files with the given extension..
            files.push_back(Filename);
        }
    }
    closedir(dp);
    return files;
}

std::string getcwd_string( void )
{
        char buff[PATH_MAX];
        getcwd( buff, PATH_MAX );
        std::string cwd( buff );
    return cwd;
}


	/// read inputs from file 

	// yes I love vectors 
	
std::vector<std::string> GetVectorOfLinesInFile(std::ifstream &infile)
{ // load each line in the file into a vector index returns the vector 

	std::vector<std::string> inputFileLines; // store each line as a seperate entry in a vector 
	
	std::string line;
	while (std::getline(infile, line))
	{	
	// 		// yup no error could ever happen here.... 
	 	    inputFileLines.push_back(line); // this should just use std:move to create the object in the vector
		    
	 }

	// 	// return the vector 
	 	return inputFileLines;
}
