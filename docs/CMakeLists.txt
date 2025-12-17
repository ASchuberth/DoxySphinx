
# Documentation


find_package(Doxygen REQUIRED)

message("Doxygen")

# if(Doxygen_FOUND)


    # Doxyfile Configurations
    
    # Location of source code for doxygen to parse
    set(DOXYGEN_INPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src)

    # Location to place the output of doxygen
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
    
    # Project Name that appears in doxygen documentation header
    set(DOXYGEN_PROJECT_NAME "DoxySphinx" )
    
    
    set(DOXYGEN_GENERATE_XML "YES")
    
    set(DOXYGEN_GENERATE_LATEX "YES")
    
    # These 2 need to be set to the following to display LaTex correctly
    set(DOXYGEN_LATEX_CMD_NAME "latex")
    set(DOXYGEN_USE_MATHJAX "YES")
    
    
    # Other custom settings for Doxygen
    set(DOXYGEN_FULL_PATH_NAMES "NO")
    set(DOXYGEN_EXTRACT_ALL "YES")
    set(DOXYGEN_EXTRACT_PRIVATE "YES")
    set(DOXYGEN_EXTRACT_PRIV_VIRTUAL "YES")
    set(DOXYGEN_EXTRACT_STATIC "YES")
    set(DOXYGEN_HTML_COLORSTYLE "TOGGLE")
    set(DOXYGEN_HTML_DYNAMIC_MENUS "NO")

    # For future implementation of Sphinx and Breathe
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIRECTORY}/html/index.html)


    
    # Create the output directory, doxygen/, if not already there
    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}) 

    # Create doxygen target for generating doxygen docs
    # Target name is doxygen.  This can be changed if desired.
    doxygen_add_docs(
                        doxygen 
                        ${DOXYGEN_INPUT_DIRECTORY}
                    )



    message("DOXYGEN_INPUT_DIRECTORY: ${DOXYGEN_INPUT_DIRECTORY}")
    message("DOXYGEN_OUTPUT_DIRECTORY: ${DOXYGEN_OUTPUT_DIRECTORY}")
    message("DOXYGEN_INDEX_FILE: ${DOXYGEN_INDEX_FILE}")


# endif()


find_package(Sphinx REQUIRED)


set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx)

message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("SPHINX_EXECUTABLE ${SPHINX_EXECUTABLE}")
message("SPHINX_SOURCE: ${SPHINX_SOURCE}")
message("SPHINX_BUILD: ${SPHINX_BUILD}")

add_custom_target(sphinx ALL
                  COMMAND
		  ${SPHINX_EXECUTABLE} -b html
                  -Dbreathe_projects.doxysphinx=${DOXYGEN_OUTPUT_DIRECTORY}/xml
		  ${SPHINX_SOURCE} ${SPHINX_BUILD}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                  DEPENDS
                   # Other docs files you want to track should go here (or in some variable)
		   ${SPHINX_SOURCE}/index.rst
                   # ${DOXYGEN_INDEX_FILE}
		   doxygen
                   # MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
                  COMMENT "Generating documentation with Sphinx")
