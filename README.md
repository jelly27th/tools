<p align="left">
    <a href="doc/README_CN.md">中文</a> &nbsp ｜ &nbsp English
</p>

# Tools

Tools is a personal small tool written by qt6, which has the following functions.
1. convert between hex coding and SAE coding.
2. replace substring in original string.

![](doc/images/1.png)
![](doc/images/2.png)
![](doc/images/3.png)

## How to build and package programs
1. build your configuration and run to get exe file.
2. new a folder and place exe file from step 1.
3. open qt cmd and go to current path.
> cd path
4. run command as follows.
> windeployqt tools.exe
5. use `Enigma Virtual Box` to packaged your programs.

## Usage

### convert between hex coding and SAE coding.
1. clik button `hex File` to import hex file.
2. clik button `SAE File` to import SAE file.
3. if you want to convert hex coding, click button `SAE2hex`, otherwise, click button `hex2SAE` to convert SAE coding.
> Note: hex file format and SAE file format can refer [hex.txt](doc/test/hex.txt) and [SAE.txt](doc/test/SAE.txt) in test folder.

### replace substring in original string.
1. fill original string in big blank and substring which need to replace in small blank.
2. click button `Input File` to import substring file.
3. click button `Output File` to import generate file.
4. click button `OK` to replace substring in original string and write to file.
> Note substrng file format can refer [subStrt.txt](doc/test/subStr.txt) in test folder.

## todo
- add more function.
- optimize UI interface.