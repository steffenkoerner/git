git-bisect - Use binary search to find the commit that introduced a bug

In this article I want to talk how to automatically use git bisect. The manual way is discussed
very often and is very easy to understand.


You just use
* git bisect start
* git bisect bad HEAD
* git bisect good <hash of good commit>

Then you manually inspect the mentioned version. Then you just tell git if its good or bad by
* git bisect good/bad

The process is repeated until git gives you the commit that introduced the issue. 

The question as always with manual work should be if it can be automated. Is it possible in this case.

This depends if the fact we want to check can be automatically verified with e.g. a test. If it's possible then we can use the git bisect run <script.sh> functionality


At the first view this approach looks very easy as many other articles just state that you should trigger your unit tests from the script.sh and then let the script run. But this works only if your unit tests already detect the problem. But what does this means. This means that executing your unit tests at the revisions that are bad are failing. Meaning your tests are not running on master are not green. But this should never be the case. 

I assume we are doing professional software development and using a CI pipeline. Thus, our unit tests are always green on each commit. Now, this simplistic approach doesn't work anymore.

Let's how to handle this more complicated case.

First we need to implement a test e.g. a unit test that caputres the failure. Meaning this unit test fails. We will call this unit test in our bash script that we give as argument to the git bisect run <script.sh> algorithm.

We still have one problem. If we add the unit test to our test file than it's only available from this commit onwards. In all the all revisions it's obviously not there. This is a problem as git bisect automatically checks out the next revision that needs to be checked. In this revision our test is missing. 

Thus, we can't easily add our new test to the test file. One possibility is to create this test stash it and then apply it before we exeucute our tests. This makes sure that this test is executed. 

This can sometimes lead to merge conflicts and we need to take care of them.

The steps would be 

* Add unit test
* git stash
* start the bisect process
* git stash apply
* execute the test
* git clean everything ???
* git bisect good/bad


Then we loop through the commits until we find the correct commit.
* git stash apply
* execute the tests
* git clean everything
* git bisect good/bad

I made the experience that adding the tests to a separate file in the test folder is easier at there won't be
any merge conflict. But this only works if the test target automatically includes all the files in the test folder. In bazel this is done in the cc_test rule by using the glob() funcion.


* git bisect start
* git bisect good ...
* git bisect bad ...
* git bisect run <script>


