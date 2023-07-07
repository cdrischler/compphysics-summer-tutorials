# compphysics-summer-tutorials23
Repository for the 2023 Summer Tutorials on Computational Physics

## Summer tutorials

In preparation for the Fall course, we will collaborate with [Prof. Charlotte Elster](https://www.ohio.edu/cas/elster) to work on modules you should attend, mainly in the second summer session. In the past few years, first-year graduate students were required to sign up for a C-course in the CS department or complete an intro to Python module in [Coursera](https://www.coursera.org/). This year, we will hold the following one-hour tutorials, consisting of lectures and hands-on to help you get started:

| Tutorial      | Tutor | Date | 
| ----------- | ----------- | ----------- |
| Basic UNIX   |   RN     | 7/18 & 7/20 @ 3 pm | 
| Basic Python 3: numpy, scipy, pandas  | KC       | 7/25 & 7/27 @ 3 pm | 
| Basic C/C++ and Fortran | CH & KC        | 8/1 & 8/3 @ 3 pm | 
| Basis Plotting: xmgrace, gnuplot, and matplotlib | RN        | 8/8 & 8/10 @ 3 pm | 
| Git: basics and more   | CD        | 8/15 & 8/17 @ 3 pm | 

**Teaching assistants** for these tutorials will be (in alphabetical order) [Kanishk Chauhan](https://www.ohio.edu/cas/kc303218) (KC) and [Rawan Nowier](https://www.ohio.edu/cas/rn757120) (RN).

Attending these tutorials is _highly_ recommended (and in your interest) but not mandatory.


### Potential other subjects

* git
* gfortran
* gcc (BLAS, GSL)
* make/cmake
* Suse/Ubuntu
* Texmaker
* Python 3 (numpy, scipy, matplotlib, sympy, pandas, ...)
* xmgrace/gnuplot
* gdb/gprof/profiling in general
* vim/emacs/kate/nano
* diffuse/kompare
* Valgrind/openMP/MPI
* PyCharm/CLion/DataSpell (all from JetBrains) and/or VS Code
* Feel free to add!


### Helpful links

Below are the links and references to the vim tutorials and quarto I mentioned today.
 
Learning vim (random order):
* https://github.com/iggredible/Learn-Vim
* https://www.freecodecamp.org/news/vim-beginners-guide/
* https://danielmiessler.com/study/vim/
* https://www.tutorialspoint.com/vim/index.htm
* https://linuxconfig.org/vim-tutorial
* https://www.openvim.com/
 
The vim (browser) game I mentioned:
* https://vim-adventures.com/
 
Quarto:
* https://quarto.org/
 
Quarto example:
* https://nasa-openscapes.github.io/earthdata-cloud-cookbook/


## Setting up the software environment

We use VirtualBox to virtualize Ubuntu Linux on your host computer, which can run Microsoft Windows or Apple's macOS. If your system already runs Linux, you can skip this section.

Follow these steps to set up the environment on your lab computer:
* Download and install [VirtualBox](https://www.virtualbox.org/).
* Download our [customized VirtualBox hard drive](https://catmailohio-my.sharepoint.com/:u:/g/personal/drischler_ohio_edu/EYlLoSurm6tMq-rGL-Je98IBXPSi9yRtjmuERZPfB9j8Mg?e=bFu9oU), which contains pre-installed Ubuntu Linux and other software. You will need an Ohio U account to access the hard drive. 
* In VirtualBox, navigate to `File-Import Appliance` in the menu and import the downloaded file (`/Users/cdrischler/ubuntu-compphys.ova`).
* Start the virtual machine.
* The default user name _and_ password is `student`. It makes sense to change the password.

> **Note**
> Using our customized hard drive (instead of installing Ubuntu yourself) is highly recommended. The hard drive can be used, in combination with VirtualBox, on any computer, including your personal computer.

Alternatively, follow these steps to install Ubuntu in VirtualBox yourself:
* Download and install [VirtualBox](https://www.virtualbox.org/).
* Download [Ubuntu 22.04.2 LTS](https://ubuntu.com/download/desktop).
* In VirtualBox click `New` and follow the instructions to install Ubuntu using the downloaded image file. This may take a while.
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
