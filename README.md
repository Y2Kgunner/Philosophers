# Philosophers

The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenges of resource allocation and deadlock avoidance in concurrent systems. The objective of this project is to simulate the dining behavior of philosophers sitting at a round table, where they alternate between eating, thinking, and sleeping. The goal is to implement a program that ensures the philosophers can eat without starvation and without causing deadlocks.

## Key Features

- Simulation of philosophers sitting at a round table with a bowl of spaghetti and forks
- Implementation of rules for philosopher behavior, including eating, thinking, and sleeping
- Prevention of deadlocks and starvation to ensure all philosophers can eat
- Compliance with specific rules and requirements regarding thread or process management, argument parsing, and logging

## Knowledge Gained

- Understanding of concurrency and synchronization in concurrent systems
- Implementation of multithreading or multiprocessing solutions using threads or processes
- Use of synchronization primitives such as mutexes and semaphores to manage shared resources
- Handling of command-line arguments and parsing
- Logging and formatting of program output to display philosopher states and events accurately

## Mandatory Part

In the mandatory part of the project, each philosopher is represented as a thread. The forks are placed between each pair of philosophers, and their state is protected using mutexes to prevent duplication and ensure exclusive access.

## Bonus Part

In the bonus part, all forks are placed in the middle of the table, and their availability is managed using a semaphore. Each philosopher is represented as a process, with the main process orchestrating the simulation without participating as a philosopher.
