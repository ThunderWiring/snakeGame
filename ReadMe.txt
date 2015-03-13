========================================================================
    CONSOLE APPLICATION : SnakeGame Project Overview
	* created on 8 March 2015
	* Author: bassam yassin
	* website: ThunderWiring.WordPress.com
	* email: bassam.yasin@gmail.com
========================================================================
3 files that i had  written:
1)SnakeGame.cpp: this one has the main() function for driving the whole game thing..

2)grid.h: this header handles the board of the game: has the data-structure for the board
and other functions to handle this structure
3)utilities.h: includes classes for snake and the board and another class
to handle the movement of the objects(i.e the snake)
this is the design i came up with since last few days when i started..
it might not be the best(or the worst) but you can change it how you wish or continue from there.

also, if you notice, i followed some strict rules in my coding:
like naming the parameters and documenting style and *line length!*..

and if you are not using Visual Studio, remove the "#pragma region" and "#pragma endregion" 
lines wherever they are being used, so that the code would compile..
========================================================================
AppWizard has created this SnakeGame application for you.

This file contains a summary of what you will find in each of the files that
make up your SnakeGame application.


SnakeGame.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

SnakeGame.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

SnakeGame.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named SnakeGame.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
