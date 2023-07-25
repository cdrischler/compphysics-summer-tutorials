# Tutorial on compiled languages: Fortran & C/C++

**Author: Charlotte Elster**

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
>>  this is a main program and should have name - best the name for the file `hello.f90`

>> a text comment in your code needs to start with `!` as first character.
>> a good habit is to comment your code extensively (for yourself and others)  
>> `.f90` uses free source form, which means you can start you code line wherever you like.
>>  My personal preference is still (like in `.f77`) to start at position 7, since this leads in my opinion
>>   to a more esthetic layout of the code and makes it easier to read

!       with good Fortran programming habits
!
      implicit none

>>  this statement means that **all** variables must be declared. 
>>  it is very useful to immediately detect while compiling if you e.g. mistyped a variable.

!       declare variables
      real ::  first, second, average

!       default input and output
      integer ::  kread=5, kwrite=6

>>  Variables must be declared at the beginning of your code. Fortran has as basic variables
>>  `real`, `complex``, `logical`, `character`. 

!       default input and output
!      data kread/5/, kwrite/6/

>>  There are **two** default units associated with executing a Fortran code:
>>  5 for reading input (from file or screen), 6 for writing to a file or screen
>>  I put 2 different ways into the code how to assign variables.  

!        
!        talk to the computer
!
      write (kwrite,*) 'Hello, world'

>>  here `Hello, world` is written to unit 6, possibly your screen.
>>  the `*` means that the output is unformatted.

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
machine language. This is done with a `compiler`. There are different compilers on the market. We are
using the `GNU` compiler `gfortran`, which is free and installed in your UNIX setup. 

> **Tip**
> If needed, you can install `gfortran` using:
> ```shell
> sudo apt-get install gcc
> ```

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
where the executable is not called hello.  *Check it out!* 

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

## Simple Makefile for program hello.f

Instead of typing the previous commands into a command line, one can execute a so-called `Makefile`. 
A file called `Makefile` tells the `make` program package in a structured manner which source and object
file depend on other files. It also defines the commands required to compile and link the files.

Here is a simple `Makefile` to create the executable for the program `hello.f90`

```Fortran
FFOPTS = -c 
.SUFFIXES: .o .f90

OBJS   = hello.o

#-----------------------------------------------------------------------------------

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

>> real refers to a single precision number,  while double precision to a double precision number. 
>> the current preferred way is to specify this as real(kind=dp).
>> to be even more precise, one can guarantee precision to that of the machine-compiler-specific double
>> precision real using the *kind* function to get the kind of 1.d0 

>> integer, parameter :: dp = kind(1.d0)  
>> and then specify real (dp) :: something


      integer :: i

      integer :: kread=5, kwrite=6

!
      x=1.
      y=1.d0

>>  a single precision number is given by 1. and a double precision by 1.d0

>>  Here a do-loop is executed 10^6 times adding a small number to 1. or 1.d0
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
*bits* (binary integers) `0` and `1`. This means that all numbers are stored in memory in *binary8 form,
that is, as long strings of zeroes and ones. This would be awkward to look at for people. Consequently,
binary strings are converted to *octal*, *decimal*, or *hexadecimal* numbers before results are
communicated to people. While *octal* and *hexadecimal* are nice since the conversion does not loose
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

> **Tip**
> Note thate we also provide similar C files: `exp-good.cc` and `exp-bad.cc`. Feel free to explore these using `g++` instead of `gfortran`:
> ```shell
> g++ exp-good.cc -o good
> g++ exp-bad.cc -o bad
> ```

<font color="red">**Exercise and Homework:**  </font> <br>
- Understand how both codes implement the series algorithm.
- Convince yourself as well as the TA why one is better than the other.

## Fortran Flags

`gfortran` has many different command line options (also known as flags) that control what the compiler does and how it does it. To use these flags, simply include them on the command line when you run `gfortran`, e.g.
```bash
gfortran -Wall -Wextra -c mysubroutine.f90 -o mysubroutine.o
```

If you find you use certain flags often, you could add them to an alias in your .bashrc file, such as
```bash
alias gf="gfortran -Wall -Wextra -Wconversion -pedantic"
```

Though it is advisable to manage these flags through Makefiles instead. For more information on the available flags, see the `gfortran` man page. Note a “man page” is the Unix help manual documentation that is available for many Unix commands by typing, e.g.
```bash
man gfortran
```

> **Warning**
> Different fortran compilers use different names for similar flags!

### Double precision flags

One can promote all real variables to double precision using flag options as following
```bash
gfortran -fdefault-real-8 -fdefault-double-8 -c mysubroutine.f90 -o mysubroutine.o
```

In this way one conveniently removes the need to declare individual variables with double precision as shown in the first example in Sample codes.


### Output flags

These flags control what kind of output gfortran generates, and where that output goes.

        -c: Compile to an object file, rather than producing a standalone program. This flag is useful if your program source code is split into multiple files. The object files produced by this command can later be linked together into a complete program.

        -o FILENAME: Specifies the name of the output file. Without this flag, the default output file is a.out if compiling a complete program, or SOURCEFILE.o if compiling to an object file, where SOURCEFILE.f90 is the name of the Fortran source file being compiled.

Please revisit the examples we looked at Compiling, linking, and running a Fortran code.


### Warning flags

