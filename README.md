## json_scanner
Very simple json tokenizer, implemented as a solution to one of the exercises from: https://www3.nd.edu/~dthain/compilerbook/compilerbook.pdf.
Might evolve into parser as well in the future.

This program was developed on windows(x86-64), however doesn't include windows-specific code, and doesn't contain any other dependencies than libc.
### How to build
Windows

If being compiled from command line, you have to initialize msvc environment first, by executing:
```
\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat
```
Then, once cl.exe is brung into scope of the current shell, you can compile the code:
```
cl -Od -nologo -FC -WX -Zi ../main.c ../token.c /Fe:json_scanner.exe && json_scanner.exe ..\example.json
```
Replace the `example.json` file with your desired json file.
