# Computational Physics Summer Tutorials 2025 <!-- omit from toc -->

## Table of contents <!-- omit from toc -->

- [Overview](#overview)
- [More tutorials (optional)](#more-tutorials-optional)
  - [C/C++](#cc)
  - [Python](#python)
  - [Jupyter and Markdown](#jupyter-and-markdown)
  - [GNU Debugger](#gnu-debugger)
  - [Misc](#misc)
- [Setting up the software environment](#setting-up-the-software-environment)
- [Optional: Install Ubuntu Linux from scratch](#optional-install-ubuntu-linux-from-scratch)


## Overview

Welcome to the 2025 Computational Physics Summer Tutorials! This five-week course will cover the basics of scientific computing, including the Python programming language. 

While everyone is welcome to attend all or selected sessions, it also helps students prepare for the fall semester course "Computer Simulation Methods in Physics" (PHYS 4071/5071) at Ohio University. This year, we are offering one-hour tutorials twice a week in the Computer Lab in Clippinger Lab (PHYS 6900 102 Special Topics in Physics). These tutorials consist of lectures, hands-on learning activities, and a final project.

Please register if you want to attend this course. Upon completion of the final project, the participants' overall participation and the final project will be used to grade them. Working in small groups is highly encouraged. Contact the instructors (see below) if you cannot participate in the tutorials. 

The following tutorials (Tuesdays and Thursdays) will be offered this year:

| Tutorial       | Dates | 
| ----------- | ----------- |
| [Basic UNIX](unix_tutorial.ipynb) (CC)       | 7/8 @ **2:45 pm** & 7/10 @ **3 pm** | 
| [Basic Python 3: numpy, scipy, pandas](python_tutorial.ipynb) (RW)         | 7/15 & 7/17 @ 3 pm | 
| [Basic Plotting: xmgrace, gnuplot, and matplotlib](plotting_tutorial/plotting_tutorial.ipynb) (RW)        | 7/22 & 7/24 @ 3 pm | 
| [Basic Git/GitHub](git-github/README.md) (CD)         | 7/29 & 7/31 @ 3 pm | 
| [Final project](final_project/final_project.ipynb)           | 8/5 & 8/7 @ 3 pm | 

Feel free to suggest topics for future summer tutorials.

**Instructors** for these tutorials are (in alphabetical order):
* [Chase Cartwright](https://www.ohio.edu/cas/cc627122) (CC)
* [Christian Drischler](https://www.ohio.edu/cas/drischler) (CD)
* [Rawan Nowier](https://www.ohio.edu/cas/rn757120) (RN)

The tutorials were previously held in the summers of 2023 and 2024. 
We are grateful to Charlotte Elster and Kanishk Chauhan for their fruitful discussions and for providing lecture material from the 2023 Summer Tutorials.

## More tutorials (optional)

In addition, the tutorials we will teach in the summer, you might want to check out the selection of tutorials below, some of which are external links.

### C/C++
* [GNU Scientific Library (GSL)](gsl.ipynb)
* [GCC compiler options](gcc_compiler_options.ipynb)
* [Computational Physics: Teach yourself C++](https://computationalscienceuio.github.io/RefreshProgrammingSkills/notebooks/Cpp/LectureNotes.html)
* [Makefile tutorial](https://makefiletutorial.com/#makefile-cookbook)

### Python
* [Basic Python3: numpy and matplotlib](Python3/tutorial.ipynb)
* [Animations with Python and matplotlib](Python3/tutorial_animations.ipynb)
* [Scientific Python Lectures](https://github.com/jrjohansson/scientific-python-lectures); especially:
  -  [Introduction to Python programming](https://github.com/jrjohansson/scientific-python-lectures/blob/master/Lecture-1-Introduction-to-Python-Programming.ipynb)
  -  [Numpy](https://github.com/jrjohansson/scientific-python-lectures/blob/master/Lecture-2-Numpy.ipynb)
  -  [Scipy](https://github.com/jrjohansson/scientific-python-lectures/blob/master/Lecture-3-Scipy.ipynb)
  -  [Matplotlib](https://github.com/jrjohansson/scientific-python-lectures/blob/master/Lecture-4-Matplotlib.ipynb)
  -  [Git](https://github.com/jrjohansson/scientific-python-lectures/blob/master/Lecture-7-Revision-Control-Software.ipynb)
* [LearnPython.org interactive Python tutorial](https://www.learnpython.org/)

### Jupyter and Markdown
* [Jupyter notebooks](https://www.dataquest.io/blog/jupyter-notebook-tutorial/)
* [Basic Markdown](https://github.com/jrjohansson/numerical-python-book-code/blob/master/ch01-Markdown.ipynb)

To run the interactive Jupyter notebooks in this `git` repository, simply execute the following commands in the command line (in this directory):

```shell
python3 -m pip install jupyter  # need to run only once
jupyter-notebook &
```

### GNU Debugger 
* [GDB manual](https://www.asc.ohio-state.edu/physics/ntg/6810/handouts/gdb_debugger.pdf)
* [Debugging tutorial](https://heather.cs.ucdavis.edu/~matloff/debug.html)


### Misc
* [Navigating scientific journals](journals.md)


## Setting up the software environment

We use VirtualBox to virtualize Ubuntu Linux on your host computer, which can run Microsoft Windows or Apple's MacOS. If your system already runs Linux, you can skip this section.

> **Note**
> You don't need to follow these steps on the computers in the Computer Lab. Just start up your virtual machine in VirtualBox that you created in the first lecture week.

Follow these steps to set up our customized environment with pre-installed software on your lab computer:
* Download and install [VirtualBox](https://www.virtualbox.org/). On Lab computers, this step can be skipped.
* Retrieve our customized virtual hard drive (ask the instructors), which contains pre-installed Ubuntu Linux and other software.
* In VirtualBox, navigate to `File-Import Appliance` in the menu and import the downloaded file (e.g., `/Users/student/ubuntu-compphys.ova`).
* Disable the USB controller in the settings of your new virtual machine in VirtualBox.
* Start the virtual machine.
* The default user name _and_ password is `student`.

> **Note**
> Using our customized hard drive (instead of installing Ubuntu yourself) is highly recommended. The hard drive can be used with VirtualBox on any computer, including your personal computer.

## Optional: Install Ubuntu Linux from scratch

Alternatively, follow these steps to install Ubuntu in VirtualBox from scratch:
* Download and install [VirtualBox](https://www.virtualbox.org/).
* Download [Ubuntu 22.04.2 LTS](https://ubuntu.com/download/desktop).
* In VirtualBox, click `New` and follow the instructions to install Ubuntu using the downloaded image file. This may take a while.
* To fix the issue with the resolution, follow:
```shell
sudo apt-get update
sudo apt-get install build-essential gcc make perl dkms
```
* insert and install `Guest Additions CD Image` (under `Devices` in the menu) and then shut down the virtual system
* increase the video memory significantly in the settings
* reboot the virtual system

We will likely need the following selection of standard software, which can be conveniently downloaded using `apt`:
```shell
sudo apt-get install git diffuse kompare gnuplot grace cmake gfortran
sudo apt-get install texlive texmaker 
sudo apt-get install python3 python3-pip
sudo apt-get install synaptic
sudo apt-get install pandoc libgsl-dev texlive-xetex
sudo apt-get install cm-super dvipng
sudo apt-get install libportaudio2 libasound-dev
```

We also install standard Python packages:
```shell
python3 -m pip install numpy scipy pandas sympy jupyter
python3 -m pip install matplotlib seaborn scikit-learn tqdm numba
```

Next, we install software directly from source:
* [Microsoft Visual Studio Code (for Jupyter development)](https://code.visualstudio.com/docs/setup/linux#_debian-and-ubuntu-based-distributions)
* JetBrain's PyCharm Community version (for Python development)
```shell
sudo snap install pycharm-community --classic
```
