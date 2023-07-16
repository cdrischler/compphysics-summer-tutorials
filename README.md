# Computational Physics Summer Tutorials 2023

To help students get prepared for the fall semester course *Computer Simulation Methods in Physics (PHYS 4071/5071)* at Ohio University, we offer this year one-hour tutorials, consisting of lectures and hands-on learning, in the Computer Lab in Clippiner Lab. 

Attending these tutorials is _highly_ recommended (and in your interest) but not mandatory. Contact the instructors (see below) if you cannot participate in the tutorials. 

> **Warning**
> We no longer require first-year graduate students to sign up for a C-course in the CS department or complete an intro to Python module in [Coursera](https://www.coursera.org/).


The following tutorials will be offered this year:

| Tutorial      | Tutor | Dates | 
| ----------- | ----------- | ----------- |
| [Basic UNIX](unix_tutorial.ipynb)   |   RN     | 7/18 & 7/20 @ **2:45 pm** | 
| [Basic Python 3: numpy, scipy, pandas](python_tutorial.ipynb)  | KC       | 7/25 & 7/27 @ 3 pm | 
| [Basic C/C++ and Fortran](fortranC/README.md) | CH & KC        | 8/1 & 8/3 @ 3 pm | 
| Basic Plotting: xmgrace, gnuplot, and matplotlib | RN        | 8/8 & 8/10 @ 3 pm | 
| [Basic Git](git-github/README.md)   | CD        | 8/15 & 8/17 @ 3 pm | 

Feel free to suggest topics for future summer tutorials.

**Instructors** for these tutorials are (in alphabetical order):
* [Christian Drischler](https://www.ohio.edu/cas/drischler) (CD)
* [Charlotte Elster](https://www.ohio.edu/cas/elster) (CE)

**Teaching assistants** for these tutorials are (in alphabetical order):
* [Kanishk Chauhan](https://www.ohio.edu/cas/kc303218) (KC) 
* [Rawan Nowier](https://www.ohio.edu/cas/rn757120) (RN)


## Setting up the software environment

We use VirtualBox to virtualize Ubuntu Linux on your host computer, which can run Microsoft Windows or Apple's macOS. If your system already runs Linux, you can skip this section.

> **Warning**
> You don't need to follow these steps on the computers in the Computer Lab. Just start up your virtual machine in VirtualBox.

Follow these steps to set up the environment on your lab computer:
* Download and install [VirtualBox](https://www.virtualbox.org/).
* Download our [customized VirtualBox hard drive](https://catmailohio-my.sharepoint.com/:u:/g/personal/drischler_ohio_edu/EYlLoSurm6tMq-rGL-Je98IBXPSi9yRtjmuERZPfB9j8Mg?e=bFu9oU), which contains pre-installed Ubuntu Linux and other software. You will need an Ohio U account to access the hard drive. 
* In VirtualBox, navigate to `File-Import Appliance` in the menu and import the downloaded file (e.g., `/Users/student/ubuntu-compphys.ova`).
* Start the virtual machine.
* The default user name _and_ password is `student`. It makes sense to change the password.

> **Note**
> Using our customized hard drive (instead of installing Ubuntu yourself) is highly recommended. The hard drive can be used with VirtualBox on any computer, including your personal computer.

Alternatively, follow these steps to install Ubuntu in VirtualBox yourself:
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
sudo apt-get install git diffuse kompare gnuplot grace cmake
sudo apt-get install texlive texmaker 
sudo apt-get install python3 python3-pip
sudo apt-get install synaptic
```

We also install standard Python packages:
```shell
python3 -m pip install numpy scipy pandas jupyter matplotlib seaborn scikit-learn tqdm numba
```

Next, we install software directly from source:
* [Microsoft Visual Studio Code (for Jupyter development)](https://code.visualstudio.com/docs/setup/linux#_debian-and-ubuntu-based-distributions)
* JetBrain's PyCharm Community version (for Python development)
```shell
sudo snap install pycharm-community --classic
```

## Potential topics

These are topics we might cover in future summer tutorials:
* BLAS and GSL
* make/cmake
* Texmaker
* debuggers and profilers (gdb, gprof, profiling, etc.)
* emacs
* diffuse/kompare
* valgrind
* openMP/MPI
* PyCharm/CLion/DataSpell (all from JetBrains) and Microsoft VS Code
* Feel free to add!
