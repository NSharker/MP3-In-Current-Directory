#include <iostream>
#include <vector>
#include <string>
#include <fstream> // text file openings
#include <dirent.h>
#include <cstdlib>

using namespace std;




int main(){

    //open file 1 = filename
    ofstream fileSongName;
    fileSongName.open("songnames.txt");



    //Keeps a list of all the music files in the directory
    vector <string> dirList;

    //
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (".")) != NULL) {
      /* store all the files and directories within directory */
      while ((ent = readdir (dir)) != NULL) {
        //printf ("%s\n", ent->d_name);
        string fname;
        fname = ent->d_name;
        int strlength = fname.length();

        //Check for filename to be longer than 3
        //there are files called . and .. that we should skip
        //if the file is a .mp3 we add it to music file vector, dirList
        if (strlength > 3)
        {
            string fileType;
            fileType = fname.substr(strlength-3,3);
            if (fileType == "mp3")
            {
                dirList.push_back(fname);
            }

        }


      }
      closedir (dir);
    } else {
      /* could not open directory */
      perror ("");
      return EXIT_FAILURE;
    }


    for (int i = 0; i < dirList.size(); i++)
    {
        fileSongName << dirList[i] << endl;
    }

	return 0;

}
