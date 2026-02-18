# Doxygen Sphinx Example
Simple example of using Doxygen, Sphinx, and Breathe for creating documentation for C++ projects.


See the post [here](https://amschubehttps://amschuberth.gitlab.io/blog/posts/doxysphinx/).

Read the Docs hosted documentation for this example can be found [here](https://doxygensphinxexample.readthedocs.io/en/latest/).

## Prerequisites

1. CMake 
2. Python
3. Doxygen 

This example uses `doxygen_add_docs()`, which was added in CMake v3.9, so ensure your version is >= to this.

I have tested this example with 
- CMake v4.2.3
- Python v3.13.5
- Doxygen v1.16.1

## Building

Git clone the repository:

```bash
git clone https://github.com/ASchuberth/DoxygenSphinxExample.git
```

Inside the project directory, run:

```bash
python -m venv .venv
```

Activate the virtual environment:

```bash
source .venv/bin/activate
```

Install the python dependencies with:

```bash
python -m pip install -r docs/requirements.txt
```

Finally, build the project with:

```bash
cmake -S . -B build/
cmake --build build/ --target docs
```

## Steps Folder

The `steps/` folder contains folders for each step for this example.  For example,
`00-initial-folder-structure/` has the initial folder structure. 
`03-doxygen-setup/` has all the steps done in the "Doxygen CMake Setup" 
section of the blog post.  These are meant to be used as references.
