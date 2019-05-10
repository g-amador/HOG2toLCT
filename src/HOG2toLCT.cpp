// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main (int argc, char *argv[]) {
  if (argc < 3) {
    cout << "Insufficient number of arguments!!!\n";
    cout << "Usage: HOG2toLCT HOG2MAP.MAP TRIPLANNERMAP.LCT\n";
    return -1;
  }

  cout << "Converting '" << argv[1] << "' to triplaner map format!\n";

  ofstream outFile (argv[2]);
  if (outFile.is_open())
  {
    outFile << "# Triplanner 0.0.1 Copyright (c) 2017-2019 Geometric Spaces Inc.\n\n";
    outFile << "LCT\n\n";
    

    //outFile << "# polygons: ?\n\n";
    //outFile << "epsilon 0.01\n\n";
    //outFile << "expansion 0.02\n\n";
    //outFile << "domain\n";

    ostringstream polygons;
    string line;
    ifstream inFile (argv[1]);
    if (inFile.is_open())
    {
      int height, width, p = 1; 
      for (unsigned l = 0, i = 0; getline (inFile,line); l++)
      {
        if (l == 1) {
          istringstream iss (line.substr(7,line.length()));
          iss >> height;
          //cout << height << '\n';
        }
        if (l == 2) {
          istringstream iss (line.substr(6,line.length()));
          iss >> width;
          //cout << width << '\n';
        }
        if (l > 3) {
          //cout << line << '\n';
          for (unsigned j = 0; j < line.length(); ++j) {
            //. - passable terrain
            //G - passable terrain
            //@ - out of bounds
            //O - out of bounds
            //T - trees (unpassable)
            //S - swamp (passable from regular terrain)
            //W - water (traversable, but not passable from terrain)
            if (line.at(j) == '@' 
                || line.at(j) == 'O' || line.at(j) == 'o' 
                || line.at(j) == 'T' || line.at(j) == 't' 
                || line.at(j) == 'W' || line.at(j) == 'w') {
                polygons << "polygon " << p << "\n";
                polygons << "" << j << " " << (height - 1 - i) << " " 
                    << j + 1 << " " << (height - 1 - i) << " " 
                    << j + 1 << " " << height - i << " " 
                    << j << " " << height - i << ";\n\n";
                p++;                
                //cout << line.at(j);  
                //cout << "bla bla bla";
            }
          }
          i++;  
        } 
      }

      outFile << "# polygons: " << (p - 1) << "\n\n";
      outFile << "epsilon 0.01\n\n";
      outFile << "expansion 0.02\n\n";
      outFile << "domain\n" 
            << "0.0 0.0 " 
            << width << " 0.0 " 
            << width << " " << height 
            << " 0.0 " << height << ";\n\n";;      
      outFile << polygons.str();        
      inFile.close();
    }
    else cout << "Unable to open inFile"; 
    outFile.close();
  }
  else cout << "Unable to open outFile";

  cout << "Conversion finished successfully\n";

  return 0;
}
