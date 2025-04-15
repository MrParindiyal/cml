
# KNN algorithm implementation in C



 <br>

## KNN - what is KNN
KNN stands for K-nearest neighbors which is a simple and effective machine learning algorithm used for classification and regression tasks through supervised learning approach. It is a **non-parametric** and **instance-based** learning method, meaning it makes decisions based on the closest data points in the training set without assuming any prior distribution of the data.

- ### <ins> Non Parametric</ins> :
	- **Non-parametric** methods refer to algorithms that do not make strong assumptions about the underlying data distribution. This means that the model does not have a fixed set of parameters that define it and instead can adapt to the data based on the number of data points available. Non-parametric models are flexible because they can grow in complexity as the amount of data increases.

	 - **K-Nearest Neighbors (KNN)** is a non-parametric algorithm because it does not assume any prior distribution for the data. It doesn't learn a global model; rather, it makes predictions based on the local neighborhood of a query point. As you add more data points, the model becomes more complex because it simply looks at more neighbors.


- ### <ins> Instance based</ins> :
	- **Instance-based** learning methods make predictions by using the actual training data instances rather than creating an explicit model based on those instances. In other words, the learning happens at the time of prediction, not during training. So, instance-based learning is like storing all the data points and using them directly to make predictions when needed, rather than summarizing the data into a model with parameters.

	- In **KNN** the model does not "learn" a function or set of parameters during the training phase. Instead, it stores the entire dataset and classifies a new data point by looking at the labels of the "k" closest training instances to the point. The prediction is based on the characteristics of those stored instances, and no generalization is made during the training phase (as there is no training phase).


- ### <ins>Lazy learner</ins> :
	- A **lazy learner** is a type of machine learning algorithm that **does not learn a model** during the training phase. Instead, lazy learning algorithms **store the training data** and defer the computation until a prediction is needed. In other words, these algorithms only "learn" when making predictions on new data, rather than creating a model that generalizes from the data during training.

	- Since KNN also skips the training phase and directly calculates the outcome on query, **KNN** can be classified as a lazy learner.

	- As KNN is a lazy learner and does not train a model for the dataset, the computation required per prediction grows rapidly as the data points in dataset increase. Computation is also directly proportional to features in the dataset (dimensionality).

<br><br>

## How KNN Works:

-  **Data Representation:** Each data point is represented in an n-dimensional space (for n features). In our program we default to `2`, so , n = `2`.

-  **Distance Calculation:** To classify a new data point, the algorithm computes the distance (in our case, `Euclidean`) from the new point to all points in the dataset.

-  **Neighbor Selection:** It identifies the `k` closest points (neighbors) to the new data point.

-  **Prediction :-**
	- **Majority Voting (Classification):** For classification tasks, the new point is assigned the label that is most common among its `k` closest neighbors. In our program, we take average label and round off to nearest integer to get the label for new point (assuming the labels are encoded into integers).

	- **Weighted Average (Regression):** For regression tasks, the value is predicted based on the weighted average of the neighbors' values. The neighbors closer to the point get more weights and farther points get lesser weights. (Not implemented in our program, yet).

<hr>

### Advantages :

-   **Simple to Implement:** The algorithm is straightforward and simple to understand.
-   **Lazy Learning:** KNN stores the training data and performs computation only during the prediction phase, making it a lazy learner. This works very well on comparatively smaller datasets.

<hr>

### Disadvantages :

-   **k value:** Too small or too large k value can influence the final outcome.
-   **Computation:** KNN will calculate the distance each time a new point needs to be classified, thus calculation becomes repetitive. Large datasets and multiple dimensions can also increase computation times.
-   **Highly Sensitive:** The outcome can be misleading/incorrect if the dataset contains irrelevant features.
<hr>

## Codebase :
* ### `knn` folder contains all the required files.

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

- #### After the main `knn.c` file is compiled, we can then have a look at the CSV file:
	- The `test.csv` file gives the glimpse of format that is acceptable by the program.
	- `test.csv` contains `4` columns : `name`, `x`, `y`, `label`. Custom data can also be used if it meets the following requirements :
		- There are `4` columns i.e. `name`, `x`, `y`, `label`
		- There is no missing value (`NULL`, `NaN` etc.) in the dataset.
		- There a no more than `5000` rows (this can be changed by editing `#define  MAX_ROWS  5000` on line `7` in `/knn/handle_csv.c`)
		- Custom file path needs to be changed in `fopen()` on line `43` in `/knn/handle_csv.c`
		- `x` and `y` should be `float` values and `label` should be an `int` value.

- #### Now when we run
```bash
./knn
```
-	the terminal will print entire CSV data. This behaviour can be changed by calling `print_df(data, rows)` instead of `print_df_full()` ; where `rows` is the number of rows we want to display, on line `14` of `/knn/knn.c`
-	Now the terminal will ask for `x`, `y` and `k` values for the new point label calculation. Then it will display the predicted label/class of the point whose coordinates you gave earlier.


<hr>

##### NOTE : In our case, we are expecting data to have `2` dimensions (features) as the program is hardcoded for 2 features `x` and `y` only. However this can be easily tuned manually for dimensions upto `~10` (after that, code will start to look messy) by changing the `read_csv()`, `print_df()` & `print_df_full()` in `handle_csv.c` header file and `get_euclidean_distance()` in `knn_calc.c` header file.

<hr>

- You can also visualize the existing points in `test.csv` by opening `/knn/notebook.zip` file.
		- If you are using VS Code, you can also open `knn.ipynb` through terminal:
```bash
unzip knn/notebook.zip
```
- This notebook can be modified to visualize your custom csv files also.




