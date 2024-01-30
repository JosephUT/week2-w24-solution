# Homework 2
{: .no_toc }
Due 11:59PM Feb 6, 2024
{: .fs-6 .fw-300 }

There are two files with coding problems. Read each file and complete the sections marked **TODO**.
Although you can complete the problems in any order, it will be most convenient to follow the order
below.

1. ```CMakeLists.txt```
2. ```src/client_server.cpp```

The focus of this week is to onboard with using C libraries that interface with the Linux kernel, more 
specifically Linux sockets. Please take your time to read the documentation referenced in lab 2. This 
homework should be fairly simple, but it is important you understand it as we will continue working with 
sockets in future labs and projects.

## Testing
The client server functions should be tested by invoking the unit tests under ```/test```. You should
be able to invoke your unit tests by running ```ctest``` in the root of the build tree.

If it is more intuitive or useful for debugging purposes, we have provided separate executables under
```test_manual```. Feel free to use these to run your client and server manually on separate processes.

## Grading and Submission

Points for this homework will be assigned as follows.

- 0.25 - All code builds.
- 0.25 - The test is runnable through CTest.
- 2.5 - The ```test_client_server``` test case passes.

To submit, **push your code** before the deadline and **submit a link** to your repository in the assignment on Canvas.