# Git Bisect

This is a playground to experiment with the git bisect command. If you want to learn more about how to use git bisect you can check out this blog post ??????

The project is implemented in C++ and bazel is used as a build system.
# Prerequisites

* Bazel is installed [Installation](https://bazel.build/install)
* 


# Set UP
* Clone the repository
* Checkout the test branch
* Run "bazel test //..." from within the bisect folder

# Your challenge
Use git bisect to solve the following challenge. If you need more background information check out this blog post.

You just discovered that somehow the sum(int a , int b) function is misbehaving if you set a to 23. This means that sum(23,3) returns -1 instead of 26. You are sure that it was correctly at the beginning. Can you find the commit that introduced the bug?