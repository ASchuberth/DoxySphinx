# DoxySphinx
Simple example of using Doxygen, Sphinx, and Breathe for creating documentation for C++ projects.


Work in progress


# Steps for setting up Sphinx

## Installs

### Doxygen

Download the latest version from the 
official website 
[here.](https://www.doxygen.nl/)

### CMake

Download the latest version from the 
official website 
[here.](https://cmake.org/download/)


### Python Packages

1. Create python environment using venv

```cmd
python -m venv .venv
```

2. Add `requirements.txt` with the following:

```
sphinx
sphinx-rtd-theme
breathe
```

3. Activate .venv environment

```
.venv\Scripts\activate
```

4. Install python packages

```
python -m pip install -r requirements.txt
```

## Project Setup

### Sphinx Setup

1. Make CMake project with your source code in
   `src/` and a `docs/` folder.

```
Project Folder/
|
---- .venv/
---- cmake/
---- docs/
---- src/
---- .gitignore
---- CMakeLists.txt
```

2. In the terminal, navigate to `docs/` and
   run `sphinx-quickstart.exe`

```
cd docs/
sphinx-quickstart.exe
```

Fill out the given prompts.

The default HTML Sphinx documentation can be 
created running in the `docs/` folder

```
make html
```

3. Change theme of Sphinx

docs/conf.py:
```
...
html_theme = 'sphinx_rtd_theme'
...
```

### Sphinx CMake Setup

1. Create `FindSphinx.cmake` in top level `cmake/` folder.

```

if(WIN32)
set(PYTHON_ENVIRONMENT ${CMAKE_SOURCE_DIR}/.venv/Scripts/)
message("Python Environment: ${PYTHON_ENVIRONMENT}")
endif()

if(UNIX)
set(PYTHON_ENVIRONMENT ${CMAKE_SOURCE_DIR}/.venv/bin/)
message("Python Environment: ${PYTHON_ENVIRONMENT}")
endif()


#Look for an executable called sphinx-build
find_program(SPHINX_EXECUTABLE
             NAMES sphinx-build
             HINTS ${PYTHON_ENVIRONMENT}
             DOC "Path to sphinx-build executable")

include(FindPackageHandleStandardArgs)

#Handle standard arguments to find_package like REQUIRED and QUIET
find_package_handle_standard_args(Sphinx
                                  "Failed to find sphinx-build executable"
                                  SPHINX_EXECUTABLE)
```
Modified from [1] to give hint that sphinx-build is in the `.venv/` folder.


2. Add following line to top-level CMakeLists.txt to look for custom modules
   in the `cmake/` folder.

```
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
```

3. Add the following to `docs/CMakeLists.txt`:
```
set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR})
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx)

add_custom_target(Sphinx ALL
                COMMAND
                ${SPHINX_EXECUTABLE} -b html
                ${SPHINX_SOURCE} ${SPHINX_BUILD}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating documentation with Sphinx")
```

Building with CMake should now generate the Sphinx documentations at
`build/<configurePresetName>/docs/sphinx/`



# References

[1] https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/

[2] https://www.sphinx-doc.org/en/master/usage/installation.html

[3] https://packaging.python.org/en/latest/guides/installing-using-pip-and-virtual-environments/
