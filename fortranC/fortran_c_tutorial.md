# Tutorial on compiled languages: Fortran & C++

**Author: Charlotte Elster (Fortran) & Christian Drischler (C++)**

## What is Fortran?

`Fortran`, short for `Formula Translator`, was the first widely used upper-level programming language
and originated in the 1950s. Despite its age, it remains a high-performance computing language
and can be faster than both, C and C++.

Initially designed for scientists and engineers to run large-scale models and simulations in
areas such as fluid dynamics and organic chemistry, Fortran is still frequently used today by
physicists.
Its specialty lies in modeling and simulations, which are essential for numerous fields, including
Machine Learning. Thus, Fortran is perfectly poised to tackle Data Science problems, as it was invented
to do decades ago, and it is worthwhile for today's Data Scientists to be aware of it.

One of the reasons Fortran is still in use is longevity. It is much easier to build on something
that was originally developed in Fortran (which is backward compatible), rather than starting from
scratch. Some people make starting from scratch so easy, but many re-engineering projects got stuck due
to a failure to understand how the original software worked. And who wants to spend a lot of time
redoing codes -- one would not get to something new before the project time is used up.
Fortran is also exceptionally good at doing math, and e.g. climate models are nothing if not all about
crunching data and doing math.

Sure, there are challenges - but find me a language that does not have some challenges.

## Fortran was built around a performance-centric culture

For rather self-explanatory reasons, performance has been the top priority of the high-performance
computing community.
The development of Fortran historically had optimization as the main focus. This often meant that, in
order to give the compiler the best possible chances of aggressively optimizing code, the language
imposed many restrictions on the programmer.
Simply put, they made it very hard to write slow code in Fortran, while in other languages, even
including C, you have the freedom to do things that would lead to slow code.

It should be noted that it took some time for C/C++ compilers to catch up with the speed that the
Fortran compilers had enjoyed historically, thanks to the straightforward restriction-based approach
they had put forth since the beginning. For example, the C99 standard introduced restricted pointers,
which enable better optimization by the compiler.

Over the years, compiler theory and practice improved, and compilers got better at optimizing all sorts
of code. Consequently, both in Fortran and in other languages, the focus has been shifting towards
adding features that would enhance the programmer's productivity.

