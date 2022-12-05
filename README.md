# ECE 39595 - Course Project
## Team: Shantanu Sinha (sinha93), Ronit Nallagatla (rnallaga)

---

**Final submisison can be found under `tags/step3`**

## Parser Fun

The parser code is contained in the `step1/` directory. 

Running `make` in the `step1/` directory will create a an executable called `comp`.

The parser will produce `.out` files that will be read by the VM.

## VM Fun

VM code can be found in the `step2/` directory.

Similar to the parser, running `make` in the `step2/` directory will compile and create an executable called `vm`. 

## Notes

Running `make clean` at any point will delete all output files (both Parser and VM output), so it should ideally not be run. If `make clean` is run, then all outputs would have to be re-generated.

The output of the VM is printed to `stdout` and can be piped to a file (`.vout` file). However, the parser output, or the input to the VM (`.out` file) is manually generated using fstream in the parser. Hopefully this doesn't mess things up grading-wise.