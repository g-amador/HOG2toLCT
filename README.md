# <a name="toc">Table of contents 

* [HOG2 map to LCT format converter.](#HOG2toLCT)

	* [Setup](#setup)
	* [Project Organization](#p_organization)
	* [Contact](#contact)


# <a name="HOG2toLCT">HOG2 map to LCT format converter.


This project is a converter from HOG2 maps (https://digitalcommons.du.edu/gridmaps2D/) into the LCT file format.
The LCT file format can be loaded by the Triplanner dynamic library with C/C++ API (https://www.geometricspaces.com/index.php/products/). 

[Back to Table of contents](#toc)


## <a name="setup">Setup

###### Build 

In the terminal, inside the project main folder, run:
** g++ src/HOG2toLCT.cpp -o HOG2toLCT **

###### Run

In the terminal run:
** ./HOG2toLCT "assets/HOG2/DragonAgeOrigins/map/arena2.map" "assets/HOG2/DragonAgeOrigins/map/arena2.lct **

Note: some HOG2 map files are provied in the assets folder.

[Back to Table of contents](#toc)


## <a name="p_organization">Project Organization


    .
    ├── assets                                          # HOG2 maps sample files. 
    ├── src                                             # Converter source code.
    ├── build & run.sh                                  # Linux shell script to compile and run the converter, for all maps in the assets folder.
    ├── LICENSE
    └── README.md                          

[Back to Table of contents](#toc)


## <a name="contact">Contact

If you have any questions, feel free to e-mail me at [gmail](mailto://g.n.p.amador@gmail.com) and ask away.

[Back to Table of contents](#toc)