As example, in 2014, 16 well known climate models were analyzed. They were all written in Fortran.
Why do they still use Fortran?

 - **Performance**: Fortran is fast, in cases faster than C, and e.g. climate modeling like much of
                 scientific computing is all about speed.

 - **Parallelism**: Performance necessitates parallelism, and Fortran implemented this long before other languages.

 - **Reuse**: Backward compatibility means that exisiting libraries can easily be reused.

 - **Arrays**: Fortran supports multi-dimensional arrays, slicing, reduction, reshaping, and many
                 optimization for array based calculations like vectorization

 - **Longevity**: Models in e.g. Climate science, Fluid Dynamics and similar should not be implemented
                 in languageas that (i) are not backward compatible, and (ii) always change. If you
                 write a code in Fortran today, it is still likely to work in 20 years.

 - **Effort**: Can you imagine how much effort would be involved in re-engineering complex models?
                 New languages may be problematic in that respect.

 - **MPI**: The [Message Passing Interface](https://en.wikipedia.org/wiki/Message_Passing_Interface) (MPI) is a gateway to high-performance computing, and Fortran handles it well.


Fortran was designed for scientific computing. Sure, Fortran is old, but so is Unix, and C as well.

## First Fortran Code

Let's first install [GNU Fortran](https://gcc.gnu.org/fortran/). On Ubuntu, this can be done with the following command:
```shell
sudo apt-get install gfortran
```

Now, let us learn about
 - the Fortran language 
 - how to run a Fortran code once it is written

Download the tar-file `simplef.tar` to a practice directory (e.g., `Fpractice`) in which you want to work with your Fortran codes. For instance:
```bash
mkdir Fpractice && cd $_
wget https://github.com/cdrischler/compphysics-summer-tutorials23/blob/main/fortranC/simplef.tar 
```

> **Tip**
> If you have cloned the `git` repository, then you don't need to download the file. It's already in your folder tree.

Unpack the file via
```shell
tar -xvf simplef.tar
```
and you should see three files with the ending `.f90`.
Those are your first practice codes.

*Remark on suffixes:* the suffix `.f90` is the accepted standard for all Fortran codes using the `free
source form`. Though there are different Fortran standards, like `.f90`, `.f95`, `.f03`, `.f08` and so
on, that indicate which ANSI-standard of Fortran version is used, the suffix `.f90` means that the
source code is in free format, not that the code conforms to the Fortran 90 standard. Code that uses the
`.f90` suffix can use features from all Fortran standards. 

All Fortran compilers recognize `.f90` as suffix indicating free source form, but some may not recognize
a suffix as `.f95`, `.f03`, or `.f18`. 

Open `hello.f90` in your favorite editor.

```Fortran
      program Hello
```
This is a main program and should have name - best the name for the file `hello.f90`

A text comment in your code needs to start with `!` as first character. A good habit is to comment your code extensively (for yourself and others)   `.f90` uses free source form, which means you can start you code line wherever you like. My personal preference is still (like in `.f77`) to start at position 7, since this leads in my opinion to a more esthetic layout of the code and makes it easier to read
```Fortran
!       with good Fortran programming habits
!
      implicit none
```
This statement means that **all** variables must be declared. 
It is very useful to immediately detect while compiling if you e.g. mistyped a variable.
```Fortran
!       declare variables
      real ::  first, second, average

!       default input and output
      integer ::  kread=5, kwrite=6
```
 Variables must be declared at the beginning of your code. Fortran has as basic variables `real`, `complex`, `logical`, and `character`.
```Fortran
!       default input and output
!      data kread/5/, kwrite/6/
```
There are **two** default units associated with executing a Fortran code:
5 for reading input (from file or screen), 6 for writing to a file or screen.
I put 2 different ways into the code how to assign variables.  
```Fortran
!        
!        talk to the computer
!
      write (kwrite,*) 'Hello, world'
```
Here `Hello, world` is written to unit 6, possibly your screen.
The `*` means that the output is unformatted.
```Fortran
      write (kwrite,*) 'Input first variable:'
      read (kread,*) first
      write (kwrite,*) 'first variable:', first


      write (kwrite,*) 'Input second variable:'
      read (kread,*) second
      write (kwrite,*) 'second variable:', second

      average = (first+second)*0.5

      write (kwrite,*) 'average of first and second variable is:', average

      stop 
      end 
```
 
 I was a bit sloppy with the ending. You could write `end program Hello`
 the command `stop` stops all execution, and `end` ends everything, in this case the program Hello.
 So me being sloppy does not matter.

## Executing your first code

Before you can execute or run your code, you must `compile` it, which means you must translate it into
machine language. This is done with a `compiler`. There are different compilers on the market. We are using the `GNU` compiler `gfortran`, which is free and installed in your UNIX setup. 

The simplest way to compile is with the command

```shell
gfortran hello.f90
```
which will produce a file `a.out` in the directory you compile in.  *Check it out!* 

This is the *executable* which your computer can run.

**However**, gfortran used this way will always create a file `a.out`. What if you want to have two executables
in one directory? 
It is better to name the executable with some recognizable name.
If you want your executables having specific names, compile with

```shell
gfortran -o hello hello.f90
```
where the executable is now called hello.  *Check it out!* 

The executable is executed by  the command 
```shell
./hello
``` 

<font color="red">**Exercise:**  </font> <br>
* Add another line to the code to personalize the hello to your name.<br>
* Modify the code so that it calculates the average of three numbers.

**Remark:**  The command `gfortran` executes two separate tasks:
-- The first is translating your Fortran code into machine languages, and a file `hello.o`, the object file is created
-- The second is to link machine libraries from you computer to create the executable.

If you only want to compile, e.g. to see if you have syntax errors in your code, you can do this with
the command 
```shell
gfortran -c hello.f
```
The `-c` is called a flag for gfortran.  There will be more about flags later.

## Simple Makefile for program `hello.f`

Instead of typing the previous commands into a command line, one can execute a so-called `Makefile`. 
A file called `Makefile` tells the `make` program package in a structured manner which source and object
file depend on other files. It also defines the commands required to compile and link the files.

Here is a simple `Makefile` to create the executable for the program `hello.f90`

```Make
FFOPTS = -c 
.SUFFIXES: .o .f90

OBJS   = hello.o

hello : $(OBJS)
	gfortran -o hello $(OBJS)

hello.o : hello.f90
	gfortran $(FFOPTS) hello.f90

```
The top part of this `makefile` contains definitions, e.g. the compiler option is `-c`. Then the suffixes that are used in the execution are given, `.o` and `.f90`, and last the object file `hello.o` 

The bottom part of the `makefile` is executed from the bottom up and the sequence is given as
to be created: object `hello.o` and this is created from `hello.f90` 
the command how to create is given in the line below as `gfortran $(FFOPTS) hello.f90`.   The `FFOPTS` is a placeholder for the options defined in the top part.
After `hello.o` is created, the next directive in the `makefile` is to create the executable `hello` from the object files listed under `OBJS`, and the command to do this is `gfortran -o hello $(OBJS)`.  
Have in mind, that the indentations are `tabs` and the `make` environment is quite picky about this.

You execute the makefile in your directory with 
```shell
make -f make.hello
```
where the option `-f` points to the filename you give. 

With such a setup you can have several `makefiles` with different names for different codes. 
You can also compile a bunch of codes with their own object files, which the last command then links together to create the executable.          

## Second Fortran code 

With this code we want to check out numerical precision in computations, here specifically addition of
small numbers.

```Fortran
      program precision 
!
!       check out double precision arithmetic vs. singe precision
!
      implicit none

      real :: x
      double precision :: y
```
Real refers to a single precision number,  while double precision to a double precision number. The current preferred way is to specify this as `real(kind=dp)`.
To be even more precise, one can guarantee precision to that of the machine-compiler-specific double precision real using the *kind* function to get the kind of `1.d0`: 
`integer, parameter :: dp = kind(1.d0)` and then specify `real (dp) :: something`.
```
      integer :: i

      integer :: kread=5, kwrite=6

!
      x=1.
      y=1.d0
```
A single precision number is given by `1.` and a double precision by `1.d0`
Next, a do-loop is executed $10^6$ times adding a small number to `1.` or `1.d0`.
```Fortran
      do i=1,1000000
        x = x + 0.000001
        y = y + 0.000001d0
      end do

      write (kwrite,*) 'Which number is closer to two?'
      write (kwrite,*) '  x = ',x
      write (kwrite,*) '  y = ',y
     
      stop 
      end 
```

Run the code and get the answer. Are you surprised? 


<font color="red">**Exercise:**  </font> <br>
Look at the third code in the tar-file, `precisionm.f90`, and either look at it first and try to figure out
what the code is supposed to do, then run it, or run it first and then look at the code

Your course on Computational Physics should go into the representation of numbers on the computer in
more depth. You have to remember, that the most elementary units of the computer memory are the two
*bits* (binary integers) `0` and `1`. This means that all numbers are stored in memory in *binary* form,
that is, as long strings of zeroes and ones. This would be awkward to look at for people. Consequently,
binary strings are converted to *octal*, *decimal*, or *hexadecimal* numbers before results are
communicated to people. While *octal* and *hexadecimal* are nice since their conversion does not loose
precision, the for us most useful *decimal* numbers leads to a decrease in precision, unless the number
is a power of 2. 

## First computational problem: Summing Series.

A classic numerical problem is the summation of a series to evaluate a function. Let us consider
the power series

$$ e^{-x} = 1 - x + \frac{x^2}{2!} - \frac{x^3}{3!} + \cdots $$ 

which is **exact** when summed up to all orders.

While an infinite series is exact in a mathematical sense, to use it as an **algorithm**, we must stop the
sum at some point, so that the algorithm reads

$$ e^{-x} \simeq \sum_{n=0}^{N} \frac{(-x)^n}{n!} $$

How do we decide to stop? 

Before thinking about that we need to write a code for the summation. 

<font color="red">**Exercise:**  </font> <br>
Take 5 minutes to think about how you would code this problem. Do **not** get stuck by thinking about 
specific Fortran commands, rather think in terms of `Pseude-code`, where you just write down the steps
and manipulations you need to eventually code. And think about what you will need to define in order to
the the equation steps into a code.

Obviously, there are most of the time more than one way to manipulate and code a mathematical problem
into an algorithm, and then to implement this algorithm into a code.

Such implementations can be either clever or not so clever, fast or slow, or some can be more efficient
than others. 

Do not be disheartened by such a comment, writing good codes is something everybody needs to learn. Your
course in computational physics will hopefully give a start on this. Truthfully, writing efficient and
good code is a life long journey of any computational physicist. 

Now, let us look at two implementations of an algorithm to compute $e^{-x}$ as series. 
There are two codes in the directory:
- `exp-good.f90`
- `exp-bad.f90` 

Download both codes to your practice directory. Though both give you the same answer to the printed precision, one is better than the other.

<font color="red">**Exercise and Homework:**  </font> <br>
- Understand how both codes implement the series algorithm.
- Convince yourself as well as the TA why one is better than the other.


## C++ programming languages

`C++` is very popular compiled pgramming language in both industry and academia. It is used to develop high-performance applications, operating systems, games, and many more.
Having "C with classes" in mind, `C++` was developed by Bjarne Stroustrup as an extension of the `C` language. It gives a high level of control over system resources and memory.

Why should you learn `C++` in 2023? Because it is:
* one of the [most used and popular](https://www.tiobe.com/tiobe-index/) programming languages.
* an object-oriented programming (OOP) language that, like any OOP language, gives a clear structure to programs and allows code to be reused.
* similar in syntax to other languages such as `C` and `Java`.
* And many more!

> **Question**  
> What is the most popular programming language according to the TIOBE index? 
> Do you agree?   
> Where is Fortran?  

There are many powerful libraries for scientific computing. Some of the frequently used ones are:
* [GNU Scientific Library (GSL)](https://www.gnu.org/software/gsl/): numerous mathematical routines such as random number generators, special functions and least-squares fitting
* [Boost Libraries](https://www.boost.org/): provides free peer-reviewed portable C++ source libraries
* [Cubature](https://github.com/stevengj/cubature): multi-dimensional adaptive integration (cubature) in C 
* and many more!

> **Question**  
> How would you quickly implement Clebsch-Gordan coefficients in `C++`?


### First C program

Below is a simple `C` program to display "Hello World". 

```CPP
// Header file for input output functions
#include <iostream>
using namespace std;
 
// Main() function: where the execution of program begins
int main() {
    cout << "Hello World" << endl;  // print the string and ends the line
    return 0;
}
```
Notice the semicola and curly braces! Just copy the code snippet to a new file, e.g., `HelloWorld.cpp` in your current folder. Let's compile and run it:
```shell
g++ -o helloworld HelloWorld.cpp
./helloworld  # what output do you expect?
```

Let's break the simple code down, line by line:

```CPP
// Header file for input output functions
```
Comments are used to display additional information about the program. Any line beginning with `//` or blocks between `/*...*/` in `C++` is considered a comment. Comments will be ignored by compilers.

```CPP
#include <iostream>
```
Lines beginning with `#` are called directives. They are processed by the preprocessor during compilation. The `include` directive tells the preprocessor to include the content of the specified file in-place. In this case, the standard `iostream` file, containing declarations of all the standard input/output library functions. This line is needed to used `std::cout` and `std::endl` in the body of the `main` function (see below).
```CPP
using namespace std;
```
This line imports the entire standard (`std`) namespace into the current namespace of the program, which is typically considered a bad practice because it pulls numerous type definitions into the current scope. Note that the `std` namespace is huge. On the other hand, good practice is to specify the namespace to which the identifier belongs using the scope operator (`::`) when a type is declared; e.g., `std::cout` and `std::endl`.
```cpp
int main() {...}
```
`C++` programs begin with a `main()` function. The location does not matter but it has to be somewhere. It returns an integer (`int`). A function is a group of statements designed to perform a specific task. 


Opening braces `{` indicates the beginning of a block such as the `main` function or any other function, and the closing braces `}` indicates the ending. Code in between is refered to as the body of the `main` function.

```c
cout << "Hello World" << endl;  // print the string and ends the line
```
This statement prints “Hello World” on the screen. Semi-colons `;` end every statement (i.e., end of the line of code). There may be more than one statement per line. `std::cout` is used to identify the standard character output device, usually the screen. The string after the operator `<<` is displayed on the output device, and ``<< endl`` ends the line, so that the next print statement will begin in the next line.

The indentation is very helpful to keep source codes readable. But unlike Python indentation is not required.

```CPP
return 0;
```
This `return` statement ends the `main` function (or any other function). While in general this statement is used to return the "value" of the function (unless it's `void`), in this case `return` returns the status (`0` if successful or `1` if failed) of the program executation to the operating system.


### Series summation revisted

Now, knowing the absolute basic in `C++`, let's revisit the series summations we studied in Fortran. We have corresponding source code written in C++: [exp-good.cpp](exp-good.cpp) and [exp-bad.cpp](exp-bad.cpp). You can compile them using  
```shell
g++ -O3 exp-good.cpp -o cgood
g++ -03 exp-bad.cpp -o cbad
```
where we have enabled optimization at compile time (`-O3`).

**Exercise:**
Compare the Fortran and `C++` source codes line by line. Try to understand similarities and dissimilarities (after all they compute the same exponential function). You may modify the code and compile to experiment. Don't be afraid of compile errors. Answer the following questions:
* What is `cmath` and `iomanip` needed for?
* What does the `const` keyword do? Why is it used? When could it be useful?
* What is `double x[max]`?
* What does `setw(20)` do?
* Explain briefly how the data files are generated.

### Further reading

The following resources will help you become more literate in C++ and C:
* https://www.geeksforgeeks.org/cpp-tutorial/  
* https://www.w3schools.com/cpp/  
* https://www.tutorialspoint.com/cplusplus/index.htm  
* https://www.geeksforgeeks.org/c-programming-language/?ref=lbp (tutorial on C)
