Philosophers Project

This project is part of the curriculum at 42 Ecole and focuses on implementing a simulation of philosophers eating in a dining setup using threads and mutexes to handle concurrency.
Objective

The goal of the project is to simulate a classical problem in computer science, known as the "Dining Philosophers Problem," which deals with synchronization and deadlock prevention in a multi-threaded environment. The problem involves philosophers who sit at a table, each with a fork on either side, and they alternate between thinking and eating. Philosophers need both forks to eat, but they must avoid deadlock and ensure that they don't starve by taking turns.
Requirements

    C programming language
    POSIX Threads (pthread) for multi-threading
    Mutexes to manage access to shared resources (forks)
    Timely management to avoid philosophers starving
    Error handling for thread and mutex operations

Features

    Philosophers simulation: Each philosopher alternates between thinking and eating.
    Concurrency management: Multiple threads are used to represent philosophers.
    Mutex protection: Mutexes are used to prevent multiple philosophers from picking up the same fork simultaneously.
    Avoidance of deadlock: The solution is designed to ensure that philosophers can always eat by managing access to shared resources and avoiding deadlock situations.
    Starvation prevention: The implementation makes sure that no philosopher will starve by allowing them to eat after a set time of thinking if they haven't eaten yet.

Instructions

    Compilation:
    To compile the project, run the following command:

make

Execution:
To run the simulation with a specified number of philosophers and time limits for eating and thinking:

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>

    number_of_philosophers: The number of philosophers (must be greater than 0).
    time_to_die: The time (in milliseconds) before a philosopher dies from starvation.
    time_to_eat: The time (in milliseconds) a philosopher spends eating.
    time_to_sleep: The time (in milliseconds) a philosopher spends sleeping.

Example:
To run the simulation with 5 philosophers, where each philosopher has 800ms to eat, 200ms to sleep, and 200ms before dying from starvation:

    ./philo 5 800 200 200

Design

    Philosophers: Represented as threads, each of which alternates between thinking, eating, and sleeping.
    Forks: Shared resources (represented as mutexes) that each philosopher needs to pick up to eat.
    Mutexes: Used to ensure that only one philosopher can pick up a fork at a time.
    Time management: The simulation keeps track of when each philosopher eats and sleeps, ensuring proper timing and managing the starvation condition.

Concurrency and Synchronization

The project heavily focuses on multithreading and mutex synchronization:

    Each philosopher is represented by a thread, and each fork is a shared mutex.
    Philosophers need both forks to eat and release them after eating.
    The simulation ensures that no two philosophers can pick the same fork simultaneously, preventing data corruption and potential crashes.

Error Handling

The program handles potential errors, such as:

    Invalid input arguments.
    Thread creation failures.
    Mutex initialization failures.

If an error occurs, the program will terminate gracefully, providing an error message to guide the user.
