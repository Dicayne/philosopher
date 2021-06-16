# Philosophers 42 Project

The goal of this project is to create a program that simulates the life of one or more philosopher with certain constraints.\
Philosophers 42 project's goal, is to discover the principle of multi threading.

### SUBJECT

* Several philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping
* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
* There are some forks on the table.
* As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
* One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
* To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.
* Each philosopher should be a thread.
* Each time a philosopher has finished eating, he will drop his forks and start sleeping.
* When a philosopher is done sleeping, he will start thinking.
* While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
* The simulation stops when a philosopher dies.

### COMPILATION AND EXECUTION:

This program take 4 or 5 arguments
```
make
./philo Arg1 Arg2 Arg3 Arg4 Arg5(optional)
```
* Arg 1 ➜ Number of Philosophers
* Arg 2 ➜ Time to die : This is the maximum time that the philosopher can stay without eating.
* Arg 3 ➜ Time to eat : This is the time that the philosopher take to eat.
* Arg 4 ➜ Time to sleep : This is the time that the philosopher take to sleep.
* Arg 5(optional) ➜ Number of times each philosopher must eat : This is the number of time philosopher must eat before stop program, when a philosopher have eaten enouth, his thread end.

#### EXEMPLE

```
./philo 2 310 150 150 ➜ Will never die
./philo 12 800 200 300 ➜ Will never die
./philo 120 800 350 350 ➜ Will never die
./philo 4 100 100 100 ➜ Will die
./philo 20 100 70 40 ➜ Will die
./philo 20 410 200 200 15 ➜ Will never die and stop when all philosophers have eaten 15 times
./philo 3 410 200 200 1 ➜ Will never die and stop when all philosophers have eaten 1 times
```

### EXPLANATION OF DISPLAY

```
120(a)     2(b): is eating(c)
```
* a ➜ Time elapsed since the start of the simulation
* b ➜ Which philosopher make the action
* c ➜ Action that philosopher make

If you put the optional Arg 5, you will see:
```
Philo[3] have eaten 4 time
```
This is displayed when a philosopher has eaten enough and his thread ends

### DISCLAIMER

This program is greedy and can have different behaviors depending on your computer.\
If for example, in ``` ./philo 2 310 150 150 ``` a philosopher die, don't hesitate to grow up th Time to die and/or reduce time to eat and/or time to sleep.

Enjoy :smile:
