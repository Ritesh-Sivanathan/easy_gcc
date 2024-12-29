# Easy GCC

TODO: write tests

## About
A small program I made to easily compile and run your C programs with GCC. <br><br>
Currently, you can compile and execute your C programs in a bash terminal with one command. There are options for flags such as --sudo, which lets you run the command with elevated priviledges. You can include arguments when executing a function if the program you are running requires arguments to be passed to it.

## Usage
 
`run {flagsToEasyGCC} {fileName} {argumentsToProgram}` <br>

<b> flagsToEasyGCC </b> ==> These are the flags for the utility, _not_ for the program you are trying to compile and execute. <br>
<b> argumentsToProgram </b> ==> These are the space separated arguments and flags for the program you are trying to compile and execute. <br>

### Optional Flags

`--sudo` ==> allows you to compile and execute the program as superuser

## Installation

### Linux (Bash)
`cd /usr/local/bin` <br>
`sudo git clone https://github.com/Ritesh-Sivanathan/easy_gcc.git` <br>
`cd easy_gcc_compile` <br>
`sudo gcc run.c -o run` <br>
`sudo echo "export PATH=\"$PATH:/usr/local/bin/easy_gcc/\"" >> ~/.bashrc` <br>

(haven't tried on Windows yet so will add later)

<hr>

#### Please let me know if there are any issues or mistakes! Also, if you have the time, please provide feedback or guidance as I would really appreciate it!
