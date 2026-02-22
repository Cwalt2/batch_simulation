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

        return true;
    }

     bool compileAll() { // option 4
        system("g++ -o a.out *.cpp && ./a.out\n");
        pause();


        fs::path fullPath = fs::current_path();

        std::string output = "job.out";

        std::string command =
            "g++ " + fullPath.string() + " -o " + output +
            " && ./" + output;

        system(command.c_str());

        return true;
    }

     bool shutdown() { // option 5
        cout << "shutting down...\n";
        return false;
    }

     bool listProgramOptions() { // option 6
        cout << "Listing program options\n"; // TODO: figure out what this means
        pause();
        return true;
    }

     bool help() { // option 7
        cout << "Help/Guide\n"; // TODO: Make a guide to the program
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
