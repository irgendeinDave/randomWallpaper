#include <iostream>
#include <vector>
#include <time.h>
#include <filesystem>

using namespace std;
using std::filesystem::recursive_directory_iterator;

unsigned int randomBgId(std::vector<string> bgs)
{
    srand(time(NULL));
    unsigned int result = rand() % bgs.size();
    return result;
}

int main(int argc, char** argv) {
    string path = argv[1];
    
    //get all items in directory and all subdirectories
    std::vector<string> backgrounds;
    for (const auto & file : recursive_directory_iterator(path))
        backgrounds.push_back(file.path());


    //apply random wallpaper
    string cmd = "gsettings set org.gnome.desktop.background picture-uri file://" 
        + backgrounds.at(randomBgId(backgrounds));

    system(cmd.c_str());
    
    return EXIT_SUCCESS;
}
