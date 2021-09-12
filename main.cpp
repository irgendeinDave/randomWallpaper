#include <iostream>
#include <vector>
#include <time.h>
#include <filesystem>

using namespace std;
using std::filesystem::recursive_directory_iterator;

unsigned int randomBgId(std::vector<std::string> bgs);

#ifdef _WIN32
    //TODO: apply wallpaper on windows
#else
void applyWallpaper(std::vector<string> bgs)
{
    //apply random wallpaper
    string cmd = "gsettings set org.gnome.desktop.background picture-uri file://" 
        + bgs.at(randomBgId(bgs));

    system(cmd.c_str());
}
#endif


unsigned int randomBgId(std::vector<string> bgs)
{
    srand(time(NULL));
    unsigned int result = rand() % bgs.size();
    return result;
}


int main(int argc, char** argv) 
{
    string path;
    if (argc == 2)
        path = argv[1];
    else 
    {
        cout << "Please enter a valid path for your wallpapers: ";
        cin >> path;
    }

    
    //get all items in directory and all subdirectories
    std::vector<string> backgrounds;
    for (const auto & file : recursive_directory_iterator(path))
        backgrounds.push_back(file.path());

    applyWallpaper(backgrounds);
    
    return EXIT_SUCCESS;
}
