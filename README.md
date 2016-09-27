# BZFlag Green Team AI
<br>
BZFlag Tank AI implementation using decision trees, A-Star path finding, and a influence map.
<br> 
<br>
**Installation:**
<br>
Developed using Visual Studio Community 2015.
<br>
Make sure to include all fixes from the [ICS-462](http://www2.hawaii.edu/~chin/462/) website.
<br>
Locate your BZFlag installation and then locate your "src" directory. Then inside of the directory, delete your current "bzflag" directory then execute the following commands.
```
git clone https://github.com/jlarobello/ICS462-Shootout-Green-Team.git
```
<br>
Then on windows using visual studio:
  1. Do "add->existing item" in your bzflag project for these files: AStarNode.cpp/h, InfluenceMap.cpp/h, dectree.cxx/h
  2. Make sure that you have included the [yagsbpl-2.1](https://github.com/subh83/YAGSBPL) library path in your bzflag project properties/VC++ Directories/Include Directories.
  3. Make sure that you have included the [pdcurses](https://sourceforge.net/projects/pdcurses/files/) library to both your include and library directories. For our project, we used pdc25_vc_w32.
  4. Build the solution.
