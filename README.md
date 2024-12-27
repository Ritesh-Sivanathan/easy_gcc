# Easy GCC

## About
A small program I made to easily compile and run your C programs with GCC. <br>

As of the time writing this program, I had been learning C for just under 5 days. I created this program as I was tired of running the tedious `gcc {file} -o {output}` and then `./{output}` and I wanted to challenge myself by trying to write a program that could do this for me. <br>

I used some tutorials on how to create basic CLI utilities with C and pieced them together to make this. <br>
I learnt a few new functions like system, snprintf, and fprintf. Overall a good learning experience <br>

## Usage

I haven't learned how to make this process user friendly so please excuse the overcomplicated installation.

### Linux (Bash)
`cd /usr/local/bin` <br>
`sudo git clone https://github.com/Ritesh-Sivanathan/easy_gcc.git` <br>
`cd easy_gcc_compile` <br>
`sudo gcc run.c -o run` <br>
`sudo echo "export PATH=\"$PATH:/usr/local/bin/easy_gcc/\"" >> ~/.bashrc` <br>

(haven't tried on Windows yet so will add later)

## Please let me know if there are any issues or mistakes! Also, if you have the time, please provide feedback or guidance as I would really appreciate it!
