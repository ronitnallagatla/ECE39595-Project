Our parser does not output the correct output needed for the VM to run. This means the Parser needs to be modifed to work.

Parser/parsegood will run our Parser with the testcases, and diff it with the expected output. Both the expected output and Parser Outputs are in TestCasesPart2_v2

The Parser Output is {FILENAME}Test.pout

Run Parser/parsegood

In particular, the GoSubLabel output for our PArser is very wrong. At the time, it was easier to just store the Label string instead to putting it in the symbol table.
However, the expected ouput was changed and they don't want the label name and instead want label location. We never stored label location. To fix it, go into Parser, 
add the GoSubLabel label to the sybmol table (instead of just storing the string value) and print it out like we do for Jump cases.


Also the column output from diff is the -y flag in the diff command in parsegood. Disable it if annoying.

---
Edit: I fixed GoSubLabel, there's some errors with JumpNZero that I'm working on.

Edit2: 27DotProd jumpnzero is the only one thats failing, everything else looks fine.

Edit3: 27DotProd is failing cos the the location of the label is being updated when the program sees it the second time.



EDIT4:  IT WORKS. 