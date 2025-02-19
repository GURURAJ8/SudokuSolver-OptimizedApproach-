# Sudoku Solver (Optimized with Bitmasking & Constraint Propagation)

## 🚀 Overview
This is an **optimized Sudoku solver** implemented in **C++**, using **bitmasking** and **constraint propagation** for efficient solving. It leverages **Minimum Remaining Values (MRV)** and **forward checking** to prune the search space, making it significantly faster than brute-force methods.

## ⚡ Features
- **Bitmasking**: Uses efficient bitwise operations to track constraints.
- **Constraint Propagation**: Eliminates invalid choices early, reducing backtracking.
- **MRV Heuristic**: Prioritizes cells with fewer possible values to speed up solving.
- **Optimized Recursive Backtracking**: Solves even hard Sudoku puzzles quickly.

## 🛠 How It Works
1. **Preprocessing:**
   - Initializes row, column, and 3×3 box constraints using bitmasks.
   - Identifies blank cells and sorts them by the number of available choices (**MRV heuristic**).
2. **Solving Algorithm:**
   - Selects the most constrained blank cell.
   - Tries available numbers while respecting Sudoku rules.
   - Uses **bitwise operations** to update constraints dynamically.
   - Recursively solves until completion or backtracks when needed.
3. **Output:**
   - Prints the solved Sudoku grid.

## 🖥️ Installation & Usage
### **1. Clone the Repository**
```sh
git clone https://github.com/your-username/sudoku-solver.git
cd sudoku-solver
```

### **2. Compile & Run**
```sh
g++ sudoku_solver.cpp -o sudoku_solver
./sudoku_solver
```

## 📌 Example Input & Output
**Input Grid:**
```
5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
---------------------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
---------------------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9
```

**Solved Output:**
```
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
---------------------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
---------------------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
```

## 🔥 Performance Benchmark
✅ Solves standard Sudoku puzzles in **milliseconds**.  
✅ More efficient than naive brute-force methods.

## 📌 Future Improvements
- Add a **graphical UI** to visualize solving in real time.
- Implement **parallel processing** for even faster performance.
- Compare with **Dancing Links (DLX)** for further optimizations.

## 📜 License
This project is licensed under the **MIT License**. Feel free to use and contribute!

## 🤝 Contributing
Pull requests are welcome! If you find a bug or have an idea for improvement, open an issue.

---
**Author:** Gururaj Prashant Saraph  
🔗 GitHub: [Your Profile](https://github.com/GURURAJ8)

