<p align="left">
    中文 &nbsp ｜ <a href="../README.md">English</a> &nbsp 
</p>

# Tools

Tools是用qt6编写的个人小工具，具有以下功能。
1. 在十六进制编码和SAE编码之间转换。
2. 替换原始字符串中的子字符串。
3. 通过超链接启动多个程序。

![](images/1.png)

## 如何构建和打包程序
1. 构建您的配置并运行以获取exe文件。
2. 新建文件夹并放置步骤1中的exe文件。
3. 打开qt自身的命令行(cmd)并转到当前路径。 
> cd path
4. 按如下方式运行命令。
> windeployqt tools.exe
5. 使用`Enigma Virtual Box`打包您的程序。

## 如何使用


1. [在十六进制编码和SAE编码之间转换](usage/CN/hex2SAE_CN.md)
2. [替换原始字符串中的子字符串](usage/CN/stringCopy_CN.md)
3. [通过超链接启动多个程序](usage/CN/launchMultExe_CN.md)

## todo
- 添加更多功能。
- 优化UI界面。