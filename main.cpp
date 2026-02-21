#include <iostream>
#include <list>
#include <string>
#include <filesystem>

using namespace std;

class Helpers {
    public:
    string listJobs() {
        cout << "List of Jobs:\n";
        // system("ls -al");
        system("cd ~/CLionProjects/batch_simulation/jobs/ && ls *.cpp");
        return "";
    }

    bool menuOptions() {
        string option;
        char s[100];
        cout << "Start Menu:\n";
        cout << "1. List Jobs\n2. Set jobs directory\n3. Compile and run a specific program\n4. Compile and run all jobs in a specific directory\n5. Shutdown\n6. List program options\n7. Help\n";
        cin >> option;
        if (option == "1") { // TODO: fix sigtrap exit
            listJobs();
            return true;
        }
        if (option == "2") {
            system("ls -al");
            std::filesystem::current_path("/Users/cwalt/CLionProjects/batch_simulation/jobs");
            std::cout << "New working directory: "
                      << std::filesystem::current_path() << system("ls -al") << std::endl;
            return true;
        }
        if (option == "3") {
            system("g++ dots.cpp && ./a.out\n"); // TODO: change to user input filepath
            return true;
        }
        if (option == "4") {
            system("cd jobs/ && g++ -o a.out *.cpp && ./a.out\n");
            return true;
        }
        if (option == "5") {
            cout << "shutting down...\n";
            return false; // TODO: make this more efficient through the while loop bool
        }
        if (option == "6") {
            cout << "Listing program options\n"; // TODO: figure out what this means
            return true;
        }
        if (option == "7") {
            cout << "Help/Guide\n"; // TODO: Make a guide to the program
            return true;
        }
        return false;
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
