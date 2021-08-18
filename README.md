
# Description
This basic Library application was created to practice the fundimentals of C++. A user can view checkout and return three books:
- alice = Project Gutenberg: Alice in Wonderland, by Lewis Carroll (Version 2.7)
- crowd = Far from the Maddening Crowd, by Thomas Hardy (1874)
- ironheel = The Iron Heel, by Jack London (1907)

which were obtained from [textfiles.com: The Classics In ASCII](http://www.textfiles.com/etext/)

More books / files could be added but would require modifying main.cpp in its current implementation.

# Dependencies (Windows)
- Windows MSVC (downloaded [here](https://visualstudio.microsoft.com/downloads/#other) under Tools for Visual Studio -> Build Tools for Visual Studio)

# Building

```shell 
cl /EHsc src\*.cpp /I "include" /link /out:"out\main.exe" 
```

After executing the above command main.exe will be found in the \out directory. 