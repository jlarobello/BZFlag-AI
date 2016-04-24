# BZFlag Green Team AI
<br>
Working BZFlag AI
<br> 
<br>
**Installation:**
<br>
Locate your BZFlag installation and then locate your "src" directory. Then inside of the directory, delete your current "bzflag" directory then execute the following commands.
```
git init
git remote add origin https://github.com/jlarobello/ICS462-Shootout-Green-Team.git
git fetch --prune origin
git merge --ff-only origin/master
```
<br>
Then on windows using visual studio:
  1. Do "add->existing item" in your bzflag project for these files: AStarNode.cpp/h, InfluenceMap.cpp/h, dectree.cxx/h
  2. Make sure that you have included the [yagsbpl-2.1](https://github.com/subh83/YAGSBPL) library path in your bzflag project properties/VC++ Directories/Include Directories.
  3. Rebuild the solution to avoid unexpected errors.

<br>
**A few more things:**
  1. PLEASE do not commit or merge anything into the origin and your local repositories master branch. Instead, do the pull request directly on github. This is so your code can be reviewed before being merged. 
  2. If you create your own branch to do your own developments, please make sure to include a summary in your README.md so we know what the hell you are doing.
  3. Also, don't use git pull.
  4. That's it
