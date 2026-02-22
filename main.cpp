#include <iostream>
#include <list>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// helpers class to call methods
class Helpers {
    public:

     void pause() {
        system("read -n 1 -s -r -p \"Press any key to continue\"");
    }

    // uses a system call to open the project folder and list all .cpp files
     bool listJobs() { // option 1
        cout << "List of Jobs:\n";
        system("ls *.cpp"); // TODO: make OS consistent + work with any directory
        pause();
         return true;
    }

     bool setJobsDirectory() { // option 2
        string option;
        const fs::path mainDir = fs::current_path();

        cout << "Current directory is:\n" << fs::current_path() << "\n"; // batch_simulation
        cout << "Are you sure you want to change this directory?\n";
        cin >> option;

        if (option == "y") {
            cout << "Please choose a directory:" << system("ls -d */") << "\n";
            cin >> option;

            if (fs::exists(option) && fs::is_directory(option)) {
                fs::current_path(option); //setting path
            } else {
                cout << "invalid directory\n";
            }
        }
        else if (option == "n") {
            cout << "exiting option";
        }
        else {
            cout << "Unknown option: " << option << "\n" << "exiting...\n";
        }
        cout << "New working directory is: " << fs::current_path() << "\n";
       pause();
         return true;
    }

     bool compile() { // option 3
        string option;
        cout << "choose job\n";
        cin >> option;
        fs::path fullPath = fs::current_path() / option;

        std::string output = "job.out";

        std::string command = "g++ " + fullPath.string() + " -o " + output + " && ./" + output;

        system(command.c_str());

         pause();
        return true;
    }

     bool compileAll() { // option 4
         fs::path jobsPath = fs::current_path();

         if (!fs::exists(jobsPath) || !fs::is_directory(jobsPath)) {
             std::cerr << "Jobs directory not found.\n";
             return false;
         }

         for (const auto& entry : fs::directory_iterator(jobsPath)) {
             if (entry.path().extension() == ".cpp") {

                 std::string source = entry.path().string();
                 std::string out = entry.path().stem().string();

                 std::string command =
                     "g++ \"" + source + "\" -o \"" + out + "\" && ./" + out;

                 std::cout << "\nCompiling and running: " << source << "\n";

                 int result = system(command.c_str());

                 if (result != 0) {
                     std::cerr << "Error compiling/running: " << source << "\n";
                 }
             }
         }
         pause();
    }

     bool shutdown() { // option 5
         // unfortunately you have to choose twice
        cout << "shutting down...\n";
        return false;
    }

     bool listProgramOptions() { // option 6
        cout << "Listing program options\n";
         cout << "1. dots.cpp\n2.factorials.cpp\n3.printer.cpp\n4.summation.cpp\n";
        pause();
        return true;
    }

     bool help() { // option 7
        cout << "Help/Guide\n"; // TODO: Make a guide to the program
         cout << "The goal of this program is to simulate a "
                 "batch system that old operating systems/mainframes used to execute programs\n"
                 "each program simulates a small I/O delay a real batch system would have\n"
                 "File Structure Layout:\n"
                 "batch_simulation -|\n"
                 "  --jobs/\n"
                 "    -- dots.cpp\n"
                 "    -- factorials.cpp\n"
                 "    -- printer.cpp\n"
                 "    -- summation.cpp\n"
                 "Program Explanations:\n"
                 "dots.cpp prints out 50 dots with a small delay\n"
                 "factorials.cpp prints the factorials of 10 with a delay\n"
                 "printer.cpp prints out 100 #'s with a small delay\n"
                 "summation.cpp prints out the summation of 1 to 10\n";
        pause();
        return true;
    }

     bool menuOptions() {
        string option;

        cout << "Start Menu:\n";
        cout << "1. List Jobs\n2. Set jobs directory\n3. Compile and run a specific program\n4. Compile and run all jobs in a specific directory\n5. Shutdown\n6. List program options\n7. Help\n";
         cin >> option;

         if (option == "1") {
            listJobs();
        }
        if (option == "2") {
            setJobsDirectory();
        }
        if (option == "3") {
            compile();
        }
        if (option == "4") {
            compileAll();
        }
        if (option == "5") {
            shutdown();
            return false;
        }
        if (option == "6") {
            listProgramOptions();
        }
        if (option == "7") {
            help();
        }

        return true;
    }
};

int main()
{
    /* calling helper methods */
    Helpers helper;

    /* while loop boolean */
    bool loop = true;

    while (loop) {
        /* list jobs method */
        helper.menuOptions();

        loop = helper.menuOptions(); // TODO: get this to work properly
    }

    return 0;
}
