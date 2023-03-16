#include <cstdlib>
#include <iostream>

int main() {
    std::string cgi_executable = "./php-cgi";
    std::string cgi_arguments = "script.php"; // Replace with any necessary arguments
    
    // Build the command to execute the CGI executable with arguments
    std::string command = cgi_executable + " " + cgi_arguments;
    
    // Execute the command using system()
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error executing command: " << command << std::endl;
        return 1;
    }
    
    return 0;
}
