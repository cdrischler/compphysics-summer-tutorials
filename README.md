# Computational Physics Summer Tutorials 2024 <!-- omit from toc -->

## Table of contents <!-- omit from toc -->

- [Overview](#overview)
- [More tutorials](#more-tutorials)
  - [C/C++](#cc)
  - [Python](#python)
  - [Jupyter and Markdown](#jupyter-and-markdown)
  - [GNU Debugger (optional)](#gnu-debugger-optional)
- [Setting up the software environment](#setting-up-the-software-environment)
- [Optional: Install Ubuntu Linux from scratch](#optional-install-ubuntu-linux-from-scratch)


## Overview

To help students prepare for the fall semester course Computer Simulation Methods in Physics (PHYS 4071/5071) at Ohio University, we are offering this year one-hour tutorials twice a week in the Computer Lab in Clippinger Lab. These tutorials consist of lectures, hands-on learning activities, and a final project.

You will need to register to attend this course. Overall participation and the final project will be used to grade the participants upon completion of the project. Working in small groups is _highly_ encouraged. Contact the instructors (see below) if you cannot participate in the tutorials. 

> **Warning**
> We no longer require first-year graduate students to sign up for a C-course in the CS department or complete an intro to Python module in [Coursera](https://www.coursera.org/).

The following tutorials (Tuesdays and Thursdays) will be offered this year:

| Tutorial       | Dates | 
| ----------- | ----------- |
| [Basic UNIX](unix_tutorial.ipynb)        | 5/14 @ **2:45 pm** & 5/16 @ **3 pm** | 
| [Basic Python 3: numpy, scipy, pandas](python_tutorial.ipynb)         | 5/21 & 5/23 @ 3 pm | 
| [Basic Plotting: xmgrace, gnuplot, and matplotlib](plotting_tutorial/plotting_tutorial.ipynb)        | 5/28 & 5/30 @ 3 pm | 
| (no tutorials)   |      | 
| [Basic Git](git-github/README.md)          | 6/11 & 6/13 @ 3 pm | 

Feel free to suggest topics for future summer tutorials.

**Instructors** for these tutorials are (in alphabetical order):
* [Christian Drischler](https://www.ohio.edu/cas/drischler) (CD, lead instructor)
* [Rawan Nowier](https://www.ohio.edu/cas/rn757120) (RN)

We are grateful to Charlotte Elster and Kanishk Chauhan for fruitful discussions and lecture material from the 2023 Summer Tutorials.


## More tutorials

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

### GNU Debugger (optional)
* [GDB manual](https://www.asc.ohio-state.edu/physics/ntg/6810/handouts/gdb_debugger.pdf)
* [Debugging tutorial](https://heather.cs.ucdavis.edu/~matloff/debug.html)


## Setting up the software environment

We use VirtualBox to virtualize Ubuntu Linux on your host computer, which can run Microsoft Windows or Apple's MacOS. If your system already runs Linux, you can skip this section.

> **Note**
> You don't need to follow these steps on the computers in the Computer Lab. Just start up your virtual machine in VirtualBox that you created in the first lecture week.

Follow these steps to set up our customized environment with pre-installed software on your lab computer:
* Download and install [VirtualBox](https://www.virtualbox.org/).
* Download our [customized VirtualBox hard drive](https://catmailohio-my.sharepoint.com/:u:/g/personal/drischler_ohio_edu/EYlLoSurm6tMq-rGL-Je98IBXPSi9yRtjmuERZPfB9j8Mg?e=bFu9oU), which contains pre-installed Ubuntu Linux and other software. You will need an Ohio U account to access the hard drive. 
* In VirtualBox, navigate to `File-Import Appliance` in the menu and import the downloaded file (e.g., `/Users/student/ubuntu-compphys.ova`).
* Start the virtual machine.
* The default user name _and_ password is `student`. It makes sense to change the password.

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
