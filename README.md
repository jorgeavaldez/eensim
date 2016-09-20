# Stop and Reroute: An Exercise in End-to-End Routing
This is the simulation directory for our Networks project.

## Directories
This repository consists of three directories:
  - bin: holds the final compiled binaries to run any simulations
  - obj: holds the compiled .o files
  - src: holds the source files for the project

## Building
**With Vagrant**
To build, make sure that you have Vagrant installed.
Move into this direcroty then run `vagrant up` to 
provision the vagrantbox.

Once your vagrantbox is up, run `vagrant ssh` to log
in.

Then run `make`.

**Notes**
Currently the Makefile does not support any other targets.

If you don't want to use Vagrant, then just run `make` on
any computer that has GNU Make and a g++ version with 
C++ 11 support on it.