Warning flags tell gfortran to warn you about legal but potentially questionable sections of code. These sections of code may be correct, but warnings will often identify bugs before you even run your program.

        -Wall: Short for “warn about all,” this flag tells gfortran to generate warnings about many common sources of bugs, such as having a subroutine or function with the same name as a built-in one, or passing the same variable as an intent(in) and an intent(out) argument of the same subroutine. In spite of its name, this does not turn all possible -W options on.

        -Wextra: In conjunction with -Wall, gives warnings about even more potential problems. In particular, -Wextra warns about subroutine arguments that are never used, which is almost always a bug.

        -Wconversion: Warns about implicit conversion. For example, if you want a double precision variable sqrt2 to hold an accurate value for the square root of 2, you might write by accident sqrt2 = sqrt(2.). Since 2. is a single-precision value, the single-precision sqrt function will be used, and the value of sqrt2 will not be as accurate as it could be. -Wconversion will generate a warning here, because the single-precision result of sqrt is implicitly converted into a double-precision value.

        -pedantic: Generate warnings about language features that are supported by gfortran but are not part of the official Fortran 95 standard. Useful if you want be sure your code will work with any Fortran 95 compiler.

        -Werror: Turn warnings into errors.

###Other useful flags
Since different flavors of fortran compilers may have some extra features, that although being convenient are not standard, it is advisable to code in standard fortran so that your codes are portable to different computers with possibly different implementations of fortran compilers 
To test if you code is standard fortran use the flag

	-ansi: this will flag all nonstandard commands you used. It is advisable to replace them with standard ones
If you run into issues because some older fortran standard is used, the flag

	-std=legacy  can be useful. you can also specify a specific standard, e.g. std=f95 

### Debugging flags

Debugging flags tell the compiler to include information inside the compiled program that is useful in debugging, or alter the behavior of the program to help find bugs.

        -g: Generates extra debugging information usable by GDB. -g3 includes even more debugging information.

        -fbacktrace: Specifies that if the program crashes, a backtrace should be produced if possible, showing what functions or subroutines were being called at the time of the error.

        -fbounds-check: Add a check that the array index is within the bounds of the array every time an array element is accessed. This substantially slows down a program using it, but is a very useful way to find bugs related to arrays; without this flag, an illegal array access will produce either a subtle error that might not become apparent until much later in the program, or will cause an immediate segmentation fault with very little information about cause of the error.

        -ffpe-trap=zero,overflow,underflow tells Fortran to trap the listed floating point errors (fpe). Having zero on the list means that if you divide by zero the code will die rather than setting the result to +INFINITY and continuing. Similarly, if overflow is on the list it will halt if you try to store a number larger than can be stored for the type of real number you are using because the exponent is too large.

        Trapping underflow will halt if you compute a number that is too small because the exponent is a very large negative number. For 8-byte floating point numbers, this happens if the number is smaller than approximate 1E-324. If you don’t trap underflows, such numbers will just be set to 0, which is generally the correct thing to do. But computing such small numbers may indicate a bug of some sort in the program, so you might want to trap them.

### Optimization flags

Optimization options control how the compiler optimizes your code. Optimization usually makes a program faster, but this is not always true.

        -O level: Use optimizations up to and including the specified level. Higher levels usually produce faster code but take longer to compile. Levels range from -O0 (no optimization, the default) to -O3 (the most optimization available).

### Flags with command line compilations vs. Makefile

Later, we are going to learn how we can write a Makefile for Fortran (see Makefiles). A Makefile provides users with a handy way to compile multiple source codes, in which case the manual command line compilation of each and every source code is very challenging and almost impractical. In a Makefile we are going to use macros to define a set of rules and dependencies, where we can include various Fortran flags as well.
Practical gfortran flags for development and production run

One very good set of choices for these flags can be found at http://www.fortran90.org/src/faq.html.

In short, for development where you should turn on all debugging warnings and checks, you want to consider

-Wall -Wextra -Wimplicit-interface -fPIC -fmax-errors=1 -g -fcheck=all -fbacktrace

This turns on lots of useful debugging checks, stops at the first error, and turns on backtrace printing which can help diagnose runtime errors (typically accessing an array out of bounds).

Once you have finished all of your debugging and code verification, you will want to compile a highly optimized version of your software. This will allow you to handle substantially larger runs and reduce your time-to-solution by potentially orders of magnitude. In this case you may want to use

-Wall -Wextra -Wimplicit-interface -fPIC -fmax-errors=1 -O3 -march=native -ffast-math -funroll-loops

This turns off all active debugging options (like bounds checks) which significantly slow down the code performance, and at the same time, turns on optimizing options (fast math and platform dependent code generation), providing an accelerated code performance.

Optimization can modify the internal representation of your program substantially, and has the potential to hide problematic bugs. To quote Prof. Donald Knuth:

> **Warning**
> Premature optimization is the root of all evil (or at least most of it) in programming.

Always start with relevant debugging flags present!!

### Further reading

* This list is by no means exhaustive. A more complete list of `gfortran`-specific specific flags is at http://gcc.gnu.org/onlinedocs/gfortran/Invoking-GNU-Fortran.html or on the `gfortran` man page.
* `gfortran` is part of the GCC family of compilers; more general information on GCC command line options is available at http://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html, although some of this information is specific to compiling C programs rather than Fortran.
* See also http://linux.die.net/man/1/gfortran.
* A list of debug flags can also be found at http://www.fortran-2000.com/ArnaudRecipes/CompilerTricks.html#CompTable_fortran


Content of this was taken from [here](https://people.ucsc.edu/~imay1/_static/AM129_F20/chapters/chapt02/ch02_fortran_flags.html).