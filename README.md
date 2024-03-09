# ft_containers

## Overview

`ft_containers` is a project that aims to re-implement some of the fundamental containers provided by the Standard Template Library (STL) in C++. The project provides implementations of commonly used data structures such as `vector`, `deque`, `set`, `map`, and `stack`. These containers are crucial components of C++ programming, offering dynamic data storage and manipulation capabilities.

## Motivation

The primary motivation behind this project is to deepen understanding of data structures and algorithms by implementing them from scratch. By developing our versions of these containers, we gain insights into their internal workings, algorithms, and complexities. Furthermore, this project allows us to practice C++ programming, including template programming, memory management, and algorithm design.

## Implemented Containers

### 1. Vector

- **Description**: A dynamic array that automatically resizes itself as elements are added or removed.
- **Implemented Methods**: `push_back()`, `pop_back()`, `size()`, `empty()`, `clear()`, `operator[]`, `at()`, etc.
- **Internal Implementation Details**: Utilizes dynamic memory allocation, resizing strategies, and iterator support.

### 2. Deque

- **Description**: A double-ended queue that supports efficient insertion and deletion at both ends.
- **Implemented Methods**: `push_back()`, `push_front()`, `pop_back()`, `pop_front()`, `size()`, `empty()`, `clear()`, etc.
- **Internal Implementation Details**: Utilizes multiple dynamically allocated buffers for efficient front and back insertions.

### 3. Set

- **Description**: A container that stores unique elements in sorted order.
- **Implemented Methods**: `insert()`, `erase()`, `find()`, `size()`, `empty()`, `clear()`, etc.
- **Internal Implementation Details**: Utilizes balanced binary search trees (e.g., red-black trees) for efficient storage and retrieval.

### 4. Map

- **Description**: A container that stores key-value pairs in sorted order based on the keys.
- **Implemented Methods**: `insert()`, `erase()`, `find()`, `operator[]`, `size()`, `empty()`, `clear()`, etc.
- **Internal Implementation Details**: Combines the functionality of set and custom data structure for efficient key-based lookup.

### 5. Stack

- **Description**: A container adapter that provides Last-In, First-Out (LIFO) functionality.
- **Implemented Methods**: `push()`, `pop()`, `top()`, `size()`, `empty()`, etc.
- **Internal Implementation Details**: Utilizes underlying container for stack operations and maintains proper LIFO behavior.

## Usage

To use the implemented containers in your projects, follow these steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/zrabhi/Ft_containers.git
2. Navigate to the project directory
   ```bash
   cd Ft_containers && cd Mandatory
3. Compile the program
   ```bash
   make
