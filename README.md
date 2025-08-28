# CML

## What is CML
CML is a hobby project which aims to implement some of the most popular machine learning algorithms in C language.

- But why? I don't know... To be honest, I started this project in mid 2024 because I had very little coding experience and wanted to learn some new things. For instance, I learned how to write C header files, how functions from header files are imported, the steps of complitation, how required libraries are linked at the time of compilation etc...

- Is CML limited to KNN only ? No, I plan on implementing more, hopefully soon.

- Don't these already exist in Python ? Yes they do, but these kinds of implementations made me understand how they actually work under the hood.

- But why code in C? I like memory fails every now and then...

<hr>

## Codebase :
* ### `knn` folder contains all the required files (currently).

### Steps to compile and run on your machine :

- ### First we need to access the codebase. This can be done by cloning the repo locally :
	- get the repo link from `Clone` > `Local` tab > `HTTPS` > `https://github.com/****/project.git` (some URL like this, end with `.git`)
	- then open a terminal in your desired folder and run (replace `<URL>` with actual URL	) :
```bash
git clone <URL>
```

- #### Or alternatively :
	- You can download the zip file directly from `Code` > `Local` tab > `Download ZIP`
	- Open the repo in a codespace : `Code` > `Codespaces` tab > `Create codespace on main`

- #### Now that we have access to codebase, we will compile the C files into executable :
	- First open a terminal in your folder where the repo is downloaded/located
	- Then :

```bash
cd knn/
```

- we are now in the `knn` dir.	 Here a `makefile` is already there which will compile and link the header files with our main `knn.c` file using `clang`. If you have `clang` installed, then you can use :


```bash
make knn
```

- Or you may manually compile the files as you like, using your own compiler along with your own flags etc.

For example, using gcc:
```bash
gcc -c handle_csv.c -o handle_csv.o
gcc -c knn_calc.c -o knn_calc.o
gcc -c knn.c -o knn.o
```

```bash
gcc handle_csv.o knn_calc.o knn.o -o knn -lm
```

- #### Now when we run
```bash
./knn
```


<hr>

<hr>

- You can also visualize the existing points in `test.csv` by opening `/knn/notebook.zip` file.
		- If you are using VS Code, you can also open `knn.ipynb` through terminal:
```bash
unzip knn/notebook.zip
```
- This notebook can be modified to visualize your custom csv files also.

