# Git Bisect

This is a playground to experiment with the git bisect command. If you want to learn more about how to use git bisect you can check out this corresponding [blog post](https://steffenkoerner.github.io/git/2023/03/17/git-bisect-tutorial.html)

The project is implemented in C++ and bazel is used as a build system.
## Prerequisites
* Bazel is [installed](https://bazel.build/install)

## Setup

### Clone the repository
You can clone the repository with
```
 git clone https://github.com/steffenkoerner/git.git
```
### Checkout the challenge branch
The main branch already contains the solution. Thus, if you want to solve it on your own you need to check out the
challenge branch.
This can be done with the following command
```
 git checkout challenge
```

### Check Status
You should run all the unit tests to make sure that you set up everything correctly. You can run the unit tests with the following command from within the git/bisect folder:
```
bazel test //...
```

## Your challenge
Use git bisect to solve the following challenge. If you need more background information check out this [blog post](https://steffenkoerner.github.io/git/2023/03/17/git-bisect-tutorial.html).

You just discovered that somehow the sum(int a , int b) function is misbehaving if you set a to 23. This means that sum(23,3) returns -1 instead of 26. The sum function can be found here: bisect/src/application.h

You are sure that it was correctly somewhere in the past. Can you find the commit that introduced the bug?