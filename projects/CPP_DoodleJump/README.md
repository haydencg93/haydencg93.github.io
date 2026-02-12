# DoodleJump
The original code came from  
FamTrinli Published on Apr 26, 2016  
https://www.youtube.com/watch?v=7Vf_vQIUk5Q.
Download source: https://drive.google.com/uc?export=do...
Category Education  
License Standard YouTube License  

Follow the instructions below to compile and run the DoodleJump game.
1.	Start CLion in the VDI.
2.	If you have not been using VDI, create a folder to save your full SVN directory (e.g., H:\cie).
3.	Checkout your full SVN directory using CLion on the VDI. (https://class-svn.engineering.uiowa.edu/cie/projects/fall19)
4.	Load CMakeLists.txt
5.	Select the DoodleJump | Debug in the dialog box next to the green triangle if necessary.
6.	Compile the DoodleJump program by clicking on the green triangle.  You should get the following error.
Process finished with exit code -1073741515 (0xC0000135)
7.	Once the file is built, the current CMakeLists.txt does not copy the needed .dll files to the build directory.
You must add two directories to the PATH in the project debug environment in order to make it work. 
Click on the down arrow next to the project debug button, then choose “Edit Configurations”. 
In the resulting dialog box click on the folder icon next to Environment variables. In the resulting dialog box
click on the plus sign and add a variable named PATH with a value of
"%PATH%;C:\Program Files\SFML-2.6.0\bin;C:\Program Files\mingw64\x86_64-w64-mingw32\bin"
without the quotes. This will allow the compiled DoodleJump.exe to find the .dll files when you click on run. Click OK.
